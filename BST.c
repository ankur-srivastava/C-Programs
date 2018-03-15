#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *l;
	struct node *r;
}root;

void insert(struct node *new, struct node *t);
void in(struct node *t);

int main(){
	int a[] = {30, 25, 42, 10, 50};
	int size = sizeof(a)/sizeof(a[0]);
	printf("We have %d elements \n", size);
	struct node root = {a[0], NULL, NULL};
	//Construct BST
	printf("Let's create BST \n");
	for(int i=1;i<size;i++){
		struct node *n = (struct node *)malloc(sizeof(struct node));
		n->data = a[i];
		n->l = NULL;
		n->r = NULL;
		printf("Insert %d \n",a[i]);
		insert(n, &root);
	}
	
	printf("Inorder Traversal of BST gives ");
	in(&root);
	printf("\n");
	return 0;
}

void insert(struct node *new, struct node *t){
	if(new->data < t->data){
		if(t->l == NULL){
			t->l = new;
			return;
		}else{
			insert(new, t->l);	
		}
	}
	if(new->data > t->data){
		if(t->r == NULL){
			t->r = new;
			return;
		}else{
			insert(new, t->r);	
		}
	}
}

void in(struct node *t){
	if(t == NULL){
		return;
	}
	in(t->l);
	printf("%d ", t->data);
	in(t->r);
}