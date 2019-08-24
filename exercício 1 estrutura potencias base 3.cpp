#include<stdio.h>
#include<math.h>

int main(){
	int i;
	int base =3;
	long result;
	
	printf("\n ----- potencias na base 3 ------- \n");
	
	for (i=0;i<=15;i++){
		
	result = pow(base,i);
	
	printf("\n 3 elevado a %i = %i\n",i,result);
	
	}
}
