#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    
};
struct node *head = NULL;
struct node *temp = NULL;

void insert_begining(struct node*);
void insert_end(struct node*);
void del_begining();
void del_end();
void traverse();
void insert_pos(struct node*,int);
void deletion_pos(int);
int main(){
    int x = 1;
   while(1){
   struct node *new1;
    printf("Enter 1 for Insert At The Begining \n Enter 2 For Insert At The End \n Enter 3 For Deletion At The Begining \n Enter 4 For Deletion At The End \n Enter 5 To Travese \n Enter 6 To insert at a position \n Enter 7 to Delete at a position ");
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
            break;
        case 5 :
            traverse();
            break;
        case 6 :
             int n1;
             printf("Enter postion to insert :");
             scanf("%d",&n1);
             new1 = (struct node*)malloc(sizeof(struct node));
             scanf("%d",&new1->data);
             insert_pos(new1,n1);
             break;
        case 7 :
             int n2;
             printf("Enter position for deletion:");
             scanf("%d",&n2);
             deletion_pos(n2);
             break;
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
            return;
        }
        if (head->next == NULL) {   // only one node
        free(head);
        head = NULL;
        return;
        }

        else {
        while(temp->next!=NULL){
            temp=temp->next;
        }
        while (temp1->next!=temp){
            temp1=temp1->next;
        }
       temp1->next=NULL;
       
       }
       free(temp);
       temp=NULL;
}
void traverse(){
    if(head == NULL){
        printf("Nothing To Traverse ");
        return;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void insert_pos(struct node* new1,int n){
       if (n<1){
         printf("Enter valid number");
       }
       else if (n==1){
          new1->next=head;
          head = new1;  
       }
       else if (n>1){
         temp = head ;
         for(int i = 1;i<n-1;i++){
              if (temp==NULL){
                printf("NO NODES");
                return ;
              }
              temp=temp->next;
         }

         new1->next=temp->next;
         temp->next=new1;

       }
}
void deletion_pos(int n){
    if(n<1){
        printf("Invalid input ");
    }
    else if (n==1){
        temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
        return ;
    }
    else if (n>1){
        struct node *ptr ;
        temp = head;
        ptr = NULL;
        for(int i = 1;i<n;i++){
            ptr=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf("Position not found");
            return;
        }
        ptr->next=temp->next;
        free(temp);
    }
  
}