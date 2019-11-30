#include "CSen.h"

CSen::CSen(){
    p_itsISen = (ISen*) new (CentralSystem);             // CSen port
}

CSen::~CSen(){
    delete(p_itsISen);
}

/* CSen */
void CSen::set_ItsISen(ISen* arg){
    p_itsISen = (NULL != arg) ? arg : NULL;
}

ISen* CSen::get_ItsISen(){
    return p_itsISen;
}

IMan* CSen::get_ItsIMan(){
    return p_itsIMan;
}

void CSen::set_ItsIMan(IMan* arg){
    p_itsIMan = (NULL != arg) ? arg : NULL;
}

void CSen::init(){
    p_itsISen->init();
}

/* CentralSystem */
CentralSystem::CentralSystem(){
    p_itsUltrasonic = new(Ultrasonic);
}

CentralSystem::~CentralSystem(){
    delete(p_itsUltrasonic);
}

void CentralSystem::init_CentralSystem(){
    p_itsUltrasonic->init();
}

ISen* CentralSystem::get_ItsISen(){
    return (ISen*) this;
}

// CMot setter function
void CentralSystem::set_ItsCSen(CSen* arg){
    p_itsCSen = (NULL != arg) ? arg : NULL;
}

// Initialisation function
void CentralSystem::init(){
    this->init_CentralSystem();
}

/* Ultrasonic */
void Ultrasonic::init_Ultrasonic(){
    Serial.println("Ultrasonic sensor initialised");
}

Ultrasonic* Ultrasonic::get_ItsUltrasonic(){
    return this;
}

void Ultrasonic::set_ItsCentralSystem(CentralSystem* arg){
    p_itsCentralSystem = (NULL != arg) ? arg : NULL;
}

void Ultrasonic::init(){
    this->init_Ultrasonic();
}