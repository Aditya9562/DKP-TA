#include <led.h>
led lampu;

void setup(){

}

void loop (){
    led.led_hidup();
    delay(200);
    led.led_mati();
    delay(200);
}