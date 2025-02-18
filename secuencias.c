#include "EasyPIO.h"
#include<time.h>
#define N 8
int y, i;
int vec[] = {23,24,25,12,16,20,21,26}; // Se declare GPI° 17 come entrada
void gpio_low(int *a){
for(y=0;y<8;y++)
	digitalWrite(a[y], 0);
}

void inicia(void){
       	 pioInit(); 
	 for(i=0;i<N;i++)
	 	pinMode(vec[i],OUTPUT); 	
			 
         }

int choque(void){
	 int j;
	 int table[11][8] = {
	 	{0,0,0,0,0,0,0,0},
	 	{1,0,0,0,0,0,0,1},
	 	{0,1,0,0,0,0,1,0},
	 	{0,0,1,0,0,1,0,0},
	 	{0,0,0,1,1,0,0,0},
	 	{0,0,0,0,0,0,0,0},
	 	{0,0,0,1,1,0,0,0},
	 	{0,0,1,0,0,1,0,0},
	 	{0,1,0,0,0,0,1,0},
	 	{1,0,0,0,0,0,0,1},
	 	{0,0,0,0,0,0,0,0},
	 };
	 gpio_low(vec);
	 while(1){
		 for(i=0;i<11;i++){
			 for(j=0;j<8;j++){
				 digitalWrite(vec[j], table[i][j]);
			 
			 }

		 	usleep(500000);
		 	}
	 }

return 0;
}

int apilada(void){

	 int j;
	 int table[52][8] = {
	 	{1,0,0,0,0,0,0,0},
	 	{0,1,0,0,0,0,0,0},
	 	{0,0,1,0,0,0,0,0},
	 	{0,0,0,1,0,0,0,0},
	 	{0,0,0,0,1,0,0,0},
	 	{0,0,0,0,0,1,0,0},
	 	{0,0,0,0,0,0,1,0},
	 	{0,0,0,0,0,0,0,1},//primero en llegar
	 	{0,0,0,0,0,0,0,0},
	 	{1,0,0,0,0,0,0,1},
	 	{0,1,0,0,0,0,0,1},
	 	{0,0,1,0,0,0,0,1},
	 	{0,0,0,1,0,0,0,1},
	 	{0,0,0,0,1,0,0,1},
	 	{0,0,0,0,0,1,0,1},
	 	{0,0,0,0,0,0,1,1},
	 	{0,0,0,0,0,0,0,0},//segundo en llegar
	 	{1,0,0,0,0,0,1,1},
	 	{0,1,0,0,0,0,1,1},
	 	{0,0,1,0,0,0,1,1},
	 	{0,0,0,1,0,0,1,1},
	 	{0,0,0,0,1,0,1,1},
	 	{0,0,0,0,0,1,1,1},
	 	{0,0,0,0,0,0,0,0}, //tercero en llegar
	 	{1,0,0,0,0,1,1,1},
	 	{0,1,0,0,0,1,1,1},
	 	{0,0,1,0,0,1,1,1},
	 	{0,0,0,1,0,1,1,1},
	 	{0,0,0,0,1,1,1,1},
	 	{0,0,0,0,0,0,0,0},//cuarto 
	 	{1,0,0,0,1,1,1,1},
	 	{0,1,0,0,1,1,1,1},
	 	{0,0,1,0,1,1,1,1},
	 	{0,0,0,1,1,1,1,1},
	 	{0,0,0,0,0,0,0,0}, //quinto 
	 	{1,0,0,1,1,1,1,1},
	 	{0,1,0,1,1,1,1,1},
	 	{0,0,1,1,1,1,1,1},
	 	{0,0,0,0,0,0,0,0}, //sexto
	 	{1,0,1,1,1,1,1,1},
	 	{0,1,1,1,1,1,0,1},
	 	{0,0,0,0,0,0,0,0}, //septimo
	 	{1,1,1,1,1,1,1,1},
	 	{0,0,0,0,0,0,0,0}, //octavo
	 };
	 gpio_low(vec);
	 while(1){
		 for(i=0;i<47;i++){
			 for(j=0;j<8;j++){
				 digitalWrite(vec[j], table[i][j]);
			 
			 }

		 	usleep(500000);
		 	}
	 }

return 0;
}

int carrera(void){
	 gpio_low(vec);
	while(1){	
  		for(i=0; i<N; i++){
    			digitalWrite(vec[i], 1);
    			sleep(1);
    			digitalWrite(vec[i], 0);
  				}
  		for(i=0; i<N; i++){
    			digitalWrite(vec[i], 1);
		}  
		sleep(1); 
  		for(i=0; i<N; i++){
    			digitalWrite(vec[i], 0);
		}
		sleep(1);
	}
 
return 0;
}

int auto_(void){	
	 gpio_low(vec);
	 while(1) {
  		for(i=0; i<N; i++){
    			digitalWrite(vec[i], 1);
    			sleep(1);
    			digitalWrite(vec[i], 0);
  				}
  		for(i=N-1; i>=0; i--){
    			digitalWrite(vec[i], 1);
    			sleep(1);
    			digitalWrite(vec[i], 0);
  					} 
		 }
 
 return 0;
} 

