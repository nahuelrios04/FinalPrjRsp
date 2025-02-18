#include"EasyPio.h"
#include<wiringPi.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h> 
void gpio_low(int *a){
int y;
for(y=0;y<8;y++)
	digitalWrite(a[y], 0);
}
void autoFantas(void){
 int vec[] = {23,24,25,12,16,20,21,26}; 
 int i;
 int op=0;
 pioInit();
 wiringPiSetup();
  for(i=0; i<8; i++){
	pinMode(vec[i], OUTPUT);
  }
  for(i=0; i<8; i++){
    digitalWrite(vec[i], HIGH);
    usleep(10000000);
    digitalWrite(vec[i],LOW );
  }
  for(i=7; i>=0; i--){
    digitalWrite(vec[i], HIGH);
    usleep(10000000);
    digitalWrite(vec[i], LOW);

  
op++; }
 

}

