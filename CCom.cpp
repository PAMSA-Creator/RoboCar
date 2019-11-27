#ifndef _C_COM_H
#include "CCom.h"
#endif

CCom::CCom(){
    p_itsICom = (ICom *) new(HC05);
}

CCom::~CCom(){
    if(NULL != p_itsICom) delete(p_itsICom);
}

ICom* CCom::get_ItsICom(){
    return p_itsICom;
}

void CCom::set_ItsICom(ICom *arg){
    p_itsICom = (NULL != arg) ? arg : NULL;
}