// question 1 
// Input and Display array(using base address)
#include<stdio.h>
int printarray(int *base,int nofe);
int main(){
    int n ;
    printf("Enter the number of elements do you want to enter");
    scanf("%d",&n);
    int arr[n];
    int *ptr;
    ptr=arr;
    for(int i =0;i<n;i++){
        printf("Enter element");
        scanf("%d",(ptr+i));
    }
    for(int j=0;j<n;j++){
        printf("%d \t",*(ptr+j));
    
    }

// question 2
// Input an array and pass array as a function parameter and display the content of the array in function defination (pass base adress)
int m ;
printf("Enter the number of elements do you want to enter ");
scanf("%d",&m);
int arr2[m];
int *ptr1;
ptr1=arr2;
for(int i =0;i<m;i++){
    printf("Enter Element \t");
    scanf("%d",(ptr1+i));
}
printarray(arr2,m);
return 0;
}

int printarray(int *address,int numberOfElements){
    for(int i=0;i<numberOfElements;i++){
        printf("%d\t",*(i+address));
    }
return 0;
}