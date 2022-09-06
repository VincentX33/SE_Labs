#include <stdio.h>
 
int fib(int n){
	int a;
	if (n==1||n==2){
		return 1;
	}
	else {
		a = (fib(n-1) + fib (n-2));
		return a;
	}
}
int fibs[40]= {0,1};


int main(){
	for (int i = 2;i<40;i++)
		fibs[i] = fibs[i-1]+fibs[i-2];

	printf("Fibonacci series for n terms\n");
	for (int i = 0;i<40;i++)
		printf("%d ",fibs[i]);
	return 0;	
}
