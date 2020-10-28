#include "CCom.h"

/* -------------------- CCom -------------------------- */
/*
Default constructor
Build all internal objects
*/
CCom::CCom(){
    p_itsACom = new ACom();
    p_itsBluetooth = new Bluetooth();
    p_itsIMan = NULL;
}

/*
Default destructor
Destroy all internal objects and nullify all external pointers
*/
CCom::~CCom(){
    p_itsIMan = NULL;
    if(NULL != p_itsACom) delete(p_itsACom);
    if(NULL != p_itsBluetooth) delete(p_itsBluetooth);
}

/*
Getter: get_ItsICom
Return an ICom pointer to the ACom object
*/
ICom* CCom::get_ItsICom(){
    return (ICom*) p_itsACom;
}

/*
Setter: set_ItsIMan
Pass a valid IMan pointer to local variable p_itsIMan or nullify
*/
void CCom::set_ItsIMan(IMan* arg){
    p_itsIMan = (NULL != arg) ? arg : NULL;
    // !!! Need to catch exception !!!
}

/*
Initilisation
Check and set all relationships (pointers)
*/
void CCom::init(){
    Serial.println("CCom::init()");
    if(NULL != p_itsBluetooth){
        p_itsBluetooth->init();                         // Initialise Bluetooth object
    } // !!! Need to catch exception !!!

    if(NULL != p_itsACom){
        p_itsACom->set_ItsBluetooth(p_itsBluetooth);    // Set relationship with Bluetooth
        p_itsACom->init();                              // Initialise ACom
    } // !!! Need to catch exception !!!
    else Serial.println("!!! Failed to initialise CCom !!!");
}

/* --------------------- ACom ------------------------- */
/*
TBD
*/
ACom::ACom(){
    // TBD
}

/*
TBD
*/
ACom::~ACom(){
    // TBD
}

/*
Setter: set_ItsBluetooth
Pass a valid Bluetooth pointer to local variable p_itsBluetooth or nullify
*/
void ACom::set_ItsBluetooth(Bluetooth* arg){
    p_itsBluetooth = (NULL != arg) ? arg : NULL;
    // !!! Need to catch exception !!!
};

/*
Initilisation
Initialise ACom
*/
void ACom::init_ACom(){
    Serial.println("ACom::init_ACom()");
    return p_itsBluetooth->init();
}

void ACom::init(){
    this->init_ACom();
}

/*
TBD
*/
void ACom::println(const char* arg){
    if(NULL != p_itsBluetooth) p_itsBluetooth->println(arg);
    // !!! Need to catch exception !!!
}

void ACom::BTControlLED(){
    //call the function from the Bluetooth class
   return p_itsBluetooth->BTControlLED();
}

void ACom::CmdRxCheck(){
    //call the function from the Bluetooth class
   return p_itsBluetooth->CmdRxCheck();
}

char ACom::readCmd(){
    return p_itsBluetooth->readCmd();
}

/* --------------------- Bluetooth ------------------------- */
/*
TBD
*/
Bluetooth::Bluetooth(){
//TBD
#define _HC05
#ifdef _HC05 
    p_HC05 = new SoftwareSerial(3, 2); // 3,2 are the Rx and Tx pins in arduino UNO respectively
    //https://www.arduino.cc/en/Reference/SoftwareSerialConstructor
#endif
}

/*
TBD
*/
Bluetooth::~Bluetooth(){
    delete p_HC05;
}

/*
TBD
*/
void Bluetooth::init_Bluetooth(){
    
    if(!Serial){ // do nothing
    }
    #define _HC05
    #ifdef _HC05
    //I've included SoftwareSerial.h library in the CCom.h
    p_HC05 = new SoftwareSerial(3,2); // 3,2 are the Rx and Tx pins in arduino UNO respectively
    if (p_HC05 !=NULL){
        p_HC05-> begin (9600);
    }
    #endif
    Serial.println("Bluetooth::init_Bluetooth()");
    Serial.println ();
}

/*
TBD
*/
void Bluetooth::init(){
    this->init_Bluetooth();
}

/*
TBD
*/
void Bluetooth::println(const char* arg){
    Serial.println(arg);
}

void Bluetooth::BTControlLED(){
    // Local variables
    char state = 'x';
    int LED = 13;
    pinMode (LED,OUTPUT);

 #ifdef _HC05 
    if (p_HC05->available()){
        state = p_HC05->read ();
        Serial.println("Reading the serial BT");
    }
#else 
    state = ('0' == state ) ? '1' : '0'; // This line is to toggle the state between 0 and 1 values
#endif

    if (state == '0'){
        digitalWrite (LED, LOW);
        Serial.println ("LED is OFF!");
    }
    else if (state == '1'){
        digitalWrite (LED, HIGH);
        Serial.println ("LED is ON!");
    }
    else{
        Serial.println ("!!! NOT POSSIBLE !!!");
    }
}

void Bluetooth::CmdRxCheck(){
    // Local variables
    char Cmd = 'x';
#ifdef _HC05
    // while (!p_HC05->available()); //waiting for input to BT
    if (p_HC05->available()){
        Cmd = p_HC05->read ();
        //Serial.println("Reading the serial BT");
        //delay(500);
        //Serial.print ("Your Command is:");
        //Serial.println (Cmd);
        //Serial.write (Cmd);
        //Serial.println( );
    }
   #else 
       Serial.println ("No Command was recieved!");
   #endif
}

char Bluetooth::readCmd(){
//This function is to read the char sent to the Arduino through the BT then send it to the CMan 
char Cmd = 'a';
#ifdef _HC05
    while (!p_HC05->available()); //waiting for input to BT
    if (p_HC05->available()){
        Cmd = p_HC05->read ();
    }
#endif
Serial.print("The Recieved BT command is:");
Serial.println(Cmd);
return Cmd;
}