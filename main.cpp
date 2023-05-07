//Uses the measured z-acceleration to drive leds 2 and 3 of the mbed

#include "mbed.h"
#include "MMA7660.h"

MMA7660 MMA(p28, p27);

DigitalOut connectionLed(LED1);
PwmOut Zaxis_p(LED2);
PwmOut Zaxis_n(LED3);

float calculateAngle(float ax, float ay, float az) {
float pitch = atan(ax / sqrt(ay * ay + az * az));
return pitch;
}

int main() {  
    if (MMA.testConnection())
        connectionLed = 1;
        
    while(1) {
        float ax = MMA.x();
        float ay = MMA.y();
        float az = MMA.z();
        float pitch = calculateAngle(ax, ay, az);
        Zaxis_p = pitch;
        Zaxis_n = -pitch;
    }

}