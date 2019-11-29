#ifndef _C_COM_H
#define _C_COM_H

#include <Arduino.h>

class ICom;
class HC05;
class CCom;

#include "CManager.h"

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
    ICom* p_itsICom = NULL;             // ICom port
    IManager* p_itsIManager = NULL;     // IManager port

    // Interface (ICom) setter
    void set_ItsICom(ICom* arg);

    public:
    // Default constructor
    CCom();
    // Default destructor
    ~CCom();

    // Interface (ICom) getter
    ICom* get_ItsICom();

    // IManager getter and setter
    IManager* get_ItsIManager();
    void set_ItsIManager(IManager* arg);

    // Initialisation
    void init();

    // Println
    void println(const char* arg);
};

#endif