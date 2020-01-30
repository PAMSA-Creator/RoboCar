#include "PkgRoboCar.h"

RoboCar myRoboCar;
byte status = 0;

void setup()
{
	status = myRoboCar.init();
    Serial.println("RoboCar::setup()");
    if(0 != status) Serial.println("Error initialising myRoboCar");
}

void loop()
{
    Serial.println("RoboCar::loop()");
    myRoboCar.run();
}