#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
} *head;

void insert(int item);
void traverse();

int main(){
	int u[3];
	struct node n1 = {2, NULL};
	
	head = &n1;

	printf("Enter a number \n");
	scanf("%d", &u[0]);
	insert(u[0]);
	printf("Enter a number \n");
	scanf("%d", &u[1]);
	insert(u[1]);

	n1.next = head;
	traverse();

	return 0;	
}

void insert(int item){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->next = head;
	head = temp;	
}
void traverse(){
	struct node *t = head;
	int data = t->data;
	while(1){
		printf("%d ", t->data);
		if(t->next->data == data){
			break;
		}
		t = t->next;
	}
}	