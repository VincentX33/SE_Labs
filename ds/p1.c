#include <stdio.h>

long factorial(int n){
	if (n <= 1)
			return 1;
	else 
		return (n* factorial(n-1));
}


int main(){
	
	int n=0;
	printf("Factorial program (for n up till 20)\n");
	while (n!=100){
	printf("Enter n:(100 to exit)");
	scanf("%d",&n);
	if (n==100)
		break;
	printf("Factorial of %d is :%ld\n",n,factorial(n)); 	
	}
	return 0;
}
