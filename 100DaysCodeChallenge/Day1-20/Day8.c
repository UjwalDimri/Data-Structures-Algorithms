#include<stdio.h>

void change (int *p){
    *p=*p+20;
}
int main(){
    int x = 5;
    change(&x);
    printf("%d",x);
    return 0;
}