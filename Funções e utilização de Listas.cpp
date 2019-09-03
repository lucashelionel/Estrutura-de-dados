#include<stdio.h>
#include<string.h>
#define MAX 10

typedef struct elementos{
	char nome[40];
}t_elemento;

typedef struct lista{
	t_elemento vetor[MAX];
	int n;
}t_lista;
/**************************************************************************************************************************************************/
/**
 * Cria uma nova lista, inicializa o n, e retorna o registro.
 * 
 * @return Lista inicializada
 */

t_lista criar() {		                    
    t_lista lista;        

    lista.n = -1;

    return lista;
}
/**
 * Verifica se a lista esta vazia ou nao.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a lista estiver vazia, ou falso (0) caso contrario.
 */
int isVazia(t_lista * lista) {
    return (lista->n == -1);
}
/**
 * Verifica se a lista esta cheia ou nao.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a lista estiver cheia, ou falso (0) caso contrario.
 */
int isCheia(t_lista * lista) {
    return (lista->n == MAX-1);
}
/**
 * Obtem o tamanho atual da lista, nao o tamanho maximo.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @return o quantidade de elementos que estao na lista.
 */
int getTamanho(t_lista * lista) {
    return lista->n + 1;
}
/**
 * Obtem um elemento da lista especificado por pos.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 * @param pos   posicao do elemento desejado
 *
 * @return ponteiro para o elemento desejado, caso a posicao seja invalida retorna 0.
 */
t_elemento * getElemento(t_lista * lista, int pos) {
    // verifica se pos eh valida
    if ( (pos > lista->n) || (pos < 0) )
        return 0;

    return &(lista->vetor[pos]);
}
/**
 * Obtem a posicao de um elemento, a partir de seu valor.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 * @param dado  t_elemento a ser buscado na lista
 *
 * @return a posicao do elemento, ou -1 se o elemento nao estiver na lista.
 */
 int compara(t_elemento dado1, t_elemento dado2) {
    return strcmp(dado1.nome, dado2.nome);
}
int getPosicao(t_lista * lista, t_elemento dado) {
    int i;
    for (i=0; i<=lista->n; i++)
        if (compara(lista->vetor[i], dado)==0)
            return i;
    return -1;
}
/**
 * Desloca os elementos da lista para a direita a partir de pos
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 * @param pos   posicao do elemento, a partir do qual sera iniciado o deslocamento.
 *
 * @return Falso(0) se a posi��o for invalida ou se a lista estiver cheia, caso contrario, retorna Verdadeiro(1).
 */
int deslocaDireita(t_lista * lista, int pos) {
    int i;

    for (i=lista->n + 1; i>pos; i--){
	
        lista->vetor[i] = lista->vetor[i-1];
	}
    return 1;
}
/**
 * Insere um elemento (dado) em determinada posicao da lista.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 * @param pos   posicao do elemento, a partir do qual sera iniciado o deslocamento.
 * @param dado  elemento a ser inserido
 *
 * @return Falso(0) se a posi��o for invalida ou se a lista estiver cheia, caso contrario, retorna Verdadeiro(1).
 */
 
int inserir (t_lista * lista, int pos, t_elemento dado) {
    if ( isCheia(lista) || (pos > lista->n + 1) || (pos < 0) )
        return 0;

    deslocaDireita(lista, pos);
    lista->vetor[pos] = dado;
    (lista->n)++;
    return 1;
}

/**
 * Desloca os elementos da lista para a esquerda a partir de pos
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 * @param pos   posicao do elemento, a partir do qual sera iniciado o deslocamento.
 *
 * @return 0 se a posi��o for invalida ou se a lista estiver cheia, caso contrario, retorna 1.
 */
int deslocaEsquerda(t_lista * lista, int pos) {
    int i;

    for (i=pos; i<(lista->n); i++)
        lista->vetor[i] = lista->vetor[i+1];

    return 1;
}
/**
 * Remove um elemento de determinada posicao da lista.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 * @param pos   posicao do elemento, a partir do qual sera iniciado o deslocamento.
 *
 * @return Falso(0) se a posi��o for invalida ou se a lista estiver cheia, caso contrario, retorna Verdadeiro(1).
 */
int remover (t_lista *lista, int pos) {
    if ( (pos > lista->n) || (pos < 0) )
        return 0;

    deslocaEsquerda(lista, pos);

    (lista->n)--;
    return 1;
}
/*int mostraLista(t_elemento * lista){
	//t_elemento lista;
	int i;
	for(i=0; i<= lista->n; i++){
		printf("%s",lista->vetor[i].nome);
	}
}*/
/************************************************** EXEMPLO ******************************************************************/
int main(){
	t_lista lista1;
	lista1.n = -1;
	int i;
	
	for(i=0;i<=2;i++){
		printf("digite um nome:");
		scanf("%s ",&lista1.vetor[i].nome);
		lista1.n = i;
	}
	printf("\nlista adicionada e:");
	for(i=0; i<= lista1.n; i++){
		printf("%s ",lista1.vetor[i].nome);
	}
	
	printf("\nsegundo nome buscado:");
	printf("%s ",getElemento(&lista1,1));
	remover (&lista1,0);
	
	printf("\nnova lista:");
	for(i=0; i<= lista1.n; i++){
		printf("%s ",lista1.vetor[i].nome);
	}
}
















