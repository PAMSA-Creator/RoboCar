#include "CMan.h"

/* -------------------- CMan -------------------------- */
/*
Default constructor
Build all internal objects
*/
CMan::CMan(){
    p_itsAMan = new AMan();
    p_itsBrain = new Brain();
    p_itsICom = NULL;
    p_itsIMot = NULL;
    p_itsISen = NULL;
}

CMan::~CMan(){
    p_itsICom = NULL;
    p_itsIMot = NULL;
    p_itsISen = NULL;
    if(NULL != p_itsAMan) delete(p_itsAMan);
    if(NULL != p_itsBrain) delete(p_itsBrain);
}

/*
Getter: get_ItsIMan
Return an IMan pointer to the AMan adapter
*/
IMan* CMan::get_ItsIMan(){
    return (IMan*) p_itsAMan;    
}

/*
Setter: set_ItsICom
Pass a valid ICom point to local variable p_itsICom or nullify
*/
void CMan::set_ItsICom(ICom* arg){
    p_itsICom = (NULL != arg) ? arg : NULL;
}

/*
Setter: set_ItsIMot
Pass a valid IMot point to local variable p_itsIMot or nullify
*/
void CMan::set_ItsIMot(IMot* arg){
    p_itsIMot = (NULL != arg) ? arg : NULL;
}

/*
Setter: set_ItsISen
Pass a valid ISen point to local variable p_itsISen or nullify
*/
void CMan::set_ItsISen(ISen* arg){
    p_itsISen = (NULL != arg) ? arg : NULL;
}
/*Getters*/
ICom* CMan::get_ItsICom() {return p_itsICom;}
IMot* CMan::get_ItsIMot(){return p_itsIMot;}
ISen* CMan::get_ItsISen(){return p_itsISen;}

/*
Initilisation
Check and set all relationships (pointers)
*/
void CMan::init(){
    Serial.println("CMan::init()");
    if(NULL != p_itsBrain){
        p_itsBrain->setItsCMan(this);
        p_itsBrain->init();                         // Initialise Brain
    } // !!! Need to catch exception !!!
    

    if(NULL != p_itsAMan){
        p_itsAMan->set_ItsBrain(p_itsBrain);        // Set relationship with Brain
        p_itsAMan->init();                          // Initialise AMan
    } // !!! Need to catch exception !!!
}

/* --------------------- AMan ------------------------- */
/*
Default constructor
*/
AMan::AMan(){
    // TBD
}

/*
Default destructor
*/
AMan::~AMan(){
    // TBD
}

/*
Setter: set_ItsBrain
Pass a valid Brain pointer to local variable p_itsBrain or nullify
*/
void AMan::set_ItsBrain(Brain* arg){
    p_itsBrain = (NULL != arg) ? arg : NULL;
    // !!! Need to catch exception !!!
};

/*
Initilisation
Initialise AMan
*/
void AMan::init_AMan(){
    Serial.println("AMan::init_AMan()");
}

void AMan::init(){
    this->init_AMan();
}

void AMan::run(){
    p_itsBrain->run();
}



/* -------------------- Brain -------------------------- */
/*
Default constructor
*/
Brain::Brain(){
    // TBD
}

/*
Default destructor
*/
Brain::~Brain(){
    // TBD
}
/*
Getters and Setters
*/
Brain* Brain::getItsBrain() 
{
return this;
}
void Brain::setItsCMan(CMan* arg)
{
p_itsCMan = arg; //set the pointer to CMan
}
/*
Initilisation
Initialise Brain
*/
void Brain::init_Brain(){
    Serial.println("Brain::init_Brain()");
}

void Brain::init(){
    this->init_Brain();
}

void Brain::run(){
    //the first thing to do is to check the BT for any commands
    char Cmd = p_itsCMan->get_ItsICom()->readCmd();

    //If a Cmd has been received then pass it to the correct component (CMot for assignment 3)

}