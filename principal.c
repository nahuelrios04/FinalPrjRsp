#include <stdio.h>
#include <stdlib.h>
#include "EasyPIO.h"
#include <wiringPi.h>
#include <ncurses.h>

void AutoFantastico (void);
void LaCarrera(void);
void Acumulador(void);
void Elchoque(void);
void Ejercicio4(void);
void Secuencia5(void);
void Secuencia6(void);
void Secuencia7(void);
void Secuencia8(void);
int  Password(void);
void SeteoDeVelocidad(void);
void ConfiguracionDeIO(void);
int Comunicacionserie2(void);

int led[8]={23,24,25,12,16,20,21,26},pulsadores[2]={17,27} , llaves[4]={5,6,13,19},contador=250000,serial_port;

int main(){

	int s,q,check;

	check = Password();
	
	if (check==0)
		return 0;
	
	pioInit();
	
	ConfiguracionDeIO();
	
	while(1){
		
		system("clear");
		refresh();
		printf("Seleccione una opcion (con numeros): \n --Secuencia (1): Auto Fantastico  \n --Secuencia (2): La Carrera \n --Secuencia (3): Acumulador \n --Secuencia (4): El choque \n --Secuencia (5): El beso	\n --Secuencia (6): La escalera \n --Secuencia (7): El vigilante \n --Secuencia (8): La alarma \n --Manejo remoto (9) \n --Seteo de Velocidad (10) \n --Salir (11) \n");
		scanf("%d",&s);
		getchar();

	switch(s){
			
			case 1:{
				AutoFantastico();
				break;
				}
			case 2:{
				LaCarrera();
				break;
				}
			case 3:{
				Acumulador();
				break;
				}
			case 4:{
				Elchoque();
				break;
				}
			case 5:{
				Secuencia5();
				break;
				}
			case 6:{
				Secuencia6();
				break;
				}
			case 7:{
				Secuencia7();
				break;
				}
			case 8:{
				Secuencia8();
				break;
				}
			case 9:{
					system("clear");
					Comunicacionserie2();
					break;
				}
			case 10:{
				SeteoDeVelocidad();
				break;
				}
			case 11:{
				return 0;
				}
			default:{
				system("clear");
				printf("\n****SELECCION NO VALIDA****\n\n");
				delay(1000);
				break;
				}
		}  

	}
    
}
