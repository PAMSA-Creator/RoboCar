/* 
    TYPE:       COMPONENT
    NAME:       CMot
    INTERFACE:  IMot
    ADAPTER:    AMot
    PORT:       p_itsIMot

    CMot is the motion controller subsystem for RoboCar.
    It controls all actuators such as motors and arms.
    The main actuators consists of a series of DC motors for and servo motors
 */

#ifndef _C_MOT_H
#define _C_MOT_H

#include <Arduino.h>

class CMot;
class IMot;
class AMot;
class Controller;
class DCMotor;
class Servo;

#include "CMan.h"

class CMot{
    private:
    AMot* p_itsAMot = NULL;             // CMot Adapter (AMot)
    IMan* p_itsIMan = NULL;             // CMan port
    Controller* p_itsController = NULL; // Controller  object
    DCMotor* p_itsDCMotorRight = NULL;       // DCMotor object
    DCMotor* p_itsDCMotorLeft = NULL;       // DCMotor object
    Servo* p_itsServo = NULL;           // Servo object

    public:
    // Default Constructor & Destructor
    CMot();
    ~CMot();

    // Getters & Setters
    IMot* get_ItsIMot();
    void set_ItsIMan(IMan* arg);

    // Initialisation
    void init();
};

class IMot{

    public:
    virtual void init();
};

class AMot : public IMot{
    private:
    Controller* p_itsController = NULL;

    // Initialisation
    void init_AMot();

    public:
    // Default Constructor & Destructor
    AMot();
    ~AMot();

    // Getters & Setters
    void set_ItsController(Controller* arg);

    // Initialisation
    void init();
};

class Controller{
    private:
    DCMotor* p_itsDCMotorRight = NULL;
    DCMotor* p_itsDCMotorLeft = NULL;
    Servo* p_itsServo = NULL;

    // Initialisation
    void init_Controller();

    public:
    // Default Constructor & Destructor
    Controller();
    ~Controller();

    // Getters & Setters
    void set_ItsDCMotorRight(DCMotor* arg);
    void set_ItsDCMotorLeft(DCMotor* arg);
    void set_ItsServo(Servo* arg);

    // Initialisation
    void init();
    void move_forward(int argSpeed);
    void spin_right(int argSpeed);
    void turn_right(int argSpeed);
};

class DCMotor{
    private:
    Controller* p_itsController = NULL; 
    int EN;
    int In1;
    int In2 ; 

    // Initialisation
    void init_DCMotor();

    public:
    // Getters & Setters
    void set_ItsController(Controller* arg);

    // Initialisation
    void init(int a,int b, int c);
    void run(int argSpeed, bool argDirection);
};

class Servo{
    private:
    Controller* p_itsController = NULL;  

    // Initialisation  
    void init_Servo();

    public:
    // Getters & Setters
    void set_ItsController(Controller* arg);

    // Initialisation function
    void init();
};

#endif