#include<stdio.h>
#include<math.h>

int main(){
	
	int i,b,e;
	long result;
	
	printf("informe a base da potencia: ");
	scanf("%i",&b);
	printf("informe o expoente da potencia: ");
	scanf("%i",&e);
	
	result = pow(b,e);
	
	printf(" \n---- resultado ----\n");
	printf(" \n %i elevado a %i = %i \n",b,e,result);	

	
}
