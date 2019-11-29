#ifndef _PKG_ROBOCAR_H
#define _PKG_ROBOCAR_H

#include <Arduino.h>

#include "CMan.h"
#include "CCom.h"

class RoboCar{
    private:
    CMan* p_itsCMan = NULL;
    CCom* p_itsCCom = NULL;

    public:
    // Default constructor
    RoboCar();

    // Default destructor
    ~RoboCar();

    // Initialisation function
    void init();

    // Run function
    void run();
};

#endif