#ifndef _PKG_ROBOCAR_H
#define _PKG_ROBOCAR_H

#include <Arduino.h>

class RoboCar;

#include "ErrorCodes.h"
#include "CMan.h"
#include "CCom.h"
#include "CMot.h"
#include "CSen.h"

class RoboCar{
    private:
    CMan* p_itsCMan = NULL;
    CCom* p_itsCCom = NULL;
    CMot* p_itsCMot = NULL;
    CSen* p_itsCSen = NULL;

    public:
    // Default constructor
    RoboCar();

    // Default destructor
    ~RoboCar();

    // Initialisation function
    int init();

    // Run function
    void run();
};

#endif