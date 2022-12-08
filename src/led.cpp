#include "led.h"
const int led_pin=14;
led::led(){
    serial.begin(9600);
    pinMode(led_pin, OUTPUT);

}
led::~led(){

}
void led :: led_hidup(){
    digitalWrite(led_pin, HIGH);  
}

void led :: led_mati(){
    digitalWrite(led_pin, LOW);
}