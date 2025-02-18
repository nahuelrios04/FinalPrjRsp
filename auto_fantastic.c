#include "EasyPIO.h"
void gpio_low(int *a){
int y;
for(y=0;y<8;y++)
	digitalWrite(a[y], 0);
}
int auto_(void){
       	pioInit(); 
 int vec[] = {23,24,25,12,16,20,21,26}; // Se declare GPI° 17 come entrada
 int i;
 pinMode(23, OUTPUT); 
 pinMode(24, OUTPUT);
 pinMode(25, OUTPUT); 
 pinMode(16, OUTPUT);
 pinMode(12, OUTPUT); 
 pinMode(20, OUTPUT);
 pinMode(21, OUTPUT); 
 pinMode(26, OUTPUT);
 while(1) {
  gpio_low(vec);
  for(i=0; i<8; i++){
    digitalWrite(vec[i], 1);
    sleep(1);
    digitalWrite(vec[i], 0);
  }
  for(i=7; i>-1; i--){
    digitalWrite(vec[i], 1);
    sleep(1);
    digitalWrite(vec[i], 0);
  } 
 }
 
 return 0;
} 

