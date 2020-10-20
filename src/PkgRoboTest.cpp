/*
    In this package we will only build the Test component and the components that we need to test
    We need to be careful to satisfy all required interfaces to avoid breaking the logic of our Architecture.
    For example:
        CMot requires a CMan interface.
        If we are not building CMan for our tests then CTest needs to implement the CMan interface (IMan).
        In this instance IMan will be provided by the ITstMan interface from CTst.

    To define which component gets created or emulated we use #define directives.
    If a component needs to be emulated, we define a #define _<component name>_EMU.
    For example if we want CMan to be emulated we will det the following directive to true:
        #define _CMAN_EMU   true
*/
#include "PkgRoboTest.h"

#define _CMAN_EMU   false   // Set to false for ASSIGNMENT 3
#define _CCOM_EMU   false   // Set to false for ASSIGNMENT 2 & 3
#define _CMOT_EMU   false   // Set to false for ASSIGNMENT 1 & 3
#define _CSEN_EMU   true

RoboTest::RoboTest(){ //RoboTest() is the package constructor,(N.B.the constructor is always named after the class name)
    // The test component always gets created
    p_itsCTst = new(CTst);
    itsTestToRun = new char[4];

    // All other components are either instanciated as normal or emulated by CTst
#if (false == _CMAN_EMU) /* "#if()" that's called a preprocessor if and it's only preprocessed at the first step of 
compiling the program, whereas the normal if(){}, is handeled at run time when the program is executed.*/
    p_itsCMan = new(CMan);
    itsTestToRun = "Man";
#endif
#if (false == _CCOM_EMU)
    p_itsCCom = new(CCom);
    itsTestToRun = "Com";
#endif
#if (false == _CMOT_EMU)
    p_itsCMot = new(CMot);
    itsTestToRun = "Mot";
#endif
#if (false == _CSEN_EMU)
    p_itsCSen = new(CSen);
    itsTestToRun = "Sen";
#endif
}

RoboTest::~RoboTest(){
    delete(p_itsCTst);
    delete(itsTestToRun);
#if (false == _CMAN_EMU)
    delete(p_itsCMan);
#endif
#if (false == _CCOM_EMU)
    delete(p_itsCCom);
#endif
#if (false == _CMOT_EMU)
    delete(p_itsCMot);
#endif
#if (false == _CSEN_EMU)
    delete(p_itsCSen);
#endif
}

int RoboTest::init(){
    Serial.println("RoboTest::init()");

    // Check each component was created successfully or return and _ERRNO_NULL_POINTER_CCOM
    // CTst is always instanciated
    if(NULL == p_itsCTst) return _ERRNO_NULL_POINTER_CTST;
    // Other components are created depending on directives
    // We need to set the interfaces correctly
    // First we start with CTest and set all pointers, included NULL ones
#if (false == _CMAN_EMU)
    if(NULL == p_itsCMan) return _ERRNO_NULL_POINTER_CMAN;
    p_itsCTst->set_ItsIMan(p_itsCMan->get_ItsIMan());
#endif
#if (false == _CCOM_EMU)
    if(NULL == p_itsCCom) return _ERRNO_NULL_POINTER_CCOM;
    p_itsCTst->set_ItsICom(p_itsCCom->get_ItsICom());
#endif
#if (false == _CMOT_EMU)
    if(NULL == p_itsCMot) return _ERRNO_NULL_POINTER_CMOT;
    p_itsCTst->set_ItsIMot(p_itsCMot->get_ItsIMot());
#endif
#if (false == _CSEN_EMU)
    if(NULL == p_itsCSen) return _ERRNO_NULL_POINTER_CSEN;
    p_itsCTst->set_ItsISen(p_itsCSen->get_ItsISen());
#endif

    // Now we set each component interfaces as required.
    // If a component exists we use the instanciated interface.
    // If a component is emulated we use the emulated interface.

#if (false == _CCOM_EMU)
    #if (false == _CMAN_EMU)
    p_itsCCom->set_ItsIMan(p_itsCMan->get_ItsIMan());
    #else
    p_itsCCom->set_ItsIMan(p_itsCTst->get_ItsIMan());
    #endif
#endif

#if (false == _CMOT_EMU)
    #if (false == _CMAN_EMU)
    p_itsCMot->set_ItsIMan(p_itsCMan->get_ItsIMan());
    #else
    p_itsCMot->set_ItsIMan(p_itsCTst->get_ItsIMan());
    #endif
#endif

#if (false == _CSEN_EMU)
    #if (false == _CMAN_EMU)
    p_itsCSen->set_ItsIMan(p_itsCMan->get_ItsIMan());
    #else
    p_itsCSen->set_ItsITst(p_itsCMan->get_ItsIMan());
    #endif
#endif

#if (false == _CMAN_EMU)
    #if(false == _CCOM_EMU)
    p_itsCMan->set_ItsICom(p_itsCCom->get_ItsICom());       // Real Icom
    #else
    p_itsCMan->set_ItsICom(p_itsCTst->get_ItsICom());       // Emulated Icom
    #endif

    #if(false == _CMOT_EMU)
    p_itsCMan->set_ItsIMot(p_itsCMot->get_ItsIMot());       // Real IMot
    #else
    p_itsCMan->set_ItsIMot(p_itsCTst->get_ItsIMot());       // Emulated IMot
    #endif

    #if(false == _CSEN_EMU)
    p_itsCMan->set_ItsISen(p_itsCSen->get_ItsISen());       // Real ISen
    #else
    p_itsCMan->set_ItsISen(p_itsCTst->get_ItsISen());       // Emulated ISen
    #endif
#endif

    // Initialise all components as required.
    // CTst must be initialised first
    p_itsCTst->init();
    // Other components are only initialised if they were instanciated
#if (false == _CMAN_EMU)
    p_itsCMan->init();
#endif
#if (false == _CCOM_EMU)
    p_itsCCom->init(); //look at line 45 in CCom.cpp
#endif
#if (false == _CMOT_EMU)
    p_itsCMot->init();
#endif
#if (false == _CSEN_EMU)
    p_itsCSen->init();
#endif

    return 0;
}

void RoboTest::run(){
    static bool bRun = false;
    if(!bRun){  //if false
        Serial.println("RoboTest::run()");
        bRun = true;
    }
    /*FIRST ASSIGNMENT:    SET THE WHEELS IN MOTION
    Create a runATest() function in the Tester class (CTst) that will read an input from the keyboard and send the command to a Controller class (CMot).

    Authorised keyboard inputs are all numerical single digit characters (0,1,2,3,4,5,6,7,8,9).
    To pass the information between components you must use the interfaces.

    The runTest() function must be called using the CTst interface so the equivalent function must be declared in ITst and implemented by ATst.

    To use a fuction from an interface the pointer to the said interface may not need to be stored locally but can be accessed as follows:
    p_itsComponent->get_ItsInterface()->functionCall();
    example: p_itsCTst->get_ItsITst()->init();*/

    // Call the runATest() function with argument "Mot" from ITst, the CTst interface
    //p_itsCTst->get_ItsITst()->runATest("Mot");

    /*SECOND ASSIGNMENT:    CHECK THE COMMUNICATION INTERFACE
    Call the runATest function that we used previously in assignment 1.
    First change the function to take a string parameter "Mot" or "Com" so on and so forth to run the correct test.
    will confirm the data received on the communication interface by displaying the value on a screen (e.g. terminal or LCD).

    The function will present the raw data received to the display.
    It will also indicate the time between each stream received.
    HINT: research how to read time from Arduino, use newtime and oldtime to calculate the duration between each input.
    This is to check the frequency at which information can be sent via the Communication interface.
    For example how quickly can we press multiple commands before one or more gets dropped.

    The receive command will need to be triggered by an interrupt to avoid the whole system to hang waiting for an input.
    This can be done last after confirming the hardware works properly.

    Remember to enable the CCom component and disable all other to use their emulators.
    */

    // Call the test function with argument testToRun set to "Com" (remember to set it in the CTest constructor)
    // Serial.print("Test to be run: ");
    // Serial.println(itsTestToRun);
    //  p_itsCTst->get_ItsITst()->runATest(itsTestToRun);
    //  p_itsCTst->get_ItsITst()->runATest("Com");

    /* THIRD ASSIGNMENT:    CONNECT CMAN, CCOM AND CMOT TO DRIVE THE MOTORS FROM THE BLUETOOTH interface
    In this assignment we are now using the CCom and CMot components that have been tested previously to test the CMan component
    The aim is to read a charcter from the CCom Bluetooth serial port and pass it to the CMot to action the MOTORS
    HINTS:  IMan must provide a run() function
                In the run() function CMan will read a character from CCom and pass it to CMot (watch out for any conversion needed)
            CCom must provide a read() function - This will return a char - it will be used by CMan to read the character
            CMot should only have to take the command and execute it
    !!! Watch for the initialisation of the package, making sure all Components are initialised properly with the right pointers !!!
    */
    p_itsCTst->get_ItsITst()->runATest("Man");
}