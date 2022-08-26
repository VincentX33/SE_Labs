#include <stdio.h>
 
void fib(int n){
	if (n==1||n==2){
		printf("%d ",1);
		return 1;
	else {
		printf("%d ", 
		return (fib(n-1) + fib (n-2));
	}
}

int main(){
	
	printf("Fibonacci series for n terms\n");
	return 0;	
}
