/* 
    TYPE:       COMPONENT
    NAME:       CMan
    INTERFACE:  IMan
    ADAPTER:    AMan
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
class AMan;
class Brain;

#include "CCom.h"
#include "CMot.h"
#include "CSen.h"

/* Class CMan (Component) */
class CMan{
    private:
    AMan* p_itsAMan = NULL;     // CMan Adapter (AMan)
    ICom* p_itsICom = NULL;     // CCom port
    IMot* p_itsIMot = NULL;     // CMot port
    ISen* p_itsISen = NULL;     // CSen port
    Brain* p_itsBrain = NULL;   // Brain object

    public:
    // Default constructor & destructor
    CMan();
    ~CMan();

    // Getter & Setters
    IMan* get_ItsIMan();
    void set_ItsICom(ICom* arg);
    void set_ItsIMot(IMot* arg);
    void set_ItsISen(ISen* arg);

    // Initialisation
    void init();

    // Behaviour
};

/* Interface class */
class IMan{
    public:
    virtual void init();
};

/* Adapter class */
class AMan:public IMan{
    private:
    /* Pointer to Brain object */
    Brain* p_itsBrain = NULL;

    /* Initialisation */
    void init_AMan();

    public:
    // Default constructor & destructor
    AMan();
    ~AMan();

    // Getters & Setters
    void set_ItsBrain(Brain* arg);

    // Initialisation
    void init();

    // Behaviour
};

/* Brain class */
class Brain{
    private:
    void init_Brain();

    public:
    // default constructor and destructor
    Brain();
    ~Brain();

    // Getters and Setters

    // Initialisation
    void init();

    // Behaviour
};

#endif