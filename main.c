#include<stdio.h>
#include<stdlib.h>
#include"EasyPIO.h"
#include<wiringPi.h>
#include<unistd.h>
#include"mislibrerias.h"

int main(void){
	int ok;
	int choose;

	ok = validaPass(); 

	if(ok==1){
	printf("Elija una opción. \n ");
	printf("\n1 - Autofantastico");
	printf("\n2 - El choque");
	printf("\n3 - La apilada");
	printf("\n4 - La carrera");
	printf("\n5 - eleccion1");
	printf("\n6 - eleccion2");
	printf("\n7 - eleccion3");
	printf("\n8 - eleccion4");
        }	
choose=getchar();
printf("\n");
choose=choose-'0';
inicia();
switch(choose){
	case 1: printf("Ud. ha seleccionado Auto Fantástico.\n");
		printf("Presione 'q' para salir\n");
		auto_();
		close_keyboard();
		gpio_low(vec);
	       break; 
	case 2: printf("Ud. ha seleccionado Choque.\n");
		printf("Presione 'q' para salir\n");
	        choque();
		close_keyboard();
		gpio_low(vec);
	        break;
		
	case 3: printf("Ud. ha seleccionado Apilada.\n");
		printf("Presione 'q' para salir\n");
		apilada();
		close_keyboard();
		gpio_low(vec);
		break;
	case 4: printf("Ud. ha seleccionado La carrera.\n");
		printf("Presione 'q' para salir\n");
		carrera();
		close_keyboard();
		gpio_low(vec);
		break;
	default: break; 	
}
return 0;

}




