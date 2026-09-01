#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void receber_valores(int vetor[TAM]) {
    int i;
    for (i = 0; i < TAM; i++){
        printf("Digite um numero para a posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
}   

void inverter_valores(int vetor[TAM]) {
    // Maneira mais extensa de resolver o mesmo exercicio
    //int inicio = 0;
    //int fim = TAM - 1;   
    //int temp;
    /*for (inicio = 0, fim = TAM - 1; inicio < fim; inicio++, fim--){
        temp = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = temp;
    }*/
   // Maneira simplificada de resolver o exercicio
   for (int i = TAM - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
   }
   printf("\n");
}

void imprimir_vetor(int vetor[TAM]) {
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
}

int main () {
    int vetor[TAM];

    receber_valores(vetor);
    printf("antes de inverter: ");

    imprimir_vetor(vetor);
    printf("\ndepois de inverter: ");

    inverter_valores(vetor);
    return 0;

}