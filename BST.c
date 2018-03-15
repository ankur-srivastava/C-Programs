#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *l;
	struct node *r;
}root;

void insert(struct node *new, struct node *t);
void in(struct node *t);
void delete(int data);
struct node *find_node(int data, struct node *t);

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
	printf("Let's delete the Node with value 30 \n");
	//Delete functionality has not been implemented completely. The basic idea has been coded.
	//delete(30);
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

//Basic Idea has been presented here. Swap function needs to be implemented.
void delete(int data){
	struct node *del_node = find_node(data, &root);
	if(del_node != NULL){
		if(del_node->l == NULL && del_node->r == NULL){
			//delete
			printf("Leaf Node \n");
		}else if(del_node->l != NULL){
			//delete
			printf("Find Max from LST of %d \n", del_node->data);
			//struct node *min = findMin(del_node);
			//swap(del_node, min);
		}else if(del_node->r != NULL){
			//delete
			printf("Find Min from RST of %d \n", del_node->data);
			//struct node *max = findMax(del_node);
			//swap(del_node, max);
		}
		
	}
}

struct node *find_node(int data, struct node *t){
	if(data == t->data){
		return t;
	}else{
		if(data < t->data){
			return find_node(data, t->l);
		}else if(data > t->data){
			return find_node(data, t->r);
		}else{
			printf("Node not found \n");
			return 0;
		}
	}
}
