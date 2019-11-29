#include "PkgRoboCar.h"

RoboCar::RoboCar(){
    p_itsCMan = new(CMan);
    p_itsCCom = new(CCom);
}

RoboCar::~RoboCar(){
    delete(p_itsCMan);
    delete(p_itsCCom);
}

void RoboCar::init(){
    if(NULL != p_itsCCom){
        p_itsCCom->init();
        if(NULL != p_itsCMan) p_itsCCom->set_ItsIMan(p_itsCMan->get_ItsIMan());
    }

    if(NULL != p_itsCMan){
        if(NULL != p_itsCCom) p_itsCMan->set_ItsICom(p_itsCCom->get_ItsICom());
        p_itsCMan->init();
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