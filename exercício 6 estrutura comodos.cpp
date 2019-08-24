#include<stdio.h>

struct REGISTRO{
	char nome[30];
	int largura;
	int comprimento;
	
};

int main(){
	struct REGISTRO regi;
	int area;
	int per = 1;
	
	while(per == 1){
		
	printf("informe o nome do comodo:");
	scanf("%s",regi.nome);
	printf("informe o comprimento do comodo:");
	scanf("%i",&regi.largura);
	printf("informe a largura do comodo:");
	scanf("%i",&regi.comprimento);
	
	area = regi.comprimento * regi.largura;
	
	printf("\n os resultados sao \n");
	printf("o nome do comodo e: %s\n",regi.nome);	
	printf("area do comodo: %d \n",area);
	
	
	printf("\n deseja continuar 1 == sim // 2== nao:\n");
	scanf("%i",&per);
}
		
}
