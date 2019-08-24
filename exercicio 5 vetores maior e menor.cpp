#include <stdio.h>
#include <stdlib.h>
int main(){
    int a, maior=0, menor=0;
    float vet[5];

    printf("digite 5 numeros");
    printf("\n");
    for (a=0;a<5;a++){
      printf("valor (%d): ", a+1);
      scanf("%f", &vet[a]);
      if(a==0){maior=vet[a];menor=vet[a];}
      if(vet[a]>maior){
        maior=Notas[a];
      }
      else{
        if(Notas[a]<menor){
            menor=vet[a];
        }
      }
    }
    printf("\no maior valor e %d\n", maior);
    printf("\ne o menor valor e %d\n\n", menor);
    return 0;
}
