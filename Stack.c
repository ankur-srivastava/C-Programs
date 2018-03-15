#include<stdio.h>
#include<stdlib.h>

int stack[10];
int top = -1;

void push(int item);
void pop();
void display();

int main(){
	push(4);
	push(5);
	display();
	pop();
	display();
	return 0;
}

void push(int item){
	top++;
	stack[top] = item;
	printf("Added %d to Stack \n", item);
}
void pop(){
	printf("Element being popped is %d \n",stack[top]);
	top--;
}
void display(){
	printf("Stack looks like ");
	for(int i=top; i>=0; i--){
		printf("%d ", stack[i]);
	}
	printf("\n");
}
