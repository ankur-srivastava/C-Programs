#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *l;
	struct tree *r;
}root;

void pre(struct tree *t);
void in(struct tree *t);
void post(struct tree *t);
int countLeaf(struct tree *t);

int main(){
	
	root.data = 5;
	root.l = NULL;
	root.r = NULL;
	
	struct tree n1 = {3, NULL, NULL};
	struct tree n2 = {4, NULL, NULL};
	
	root.l = &n1;
	root.r = &n2;
	
	printf("Print Tree using Pre Order \n");
	pre(&root);
	printf("\n");
	
	printf("Print Tree using In Order \n");
	in(&root);
	printf("\n");
	
	printf("Print Tree using Post Order \n");
	post(&root);
	printf("\n");
	
	printf("Number of Leaves %d \n", countLeaf(&root));
	printf("\n");
		
	return 0;
}

void pre(struct tree *t){
	if(t == NULL){
		return;
	}
	printf("%d ", t->data);
	pre(t->l);
	pre(t->r);
}

void in(struct tree *t){
	if(t == NULL){
		return;
	}
	in(t->l);
	printf("%d ", t->data);
	in(t->r);
}

void post(struct tree *t){
	if(t == NULL){
		return;
	}
	post(t->l);
	post(t->r);
	printf("%d ", t->data);
}

int countLeaf(struct tree *t){
	if(t->l == NULL && t->r == NULL){
		return 1;
	}
	else return (countLeaf(t->l) + countLeaf(t->r));
}