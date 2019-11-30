#include "PkgRoboCar.h"

RoboCar::RoboCar(){
    p_itsCMan = new(CMan);
    p_itsCCom = new(CCom);
    p_itsCMot = new(CMot);
    p_itsCSen = new(CSen);
}

RoboCar::~RoboCar(){
    delete(p_itsCMan);
    delete(p_itsCCom);
    delete(p_itsCMot);
    delete(p_itsCSen);
}

int RoboCar::init(){
    if(NULL == p_itsCCom) return _ERRNO_NULL_POINTER_CCOM;
    if(NULL == p_itsCMot) return _ERRNO_NULL_POINTER_CMOT;
    if(NULL == p_itsCSen) return _ERRNO_NULL_POINTER_CSEN;
    if(NULL == p_itsCMan) return _ERRNO_NULL_POINTER_CMAN;

    p_itsCCom->set_ItsIMan(p_itsCMan->get_ItsIMan());
    p_itsCMot->set_ItsIMan(p_itsCMan->get_ItsIMan());
    p_itsCSen->set_ItsIMan(p_itsCMan->get_ItsIMan());

    p_itsCMan->set_ItsICom(p_itsCCom->get_ItsICom());
    p_itsCMan->set_ItsIMot(p_itsCMot->get_ItsIMot());
    p_itsCMan->set_ItsISen(p_itsCSen->get_ItsISen());

    // Initialise communication first for debug purpose
    p_itsCCom->init();
    p_itsCMan->init();
    p_itsCMot->init();
    p_itsCSen->init();

    Serial.println("RoboCar initialisation complete");

    return 0;
}

void RoboCar::run(){
    static bool bRun = false;
    if(!bRun){
        Serial.println("RoboCar is now running");
        bRun = true;
    }
}