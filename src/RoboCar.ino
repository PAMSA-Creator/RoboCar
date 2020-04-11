/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!! First define what code to build !!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

//#define _RELEASE_BUILD
#if !defined( _RELEASE_BUILD )
    #define _TEST_BUILD
#endif

/* Build starts here */
#if  defined(_RELEASE_BUILD)
/* Only build this code if _RELEASE_BUILD is defined */
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

#elif   defined(_TEST_BUILD)
/* Only build this code if _TST_BUILD is defined */
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
#endif