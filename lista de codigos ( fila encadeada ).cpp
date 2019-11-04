#include<stdio.h>
#include <stdlib.h>
// Tipo base dos elementos da lista 
typedef struct elementos {
    char nome[50];
} t_elemento;

typedef struct no {
    t_elemento dado;
    struct no * prox;
} t_no;

typedef struct fila {
    t_no* inicio;
    int quant_element;
    t_no* final;
} t_fila;
/**
 * Cria uma fila vazia, ou seja um no cabeca.
 * inicializa os ponteiros ini e fim para NULL,
 * e seta quant_element para zero.
 * 
 * @return no cabeca alocado e inicializado
 */
t_fila * criaCabeca (){
    t_fila * fila = (t_fila*) malloc(sizeof(t_fila));

    if (fila) {
        fila->inicio = fila->final = NULL;
        fila->quant_element=0;
    }

    return fila;
}
/**
 * Cria um novo no, aloca a sua regiao de memoria,
 * inicializa o ponteiro prox, e retorna o ponteiro para a pilha criada.
 * 
 * @return No alocada e inicializada
 */
t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    // verifica se houve memoria suficiente para alocar
    if (no)
        no->prox = NULL;

    return no;
}
/**
 * Verifica se a fila esta vazia ou nao. Isto so acontece quando ela eh nula
 * 
 * @param fila ponteiro para a fila
 *
 * @return Verdadeiro (1) se a fila estiver vazia, ou falso (0) caso contrario.
 */
int isVazia (t_fila * fila){
    return (fila->quant_element == 0);
}
/**
 * Insere um elemento (valor) no fim da fila.
 * 
 * @param fila ponteiro para a fila
 * @param valor  elemento a ser inserido na fila
 *
 * @return Falso(0) se a fila estiver cheia, caso contrario, retorna Verdadeiro(1).
 */
int inserir (t_fila *fila, t_elemento valor) {
    t_no *novo;
    novo = criaNo();
    if (novo == NULL)
        return 0; // Erro: memoria insuficiente
    novo->dado = valor;
    if (isVazia(fila))
        fila->inicio = novo;
    else
        (fila->final)->prox = novo;
    fila->final = novo;
    fila->quant_element++;
    return 1;
}
/**
 * Remove um elemento do inicio da fila.
 * 
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 *
 * @return o elemento removido.
 */
t_elemento remover (t_fila *fila){
    t_no *aux;
    t_elemento valor = { "" } ;
    if (isVazia(fila))
        return valor; // Erro: fila vazia 
    valor = (fila->inicio)->dado;
    if (fila->inicio == fila->final)
        fila->final = NULL;
    aux = fila->inicio;
    fila->inicio = (fila->inicio)->prox;
    free(aux);
    fila->quant_element--;
    return valor;
}
/**
 * Exibe todos os elementos da fila
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 */
 
//exibir
void exibirInfo(t_elemento info){
    printf("Nome:%s\n", info.nome);
}
void imprimirFila(t_fila *fila){
    if(fila->inicio == NULL){
        perror("Fila vazia");
    }else{
        t_no * aux = fila->inicio;
        do{
            exibirInfo(aux->dado);
            aux = aux->prox;
        }while(aux !=fila->inicio);
    }
}
int menu(){

    int opcao;

    printf("1 - Criar uma fila\n");
    printf("2 - Ver se a fila esta vazia\n");
    printf("3 - Inserir um elemento na fila\n");
    printf("4 - Remover um elemento da fila\n");
    printf("5 - exibir um elemento da fila\n");
    printf("6 - Esvaziar a fila\n");
    printf("Escolha uma opcao!: ");
    scanf("%d", &opcao);

    return opcao;
}
void apagartudo(t_fila * fila){
	fila->inicio = NULL;
	fila->final = NULL;
}
int main(){
	int controle;
    int aux;
    t_elemento valor1;
    t_fila * fila1 = criaCabeca();

    while(1){

        controle = menu();

        switch(controle){
            case 1:
				printf("\nfila criada com sucesso\n");
                break;
            case 2:
                if(isVazia(fila1) == 1){
                	printf("\nA fila esta vazia\n");	
				}else {
					printf("\na fila esta cheia\n");
			    }
                break;
            case 3:
                printf("digite um dado: "); 
				scanf("%s", &valor1.nome);
                aux = inserir(fila1, valor1);
                if(aux) printf("\nInserido com sucesso!\n");
                else {
                	printf("\nERROR !\n");
				}
                break;
            case 4:
                valor1 = remover(fila1);
                printf("O dado removido foi:%s\n",valor1.nome);
                break;
            case 5:
                imprimirFila(fila1);
                break;
            case 6:
				apagartudo(fila1);
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
