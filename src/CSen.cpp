#include "CSen.h"

/* -------------------- CSen -------------------------- */
/*
Default constructor
Build all internal objects
*/
CSen::CSen(){
    p_itsASen = new ASen();
    IMan* p_itsIMan = NULL;
    p_itsCentralSystem = new CentralSystem();
    p_itsUltrasonic = new Ultrasonic();
}

CSen::~CSen(){
    if(NULL != p_itsASen) delete p_itsASen;
    IMan* p_itsIMan = NULL;
    if(NULL != p_itsCentralSystem) delete p_itsCentralSystem;
    if(NULL != p_itsUltrasonic) delete p_itsUltrasonic;
}

/* CSen */
ISen* CSen::get_ItsISen(){
    return (ISen*) p_itsASen;
}

void CSen::set_ItsIMan(IMan* arg){
    p_itsIMan = (NULL != arg) ? arg : NULL;
}

void CSen::init(){
    Serial.println("CSen::init()");
    if(NULL != p_itsUltrasonic){
        p_itsCentralSystem->set_ItsUltrasonic(p_itsUltrasonic);
        p_itsUltrasonic->init();
    }else return;   // Catch exception
    if(NULL != p_itsCentralSystem){
        p_itsUltrasonic->set_ItsCentralSystem(p_itsCentralSystem);
        p_itsCentralSystem->init();
    }else return;   // Cathc exception
    if(NULL != p_itsASen){
        p_itsASen->set_ItsUltrasonic(p_itsUltrasonic);
        p_itsASen->set_ItsCentralSystem(p_itsCentralSystem);
        p_itsASen->init();
    }
}

/* -------------------- ASen -------------------------- */
/*
Default constructor
TBD
*/
ASen::ASen(){
    // TBD
}

ASen::~ASen(){
    // TBD
}

void ASen::init_ASen(){
    // TBD
}

void ASen::init(){
    this->init_ASen();
}

void ASen::set_ItsCentralSystem(CentralSystem* arg){
    this->p_itsCentralSystem = (NULL != arg) ? arg : NULL;
}

void ASen::set_ItsUltrasonic(Ultrasonic* arg){
    this->p_itsUltrasonic = (NULL != arg) ? arg : NULL;
}

/* -------------------- CentralSystem -------------------------- */
/*
Default constructor
TBD
*/
CentralSystem::CentralSystem(){
    // TBD
}

CentralSystem::~CentralSystem(){
    // TBD
}

void CentralSystem::init_CentralSystem(){
    Serial.println("CentralSystem::init_CentralSystem");
}

void CentralSystem::init(){
    this->init_CentralSystem();
}

void CentralSystem::set_ItsUltrasonic(Ultrasonic* arg){
    this->p_itsUltrasonic = (NULL != arg) ? arg : NULL;
}


/* -------------------- Ultrasonic -------------------------- */
/*
Default constructor
TBD
*/
Ultrasonic::Ultrasonic(){
    // TBD
}

Ultrasonic::~Ultrasonic(){
    // TBD
}

void Ultrasonic::init_Ultrasonic(){
    Serial.println("Ultrasonic::init_Ultrasonic");
}

void Ultrasonic::init(){
    this->init_Ultrasonic();
}

void Ultrasonic::set_ItsCentralSystem(CentralSystem* arg){
    this->p_itsCentralSystem = (NULL != arg) ? arg : NULL;
}