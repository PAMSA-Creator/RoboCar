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

void setup(){
    Serial.begin(115200);
    while (!Serial);
    Serial.println("RoboCar::setup()");
	status = myRoboCar.init();
    if(0 != status) Serial.println("Error initialising myRoboCar");
}

void loop(){
    static bool bLoop = false;
    if(!bLoop) {
        Serial.println("RoboCar::loop()");
        bLoop = true;
    }
    myRoboCar.run();
}

// If _RELEASE_BUILD was commented out (not defined), check if _TEST_BUILD was defiend
// If _TEST_BUILD has been defined, let's build it.
#elif defined( _TEST_BUILD )

// In this build we will build the RoboTest Package instead. We must first include it.
#include "PkgRoboTest.h"

RoboTest myRoboTest;
byte status = 0;

void setup(){
    // First we setup and open the serial port
    Serial.begin(115200);
    // Check if Serial is ready
    while (!Serial);
    // When ready, print something to inform us where we are
    Serial.println("RoboTst::setup()");
    // Run the initialisation function
	status = myRoboTest.init();
    // Check for status message and if error is reporting, flag it up
    if(0 != status) Serial.println("Error initialising myRoboTst");
}

void loop(){
    // Create a static variable to hold the value of the bLoop variable
    static bool bLoop = false;

    // Test if it's the first time we enter the loop function
    if(!bLoop) {
        // If first time then print something
        Serial.println("RoboTst::loop()");
        // Set bLoop to 'true' to avoid printing again at the next round
        bLoop = true;
    }
    // Execute the run function
    myRoboTest.run();
}
#endif