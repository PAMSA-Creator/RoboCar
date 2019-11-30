#ifndef _PKG_ROBOCAR_H
#define _PKG_ROBOCAR_H

#include <Arduino.h>

class RoboCar;

#include "CMan.h"
#include "CCom.h"
#include "CMot.h"
#include "CSen.h"

#define _EXCEPTION_NULL_POINTER_CMAN    0xFFFE
#define _EXCEPTION_NULL_POINTER_CCOM    0xFFFD
#define _EXCEPTION_NULL_POINTER_CMOT    0xFFFC
#define _EXCEPTION_NULL_POINTER_CSEN    0xFFFB

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