#ifndef _C_MANAGER_H
#define _C_MANAGER_H

#include <Arduino.h>

class IManager{
    public:
    virtual IManager* get_ItsIManager();
    virtual void set_ItsIManager(IManager* arg);
};

class AManager: public IManager{
    private:
    IManager* p_itsIManager = NULL;

    IManager* get_ItsIManager();
    void set_ItsIManager(IManager* arg);
};

class CManager{
    private:
    IManager* p_itsIManager = NULL;

    public:
    CManager();
    ~CManager();

    IManager* get_ItsIManager();
    void set_ItsIManager(IManager* arg);
};

#endif