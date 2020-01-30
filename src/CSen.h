/* 
    TYPE:       COMPONENT
    NAME:       CSen
    INTERFACE:  ISen
    ADAPTER:    ASen
    PORT:       p_itsISen

    CSen is the sensory subsystem for RoboCar.
    It collects data from all sensors and performs pre-processing activities before distribution.
 */

#ifndef _C_SEN_H
#define _C_SEN_H

#include <Arduino.h>

class CSen;
class ISen;
class ASen;
class CentralSystem;
class Ultrasonic;

#include "CMan.h"

class CSen{
    private:
    ASen* p_itsASen = NULL;                     // CSen Adapter (ASen)
    IMan* p_itsIMan = NULL;                     // CMan port
    CentralSystem* p_itsCentralSystem = NULL;   // CentralSystem object
    Ultrasonic* p_itsUltrasonic = NULL;         // Ultrasonic object

    void init_ASen();

    public:
    // Default constructor & destructor
    CSen();
    ~CSen();

    // Getters & Setters
    ISen* get_ItsISen();
    void set_ItsIMan(IMan* arg);

    // Initialisation
    void init();
};

class ISen{

    public:
    virtual void init();
};

class ASen : public ISen{
    private:
    CentralSystem* p_itsCentralSystem = NULL;
    Ultrasonic* p_itsUltrasonic = NULL;

    // Initialisation
    void init_ASen();

    public:
    // Default Constructor and Destructor
    ASen();
    ~ASen();

    // Getters & Setters
    void set_ItsCentralSystem(CentralSystem* arg);
    void set_ItsUltrasonic(Ultrasonic* arg);

    // Initialisation
    void init();
};

class CentralSystem{
    private:
    Ultrasonic* p_itsUltrasonic = NULL;

    // Initialisation
    void init_CentralSystem();

    public:
    // Default Constructor and Destructor
    CentralSystem();
    ~CentralSystem();

    // Getters & Setters
    void set_ItsUltrasonic(Ultrasonic* arg);

    // Initialisation
    void init();
};

class Ultrasonic{
    private:
    CentralSystem* p_itsCentralSystem = NULL;

    // Initialisation
    void init_Ultrasonic();

    public:
    // Default Constructor and Destructor
    Ultrasonic();
    ~Ultrasonic();

    // Getters & Setters
    void set_ItsCentralSystem(CentralSystem* arg);

    // Initialisation
    void init();
};

#endif