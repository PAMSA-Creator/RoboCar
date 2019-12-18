#include "CCom.h"

/* CCom */
CCom::CCom(){
    // Return pointer to Bluetooth object cast as ICom type
    p_itsICom = (ICom*) new Bluetooth();
}

CCom::~CCom(){
    if(NULL != p_itsICom) delete(p_itsICom);
}

IMan* CCom::get_ItsIMan(){
    return p_itsIMan;
}

void CCom::set_ItsIMan(IMan* arg){
    p_itsIMan = (NULL != arg) ? arg : NULL;
}

ICom* CCom::get_ItsICom(){
    return p_itsICom;
}

void CCom::set_ItsICom(ICom *arg){
    p_itsICom = (NULL != arg) ? arg : NULL;
}

void CCom::init(){
    if(NULL != p_itsICom){
        p_itsICom->init();
        Serial.println("CCom initialised");
    }
    else Serial.println("!!! Failed to initialise CCom !!!");
}

/* Bluetooth */
ICom* Bluetooth::get_ItsICom(){
    return (ICom*) this;
}

void Bluetooth::init_Bluetooth(){
    Serial.println("Bluetooth initialised");
}

void Bluetooth::init(){
    this->init_Bluetooth();
    Serial.begin(115200);
    Serial.println("Communication initialised");
}

void Bluetooth::println(const char* arg){
    Serial.println(arg);
}

