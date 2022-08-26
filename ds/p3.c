#include <stdio.h>

int sumDigit(long int n){
	if (n<0)
		return 0;
	else if (n<10)
		return n;
	else 
		return (n%10 + sumDigit(n/10));	
}

int main(){
	printf("Summation of digit of number\n");
	long int n=0;
 	do {
		printf("\nEnter n (0 to exit):");
		scanf("%ld", &n);
		printf("Sum of digits of  %ld is %d",n,sumDigit(n)); 
	}while(n!=0);
	return 0;
}
