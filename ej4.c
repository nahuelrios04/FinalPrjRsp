#include "EasyPIO.h"
int main(void) {
pioInit();

pinMode(5, INPUT);
pinMode(6, INPUT);
pinMode(13, INPUT);
pinMode(19, INPUT);

pinMode(20, OUTPUT);
pinMode(21, OUTPUT);
pinMode(26, OUTPUT);

while(1){
while (digitalRead(5)){ 
digitalWrite(20, digitalRead(6));
digitalWrite(21, digitalRead(13));
digitalWrite(26, digitalRead(19));
}
}
}
