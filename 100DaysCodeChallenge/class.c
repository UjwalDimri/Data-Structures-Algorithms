#include<stdio.h>
int main(){
    int n ;
    scanf("%d",&n);
    for (int i = 1; i < n+1; i++){
        printf("%d",i);
        for (int j = n-1; j>0; j--){
            printf("%d",i);
        }
        printf("\n");
        
    }
    
}