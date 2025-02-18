#ifndef EASY_PIO_H		/* Directiva preprocesador que comprueba si ya está definido*/
#define EASY_PIO_H

int val;



#include <sys/mman.h> 	/* Libreria de gestión de memoria*/
#include <unistd.h>		/* Libreria de constantes y tipos simbólicos estándar */
#include <fcntl.h>		/* Libreria de opciones de control de archivos*/
#include <stdio.h>		/* Libreria estandar entrada-salida */


/* Definicion de constantes */

#define INPUT 	0
#define OUTPUT 	1
#define	ALT5 	2
#define ALT4 	3
#define ALT0 	4
#define ALT1 	5
#define ALT2 	6
#define ALT3 	7

/* Mapa de memoria */

#define GPIORP4_BASE		0xFE200000			/* Dirección base de GPIO en Raspberry 4*/		
#define TAMANO_BLOQUE 		(4*1024)


/* Puntero que será mapeado en memoria cuando se llame a Pioinit()*/
volatile unsigned int *gpio; /* Puntero a dirección base */




/* Registros GPIO */

#define GPFSEL ((volatile unsigned int *)(gpio + 0))
#define GPSET  ((volatile unsigned int *)(gpio + 7))
#define GPCLR  ((volatile unsigned int *)(gpio + 10))
#define GPLEV  ((volatile unsigned int *)(gpio + 13))


void pioInit() {
	int mem_fd;
	void *reg_map;
	
	mem_fd = open("/dev/mem", O_RDWR | O_SYNC); /* Abre el dispositivo /dev/mem */
	reg_map = mmap(
			  NULL,							/* Dirección donde comienza el mapeo */ 
			  TAMANO_BLOQUE ,				/* Tamaño de bloque mapeado */
			  PROT_READ|PROT_WRITE,			/* Lectura y escritura de memoria mapeada*/
			  MAP_SHARED,					/* El programa no tendrá acceso exclusivo a esta memoria*/
			  mem_fd,						/* Puntero a /dev/mem */
			  GPIORP4_BASE);				/* Offset al periferico GPIO */
			  
	gpio = (volatile unsigned *) reg_map;
	close(mem_fd);
	
}



/* Funciones GPIO */

void pinMode (int pin, int function)
{
	int reg = pin/10;
	int offset = (pin % 10)*3;
	
	GPFSEL[reg] &= ~((0b111 & ~function) << offset);
	GPFSEL[reg] |=  ((0b111 &  function) << offset);
	
	if(val)
			GPSET[reg] = 1 << offset;
	else
			GPCLR[reg] = 1 << offset;
}

void digitalWrite (int pin, int val)
{
	int reg = pin / 32;
	int offset = pin % 32;
	
	if(val)
		GPSET[reg] = 1 << offset;
	else
		GPCLR[reg] = 1 << offset;

}
int digitalRead (int pin)
{
	int reg = pin / 32;
	int offset = pin % 32;
	
	
	return (GPLEV[reg] >> offset) & 0x00000001;
	
	}
	
	
	#endif
	
	
	
	
	
	
	

	
	
	
	
	
	
	 
		
