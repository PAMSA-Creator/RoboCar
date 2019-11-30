#include "PkgRoboCar.h"

RoboCar myRoboCar;
byte status = 0;

void setup()
{
	status = myRoboCar.init();
    if(0 != status) Serial.println("Error initialising myRoboCar");
}

void loop()
{
    myRoboCar.run();
}
