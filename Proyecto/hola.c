#include"./librerias/secuencias/EasyPio.h"
#include<wiringPi.h> 
int main(){
pioInit(); 
pinMode(26,OUTPUT); 
while(1){
digitalWrite(26,1); 
sleep(10);
digitalWrite(26,0); 

}

return 0; 
}
