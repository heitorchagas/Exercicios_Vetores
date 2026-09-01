#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void preencher_vetor(int n, int vetor[n]) {
    for (int i = 0; i < n; i++) {
            printf("Digite o numero para a posicao [%d]: ", i);
            scanf("%d", &vetor[i]);
        }
}

bool verificar_ordem(int n, int vetor[n]){
    for (int l = 0; l < n-1; l++){
        if (vetor[l] > vetor[l+1]){
            return false;
        }
    }
    return true;
}

void imprimir_vetor(bool resultado, int n, int vetor[n]) {
    printf("\n A matriz ficou desta forma:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", vetor[j]);
    } if (resultado == false) {
        printf("\nNao ordenado\n");
    } else if (resultado == true) {
        printf("\nEsta ordenado\n");
    }
}

int main () {
    int vetor[5];
    preencher_vetor(5, vetor);
    bool resultado = verificar_ordem(5, vetor);
    imprimir_vetor(resultado, 5, vetor);
    
    return 0;
}