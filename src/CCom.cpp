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
Pass a valid IMan point to local variable p_itsIMan or nullify
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
    if(NULL != p_itsBluetooth){
        p_itsBluetooth->init();                         // Initialise Bluetooth
    } // !!! Need to catch exception !!!

    if(NULL != p_itsACom){
        p_itsACom->set_ItsBluetooth(p_itsBluetooth);    // Set relationship with Bluetooth
        p_itsACom->init();                              // Initialise ACom
        p_itsBluetooth->println("CCom initialised");
    } // !!! Need to catch exception !!!
    else p_itsBluetooth->println("!!! Failed to initialise CCom !!!");
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
Getter: get_ItsICom
Return the ICom pointer associated with this Acom object
*/
ICom* ACom::get_ItsICom(){
    return (ICom*) this;
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


/* --------------------- Bluetooth ------------------------- */
/*
TBD
*/
Bluetooth::Bluetooth(){
    // TBD
}

/*
TBD
*/
Bluetooth::~Bluetooth(){
    // TBD
}

/*
TBD
*/
void Bluetooth::init_Bluetooth(){
    Serial.begin(115200);
    Serial.println("Bluetooth initialised");
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