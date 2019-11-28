#include "CManager.h"

/*
    Class AManager (Adapter)
 */
IManager* AManager::get_ItsIManager(){
    return (IManager*) this;
}

void AManager::set_ItsCManager(CManager* arg){
    p_itsCManager = (NULL != arg) ? arg : NULL;
}

/*
    Class CManager (Component)
 */
CManager::CManager(){
    p_itsIManager = (IManager*) new AManager();
}

CManager::~CManager(){
    if(NULL != p_itsIManager)
        delete(p_itsIManager);
}

IManager* CManager::get_ItsIManager(){
    return (IManager*) p_itsIManager;    
}

void CManager::set_ItsICom(ICom* arg){
    p_itsICom = (NULL != arg) ? arg : NULL;
}

void CManager::init(){
    //p_itsIManager = (IManager*) new AManager();
    if(NULL != p_itsIManager) p_itsIManager->set_ItsCManager(this);
}