#include <stdio.h>

int gcd(int a,int b){
	if (a<=0 || b<= 0)
		return 0;
	else if (a==b)
		return a;
	else if (a>b){
		gcd(a-b,b);
	}else 
		gcd(a,b-a);
}
int main(){
	int a,b;
	while (1){
		printf("Enter a and b (zeroes to exit):");
		scanf("%d%d",&a,&b);
		if (a==0 && b==0)
			break;
		printf("GCD of %d and %d is %d\n",a,b,gcd(a,b));
	}
	return 0;
}
