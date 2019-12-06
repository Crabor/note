#include"CPP.h"

CPP::CPP()
{
}

CPP::CPP(int value){
    i=value;
}

CPP::~CPP()
{
}

int CPP::getInt(){
    return i;
}

float CPP::getFloat(){
    return f;
}
void CPP::setInt(int i){
    this->i=i;
}

void CPP::setFloat(float f){
    this->f=f;
}
