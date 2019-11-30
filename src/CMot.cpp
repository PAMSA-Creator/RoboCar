#include "CMot.h"

/* CMot */

CMot::CMot(){
    p_itsIMot = (IMot*) new(Controller);
}

CMot::~CMot(){
    delete(p_itsIMot);
}

void CMot::set_ItsIMot(IMot* arg){
    p_itsIMot = (NULL != arg) ? arg : NULL;
}

IMot* CMot::get_ItsIMot(){
    return p_itsIMot;
}

IMan* CMot::CMot::get_ItsIMan(){
    return p_itsIMan;
}

void CMot::set_ItsIMan(IMan* arg){
    p_itsIMan = (NULL != arg) ? arg : NULL;
}

void CMot::init(){
    p_itsIMot->init();
}

/* Controller */
Controller::Controller(){
    p_itsDCMotor = new(DCMotor);
    p_itsStepper = new(Stepper);
}

Controller::~Controller(){
    delete(p_itsDCMotor);
    delete(p_itsStepper);
}

void Controller::init_Controller(){
    if(NULL != p_itsDCMotor) p_itsDCMotor->init();
    if(NULL != p_itsStepper) p_itsStepper->init();
}

IMot* Controller::get_ItsIMot(){
    return (IMot*) this;
}

void Controller::set_ItsCMot(CMot* arg){
    p_itsCMot = (NULL != arg) ? arg : NULL;
}

void Controller::init(){
    this->init_Controller();
}

/* DCMotor */
void DCMotor::init_Motor(){
    Serial.println("DC motor initialised");
}

DCMotor* DCMotor::get_ItsDCMotor(){
    return this;
}

void DCMotor::set_ItsController(Controller* arg){
    p_itsController = (NULL != arg) ? arg : NULL;
}

void DCMotor::init(){
    this->init_Motor();
}

/* Stepper */
void Stepper::init_Motor(){
    Serial.println("Stepper motor initialised");
}

Stepper* Stepper::get_ItsStepper(){
    return this;
}

void Stepper::set_ItsController(Controller* arg){
    p_itsController = (NULL != arg) ? arg : NULL;
}

void Stepper::init(){
    this->init_Motor();
}