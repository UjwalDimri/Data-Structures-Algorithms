#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head = NULL;

void ins_beg();
void ins_end();
void del_beg();
void del_end();
void traverse1();
void traverse2();
void ins_pos();
void del_pos();

int main(){
	int choice, n;
	
	while(1){
		printf("\nenter the choice\n");
		printf("1. ins_beg\n2. ins_end\n3. del_beg\n4. del_end\n5. traverse1\n6. traverse2\n7. exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
					ins_beg();
					break;
			case 2:
					ins_end();
					break;
			case 3:
					del_beg();
					break;
					
			case 4:
					del_end();
					break;
			case 5:
					traverse1();
					break;
			case 6:
					traverse2();
					break;
			case 7:
			      ins_pos();
			case 8:
			      del_pos();
			default:
					exit(1);
		}
	}
}
	
	void ins_beg(){
		struct node *ptr = NULL;
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("enter the data\n");
		scanf("%d",&ptr->data);
		ptr->next = NULL;
		ptr->prev = NULL;

		if(head == NULL)
			head = ptr;
		else{
			head->prev = ptr;
			ptr->next = head;
			head = ptr;
		}
	}
	
	void ins_end(){
		struct node *temp = head;
		struct node *ptr = NULL;
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("enter the data\n");
		scanf("%d",&ptr->data);
		ptr->next = NULL;
		ptr->prev = NULL;

		if(head == NULL)
			head = ptr;
		else{
			while(temp->next!= NULL){
				temp = temp->next;
				ptr->prev = temp;
				temp->next = ptr;
			}
		}
	}
	
	void del_beg() {
		struct node *temp;

    		if(head == NULL) {
        		printf("no item to delete\n");
        		return;
    		}

    		temp = head;

		printf("Deleted : %d\n", head->data);

    		if(head->next == NULL) {        // only one node
			head = NULL;
    		} 
		else {
        		temp = head;
			head = head->next;
        		head->prev = NULL;
        		temp->next = NULL;
			}
		free(temp);
		temp = NULL;
		}

	void del_end() {
		    struct node *temp, *temp1;

    		if(head == NULL) {
        		printf("no item to delete\n");
        		return;
    		}
		temp = head;
		temp1 = head;

    		if(head->next == NULL) {          // only one node
        		printf("Deleted : %d\n", head->data);
        		head = NULL;
    		}
		else{
    			while(temp->next != NULL)
				temp = temp->next;
			while (temp1->next != temp)
				temp1 = temp1->next; 

    			printf("Deleted : %d\n", temp->data);
    			temp1->next = NULL;
    		}
		free(temp);
	}


	void traverse1(){
		struct node *temp = head;
		if(head == NULL){
			printf("No nodes to display");
			return;
			}

		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
	
	void traverse2(){
		struct node *temp = head;
		if(head == NULL){
                        printf("No nodes to display");
			return;
			}
		
		while(temp->next != NULL)
			temp = temp->next;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->prev;
			}
	}

	
	
