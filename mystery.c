#include<stdio.h>

void mystery(int n){
    n+=5;
    n/=10;
    printf("%s\n","**********"+10-n);
}

int main(void){
    while(1){
        int n;
        scanf("%d",&n);
        mystery(n);
        printf("\n");
    }
    return 0;
}