#include<stdio.h>
#include<stdlib.h>
#include<mm_malloc.h>
struct node {
    int data;
    struct node *next;
    
};
struct node *head = NULL;
struct node *temp = NULL;

void menu();
void insert_begining(struct node*);
void insert_end(struct node*);
void del_begining();
void del_end();
void traverse();

int main(){
    int x = 1;
   while(1){
   struct node *new1;
    printf("Enter 1 for Insert At The Begining \n Enter 2 For Insert At The End \n Enter 3 For Deletion At The Begining \n Enter 4 For Deletion At The End \n Enter 5 To Travese");
    int n;
    
    scanf("%d",&n);
    
    switch (n) {
        case 1 : 
            new1 = (struct node*)malloc(sizeof(struct node));
            scanf("%d",&new1->data);
            new1->next=NULL;
            insert_begining(new1);
            break;

        case 2 :
            new1 = (struct node*)malloc(sizeof(struct node));
            scanf("%d",&new1->data);
            new1->next=NULL;
             insert_end(new1);
            break;
        case 3 :
            del_begining();
            break;
        case 4 :
            del_end();
        case 5 :
            traverse();
        default :
            printf("Enter a valid Input");

    }
}
}
void insert_begining(struct node* new1){
    if(head==NULL){
        head=new1;
        return;
    }
    new1->next=head;
    head=new1;
}
void insert_end(struct node* new1){
    if(head==NULL){
        head=new1;
    }
    else{
        temp=head;
         while(temp->next!=NULL){
            temp = temp->next;
         }
         temp->next=new1;
    }
}
void del_begining(){
    if (head==NULL){
        printf("No Nodes To Delete");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
}
void del_end(){
    temp = head;
    struct node *temp1;
    temp1=head;
    if (head==NULL){
        printf("NO Nodes To Delete");
    }
        else {
        while(temp->next!=NULL){
            temp=temp->next;
        }
        while (temp1!=temp){
            temp1=temp1->next;
        }
       temp1->next=NULL;

    }
}
void traverse(){
    if(head == NULL){
        printf("Nothing To Traverse ");
    }
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}