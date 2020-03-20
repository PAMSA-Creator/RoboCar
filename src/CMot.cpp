#include "CMot.h"

/* CMot */

CMot::CMot(){ // constructor function
    p_itsAMot = new AMot();
    p_itsIMan = NULL;
    p_itsController = new Controller();
    p_itsDCMotorRight = new DCMotor();
    p_itsDCMotorLeft = new DCMotor();
    p_itsServo = new Servo();
}

CMot::~CMot(){ //deconstructor function
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
    p_itsDCMotorRight->init(11,12,13); //assigning the pins in the Arduino to the DCmotors using the DCMotor::init()
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

int Controller::motionCommand(int arg){
    // First is to breakdown the arg into CID and speed
int data = arg;
int lowerNibble=0, upperNibble=0, temp=0, bSpeed=0, bCID=0;
lowerNibble= data & 0xF ; //getting the first 4 bits by using the bitwise AND & with 0xF which is equal to 0b1111
temp= data - lowerNibble; // that will make the first 4 bits values equal to 0 and will maintain the original last 4 bits of data
upperNibble= temp>>4; // using the shift right >> bitwise operator and it'll shift the MSB 4 times so that they become LSB
return lowerNibble, upperNibble;
// Serial.print ("bSpeed =");
//Serial.println (lowerNibble);
//Serial.print ("bCID =");
//Serial.println (upperNibble);
}
int Controller::binaryToDecimal (int n){
    int num = n, dec=0, rem=0, base=1;  // initialising base value to 1 (i.e.2^0)
    while (num>0){
           rem=num%10; // this remainder is going to be the LSB of the binary number
           dec=dec+rem*base; //updating the decimal value untill the while condition is not true
           num=num/10; // this is going to get rid of the remainder (i.e. the LSB) and will keep the rest of the number
           base=base*2; //this is going to be the next base value (2^1 , 2^2 , 2^3, etc)
        }
    return dec;
}
// int itsSpeed = // calculate from only 16 values available (from 0 to 15) when speed is 15 then argSpeed = 255 (increment is 17)
//call the conversion function
int Speed = binaryToDecimal (bSpeed);
// int itsCID = // calculate
// function call
int CID = binaryToDecimal (bCID);
// From CID, determine the motion to execute
switch (CID)
{
    // Move forward is issued when the CID is 8
    case 8: 
    p_itsDCMotorRight->run(argSpeed, true);
    p_itsDCMotorLeft->run(argSpeed, true);
    break;
    // Move backward is issued when the CID is 9
    case 9:
    p_itsDCMotorRight->run(argSpeed, false);
    p_itsDCMotorLeft->run(argSpeed, false);
    break;
    // spin right is issued when the CID is 10
    case 10:
    p_itsDCMotorRight->run(argSpeed, false);
    p_itsDCMotorLeft->run(argSpeed, true);
    break;
    // spin left is issued when the CID is 11
    case 11:
    p_itsDCMotorRight->run(argSpeed, true);
    p_itsDCMotorLeft->run(argSpeed, false);
    break;
    // turn right is issued when the CID is 12
    case 12:
    p_itsDCMotorRight->run((int)((float)argSpeed/1.2), true);
    p_itsDCMotorLeft->run(argSpeed, true);
    break;
    //turn left is issued when the CID is 13
    case 13:
    p_itsDCMotorRight->run(argSpeed, true);
    p_itsDCMotorLeft->run((int)((float)argSpeed/1.2), true);
    break;
    //stop is issued when the CID is 14
    case 14:
    p_itsDCMotorRight->stop();
    p_itsDCMotorLeft->stop();
    break;
}

/* DCMotor */
void DCMotor::init_DCMotor(){
    // Initialise the enable pin as analogue output
    pinMode (EN,OUTPUT);
    // Initialise In1 pin as digital output
    pinMode (In1,OUTPUT);
    // Initialise In2 pin as digital output
    pinMode (In2,OUTPUT);
    //  Serial.println("DCMotor::init_DCMotor()");
    //  Serial.print("Enable pin is:");
    //  Serial.println(EN);
    //  Serial.print("In1 pin is:");
    //  Serial.println(In1);
    //  Serial.print("In2 pin is:");
    //  Serial.println(In2);
}

void DCMotor::set_ItsController(Controller* arg){
    p_itsController = (NULL != arg) ? arg : NULL;
}

void DCMotor::init(int a,int b, int c){
    EN = a;     // Enable pin
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
        digitalWrite(In1, HIGH);
        digitalWrite(In2, LOW);
    }
void DCMotor::stop(){
    analogWrite(EN,0);
    digitalWrite(In1,LOW);
    digitalWrite(In2,LOW);
}
    // Write PWN value to EN based on argSpeed
    // First cap the value at 255 if it is greater
    int speed = (255 >= argSpeed) ? argSpeed : 255;
    analogWrite(EN, speed);
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