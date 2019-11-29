/* 
    TYPE:       COMPONENT
    NAME:       CMan
    INTERFACE:  IMan
    PORT:       p_itsIMan

    CMan is the central control subsystem for RoboCar.
    It processes, arbitrates and distributes information and messages between the various components of the system.
    CMan uses a subscribtion scheme to distribute messages.
    A series of interrupts allows direct communication from other components for high priority events.
*/

#ifndef _C_MANAGER_H
#define _C_MANAGER_H

#include <Arduino.h>

class CMan;
class IMan;
class Brain;

#include "CCom.h"

class IMan{
    protected:
    CMan* p_itsCMan = NULL;

    public:
    // Getter function
    virtual IMan* get_ItsIMan();

    // CMan setter function
    virtual void set_ItsCMan(CMan* arg);
};

class Brain: public IMan{
    public:
    // Getter function
    IMan* get_ItsIMan();

    // CMan Setter function
    void set_ItsCMan(CMan* arg);
};

class CMan{
    private:
    IMan* p_itsIMan = NULL;
    ICom* p_itsICom = NULL;

    public:
    // Default constructor
    CMan();
    // Default destructor
    ~CMan();

    // Getter function
    IMan* get_ItsIMan();

    // CCom setter function
    void set_ItsICom(ICom* arg);

    // Initialisation function
    void init();
};

#endif