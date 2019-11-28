#include "PkgRoboCar.h"

RoboCar myRoboCar;

void setup()
{
	myRoboCar.init();
}

void loop()
{
    myRoboCar.run();
}
