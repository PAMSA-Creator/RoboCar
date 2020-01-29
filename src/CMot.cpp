#include "CMot.h"

/* CMot */

CMot::CMot(){
    p_itsAMot = new AMot();
    p_itsIMan = NULL;
    p_itsController = new Controller();
    p_itsDCMotor = new DCMotor();
    p_itsServo = new Servo();
}

CMot::~CMot(){
    if(NULL != p_itsAMot) delete(p_itsAMot);
    p_itsIMan = NULL;
    if(NULL != p_itsController) delete p_itsController;
    if(NULL != p_itsDCMotor) delete p_itsDCMotor;
    if(NULL != p_itsServo) delete p_itsServo;
}

IMot* CMot::get_ItsIMot(){
    return (IMot*) p_itsAMot;
}

void CMot::set_ItsIMan(IMan* arg){
    p_itsIMan = (NULL != arg) ? arg : NULL;
}

void CMot::init(){
    Serial.println("CMot::init()");
    if(NULL != p_itsDCMotor) {
        p_itsController->set_ItsDCMotor(p_itsDCMotor);
    }
    if(NULL != p_itsServo) {
        p_itsController->set_ItsServo(p_itsServo);
    }
    if(NULL != p_itsController) {
        p_itsDCMotor->set_ItsController(p_itsController);
        p_itsServo->set_ItsController(p_itsController);
        p_itsAMot->set_ItsController(p_itsController);
    }

    p_itsDCMotor->init();
    p_itsServo->init();
    p_itsController->init();
    p_itsAMot->init();
}

AMot::AMot(){
    // TBD
}

AMot::~AMot(){
    // TBD
}

void AMot::init_AMot(){
    // TBD
    Serial.println("AMot::initAMot()");
}

void AMot::init(){
    // TBD
}

void AMot::set_ItsController(Controller* arg){
    p_itsController = (NULL != arg) ? arg : NULL;
}

/* Controller */
Controller::Controller(){
    // TBD
}

Controller::~Controller(){
    // TBD
}

void Controller::init_Controller(){
    Serial.println("Controller::init_Controller()");
}

void Controller::init(){
    this->init_Controller();
}

void Controller::set_ItsDCMotor(DCMotor* arg){
    p_itsDCMotor = (NULL != arg) ? arg : NULL;
}

void Controller::set_ItsServo(Servo* arg){
    p_itsServo = (NULL != arg) ? arg : NULL;
}


/* DCMotor */
void DCMotor::init_DCMotor(){
    Serial.println("DCMotor::init_DCMotor()");
}

void DCMotor::set_ItsController(Controller* arg){
    p_itsController = (NULL != arg) ? arg : NULL;
}

void DCMotor::init(){
    this->init_DCMotor();
}

/* Servo */
void Servo::init_Servo(){
    Serial.println("Servo::init_Servo()");
}

void Servo::set_ItsController(Controller* arg){
    p_itsController = (NULL != arg) ? arg : NULL;
}

void Servo::init(){
    this->init_Servo();
}