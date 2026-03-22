// Memory Optimization

#include<stdio.h>
struct node {
    int data;
    struct node *next;
};
int main (){
    struct node n1,n2;
    n1.data=100;
    n1.next=NULL;

    n2.data=200;
    n2.next=NULL;

    n1.next=&n2;
    printf("%d",n1.next -> data);

    return 0;
}