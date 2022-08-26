#include <stdio.h>

long summation(int n)
{
	if (n == 0)
		return 0;
	else 
		return (n+summation(n-1));
}
int main(){

	int n=1;
	printf("Summation Of N\n");
	while (n!=0){
		printf("Enter n (0 to exit):");
		scanf("%d",&n);
		if (n > 145000){
			printf("Beyond computation of program\n");
			continue;
		}
		printf("Summation of %d numbers is %ld\n",n,summation(n));
	}
	return 0;
}
