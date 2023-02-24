#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *start = NULL, *end = NULL;

void creating_double_linkedList()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	
	printf("\nEnter the data in the node for Double linked list:");
	scanf("%d", &temp->data);
	temp->prev = NULL;
	temp->next = NULL;
	
	if(start == NULL)
	{
		start = temp;
		end = temp;
	}
	else
	{
		end->next = temp;
		temp->prev = end;
		end = temp;
	}
}



void InsertBegining()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data in the node to insert at the begining\n");
	scanf("%d", &temp->data);
	if(start == NULL)
	{
		start = temp;
		end = temp;
	}
	else
	{
		temp->next = start;
		start->prev = temp;
		start = temp;
	}
}


void InsertEnd()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data in the node to insert at the end\n");
	scanf("%d", &temp->data);
	if(start == NULL && end == NULL)
	{
		start = temp;
		end = temp;
	}else
	{
		end->next = temp;
		temp->prev = end;
		end = temp;
	}
}

void InserAtSpecificLocation()
{
	struct node *temp, *ptr;
	int pos;
	ptr = start;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the location in the double linked list to insert the node\n");
	scanf("%d", &pos);
	
	printf("Enter the data in the node to insert at specified location\n");
	scanf("%d", &temp->data);
	for(int i = 0; i < pos-2; i++)
	{
		ptr = ptr->next;
	}
	temp->next = ptr->next;
	ptr->next->prev = temp;
	temp->prev = ptr;
	ptr->next = temp;
	
}

void DeleteBegining()
{
	struct node *temp;
	temp = start;
	start = temp->next;
	start->prev = NULL;
	free(temp);
}

void DeleteEnd()
{
	struct node *temp;
	temp = end;
	end = temp->prev;
	end->next = NULL;
	free(temp);
}

void DeleteAtSpecificLocation()
{
	struct node *temp, *ptr;
	temp = start;
	printf("Enter the node location in double linked list to delete\n");
	int pos;
	scanf("%d", &pos);
	for(int i = 0; i < pos-2; i++)
	{
		temp = temp->next;
	}
	ptr = temp->next;
	temp->next = temp->next->next;
	temp->next->next->prev = temp;
	free(ptr);
}

void Display()
{
	struct node *temp;
	temp = start;
	printf("Data in the double linked list is :\n");
	while(temp->next != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}


int  main()
{
	int num_nodes;
	printf("Hi Srikanth....How many nodes in Double Linked List Do you want ?");
	scanf("%d",&num_nodes);
	for(int i = 0; i < num_nodes; i++){
		
		creating_double_linkedList();
	}
	printf("\n Double LinkedList is created\n");
	
	
	while(1)
	{
		printf("Choose the options to perform any of the actions on double linked list\n");
	printf("\n1.Display\n 2.Inserting node at begining\n 3.Inserting at specific location\n 4.Inserting at end\n 5.delete at begining\n 6.delete at specific position\n 7.delete at end\n");
	
	
	int choice;
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		printf("Your selected option is to Display double linked list data elements\n");
		Display();
		break;
		
		case 2:
		printf("Your selected option is to insert node at begining\n");
		InsertBegining();
		break;
		
		case 3:
		printf("Your selected option is to insert node at specific location\n");
		InserAtSpecificLocation();
		break;
		
		case 4:
		printf("Your selected option is to insert node at end\n");
		InsertEnd();
		break;
		
		case 5:
		printf("Your selected option is to delete node at begining\n");
		DeleteBegining();
		break;
		
		case 6:
		printf("Your selected option is to delete node at specific location\n");
		DeleteAtSpecificLocation();
		break;
		
		case 7:
		printf("Your selected option is to delete node at End\n");
		DeleteEnd();
		break;
		
		default :
		printf("Your selected option is not valid\n");
		printf("Please select valid option (or) do you want to exit ? Then press Ctrl + c or else \n");
		break;
		//exit(0);
		}
	}
	
	return 0;
}