#ifndef _PKG_ROBOTEST_H
#define _PKG_ROBOTEST_H

#include <Arduino.h>

class RoboTest;

#include "ErrorCodes.h"
#include "CMan.h"
#include "CCom.h"
#include "CMot.h"
#include "CSen.h"
#include "CTst.h"

class RoboTest{
    private:
    CMan* p_itsCMan = NULL;
    CCom* p_itsCCom = NULL;
    CMot* p_itsCMot = NULL;
    CSen* p_itsCSen = NULL;
    CTst* p_itsCTst = NULL;

    public:
    // Default constructor
    RoboTest();

    // Default destructor
    ~RoboTest();

    // Initialisation function
    int init();

    // Run function
    void run();
};

#endif