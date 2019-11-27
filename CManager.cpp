#include "CManager.h"

CManager::CManager(){
    p_itsIManager = (IManager*) new(AManager);
}

CManager::~CManager(){
    delete(p_itsIManager);
}

IManager* CManager::get_ItsIManager(){
    return p_itsIManager;    
}
void CManager::set_ItsIManager(IManager* arg){
    p_itsIManager = (NULL != arg) ? arg : NULL;
}