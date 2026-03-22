// create an array and display its elements
// create first program using pointers
// Access question number 2 with differnt names
// Implement ques 2 using function    
// in function pass name of an aaray as a parameter 
// and display its elemnent in its body 
#include<stdio.h>
int printarray (int*,int);
int main(){
int arr[] = {1,2,3,4,5};
for (int i = 0; i < 5; i++){
     printf("%d\t",arr[i]);
}
printf("\n");
int *ptr;
ptr = arr;
for (int i = 0; i < 5; i++)
{
    printf("%d\t",*(ptr+i));
}
int n;
printf("Enter Number Of Element Do you Want to insert in the array:\t");
scanf("%d",&n);
int arr2[n];
printarray(arr2,n);
return 0;
}
int printarray(int *nameOfArray,int noOfElement){
    int *ptr;
    ptr = nameOfArray;
    for(int j = 0;j<noOfElement;j++){
        scanf("%d",ptr+j);
    }
    for(int i = 0; i < noOfElement; i++){
        printf("%d\t",*(ptr+i));
    }
return 0;
}