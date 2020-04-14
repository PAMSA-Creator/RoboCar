#include "CTst.h"

/* -------------------- CTst -------------------------- */
/*
Default constructor
Build all internal objects
*/
CTst::CTst(){
    p_itsATst = new ATst();
    p_itsTester = new Tester();
    p_itsICom = NULL;
    p_itsIMot = NULL;
    p_itsISen = NULL;
}

CTst::~CTst(){
    p_itsICom = NULL;
    p_itsIMot = NULL;
    p_itsISen = NULL;
    if(NULL != p_itsATst) delete(p_itsATst);
    if(NULL != p_itsTester) delete(p_itsTester);
}

/*
    Getter: get_ItsITst
    Return an ITst pointer to the ATst adapter
*/
ITst* CTst::get_ItsITst(){
    return (ITst*) p_itsATst;    
}

/*
    Getter: get_ItsITstMan
    Return an IMan pointer to the ATstMan adapter (emulated Central Control subsystem)
*/
IMan* CTst::get_ItsITstMan(){
    return (IMan*) p_itsATstMan;
}

/*
    Getter: get_ItsITstCom
    Return an ICom pointer to the ATstCom adapter (emulated Communication subsystem)
*/
ICom* CTst::get_ItsITstCom(){
    return (ICom*) p_itsATstCom;
}

/*
    Getter: get_ItsITstMot
    Return an IMot pointer to the ATstMot adapter (emulated Motion Controller subsystem)
*/
IMot* CTst::get_ItsITstMot(){
    return (IMot*) p_itsATstMot;
}

/*
    Getter: get_ItsITstSen
    Return an ISen pointer to the ATstSen adapter (emulated Sensory subsystem)
*/
ISen* CTst::get_ItsITstSen(){
    return (ISen*) p_itsATstSen;
}

/*
Setter: set_ItsIMan
Pass a valid IMan point to local variable p_itsIMan or nullify
*/
void CTst::set_ItsIMan(IMan* arg){
    p_itsIMan = (NULL != arg) ? arg : NULL;
}

/*
Setter: set_ItsICom
Pass a valid ICom point to local variable p_itsICom or nullify
*/
void CTst::set_ItsICom(ICom* arg){
    p_itsICom = (NULL != arg) ? arg : NULL;
}

/*
Setter: set_ItsIMot
Pass a valid IMot point to local variable p_itsIMot or nullify
*/
void CTst::set_ItsIMot(IMot* arg){
    p_itsIMot = (NULL != arg) ? arg : NULL;
}

/*
Setter: set_ItsISen
Pass a valid ISen point to local variable p_itsISen or nullify
*/
void CTst::set_ItsISen(ISen* arg){
    p_itsISen = (NULL != arg) ? arg : NULL;
}

/*
Initilisation
Check and set all relationships (pointers)
*/
void CTst::init(){
    Serial.println("CTst::init()");
    if(NULL != p_itsTester){
        p_itsTester->init();                         // Initialise Tester
    } // !!! Need to catch exception !!!

    if(NULL != p_itsATst){
        p_itsATst->set_ItsTester(p_itsTester);        // Set relationship with Tester
        p_itsATst->init();                          // Initialise ATst
    } // !!! Need to catch exception !!!
}

/* --------------------- ACom ------------------------- */
/*
Default constructor
*/
ATst::ATst(){
    // TBD
}

/*
Default destructor
*/
ATst::~ATst(){
    // TBD
}

/*
Setter: set_ItsTester
Pass a valid Tester pointer to local variable p_itsTester or nullify
*/
void ATst::set_ItsTester(Tester* arg){
    p_itsTester = (NULL != arg) ? arg : NULL;
    // !!! Need to catch exception !!!
};

/*
Initilisation
Initialise ATst
*/
void ATst::init_ATst(){
    Serial.println("ATst::init_ATst()");
}

void ATst::init(){
    this->init_ATst();
}

/* -------------------- Tester -------------------------- */
/*
Default constructor
*/
Tester::Tester(){
    // TBD
}

/*
Default destructor
*/
Tester::~Tester(){
    // TBD
}

/*
Initilisation
Initialise Tester
*/
void Tester::init_Tester(){
    Serial.println("Tester::init_Tester()");
}

void Tester::init(){
    this->init_Tester();
}