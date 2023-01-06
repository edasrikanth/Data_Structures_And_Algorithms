#include <stdio.h>
#include <stdlib.h>

struct node
{
        int data;
        struct node *next;
};
struct node *start=NULL;

void creating_node(){
	struct node *temp, *ptr;
	
	temp = (struct node*)malloc(sizeof(struct node));

	printf("Enter data in node:");
	scanf("%d", &temp->data);
	temp->next = NULL;
	
	if(start == NULL){
		start = temp;
		}
		else{
			ptr = start;
			while(ptr->next != NULL){
				
				ptr = ptr->next;
			}
			ptr->next = temp;
		}
	
}

void Display(){
	printf("elements in LinkedList are:");
	struct node *ptr;
	if(start == NULL){
		printf("Linked List is empty");
	}
	else{
		ptr = start;
		
		while(ptr->next != NULL){
			printf("%d\n", ptr->data);
			ptr = ptr->next;
		}
		printf("%d\n",ptr->data);
	}
}

void Insert_begin(){
	printf("creating node to insert at beginning\n");

	struct node *temp, *ptr;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Node is created... \nEnter data in the node:\n");
	scanf("%d", &temp->data);
	temp->next = NULL;
	if(start->next != NULL){
	ptr = start;
	temp->next = ptr;
	start = temp;
	}
	
}

void Insert_end(){
	printf("creating node to insert at end of Linked List\n");
	
	struct node *temp, *ptr;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Node is created...\n Enter the data in the node: \n");
	scanf("%d", &temp->data);
	temp->next = NULL;
	ptr = start;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = temp;
	
}

void Insert_Any_Pos(){
	
	printf("Insert at any position\n");
	printf("creating node to insert at any position\n");

	struct node *temp, *ptr, *dum;
	int pos;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Node is created...\n Enter data in the node\n");
	scanf("%d", &temp->data);
	temp->next = NULL;
	printf("enter the position to insert the node\n");
	scanf("%d", &pos);
	ptr = start;
	if(ptr->next != NULL){
		for(int idx = 0; idx < pos-1; idx++){
			dum = ptr;
			ptr = ptr->next;
		}
		temp->next = ptr;
		dum->next = temp;
	}
	
}

void Delete_node_beginning(){
	
	printf("deleting node at the beginning\n");
	struct node *ptr;
	
	if(start->next == NULL){
		printf("There is only one element in LinkedList that is also deleting\n");
		ptr = start;
		printf("deleting data in the node is %d\n", ptr->data);
		free(ptr);
	}
	else{
		ptr = start;
		start = start->next;
		printf("data in the deleting node is %d\n",  ptr->data);
		free(ptr);
	}
	
}

void Delete_node_ending(){
	
	printf("deleting node at the ending\n");
	struct node *ptr, *dum;
	if(start->next == NULL){
		printf("Its a single node LinkedList\n");
		ptr = start;
		free(ptr);		
	}
	else{
		ptr = start;
		while(ptr->next != NULL){
			dum = ptr;
			ptr = ptr->next;	
		}
		dum->next = NULL;
		printf("Data in the deleting node is %d\n", ptr->data);
		free(ptr);
	}
	
}

void Delete_node_any_pos(){
	
	printf("Deleting node at any desired position\n");
	struct node *ptr, *dum;
	int posi;
	printf("Enter the position to delete node\n");
	scanf("%d", &posi);
	ptr = start;
	for(int j = 0; j < posi-1; j++){
		dum = ptr;
		ptr = ptr->next;
	}
	dum->next = ptr->next;
	printf("data in deleting node is %d\n", ptr->data);
	free(ptr);
	
}

void Reversing_LinkedList(){
	struct node *current, *next, *prev;
	current = start;
	prev = NULL;
	next = NULL;
	
	while(current->next != NULL){							
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	current->next = prev;
	start = current;
	printf("Linked List is Successfully Reversed!!!!\n");
	
}
int main(){
	int num_nodes, i = 0;
	char ch;
	printf("Hello Srikanth.. How many nodes do you want to create ??");
	scanf("%d",&num_nodes);
	
	while(i != num_nodes){
		creating_node();
		i++;
	}
	printf("Nodes are created\n");
	
	int itr = 1;
	while(1){
	int choice;
	printf("Enter you choice :\n");
	printf(" 1.Dispaly\n 2.Insert_begin\n 3.Insert_end\n 4.Insert_any_pos\n 5.Delete_node_beginning\n 6.Delete_node_ending\n 7.Delete_node_any_pos\n");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
		printf("Displaying LinkedList Data\n");
		Display();
		break;
		
		case 2:
		printf("Selected Option is to insert at begining of list\n");
		Insert_begin();
		break;
		
		case 3:
		printf("Selected Option is to insert at end of list\n");
		Insert_end();
		break;
		
		case 4:
		printf("Selected Option is to insert at any desired position\n");
		Insert_Any_Pos();
		break;
		
		case 5:
		printf("Selected Option is to delete node in the beginning of LinkedList\n");
		Delete_node_beginning();
		break;
		
		case 6:
		printf("Selected Option is to delete node in the ending of LinkedList\n");
		Delete_node_ending();
		break;
		
		case 7:
		printf("Seleted option is to delete node at any desired position in the LinkedList\n");
		Delete_node_any_pos();
		break;
		
		case 8:
		printf("Selected option is to reverse the LinkedList\n");
		Reversing_LinkedList();
		break;
		
		default:
		itr = 0;
		printf("Invalid input\n");
	}
	if(itr == 0){
		break;
	}
}


	return 0;
}