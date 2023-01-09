#include<stdio.h>
#include<stdlib.h>

int main(){

	printf("Array Insertion and Deletion of element at specific positions\n");
	int a[11], pos;
	
	for(int i = 0; i < 10; i++){
		
		a[i] = i + 1;
		
	}
	printf("Here Array size is 10 only. So, please select index within 1 - 10 !!!!\n");
	for(int i = 0; i < 10; i++){
		
		printf("Array Element at %d index is %d\n", i, a[i]);
		
	}
	printf("Enter the index to insert element at that index");
	scanf("%d", &pos);
	
	for(int i = 10 - 1; i >= (pos - 1); i--){
		
		a[i + 1] = a[i];
		
	}
	a[pos] = 99;
	
	for(int i = 0; i < 11; i++){
		
		printf("Array Element at %d index is %d\n",i, a[i]);
		
	}
	
	printf("Deletion of element at specified position\n");
	
	int position;
	printf("Enter the index position to to delete element at that position\n");
	scanf("%d", &position);
	
	for(int i = position; i < 11; i++){
		
			a[i] = a[i + 1];
		
	}
	
	printf("Updated array after deletion\n");
	
	for(int i = 0; i < 11; i++){
		
		printf("Array elemnt at %d index is %d\n", i, a[i]);
	}
	return 0;
}