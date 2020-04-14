/* 
    TYPE:       COMPONENT
    NAME:       CTst
    INTERFACE:  ITst
    ADAPTER:    ATst
    PORT:       p_itsITst

    CTst is the test subsystem for RoboCar.
*/
#ifndef _C_TEST_H
#define _C_TEST_H

#include <Arduino.h>

class CTst;
class ITst;
class ATst;
class Tester;

#include "CMan.h"
#include "CCom.h"
#include "CMot.h"
#include "CSen.h"

/* Class CTst (Component) */
class CTst{
    private:
    ATst* p_itsATst = NULL;     // CTst Adapter (ATst)
    ICom* p_itsICom = NULL;     // CCom port
    IMot* p_itsIMot = NULL;     // CMot port
    ISen* p_itsISen = NULL;     // CSen port
    Tester* p_itsTester = NULL;   // Tester object

    public:
    // Default constructor & destructor
    CTst();
    ~CTst();

    // Getter & Setters
    ITst* get_ItsITst();
    void set_ItsIMan(IMan* arg);
    void set_ItsICom(ICom* arg);
    void set_ItsIMot(IMot* arg);
    void set_ItsISen(ISen* arg);

    // Initialisation
    void init();

    // Behaviour
};

/* Interface class */
class ITst{
    public:
    virtual void init();
};

/* Adapter class */
class ATst:public ITst{
    private:
    /* Pointer to Tester object */
    Tester* p_itsTester = NULL;

    /* Initialisation */
    void init_ATst();

    public:
    // Default constructor & destructor
    ATst();
    ~ATst();

    // Getters & Setters
    void set_ItsTester(Tester* arg);

    // Initialisation
    void init();

    // Behaviour
};

/* Tester class */
class Tester{
    private:
    void init_Tester();

    public:
    // default constructor and destructor
    Tester();
    ~Tester();

    // Getters and Setters

    // Initialisation
    void init();

    // Behaviour
};

#endif