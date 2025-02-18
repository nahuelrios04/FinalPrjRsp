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
choose=choose-'0';
inicia();
switch(choose){
	case 1: auto_();
	       break; 
	case 2: carrera();
		break;
	default: break; 	

return 0;

}}




