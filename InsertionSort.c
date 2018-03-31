#include<stdio.h>

/*
	@author Ankur
	date March 31, 2018
	Simple C Program to illustrate insertion Sort
*/

void printList(int input[], int size);

int main(){
	/*Assume the following list of numbers that needs to be sorted*/
	int input[] = {4,3,5,2,1,6};
	int size = sizeof(input) / sizeof(input[0]);
	printList(input, size);
	printf("Perform Insertion Sort \n");
	
	/*This loop performs Insertion Sort*/
	for(int i=1;i<size;i++){
		int number = input[i];
		int k = i;
		for(int j=(i-1);j>=0;j--){
			if(number < input[j]){
				input[j+1] = input[j];
				k=j;
			}
		}
		if(k != i){
			input[k] = number;
		}
	}
	
	printList(input, size);
	
	return 0;
}

void printList(int *p, int size){
	printf("Print the List \n");
	for(int i = 0;i<size;i++){
		printf("%d ",*p);
		p++;
	}
	printf("\n");
}