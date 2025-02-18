#include "EasyPIO.h"
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

