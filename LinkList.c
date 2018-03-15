#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
} *head;

void insert(int item);
void traverse();
void recursiveTraverse(struct node *t);
void reverse();
void addAtEnd(int item);
void delete(int item);

int main(){
	int u[3];
	struct node n1 = {2, NULL};
	head = &n1;

	printf("Enter the first number \n");
	scanf("%d", &u[0]);
	insert(u[0]);
	printf("Enter the second number \n");
	scanf("%d", &u[1]);
	insert(u[1]);

	printf("Printing the List \n");
	traverse();
	//recursiveTraverse(head);	

	printf("\nPrint the List in Reverse \n");
	reverse();
	traverse();
	
	printf("Test Delete \n");
	delete(2);
	
	printf("Printing the List \n");
	traverse();
	
	printf("\n");
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
	while(t != NULL){
		printf("%d ", t->data);
		t = t->next;
	}
}

void recursiveTraverse(struct node *t){
	if(t == NULL){
		return;
	}else{
		printf("%d ", t->data);
		recursiveTraverse(t->next);
	}
}

void reverse(){
	struct node *prev = head;
	struct node *cur = prev->next;
	struct node *n = cur->next;
	
	prev->next = NULL;
	
	while(cur != NULL){
		cur->next = prev;
		prev = cur;
		cur = n;
		if(n != NULL && n->next != NULL){
			n = n->next;
		}else{
			n = NULL;
		}
	}
	head = prev;
}

void addAtEnd(int item){
	struct node *t = head;
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = item;
	newNode->next = NULL;
	while(t != NULL){
		if(t->next == NULL){
			t->next = newNode;
			break;
		}
		t = t->next;
	}
}

void delete(int item){
	struct node *t = head;
	if(t->data == item){
		printf("Node to be deleted is the first one\n");
		head = t->next;	
	}else{
	while(t != NULL){
		if(item == t->next->data){
			printf("Item found\n");
			t->next = t->next->next;
			break;
		}
		t = t->next;
	}
	}
}