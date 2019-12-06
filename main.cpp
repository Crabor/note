#include<iostream>
#include"CPP.h"

using namespace std;

int main(void){
    CPP temp(2);
    temp.setFloat(2.0);
    CPP temp2(3);
    temp2.setFloat(3.0);
    cout<<temp.getFloat()<<endl;
    return 0;
}