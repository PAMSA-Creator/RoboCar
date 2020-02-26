#include "PkgRoboCar.h"

RoboCar myRoboCar;
byte status = 0;

void setup()
{
    Serial.begin(115200);
    while (!Serial);
    Serial.println("RoboCar::setup()");
	status = myRoboCar.init();
    if(0 != status) Serial.println("Error initialising myRoboCar");
}

void loop()
{
    static bool bLoop = false;
    if(!bLoop) {
        Serial.println("RoboCar::loop()");
        myRoboCar.run();
        bLoop = true;
    }
}