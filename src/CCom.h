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
class ACom;
class Bluetooth;

#include "CMan.h"

/* Class CCom (Component) */
class CCom{
    private:
    ACom* p_itsACom = NULL;             // CCom adapter (ACom)
    IMan* p_itsIMan = NULL;             // CMan port
    Bluetooth* p_itsBluetooth = NULL;   // Bluetooth object

    public:
    // Default constructor & destructor
    CCom();
    ~CCom();

    // Getters & setters
    ICom* get_ItsICom();
    void set_ItsIMan(IMan* arg);

    // Initialisation
    void init();

    // Behaviour
};

/* Class ICom */
class ICom{

    public:
    virtual ICom* get_ItsICom();
    virtual void init();
    virtual void println(const char* arg);
};

/* Adapter calss */
class ACom : public ICom{
    private:
    /* Pointer to Bluetooth device */
    Bluetooth* p_itsBluetooth = NULL;

    // Initialisation
    void init_ACom();

    public:
    // Default constructor & destructor
    ACom();
    ~ACom();

    // Setters & getters
    ICom* get_ItsICom();
    void set_ItsBluetooth(Bluetooth* arg);

    // Initialisation
    void init();

    // Behaviour
    void println(const char* arg);
};

/* Class Bluetooth */
class Bluetooth{
    private:
    void init_Bluetooth();

    public:
    // Default constructor & destructor
    Bluetooth();
    ~Bluetooth();

    // Initialisation
    void init();

    // Behaviour
    void println(const char* arg);
};

#endif