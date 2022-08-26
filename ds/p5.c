#include <stdio.h>

double expFloat(double a,int n){
	if (n==0)
		return 1;
	else
		return (a*expFloat(a,n-1));
}

int main(){
	
	double a;
	int n=0;
	printf("Float exponentiation program for positive exponent\n");

	do {
		printf("Enter the float:");
		scanf("%lf",&a);
		printf("Enter the exponent (0 to exit):");
		scanf("%d",&n);
		printf("%lf ^ %d is %lf\n",a,n,expFloat(a,n));
	}while(n>0);	
	return 0;
}
