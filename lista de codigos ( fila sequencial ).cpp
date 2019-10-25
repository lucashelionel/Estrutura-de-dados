#include<stdio.h>
// tamanho maximo da fila
#define MAX 5

// Tipo base dos elementos da fila 
typedef struct elementos {
    char nome[50];	
} t_elemento;

typedef struct fila {
    t_elemento vetor[MAX]; // vetor que armazena a fila
    int inicio; // posicao do primeiro elemento
    int fim;    // posicao do ultimo elemento
    int quant_element;    // numero de elementos da fila
} t_fila;
/**
 * Cria uma nova fila, aloca a sua regiao de memoria,
 * inicializa o inicio, fim e a quantidade de elementos.
 * Por fim, retorna a fila criada.
 *
 * @return Fila inicializada
 */
t_fila criar(){
    t_fila fila;

    fila.inicio = 0;
    fila.fim = -1;
    fila.quant_element = 0;


    return fila;
}
/**
 * Verifica se a fila esta vazia ou nao.
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a fila estiver vazia, ou falso (0) caso contrario.
 */
int isVazia (t_fila * fila){
    return (fila->quant_element == 0);
}

/**
 * Verifica se a fila esta cheia ou nao.
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a fila estiver cheia, ou falso (0) caso contrario.
 */
int isCheia(t_fila * fila){
    return (fila->quant_element == MAX);
}
/**
 * Insere um elemento (valor) no final da fila.
 * 
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 * @param valor elemento a ser inserido na fila
 *
 * @return Falso(0) se a fila estiver cheia, caso contrario, retorna Verdadeiro(1)
 */
int inserir (t_fila * fila, t_elemento valor){
    if (isCheia(fila))
        return 0;

    (fila->quant_element)++;
    fila->fim = (fila->fim + 1) % MAX;
    fila->vetor[fila->fim] = valor;
    return 1;
}
/**
 * Remove um elemento do inicio da fila.
 * 
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 *
 * @return o elemento removido.
 */
t_elemento remover(t_fila * fila){
    t_elemento valor = { "" } ;
    if (isVazia(fila))
        return valor; // Erro: fila vazia

    valor = fila->vetor[fila->inicio];
    fila->vetor[fila->inicio].nome[0] = '\0';// zera, opcional
    (fila->quant_element)--;
    fila->inicio = (fila->inicio + 1) % MAX;
    return valor;
}
/**
 * Exibe todos os elementos da fila
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 */
void exibir(t_fila * fila) {
    int i;
    if (isVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }

    printf("\nExibindo fila:\n");
    printf("inicio: %d\n", fila->inicio);
    printf("fim:    %d\n", fila->fim);
    for (i=0 ; i<MAX ; i++) {
        printf("%d::%s\n", i, fila->vetor[i].nome);
    }
}
/**
 * Exibe todos os elementos da fila
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 */
void mostraFila(t_fila * fila){
	int i;
     if (isVazia(fila)) {
     	printf("Fila vazia\n");
	return;
     }
     for (i = fila->inicio; i != fila->fim + 1; i = (i + 1) % MAX)
         printf("%d\t", fila->vetor[i]);
}

int main(){
	
	return 0;
}
