/* 
    TYPE:       COMPONENT
    NAME:       CSen
    INTERFACE:  ISen
    PORT:       p_itsISen

    CSen is the sensory subsystem for RoboCar.
    It collects data from all sensors and performs pre-processing activities before distribution.
 */

#ifndef _C_SEN_H
#define _C_SEN_H

#include <Arduino.h>

class CSen;
class ISen;
class Ultrasonic;

#include "CMan.h"

class CSen{
    private:
    ISen* p_itsISen = NULL;             // CSen port
    IMan* p_itsIMan = NULL;             // CMan port

    // Interface (ICom) setter
    void set_ItsISen(ISen* arg);

    public:
    // Default constructor
    CSen();
    // Default destructor
    ~CSen();

    // Interface (ICom) getter
    ISen* get_ItsISen();

    // IMan getter and setter
    IMan* get_ItsIMan();
    void set_ItsIMan(IMan* arg);

    // Initialisation
    void init();
};

class ISen{
    protected:
    CSen* p_itsCSen = NULL;

    public:
    virtual ISen* get_ItsISen();
    virtual void set_ItsCSen(CSen* arg);
    virtual void init();
};

class CentralSystem : public ISen{
    private:
    Ultrasonic* p_itsUltrasonic = NULL;

    // internal initialisation function
    void init_CentralSystem();

    public:
    // Default constructor and destructor
    CentralSystem();
    ~CentralSystem();

    // Getter function
    ISen* get_ItsISen();

    // CMot setter function
    void set_ItsCSen(CSen* arg);

    // Initialisation function
    void init();
};

class Ultrasonic{
    private:
    CentralSystem* p_itsCentralSystem = NULL;    
    void init_Ultrasonic();

    public:
    // Getter function
    Ultrasonic* get_ItsUltrasonic();

    // Controller setter function
    void set_ItsCentralSystem(CentralSystem* arg);

    // Initialisation function
    void init();
};

#endif