/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!! First define what code to build !!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

// Define _RELEASE_BUILD to build the release version
//#define _RELEASE_BUILD

// If _RELEASE_BUILD is commented out then let's build the _TEST_BUILD isntead
#if !defined( _RELEASE_BUILD )
    #define _TEST_BUILD
#endif

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!! Builds start here               !!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
// Check is _RELEASE_BUILD was defined
// If _RELEASE_BUILD has been defined, let's build it.
#if defined( _RELEASE_BUILD )

// First include the RoboCar Package so we can build it
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

// If _RELEASE_BUILD was commented out (not defined), check if _TEST_BUILD was defiend
// If _TEST_BUILD has been defined, let's build it.
#elif defined( _TEST_BUILD )

// In this build we will build the RoboTest Package instead. We must first include it.
#include "PkgRoboTest.h"

RoboTest myRoboTest;
byte status = 0;

void setup()
{
    Serial.begin(115200);
    while (!Serial);
    Serial.println("RoboTst::setup()");
	status = myRoboTest.init();
    if(0 != status) Serial.println("Error initialising myRoboTst");
}

void loop()
{
    static bool bLoop = false;
    if(!bLoop) {
        Serial.println("RoboTst::loop()");
        bLoop = true;
    }
    myRoboTest.run();
    
}

#endif