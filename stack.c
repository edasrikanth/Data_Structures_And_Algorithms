#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    
    int capacity;
    int* array;
    int top;
} stack_t;

stack_t* stack = NULL;

void push(int ele){
    
    if(stack->top == stack->capacity - 1)
        printf("stack is FULL\n");
    else{
        stack->top++;
        stack->array[stack->top] = ele;
    }
    
}

int pop(){
    
    if(stack->top == -1)
    {
        printf("stack is EMPTY\n");
        return -1;
    }
    int ele;
    ele = stack->array[stack->top];
    printf("Poped element from stack is %d\n", ele);
    stack->top--;
    
    return ele;
}

void traverse(){
    
    if(stack->top == -1)
        printf("stack is empty to print the elements\n");
    else{
        printf("all the stack elements are : \n");
        for(int i = 0; i <= stack->top; i++){
            printf("%d\n", stack->array[i]);
        }
        
    }
    
}
void IsEmpty(){
    
    if(stack->top == - 1)
        printf("Stack is Empty\n");
    else{
        printf("Stack is not empty\n");
    }
}


void IsFull(){
    
    if(stack->top == stack->capacity - 1)
        printf("stack is FULL\n");
    else{
        printf("stack is not yet full\n");
    }
}

int main(){
    
    stack = (stack_t*)malloc(sizeof(stack_t));
    printf("Enter the size of stack\n");
    scanf("%d", &stack->capacity);
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    stack->top = -1;
    
    while(1){
    printf("Pls select your desired option\n");
    printf("\n 1.Push\n 2.pop\n 3.traverse\n 4.IsEmpty\n 5.IsFull\n 6.Exit\n");
    int choice;
    scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Pls Enter the value to push in to the stack\n");
            int ele1;
            scanf("%d", &ele1);
            push(ele1);
            break;
            
            case 2:
            printf("You have selected POP operatrion\n");
            int ele2;
            ele2 = pop();
            printf("poped element from stack is %d\n", ele2);
            break;
            
            case 3:
            printf("You have selected stack Traversal operation\n");
            traverse();
            break;
            
            case 4:
            printf("You have selected IsEmpty option\n");
            IsEmpty();
            break;
            
            case 5:
            printf("You have selected IsFull option\n");
            IsFull();
            break;
            
            case 6:
            printf("You have selected EXIT option\n");
            break;
            
            default:
            printf("Your selected option is NOT valid.. Pls select correct option\n");
            break;
            
        }
    }
    return 0;
}