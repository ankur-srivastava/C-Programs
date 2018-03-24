#include<stdio.h>
#include<stdlib.h>

/*
	Author: @ankur
	Date: March 24, 2018
	Version: 0.1
	This Program illustrates Breadth First Traversal.  
*/

#define MAXV 6 /* maximum number of vertices */
#define VISITED 1

/*Structure for Vertex*/
struct node{
	int label; /*data*/
	char *name; /*data*/
	int status;	
	struct node *next; /*Pointer to next node*/
};

struct qnode{
	int d;
	char *info;
	struct qnode *next;
}*f,*r;

struct node vertices[MAXV];
char *names[MAXV];

void addToList(struct node *x, int data);
void traverseGraph();
void initNames();
void displayNames();
void BFS();
/*Queue Specific*/
void eq(int data);
int dq();
void traverseQ();
int qsize();

int main(){
	/*Initialize Names*/
	initNames();
	displayNames();
	
	/*Initialize the Array*/
	for(int i=0;i<MAXV;i++){
		vertices[i].label = i;
		vertices[i].name = names[i];
		vertices[i].next = NULL;
	}
	/*
		Say we have the following Edges {(0,1), (0,2), (1,2)}
		Let's build the Adjacency List.
	*/
	
	addToList(&vertices[0], 1);
	addToList(&vertices[0], 3);
	addToList(&vertices[1], 2);
	addToList(&vertices[1], 0);
	addToList(&vertices[1], 4);
	addToList(&vertices[2], 1);
	addToList(&vertices[3], 0);
	addToList(&vertices[3], 5);
	addToList(&vertices[4], 1);
	
	/*Traverse the Adjacency List*/
	traverseGraph();
	/*Breadth First Traversal*/
	BFS();
	return 0;
}

/*Here we are trying to add an edge x->y*/
void addToList(struct node *x, int data){
	printf("Going to Add %d to the Vertex %d \n", data, x->label);
	struct node *y = (struct node *)(malloc(sizeof(struct node)));
	if(y!=NULL){
		y->label = data;
		y->name = names[data];
		if(x->next != NULL)
			y->next = x->next;
		else
			y->next = NULL;
		
		x->next = y;
	}
}

void traverseGraph(){
	printf("\nLet's see who all are Friends \n\n");
	for(int i=0;i<MAXV;i++){
		struct node *temp = &vertices[i];
		printf("%s is friend to --> ", temp->name);
		if(temp->next != NULL){
			temp = temp->next;
			while(temp != NULL){
				printf("%s", temp->name);
				if(temp->next != NULL)
					printf(", ");
				temp = temp->next;
			}			
		}
		printf("\n\n---------------------------------------------\n\n");
	}
}

void initNames(){
	names[0] = "Ankur";
	names[1] = "Dikshit";
	names[2] = "Mohan";
	names[3] = "Nidhi";
	names[4] = "Reena";
	names[5] = "Suresh";
}

void displayNames(){
	printf("\nWe have the following folks staying in a small town \n\n");
	for(int i=0;i<MAXV;i++){
		printf("%s ", names[i]);
	}
	printf("\n\n---------------------------------------------\n\n");
}

void BFS(){
		printf("\n\n-------------------BFS Traversal-------------------\n\n");
		struct node *qn =  &vertices[0];
		int tempData;		
		eq(qn->label);
		while(qsize() != 0){
			tempData = dq();
			if(tempData != 999)
				qn = &vertices[tempData];
			else
				qn = NULL;
			if(qn && qn->status != VISITED){
				qn->status = VISITED;
				printf("Visited %s\n", qn->name);	
				if(qn->next != NULL){
					/*for each vetrex adjacent to v do BFS*/
					qn = qn->next;
					while(qn != NULL){
						eq(qn->label);
						qn = qn->next;
					}
				}				
			}	
		}
		printf("\n");
}

/*Queue Methods*/

void eq(int data){
	struct qnode *new = (struct qnode *)malloc(sizeof(struct qnode));
	new->d = data;
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
}

int dq(){
	int data = 999;
	if(f && f->d != 999){
		data = f->d;
		f = f->next;
	}else{
		printf("Q is empty \n");
	}
	return data;
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

int qsize(){
	int count = 0;
	if(f != NULL){
		struct qnode *temp = f;
		while(temp != NULL){
			temp = temp->next;
			count++;
		}
		temp = NULL;			
	}
	return count;
}