/* 
    TYPE:       COMPONENT
    NAME:       CCom
    INTERFACE:  ICom
    PORT:       p_itsICom

    CCom is the communication subsystem for RoboCar.
    It enables bi-directional communication between the Arduino and outside world.
    CCom's main method of communication is built around a standard serial interface.
    CCom uses the Arduino SoftwareSerial library.
    CCom supports Bluetooth communication via an HC05 module.
 */

#ifndef _C_COM_H
#define _C_COM_H

#include <Arduino.h>

class CCom;
class ICom;
class HC05;

#include "CMan.h"

/* Class ICom (Interface) */
class ICom{
    protected:
    CCom* p_itsCCom = NULL;

    public:
    virtual ICom* get_ItsICom();
    virtual void set_ItsCCom(CCom* arg);
    virtual void init();
};

/* Class HC05 (Adapter) */
class HC05 : public ICom{
    private:
    void init_HC05();

    public:
    // Getter function
    ICom* get_ItsICom();

    // CCom setter function
    void set_ItsCCom(CCom* arg);

    // Initialisation function
    void init();
};

/* Class CCom (Component) */
class CCom{
    private:
    ICom* p_itsICom = NULL;             // CCom port
    IMan* p_itsIMan = NULL;             // CMan port

    // Interface (ICom) setter
    void set_ItsICom(ICom* arg);

    public:
    // Default constructor
    CCom();
    // Default destructor
    ~CCom();

    // Interface (ICom) getter
    ICom* get_ItsICom();

    // IMan getter and setter
    IMan* get_ItsIMan();
    void set_ItsIMan(IMan* arg);

    // Initialisation
    void init();

    // Println
    void println(const char* arg);
};

#endif