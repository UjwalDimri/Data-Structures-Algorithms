// Problem: Count Nodes in Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
int main(){
    int n , i=0 ,count=0;
    scanf("%d",&n);
    while(i<n){
        struct node *new1;
        new1=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new1->data);
        if(head==NULL){
            head=new1;
        }
        else{
            struct node *temp = head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new1;
        }
        i++;
    }
    struct node *temp1 = head;
    while(temp1!=NULL){
        count++;
        temp1=temp1->next;
    }
    printf("%d",count);
}