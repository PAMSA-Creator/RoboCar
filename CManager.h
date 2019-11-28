#ifndef _C_MANAGER_H
#define _C_MANAGER_H

#include <Arduino.h>

class IManager;
class AManager;
class CManager;

#include "CCom.h"

class IManager{
    protected:
    CManager* p_itsCManager = NULL;

    public:
    // Getter function
    virtual IManager* get_ItsIManager();

    // CManager setter function
    virtual void set_ItsCManager(CManager* arg);
};

class AManager: public IManager{
    public:
    // Getter function
    IManager* get_ItsIManager();

    // CManager Setter function
    void set_ItsCManager(CManager* arg);
};

class CManager{
    private:
    IManager* p_itsIManager = NULL;
    ICom* p_itsICom = NULL;

    public:
    // Default constructor
    CManager();
    // Default destructor
    ~CManager();

    // Getter function
    IManager* get_ItsIManager();

    // CCom setter function
    void set_ItsICom(ICom* arg);

    // Initialisation function
    void init();
};

#endif