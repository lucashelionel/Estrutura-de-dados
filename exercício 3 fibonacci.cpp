#include<stdio.h>

int main(){
	int i;
	int result;
	int a=0,b=1;
	
	printf("\n ----serie de fibonacci---- \n");
	
	printf("\n %i \n",1);
	
	for(i=0;i<15;i++){
		
		result = a + b;
		a = b;
		b = result; 
		
		printf("\n %i \n",result);
	}
}
