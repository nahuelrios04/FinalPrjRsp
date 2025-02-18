//Archivo para recibir archivo de PC a raspberry

#define BAUDRATE B9600

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "termset.h" 		//Incluir esta libreria

int main (void) {
	int fd; 		//File Descriptor
	struct termios oldtty, newtty;
	int dato=0;
	//////CAMBIAR DIRECCIÓN DE TTY//////////
	fd = open ("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY); /* Archivo lectura-escritura -> RDWR
												    * NoCTTY: Si el archivo refiere a una terminal (tty), no lo convierte 
												    * en terminal de control de procesos. */
	if (fd == -1) {
		printf ("No se pudo abrir el dispositivo");
		return -1;}
		
	// tcgetattr: obtiene los parámetros asociados con la terminal 
	tcgetattr(fd, &oldtty);
	newtty = oldtty;
	newtty.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
	newtty.c_iflag = IGNPAR;
	//newtty.c_oflag;
	//newtty.c_lflag;
	newtty.c_cc[VTIME] = 0;
	newtty.c_cc[VMIN] = 1;
	
	tcflush(fd, TCIOFLUSH);
	/* 	TCIFLUSH
     * Vacía los datos de entrada que ha recibido el sistema pero no leídos por una aplicación.
	 *	TCOFLUSH
     * Elimina los datos de salida que ha escrito una aplicación pero que no se han enviado al terminal.
	 *	TCIOFLUSH
     * Vacía tanto los datos de entrada como los de salida. */
     
     
     
     /* Esta función establece los atributos del dispositivo terminal con el archivo fd. 
      * Los nuevos atributos se toman de la estructura a la que apunta termios. */
     tcsetattr(fd, TCSANOW,&newtty);
     /* TCSANOW
      * Realiza el cambio de inmediato.  
      */
	while(1){
	printf("recibiendo cadena: ");
	read(fd, &dato, 1);
	//read(fd , &ptr , sizeof(ptr));
	printf("%d \n", dato);
	//printf("%s \n", ptr);
	tcdrain(fd);
	sleep (2);
	dato = 0;
	//tcdrain - espera la transmisión de salida 
	}
	
	tcsetattr(fd, TCSANOW,&oldtty);

	close(fd);
	
	return 0;
}
