#include "CMot.h"

/* CMot */

CMot::CMot(){
    p_itsAMot = new AMot();
    p_itsIMan = NULL;
    p_itsController = new Controller();
    p_itsDCMotorRight = new DCMotor();
    p_itsDCMotorLeft = new DCMotor();
    p_itsServo = new Servo();
}

CMot::~CMot(){
    if(NULL != p_itsAMot) delete(p_itsAMot);
    p_itsIMan = NULL;
    if(NULL != p_itsController) delete p_itsController;
    if(NULL != p_itsDCMotorRight) delete p_itsDCMotorRight;
    if(NULL != p_itsDCMotorLeft) delete p_itsDCMotorLeft;
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
    if(NULL != p_itsDCMotorRight) {
        p_itsController->set_ItsDCMotorRight(p_itsDCMotorRight);
    }
    if(NULL != p_itsDCMotorLeft) {
        p_itsController->set_ItsDCMotorLeft(p_itsDCMotorLeft);
    }
    if(NULL != p_itsServo) {
        p_itsController->set_ItsServo(p_itsServo);
    }
    if(NULL != p_itsController) {
        p_itsDCMotorRight->set_ItsController(p_itsController);
        p_itsDCMotorLeft->set_ItsController(p_itsController);
        p_itsServo->set_ItsController(p_itsController);
        p_itsAMot->set_ItsController(p_itsController);
    }
    
    
    p_itsController->init();
    //p_itsDCMotorRight->init();
    //p_itsDCMotorLeft->init();
    p_itsServo->init();
    p_itsAMot->init();
}

/* Adapter*/
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
    this->init_AMot() ;
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
    p_itsDCMotorRight->init(11,12,13);
    p_itsDCMotorLeft->init(10,9,8);
}

void Controller::set_ItsDCMotorRight(DCMotor* arg){
    p_itsDCMotorRight = arg;
}
void Controller::set_ItsDCMotorLeft(DCMotor* arg){
    p_itsDCMotorLeft = arg;
}

void Controller::set_ItsServo(Servo* arg){
    p_itsServo = arg;
}


/* DCMotor */
void DCMotor::init_DCMotor(){
     Serial.println("DCMotor::init_DCMotor()");
     Serial.print("Enable pin is:");
     Serial.println(EN);
     Serial.print("In1 pin is:");
     Serial.println(In1);
     Serial.print("In2 pin is:");
     Serial.println(In2);
}

void DCMotor::set_ItsController(Controller* arg){
    p_itsController = (NULL != arg) ? arg : NULL;
}

void DCMotor::init(int a,int b, int c){
    EN = a;
    In1 = b;
    In2 = c;

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