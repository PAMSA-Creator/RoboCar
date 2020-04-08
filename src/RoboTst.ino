#include "PkgRoboTst.h"

RoboTst myRoboTst;
byte status = 0;

void setup()
{
    Serial.begin(115200);
    while (!Serial);
    Serial.println("RoboTst::setup()");
	status = myRoboTst.init();
    if(0 != status) Serial.println("Error initialising myRoboTst");
}

void loop()
{
    static bool bLoop = false;
    if(!bLoop) {
        Serial.println("RoboTst::loop()");
        myRoboTst.run();
        bLoop = true;
    }
}