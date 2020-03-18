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

void Controller::move_forward(int argSpeed){
    p_itsDCMotorRight->run(argSpeed, true);
    p_itsDCMotorLeft->run(argSpeed, true);
}

void Controller::spin_right(int argSpeed){
    p_itsDCMotorRight->run(argSpeed, false);
    p_itsDCMotorLeft->run(argSpeed, true);
}

void Controller::turn_right(int argSpeed){
    p_itsDCMotorRight->run((int)((float)argSpeed/1.2), true);
    p_itsDCMotorLeft->run(argSpeed, true);
}

/* DCMotor */
void DCMotor::init_DCMotor(){
    //  Serial.println("DCMotor::init_DCMotor()");
    //  Serial.print("Enable pin is:");
    //  Serial.println(EN);
    //  Serial.print("In1 pin is:");
    //  Serial.println(In1);
    //  Serial.print("In2 pin is:");
    //  Serial.println(In2);

    // Initialise the enable pin as analogue output

    // Initialise In1 pin as digital output

    // Initialise In2 pin as digital output
}

void DCMotor::set_ItsController(Controller* arg){
    p_itsController = (NULL != arg) ? arg : NULL;
}

void DCMotor::init(int a,int b, int c){
    EN = a;     // Enable pin
<<<<<<< Updated upstream
    In1 = b;    // In1 pin
    In2 = c;    // In2 pin

    this->init_DCMotor();
}

void DCMotor::run(int argSpeed, bool argDirection){
    // Set In1 and In2 based on argDirection
    if(false == argDirection){
        digitalWrite(In1, LOW);
        digitalWrite(In2, HIGH);
    }
    else{
        digitalWrite(In1, LOW);
        digitalWrite(In2, HIGH);
    }

    // Write PWN value to EN based on argSpeed
    // First cap the value at 255 if it is greater
    int speed = (255 >= argSpeed) ? argSpeed : 255;
    analogWrite(EN, argSpeed);
=======
    In1 = b;    // In 1
    In2 = c;    // In 2

    this->init_DCMotor();
>>>>>>> Stashed changes
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