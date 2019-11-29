#include "CMan.h"

/*
    Class Brain (Adapter)
 */
IMan* Brain::get_ItsIMan(){
    return (IMan*) this;
}

void Brain::set_ItsCMan(CMan* arg){
    p_itsCMan = (NULL != arg) ? arg : NULL;
}

/*
    Class CMan (Component)
 */
CMan::CMan(){
    p_itsIMan = (IMan*) new Brain();
}

CMan::~CMan(){
    if(NULL != p_itsIMan)
        delete(p_itsIMan);
}

IMan* CMan::get_ItsIMan(){
    return (IMan*) p_itsIMan;    
}

void CMan::set_ItsICom(ICom* arg){
    p_itsICom = (NULL != arg) ? arg : NULL;
}

void CMan::init(){
    //p_itsIMan = (IMan*) new Brain();
    if(NULL != p_itsIMan) p_itsIMan->set_ItsCMan(this);
}