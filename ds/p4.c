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

int main(){
	printf("Program for decimal to (binary/octal/hex) conversion\n");		
	int n = -1;
	char c = 'b';
	while (n!=0){
		printf("\nEnter number to convert to binary:");
		scanf("%d",&n);
		/*
		printf("Conversion system ? (b for binary / o for octal):");

		scanf("%c",&c);
		*/
		switch(c){
			case 'b':	ItoB(n);
					break;
			case 'o':	ItoO(n);
					break;
			default:	printf("Error: unknown system\n");
					break;
		}
	}
	return 0;
}
