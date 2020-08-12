#include "CTst.h"

/* -------------------- CTst -------------------------- */
/*
Default constructor
Build all internal objects
*/
CTst::CTst(){
    // Create a new Test Adapter (ATst) object
    p_itsATst = new ATst();

    // Create all emulated component adapters
    ATstMan* p_itsATstMan = new (ATstMan);   // Adapter to an emulated CMan component if required
    ATstCom* p_itsATstCom = new (ATstCom);   // Adapter to an emulated CCom component if required
    ATstMot* p_itsATstMot = new (ATstMot);   // Adapter to an emulated CMot component if required
    ATstSen* p_itsATstSen = new (ATstSen);   // Adapter to an emulated CSen component if required

    // Create a Tester object
    p_itsTester = new Tester();

    // Set all other interfaces to NULL until initialisation
    p_itsIMan = NULL;
    p_itsICom = NULL;
    p_itsIMot = NULL;
    p_itsISen = NULL;
}

CTst::~CTst(){
    p_itsISen = NULL;
    p_itsIMot = NULL;
    p_itsICom = NULL;
    p_itsIMan = NULL;
    if(NULL != p_itsATstSen) delete(p_itsATstSen);
    if(NULL != p_itsATstMot) delete(p_itsATstMot);
    if(NULL != p_itsATstCom) delete(p_itsATstCom);
    if(NULL != p_itsATstMan) delete(p_itsATstMan);
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
    Return an IMan pointer to the ATstMan adapter (emulated subsystem)
    Return an IMan pointer to the CMan adapter if the component exists
*/
IMan* CTst::get_ItsIMan(){
    // Return the pointer that exists
    if(NULL != p_itsATstMan)
        return (IMan*) p_itsATstMan;
    else if(NULL != p_itsIMan)
        return (IMan*) p_itsIMan;
    else
        return NULL;
}

/*
    Getter: get_ItsITstCom
    Return an ICom pointer to the ATstCom adapter (emulated subsystem)
    Return an ICom pointer to the CCom adapter if the component exists
*/
ICom* CTst::get_ItsICom(){
    // Return the pointer that exists
    if(NULL != p_itsATstCom)
        return (ICom*) p_itsATstCom;
    else if(NULL != p_itsICom)
        return (ICom*) p_itsICom;
   else
        return NULL;
}

/*
    Getter: get_ItsITstMot
    Return an IMot pointer to the ATstMot adapter (emulated subsystem)
    Return an IMot pointer to the CMot adapter if the component exists
*/
IMot* CTst::get_ItsIMot(){
    // Return the pointer that exists
    if(NULL != p_itsATstMot)
        return (IMot*) p_itsATstMot;
    else if(NULL != p_itsIMot)
        return (IMot*) p_itsIMot;
   else
        return NULL;
}

/*
    Getter: get_ItsITstSen
    Return an ISen pointer to the ATstSen adapter (emulated subsystem)
    Return an ISen pointer to the CSen adapter if the component exists
*/
ISen* CTst::get_ItsISen(){
    // Return the pointer that exists
    if(NULL != p_itsATstSen)
        return (ISen*) p_itsATstSen;
    else if(NULL != p_itsISen)
        return (ISen*) p_itsISen;
   else
        return NULL;
}

/*
Setter: set_ItsIMan
Pass a valid IMan point to local variable p_itsIMan or nullify
*/
void CTst::set_ItsIMan(IMan* arg){
    p_itsIMan = (NULL != arg) ? arg : (IMan*) p_itsATstMan;
}

/*
Setter: set_ItsICom
Pass a valid ICom point to local variable p_itsICom or nullify
*/
void CTst::set_ItsICom(ICom* arg){
    p_itsICom = (NULL != arg) ? arg : (ICom*) p_itsATstCom;
}

/*
Setter: set_ItsIMot
Pass a valid IMot point to local variable p_itsIMot or nullify
*/
void CTst::set_ItsIMot(IMot* arg){
    p_itsIMot = (NULL != arg) ? arg : (IMot*) p_itsATstMot;
}

/*
Setter: set_ItsISen
Pass a valid ISen point to local variable p_itsISen or nullify
*/
void CTst::set_ItsISen(ISen* arg){
    p_itsISen = (NULL != arg) ? arg : (ISen*) p_itsATstSen;
}

/*
Initilisation
Check and set all relationships (pointers)
*/
void CTst::init(){
    Serial.println("CTst::init()");
    if(NULL != p_itsTester){
        // Set the CTest pointer
        p_itsTester->set_ItsCTst(this);
        // Then initialise Tester
        p_itsTester->init();
    }

    if(NULL != p_itsATst){
        p_itsATst->set_ItsTester(p_itsTester);        // Set relationship with Tester
        p_itsATst->init();                          // Initialise ATst
    } // !!! Need to catch exception !!!
}

/* --------------------- ATst ------------------------- */
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
//Behaviour
void ATst::runATest(const char* arg){
//     Serial.println ("runATest is being executed");
//     while (!Serial.available());
//     delay(100); //wait to recieve the characters on the serial bus
//     while(Serial.available() > 0) // check how many characters to read
//   {
//     subsystem[i] = Serial.read(); // Add the incoming byte to the array
//     i++; // Ensure the next byte is added in the next position
//     subsystem[i] = '\0'; // to null terminate the incoming string
//   }
// Serial.print("The subsystem you've chosen is:");
// Serial.println(subsystem); //confirm the recieved data
//     if (subsystem == "Mot"){
//         p_itsTester-> runMotTest();
//     }
//     else if (subsystem == "Com"){
//         p_itsTester-> runComTest();
//     }
//     else if (subsystem == "Sen"){
//         p_itsTester->runSenTest();
//     }
//     else if (subsystem == "Man"){
//         p_itsTester->runManTest();
//     }
//     else{
//         Serial.println("You have to choose which subsystem you want to test?")
//     }

    // Check which test to runATest
    // Use strcmp to compare the argument arg passed to the method and the word associated with the test
    // strcmp returns the lenght of the string
    if(0 == strcmp("Mot", arg)) p_itsTester->runMotTest();
    else if(0 == strcmp("Com", arg)) p_itsTester->runComTest();
    else if(0 == strcmp("Man", arg)) p_itsTester->runManTest();
    else if(0 == strcmp("Sen", arg)) p_itsTester->runSenTest();
    else Serial.println("You have to choose which subsystem you want to test?");
}

/* --------------------- ATstMan ------------------------- */
/*
Default constructor
*/
ATstMan::ATstMan(){
    // TBD
}

/*
Default destructor
*/
ATstMan::~ATstMan(){
    // TBD
}

/*
Setter: set_ItsTester
Pass a valid Tester pointer to local variable p_itsTester or nullify
*/
void ATstMan::set_ItsTester(Tester* arg){
    p_itsTester = (NULL != arg) ? arg : NULL;
    // !!! Need to catch exception !!!
};

/*
Initilisation
Initialise ATstMan
*/
void ATstMan::init_ATstMan(){
    Serial.println("ATstMan::init_ATstMan()");
}

void ATstMan::init(){
    this->init_ATstMan();
}

/* --------------------- ATstCom ------------------------- */
/*
Default constructor
*/
ATstCom::ATstCom(){
    // TBD
}

/*
Default destructor
*/
ATstCom::~ATstCom(){
    // TBD
}

/*
Setter: set_ItsTester
Pass a valid Tester pointer to local variable p_itsTester or nullify
*/
void ATstCom::set_ItsTester(Tester* arg){
    p_itsTester = (NULL != arg) ? arg : NULL;
    // !!! Need to catch exception !!!
};

/*
Initilisation
Initialise ATstCom
*/
void ATstCom::init_ATstCom(){
    Serial.println("ATstCom::init_ATstCom()");
}

void ATstCom::init(){
    this->init_ATstCom();
}

/* --------------------- ATstMot ------------------------- */
/*
Default constructor
*/
ATstMot::ATstMot(){
    // TBD
}

/*
Default destructor
*/
ATstMot::~ATstMot(){
    // TBD
}

/*
Setter: set_ItsTester
Pass a valid Tester pointer to local variable p_itsTester or nullify
*/
void ATstMot::set_ItsTester(Tester* arg){
    p_itsTester = (NULL != arg) ? arg : NULL;
    // !!! Need to catch exception !!!
};

/*
Initilisation
Initialise ATstMot
*/
void ATstMot::init_ATstMot(){
    Serial.println("ATstMot::init_ATstMot()");
}

void ATstMot::init(){
    this->init_ATstMot();
}

/* --------------------- ATstSen ------------------------- */
/*
Default constructor
*/
ATstSen::ATstSen(){
    // TBD
}

/*
Default destructor
*/
ATstSen::~ATstSen(){
    // TBD
}

/*
Setter: set_ItsTester
Pass a valid Tester pointer to local variable p_itsTester or nullify
*/
void ATstSen::set_ItsTester(Tester* arg){
    p_itsTester = (NULL != arg) ? arg : NULL;
    // !!! Need to catch exception !!!
};

/*
Initilisation
Initialise ATstSen
*/
void ATstSen::init_ATstSen(){
    Serial.println("ATstSen::init_ATstSen()");
}

void ATstSen::init(){
    this->init_ATstSen();
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

void Tester::set_ItsCTst(CTst* arg){
    p_itsCTst = (NULL != arg) ? arg : NULL;
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
 // Behaviour
void Tester::runMotTest(void){

    // Initialise the CMot component
    p_itsCTst->get_ItsIMot()->init();

    // The "byte" variable type can range from 0-255
    Serial.println("Please Enter your command, you can enter values between 1 and 9!");
    
    // Check for user input on the serial interface
    while(Serial.available() == 0);

    // Read the input from the Serial interface and store in a 'command' variable
    unsigned char input = Serial.read();
    // Serial.print("Got a character: ");
    // Serial.print(input, DEC);
    // Serial.println();

    // Check that 'command' is between 0 and 9 only
    // Remember that we are dealing with ASCII code at this stage
    // ASCII code for '0' is 48 (0011 0000) and ASCII cde for '9' is 57 (0011 1001)
    if((input >= '1') && (input <= '9')){
        // First we need to convert from the ASCII code to the correct command
        // 1. Get the decimal value of the character
        char value = input - '0';   /* Remember this trick */
        Serial.println("Converted to Decimal: ");
        Serial.print(value,DEC);
        Serial.println();
                                        
        // 2. Set the correct direction
        // Remember that the top-most bit is set to 1 for direction CID
        //char command = 0x80 | ((value << 4) & 0xF0);
        /* AH >> Here I made that so that the input values are still the same varying between 1 and 9 and I also changed their corresponding values in the CMot.cpp to be matching*/
        unsigned char command = (value<<4) & 0xF0;

        /* Change to the correct command required for the motion that we want to do */
        /* See CMOt for the correct command - translate from keyboard input to CID  
        for ex. 2 on the keyboard is opposed to 9 in the system*/

        // 3. Set the correct speed
        command |= 0x08;

        // Get the interface to CMot from p_itsCTest and call the motionCommand() function passing 'command' as argument
        Serial.println("Sending motionCommand: ");
        Serial.print(command, BIN);
        Serial.print(", ");
        Serial.print(command, DEC);
        Serial.println();
        p_itsCTst->get_ItsIMot()->motionCommand(command);
    }
    else {
        Serial.println ("That's an invalid value!");
    }
}

void Tester::runComTest(void){
    Serial.println("Tester::runComTest");

    // Initialise the CCom component
    p_itsCTst->get_ItsICom()->init();

    // For debug purposes wait for something to happen on the serial port.
    // Remove this once the function is fully implemented
    while(!Serial.available());
    Serial.read();

    // Initial test should be simple, e.g. turn on an LED when any string has been received on the Bluetooth (Com) interface.
    // First, wait for an input on the Bluetooth module

    // Then gradually increase the complexity by checking specific commands.
    
    // Record the time event and measure duration between messages.
}

void Tester::runManTest(void){
    // TBD
}

void Tester::runSenTest(void){
    // TBD
}