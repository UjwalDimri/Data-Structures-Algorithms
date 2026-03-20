#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max];
int top = -1;
void push(int);
void pop();
void traverse();

int main(){
    while(1){
        int choice;
        printf("\n1.Push\n2.Pop\n3.Traverse\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter a element to be inserted:");
                int a;
                scanf("%d",&a);
                push(a);
                break;
            case 2:
                 pop();
                 break;
            case 3 :
                 traverse();
                 break;
            default:
                 printf("Invalid")
        }
        printf("1 for continue 0 for exit for return ");
        scanf("%d",&choice);
        if (choice==0){
            return ;
        }
    }
}
void push(int a){
    if (top == max-1){
         printf("Stack Overflow");
         return ;
    }
    top++;
    stack[top]=a;
}
void pop() {
    if(top==-1){
        printf("Stack Empty");
        return;
    }
    printf("%d",stack[top]);
    top--;
}
void traverse(){
    if (top == -1){
        printf("No element to traverse");
        return ;
    }
    int temp = top;
    for(int i =top;i>=0;i--){
    printf("%d",stack[temp-1]);
    temp--;
    }
}