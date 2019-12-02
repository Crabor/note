#include<stdio.h>

#define max(x) max##x 

int main(void){
    int max1=1,max2=2,max3=3,max4=4,max5=5;
    for(int i=0;i<5;i++){
        printf("%d\n",max(i));
    }
    return 0;
}