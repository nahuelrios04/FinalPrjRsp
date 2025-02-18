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
switch(choose){
	case 1: auto_();
	       break; 
	case 2: break;
	default: break; 	

return 0;

}}





void autofantastic(void){
       	pioInit(); 
 int vec[] = {23,24,25,12,16,20,21,26}; // Se declare GPI° 17 come entrada
 int i;
 pinMode(23, 1); 
 pinMode(24, 1);
 pinMode(25, 1); 
 pinMode(16, 1);
 pinMode(12, 1); 
 pinMode(20, 1);
 pinMode(21, 1); 
 pinMode(26, 1);
 while(1) {
  gpio_low(vec);
  for(i=0; i<8; i++){
    digitalWrite(vec[i], 1);
    sleep(100);
    digitalWrite(vec[i], 0);
  }
  for(i=7; i>-1; i--){
    digitalWrite(vec[i], 1);
    sleep(100);
    digitalWrite(vec[i], 0);
  } 
 }
 
} 


