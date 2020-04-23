/* 
    TYPE:       COMPONENT
    NAME:       CTst
    INTERFACE:  ITst
    ADAPTER:    ATst
    PORT:       p_itsITst

    CTst is the test subsystem for RoboCar.
    It implements the necessary interfaces to emulate all necessary components.
*/
#ifndef _C_TEST_H
#define _C_TEST_H

// Include the main Arduino.h header file
#include <Arduino.h>

// Declare the classes before calling the other components header files to allow for class names to be known
class CTst;
class ITst;
class ATst;
class ATstMan;
class ATstCom;
class ATstMot;
class ATstSen;
class Tester;

// Include all other components header files
#include "CMan.h"
#include "CCom.h"
#include "CMot.h"
#include "CSen.h"

/*
    Define the Class CTst (Component).
    The aim of this component is to instanciate all necessary objects for CTest to work.
    If a component is build as part of the _TEST_BUILD by the PkgRoboTest then its pointer will be used.
    Inversely if the component is not built, then CTest will emulate it and must therefore provide the interface.
    For this reason, the CTst component implements all emulated interfaces by default (ITstMan, ITstCom, ITstMot, 
    ITstSen).
*/
class CTst{
    private:
    ATst* p_itsATst = NULL;     // CTst Adapter (ATst)
    ATstMan* p_itsATstMan = NULL;   // Adapter to an emulated CMan component if required
    ATstCom* p_itsATstCom = NULL;   // Adapter to an emulated CCom component if required
    ATstMot* p_itsATstMot = NULL;   // Adapter to an emulated CMot component if required
    ATstSen* p_itsATstSen = NULL;   // Adapter to an emulated CSen component if required
    IMan* p_itsIMan = NULL;     // CMan port if required
    ICom* p_itsICom = NULL;     // CCom port if required
    IMot* p_itsIMot = NULL;     // CMot port if required
    ISen* p_itsISen = NULL;     // CSen port if required
    Tester* p_itsTester = NULL;   // Tester object

    public:
    // Default constructor & destructor
    CTst();
    ~CTst();

    // Getter & Setters
    void set_ItsIMan(IMan* arg);
    void set_ItsICom(ICom* arg);
    void set_ItsIMot(IMot* arg);
    void set_ItsISen(ISen* arg);
    ITst* get_ItsITst(); //The function return type is a pointer (i.e. ITst*) to the interface of CTst component.
    IMan* get_ItsIMan();
    ICom* get_ItsICom();
    IMot* get_ItsIMot();
    ISen* get_ItsISen();

    // Initialisation
    void init();

    // Behaviour
};

/* Interface class */
class ITst{
    public:
    virtual void init();
    virtual void runATest();
};

/* Adapter class */
class ATst:public ITst{
    private:
    /* Pointer to Tester object */
    Tester* p_itsTester = NULL;

    /* Initialisation */
    void init_ATst(); //private initialisation

    public:
    // Default constructor & destructor
    ATst();
    ~ATst();

    // Getters & Setters
    void set_ItsTester(Tester* arg);

    // Initialisation
    void init();  //public initialisation (the interface initialisation ITst)

    // Behaviour
    void runATest();
};

class ATstMan:public IMan{ //the ":" operator is for inheritance (i.e ATstMan inherites publicly from IMan)
    private:
    /* Pointer to Tester object */
    Tester* p_itsTester = NULL;

    /* Initialisation */
    void init_ATstMan();

    public:
    // Default constructor & destructor
    ATstMan();
    ~ATstMan();

    // Getters & Setters
    void set_ItsTester(Tester* arg);

    // Initialisation
    // Implementation of the pure virtual function init() declared in IMan
    void init();

    // Behaviour
};

class ATstCom:public ICom{
    private:
    /* Pointer to Tester object */
    Tester* p_itsTester = NULL;

    /* Initialisation */
    void init_ATstCom();

    public:
    // Default constructor & destructor
    ATstCom();
    ~ATstCom();

    // Getters & Setters
    void set_ItsTester(Tester* arg);

    // Initialisation
    void init();

    // Behaviour
};

class ATstMot:public IMot{
    private:
    /* Pointer to Tester object */
    Tester* p_itsTester = NULL;

    /* Initialisation */
    void init_ATstMot();

    public:
    // Default constructor & destructor
    ATstMot();
    ~ATstMot();

    // Getters & Setters
    void set_ItsTester(Tester* arg);

    // Initialisation
    void init();

    // Behaviour
};

class ATstSen:public ISen{
    private:
    /* Pointer to Tester object */
    Tester* p_itsTester = NULL;

    /* Initialisation */
    void init_ATstSen();

    public:
    // Default constructor & destructor
    ATstSen();
    ~ATstSen();

    // Getters & Setters
    void set_ItsTester(Tester* arg);

    // Initialisation
    void init();

    // Behaviour
};

/*
    Tester class
    The Tester class implements the logic behind each emulated coponent.
*/
class Tester{
    private:
    // Pointer to CTest
    CTst* p_itsCTst = NULL;

    // Initialisation
    void init_Tester();

    public:
    // default constructor and destructor
    Tester();
    ~Tester();

    // Getters and Setters
    void set_ItsCTst(CTst* arg);

    // Initialisation
    void init();

    // Behaviour
    void runTest(void);
};

#endif