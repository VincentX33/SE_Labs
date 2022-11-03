#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkList.h"


/*
Develop a menu driven C program to do the following recursively:
1. Base conversion
2. Tower Hanoi
3. Greatest Common Divisor
4. Reverse a string
5. Search an item in a linked list.
*/
void baseConv(int n, int base){
	char nums[] = {
  '0', '1','2','3','4','5',
  '6','7','8','9','a','b',
  'c','d','e','f','g','h',
  'i','j','k','l','m','n'
  };
	int r,q;
	if (n==0)
		return;
	else {
		r = n%base;
		q = n/base;
		if (q!=0)
			baseConv(q,base);
		printf("%c",nums[r]);
	}
}
void tofh(int n, char source, char temp, char dest){
	//base case when n is zero:
	if (n == 0){
		return;
	}
	tofh(n-1, source, dest,temp);
	printf("Move disk %d from %c to %c\n", n, source, dest);
	tofh(n-1,temp, source, dest);
}
int gcd(int a,int b){
	if (a==0 || b==0){
		return 0;
	}
	if (b>a){
		int temp = a;
		a = b;
		b = temp;
	}
	if (a%b){
		return gcd(b,a%b);
	}else{
		return b;
	}
}
void revStr(char * dest, char * source){
	//if empty string ie \0
	if (*source == '\0'){
		return;
	}
	revStr(dest,source+1);
	char x[2];
	x[0] =  *source;
	x[1] = '\0';
	strcat(dest,x);
}
struct node * searchInList(struct node * start,int val){
	//if null (base case) return 0
	if (start == NULL){
		return NULL;
	}else if (start->value == val ) {
		return start;
	}else {
		return searchInList(start->next,val);
	}
}
int main(){
	char * baseStr = (char *)malloc(sizeof(char)*100);
	char * rev = (char *)malloc(sizeof(char)*100);
	
	int c, num,base,n1,n2,n;
	char c1,c2,c3;
	printf("Creation of demo linked list:\n");
	struct node * list = NULL;
	struct node * result = NULL;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	createList(&list,n);
	printf("\n----Recursive programs gallery-----\n");
	do {
		printf("Enter");
		printf("\n 1 to perform base conversion:");
		printf("\n 2 to print tower of hanoi moves:");
		printf("\n 3 to find gcd of two numbers:");
		printf("\n 4 to reverse given string:");
		printf("\n 5 to search an item in linked list:");
		printf("\n 6 to exit:\n\t:");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("Enter base to convert to: ");
				scanf("%d", &base);
				printf("Enter number to convert: ");
				scanf("%d", &num);
				baseConv(num,base);
				printf("\n");
				break;
			case 2:
				printf("Enter number of disks to move:");
				scanf("%d", &num);
				getchar();
				printf("Enter source, destination and temp pillar names:");
				scanf("%c %c %c", &c1, &c2, &c3);
				tofh(num,c1,c2,c3);
				break;
			case 3:
				printf("Enter two numbers:");
				scanf("%d %d",&n1,&n2);
				printf("GCD of %d and %d is %d\n",n1,n2,gcd(n1,n2));
				break;
			case 4:
				//reverse a string
				getchar();
				printf("Enter string to reverse:");
				gets(baseStr);
				strcpy(rev,"");
				revStr(rev,baseStr);
				printf("The reversed string is:%s\n",rev);
				break;
			case 5:
				//search item in linked list
				//assume we have created demo linked list at beginning
				printf("Enter item to be searched in linked list:");
				scanf("%d",&num);
				result = searchInList(list,num);
				if (result)
					printf("Item %d found @ %x\n",3,result);
				else
					printf("Item not found\n");
				break;
			case 6:
				break;
			default:
				printf("Invalid input\n");
		}
	}while(c!=6);
  return 0;
}