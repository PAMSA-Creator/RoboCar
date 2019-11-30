#include "CCom.h"

ICom* HC05::get_ItsICom(){
    return (ICom*) this;
}

void HC05::set_ItsCCom(CCom* arg){
    p_itsCCom = (NULL != arg) ? arg : NULL;
}

void HC05::init(){
    Serial.begin(115200);
    Serial.println("Serial port initialised!");
}

CCom::CCom(){
    p_itsICom = (ICom*) new HC05();
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
    //p_itsICom = (ICom*) new HC05();
    if(NULL != p_itsICom){
        p_itsICom->init();
        p_itsICom->set_ItsCCom(this);
    }
}

void CCom::println(const char* arg){
    Serial.println(arg);
}