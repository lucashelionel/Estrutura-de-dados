#include<stdio.h>
// Tipo base dos elementos da lista SEQUENCIALLLLL
#define MAX 4
typedef struct elementos {
    char nome[50];
    //int num;
} t_elemento;

// Estrutura da pilha
typedef struct pilha {
    t_elemento vetor[MAX];
    int topo;
} t_pilha;
/**
 * Verifica se a pilha esta vazia ou nao.
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a pilha estiver vazia, ou falso (0) caso contrario.
 */
int isVazia(t_pilha * pilha) {
    return (pilha->topo == -1);
}
/**
 * Verifica se a pilha esta cheia ou nao.
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a pilha estiver cheia, ou falso (0) caso contrario.
 */
int isCheia(t_pilha * pilha) {
    return (pilha->topo == MAX-1);
}

/**
 * Inserir um novo elemento no topo da pilha (empilhar)
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 * @param dado  elemento a ser inserido na pilha
 *
 * @return Falso(0) se a posição for invalida ou se a pilha estiver cheia, caso contrario, retorna Verdadeiro(1)
 */
int inserir(t_pilha *pilha, t_elemento valor){
    if (isCheia(pilha))
        return 0; // erro

    pilha->vetor[++pilha->topo] = valor;

    return 1; // sucesso
}
/**
 * Remove o elemento do topo da pilha (desempilhar), retornando o elemento removido
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return Uma copia do elemento do topo.
 */
t_elemento remover(t_pilha * pilha){
    t_elemento vazio = { "" };

    if (isVazia(pilha))
        return vazio; // erro
    else
        return pilha->vetor[pilha->topo--];
}
/**
 * Cria uma nova pilha, aloca a sua regiao de memoria,
 * inicializa o topo, e retorna a pilha criada.
 * 
 * @return Pilha inicializada
 */
t_pilha criar() {
    t_pilha pilha;

    pilha.topo = -1;

    return pilha;
}
/**
 * Obter o elemento do topo da pilha (sem eliminar)
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return o elemento desejado, caso a posicao seja invalida retorna vazio.
 */    
t_elemento getElementoTopo(t_pilha * pilha){
    t_elemento vazio = { "" } ;

    if (isVazia(pilha))
        return vazio; // erro
    else
        return pilha->vetor[pilha->topo];
}

void mostrar(t_pilha * pilha){
  t_elemento * atual;
  int i;
  atual = pilha->vetor;

  for(i=0;i<pilha->topo;++i){
    printf("\t\t%s\n", atual->nome);
    //atual = atual->num;
  }
}
void verifica(t_pilha pilha){
	if(isVazia(&pilha)==1){
		printf("a pilha esta vazia\n");//verificando se esta vazia
	}
	if(isCheia(&pilha)==1){
		printf("a pilha esta cheia\n");//verificando se esta cheia
	}	
}

int main(){
	int i;
	t_pilha pilha1;
	pilha1 = criar();//criação da pilha
	verifica(pilha1);
	printf("escreva um nome:");
	scanf("%S",&pilha1.vetor[0].nome); // colocar um topo++ pq funciona como um contador
	if (inserir(&pilha1,pilha1.vetor[0])==1){
		printf("\nnome add com sucesso!!!\n");
		pilha1.topo++;
	}
	printf("escreva outro nome:");
	scanf("%S",&pilha1.vetor[1].nome);
	if (inserir(&pilha1,pilha1.vetor[1])==1){
		printf("\nnome add com sucesso!!!\n");
		pilha1.topo++;
	}
	printf("escreva mais um nome:");
	scanf("%S",&pilha1.vetor[2].nome);
	if (inserir(&pilha1,pilha1.vetor[2])==1){
		printf("\nnome add com sucesso!!!\n");
		pilha1.topo++;
	}
	printf("\n-----------mostrando pilha feita------------\n");
	for(i=0;i<pilha1.topo;i++){
	printf("%S\n",pilha1.vetor[i].nome);
	}
	printf("\n---pegando elemento do topo---\n");
	printf("%S\n\n",getElementoTopo(&pilha1));// retorna o topo da pilha
	
	printf("removendo elemento do topo...\n");
	remover(&pilha1);
	printf("TUDO PRONTO !!!\n");
	printf("\n---mostrando pilha restante---\n");
	for(i=0;i<pilha1.topo;i++){
	printf("%S\n",pilha1.vetor[i].nome);
	}
/*Criar uma pilha;---------
Testar se a pilha está vazia;----------
Testar se a pilha está cheia;----------
Obter o elemento do topo (sem eliminar);
Empilhar um novo elemento (push);
Desempilhar o elemento do topo (pop).
Exibir os elementos da pilha*/

}




