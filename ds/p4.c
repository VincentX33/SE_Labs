#include <stdio.h>

void ItoB(int n){
	int r,q;
	if (n==0)
		return ;
	else {
		r = n%2;
		q = n/2;
		if (q!=0)
			ItoB(q);
		printf("%d ",r);
	}
}
		
void ItoO(int n){
    int r,q;
    if (n==0)
            return ;
    else {
            r = n%8;
            q = n/8;
            if (q!=0)
                    ItoO(q);
            printf("%d ",r);
    }        
}
void ItoH(int n){
	char nums[] = {'0', '1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	int r,q;
	if (n==0)
		return;
	else {
		r = n%16;
		q = n/16;
		if (q!=0)
			ItoH(q);
		printf("%c",nums[r]);
	}
}

int main(){
	printf("Program for decimal to (binary/octal/hex) conversion\n");		
	int n = -1,q;
	char c = 'b';
	while (1){
		printf("\nEnter number to convert:(0 to exit): ");
		scanf("%d",&n);
		if (n==0)
			break;
		printf("Conversion system ? (2 for binary / 8 for octal / 16 for hexadecimal):");
		scanf("%d",&q);
		
		switch(q){
			case 2 :	ItoB(n);
						break;
			case 8 : 	ItoO(n);
						break;
			case 16: 	ItoH(n);
						break;
			default:	printf("Error: unknown system\n");
					break;
		}
	}
	return 0;
}
