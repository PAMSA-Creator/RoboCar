/*
    In this package we will only build the Test component and the components that we need to test
    We need to be careful to satisfy all required interfaces to avoid breaking the logic of our Architecture.
    For example:
        CMot requires a CMan interface.
        If we are not building CMan for our tests then CTest needs to implement the CMan interface to CMot
*/
#include "PkgRoboTest.h"

RoboTest::RoboTest(){
    p_itsCMan = new(CMan);
    p_itsCTst = new(CTst);
    p_itsCCom = new(CCom);
    p_itsCMot = new(CMot);
    p_itsCSen = new(CSen);
}

RoboTest::~RoboTest(){
    delete(p_itsCMan);
    delete(p_itsCTst);
    delete(p_itsCCom);
    delete(p_itsCMot);
    delete(p_itsCSen);
}

int RoboTest::init(){
    Serial.println("RoboTest::init()");

    if(NULL == p_itsCMan) return _ERRNO_NULL_POINTER_CMAN;
    if(NULL == p_itsCTst) return _ERRNO_NULL_POINTER_CTST;
    if(NULL == p_itsCCom) return _ERRNO_NULL_POINTER_CCOM;
    if(NULL == p_itsCMot) return _ERRNO_NULL_POINTER_CMOT;
    if(NULL == p_itsCSen) return _ERRNO_NULL_POINTER_CSEN;

// In the following block we need to set the interfaces correctly between CTst and other components
/*
    p_itsCCom->set_ItsIMan(p_itsCMan->get_ItsIMan());
    p_itsCCom->set_ItsITst(p_itsCMan->get_ItsITst());
    p_itsCMot->set_ItsIMan(p_itsCMan->get_ItsIMan());
    p_itsCSen->set_ItsIMan(p_itsCMan->get_ItsIMan());

    p_itsCMan->set_ItsICom(p_itsCCom->get_ItsICom());
    p_itsCMan->set_ItsIMot(p_itsCMot->get_ItsIMot());
    p_itsCMan->set_ItsISen(p_itsCSen->get_ItsISen());
*/
    // Initialise communication first for debug purpose
    p_itsCMan->init();
    p_itsCTst->init();
    p_itsCCom->init();
    p_itsCMot->init();
    p_itsCSen->init();

    return 0;
}

void RoboTest::run(){
    static bool bRun = false;
    if(!bRun){
        Serial.println("RoboTest::run()");
        bRun = true;
    }
}