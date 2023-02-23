#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
};
struct node *start=NULL, *end=NULL;

void creating_circular_list()
{
	struct node *temp, *ptr;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data in the node:");
	scanf("%d", &temp->data);
	temp->next = NULL;
	
	if(start == NULL)
	{
		start = temp;
		end = temp;
	}
	else
	{
		end->next = temp;
		end = temp;
		end->next = start;
	}
	
}

void insertingBegining()
{
	struct node *temp, *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value in the node to insert at begining\n");
	scanf("%d", &ptr->data);
	ptr->next = NULL;
	
	ptr->next = start;
	start = ptr;
	end->next = start;
	//printf("srikant mf");
	
}
void insertingEnd()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data in a node to insert at End of Circular linked list\n");
	scanf("%d", &ptr->data);

	end->next = ptr;
	end = ptr;
	end->next = start;
}

void insertAtSpecificPosition()
{
	struct node *ptr, *temp;
	int pos;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the specific location to enter\n");
	scanf("%d", &pos);
	if(pos == 1)
	{
		insertingBegining();
	}
	else
	{
		printf("Enter the data in the node to insert at specific location");
	scanf("%d", &ptr->data);
	temp = start;
	
	for(int i = 0; i < pos-2; i++)
	{
		
		temp = temp->next;
	}
	ptr->next = temp->next;
	temp->next = ptr;
	}
		
}

void Display()
{
	struct node *temp, *ptr;
	temp = start;
	printf("data in Circular Linked list is : \n");
	while(temp->next != start)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}


void deletionAtBegining()
{
	struct node *temp;
	temp = start;
	start = temp->next;
	end->next = start;
	free(temp);
}

void deletionAtEnd()
{
	struct node *temp;
	temp = start;
	while(temp->next != end)
	{
		temp = temp->next;
	}
	free(temp->next);
	end = temp;
	end->next = start;
	
}

void deletionAtSpecificLocation()
{
	struct node *temp, *ptr;
	temp = start;
	int pos;
	printf("Enter the position in circular linked list to delete the node\n");
	scanf("%d", &pos);
	if(pos == 1)
	{
		deletionAtBegining();
	}
	else
		{
			for(int i = 0; i < pos-2; i++)
			{
				temp = temp->next;
			}
			ptr = temp->next;
			temp->next = temp->next->next;
			free(ptr);
		}
}

int main(){
	int num_nodes;
	printf("Hi Srikanth....How many nodes Circular List Do you want ?");
	scanf("%d",&num_nodes);
	for(int i = 0; i < num_nodes; i++){
		
		creating_circular_list();
	}
	printf("\nCircular LinkedList is created\n");
	
	
	while(1){
		printf("Choose the options to perform any of the actions on circular linked list\n");
	printf("\n1.Display\n 2.Inserting node at begining\n 3.Inserting at specific location\n 4.Inserting at end\n 5.delete at begining\n 6.delete at specific position\n 7.delete at end\n");
	
		int choice;
	scanf("%d", &choice);
	char yn;
	switch(choice)
	{
		case 1:
		printf("Your selected option is to Display Circular linked list data elements\n");
		Display();
		break;
		
		case 2:
		printf("Your selected option is to insert node at begining\n");
		insertingBegining();
		break;
		
		case 3:
		printf("Your selected option is to insert node at specific location\n");
		insertAtSpecificPosition();
		break;
		
		case 4:
		printf("Your selected option is to insert node at end\n");
		insertingEnd();
		break;
		
		case 5:
		printf("Your selected option is to delete node at begining\n");
		deletionAtBegining();
		break;
		
		case 6:
		printf("Your selected option is to delete node at specific location\n");
		deletionAtSpecificLocation();
		break;
		
		case 7:
		printf("Your selected option is to delete node at End\n");
		deletionAtEnd();
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
