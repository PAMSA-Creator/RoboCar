#ifndef _PKG_ROBOCAR_H
#include "PkgRoboCar.h"
#endif

CManager* itsCManager = NULL;
CCom* itsCCom = NULL;

void init(){
    itsCManager = new(CManager);
    itsCCom = new(CCom);
}

void run(){

}