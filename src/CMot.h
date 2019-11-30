/* 
    TYPE:       COMPONENT
    NAME:       CMot
    INTERFACE:  IMot
    PORT:       p_itsIMot

    CMot is the motion controller subsystem for RoboCar.
    It controls all actuators such as motors and arms.
 */

#ifndef _C_MOT_H
#define _C_MOT_H

#include <Arduino.h>

class CMot;
class IMot;
class Controller;
class DCMotor;
class Stepper;

#include "CMan.h"

class CMot{
    private:
    IMot* p_itsIMot = NULL;             // CMot port
    IMan* p_itsIMan = NULL;             // CMan port

    // Interface (ICom) setter
    void set_ItsIMot(IMot* arg);

    public:
    // Default constructor
    CMot();
    // Default destructor
    ~CMot();

    // Interface (ICom) getter
    IMot* get_ItsIMot();

    // IMan getter and setter
    IMan* get_ItsIMan();
    void set_ItsIMan(IMan* arg);

    // Initialisation
    void init();
};

class IMot{
    protected:
    CMot* p_itsCMot = NULL;

    public:
    virtual IMot* get_ItsIMot();
    virtual void set_ItsCMot(CMot* arg);
    virtual void init();
};

class Controller : public IMot{
    private:
    DCMotor* p_itsDCMotor = NULL;
    Stepper* p_itsStepper = NULL;

    // internal initialisation function
    void init_Controller();

    public:
    // Default constructor and destructor
    Controller();
    ~Controller();

    // Getter function
    IMot* get_ItsIMot();

    // CMot setter function
    void set_ItsCMot(CMot* arg);

    // Initialisation function
    void init();
};

class DCMotor{
    private:
    Controller* p_itsController = NULL;    
    void init_Motor();

    public:
    // Getter function
    DCMotor* get_ItsDCMotor();

    // Controller setter function
    void set_ItsController(Controller* arg);

    // Initialisation function
    void init();
};

class Stepper{
    private:
    Controller* p_itsController = NULL;    
    void init_Motor();

    public:
    // Getter function
    Stepper* get_ItsStepper();

    // Controller setter function
    void set_ItsController(Controller* arg);

    // Initialisation function
    void init();
};

#endif