#ifndef _C_COM_H
#define _C_COM_H

#include <Arduino.h>
#include "CManager.h"

class ICom{
    public:
    virtual ICom * get_ItsICom();
    virtual void set_ItsICom(ICom* arg);
};

class HC05 : public ICom{
    private:
    ICom *p_itsICom = NULL;

    public:
    ICom * get_ItsICom();
    void set_ItsICom(ICom* arg);
};

class CCom{
    private:
    ICom * p_itsICom = NULL;
    IManager* p_itsIManager = NULL;

    public:
    CCom();
    ~CCom();

    ICom * get_ItsICom();
    void set_ItsICom(ICom* arg);
};

#endif