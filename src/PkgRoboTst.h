#ifndef _PKG_ROBOTST_H
#define _PKG_ROBOTST_H

#include <Arduino.h>

class RoboTst;

#include "ErrorCodes.h"
#include "CMan.h"
#include "CCom.h"
#include "CMot.h"
#include "CSen.h"

class RoboTst{
    private:
    CMan* p_itsCMan = NULL;
    CCom* p_itsCCom = NULL;
    CMot* p_itsCMot = NULL;
    CSen* p_itsCSen = NULL;

    public:
    // Default constructor
    RoboTst();

    // Default destructor
    ~RoboTst();

    // Initialisation function
    int init();

    // Run function
    void run();
};

#endif