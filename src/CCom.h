/* 
    TYPE:       COMPONENT
    NAME:       CCom
    INTERFACE:  ICom
    PORT:       p_itsICom

    CCom is the communication subsystem for RoboCar.
    It enables bi-directional communication between the Arduino and outside world.
    CCom's main method of communication is built around a standard serial interface.
    CCom uses the Arduino SoftwareSerial library.
    CCom supports Bluetooth communication via an HC05 or HM10 module.
 */

#ifndef _C_COM_H
#define _C_COM_H

#include <Arduino.h>

class CCom;
class ICom;
class Bluetooth;

#include "CMan.h"

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
};

/* Class ICom */
class ICom{

    public:
    virtual ICom* get_ItsICom();
    virtual void init();
    virtual void println(const char* arg);
};

/* Class Bluetooth */
class Bluetooth : public ICom{
    private:
    void init_Bluetooth();

    public:
    // Getter
    ICom* get_ItsICom();

    // Initialisation
    void init();

    // println
    void println(const char* arg);
};

#endif