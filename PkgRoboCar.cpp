#include "PkgRoboCar.h"

RoboCar::RoboCar(){
    p_itsCManager = new(CManager);
    p_itsCCom = new(CCom);
}

RoboCar::~RoboCar(){
    delete(p_itsCManager);
    delete(p_itsCCom);
}

void RoboCar::init(){
    if(NULL != p_itsCCom){
        p_itsCCom->init();
        if(NULL != p_itsCManager) p_itsCCom->set_ItsIManager(p_itsCManager->get_ItsIManager());
    }

    if(NULL != p_itsCManager){
        if(NULL != p_itsCCom) p_itsCManager->set_ItsICom(p_itsCCom->get_ItsICom());
        p_itsCManager->init();
    }

    if(NULL != p_itsCCom) p_itsCCom->println("RoboCar initialisation complete");
}

void RoboCar::run(){
    static bool bRun = false;
    if(!bRun){
        if(NULL != p_itsCCom) p_itsCCom->println("RoboCar is now running");
        bRun = true;
    }
}