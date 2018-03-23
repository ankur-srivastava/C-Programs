#include<stdio.h>
#include<stdlib.h>

/*
	Author: @ankur
	Date: March 23, 2018
	Version: 0.1
	This Program demonstrates the Queue Data Structure.  
*/

struct qnode{
	int d;
	char *info;
	struct qnode *next;
}*f,*r;

void eq();
void dq();
void traverseQ();

int main(){
	printf("Let's insert elements to Q - A,B,C \n");
	eq(0, "A");
	eq(1, "B");
	eq(2, "C");
	traverseQ();
	dq();
	traverseQ();
	return 0;
}

void eq(int data, char *info){
	struct qnode *new = (struct qnode *)malloc(sizeof(struct qnode));
	new->d = data;
	new->info = info;
	new->next = NULL;
	
	struct qnode *tempf = f;
	struct qnode *tempr = r;
	
	if(f == NULL){
		f = new;
		r = new;
	}else if(f->next == NULL){
		f->next = new;
		new->next = NULL;
		r = new;
	}else{
		tempr->next = new;
		new->next = NULL;
		r = new;
	}
	printf("ENQ done for node %s\n", info);
}

void dq(){
	if(f != NULL){
		struct qnode *temp = f;
		printf("Going to Deque %s \n",temp->info);
		f = f->next;
		free(temp);
	}else{
		printf("Q is empty \n");
	}
}

int qsize(){
	int count = 0;
	if(f != NULL){
		f = f->next;
		count++;
	}
	return count;
}

void traverseQ(){
	printf("Q looks like - ");
	struct qnode *temp = f;
	while(temp != NULL){
		printf("%s ", temp->info);
		temp = temp->next;
	}
	printf("\n");
}