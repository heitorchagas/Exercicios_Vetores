#include <stdio.h>
#include <stdlib.h>


int definir_TAMvA () {
    int TAMvA;
    printf("Digite um numero para definir o tamanho do vetor A: ");
    scanf("%d", &TAMvA);
    
    return TAMvA;
} 

int definir_TAMvB () {
    int TAMvB;
    printf("Digite um numero para definir o tamanho do vetor B: ");
    scanf("%d", &TAMvB);

    return TAMvB;
}

void receber_valoresVA(int TAMvA, int VETORa[TAMvA]) {
    for (int i = 0; i < TAMvA; i++) {
        printf("Digite o %d° numero do vetor A: ", i+1);
        scanf("%d", &VETORa[i]);
    }
}

void receber_valoresVB(int TAMvB, int VETORb[TAMvB]) {
    for (int j = 0; j < TAMvB; j++) {
        printf("Digite o %d numero do vetor B: ", j+1);
        scanf("%d", &VETORb[j]); 
    }   
}

int fazer_uniao(int TAMvA, int TAMvB, int VETORa[TAMvA], int VETORb[TAMvB], int contador, int uniao_feita[]) {
    for (int k = 0; k < TAMvA; k++) {
        uniao_feita[contador] = VETORa[k];
        contador++;
    }
    for (int l = 0; l < TAMvB; l++) {
        int existe_na_uniao = 0;
        for (int h = 0; h < contador; h++) {
            if (VETORb[l] == uniao_feita[h]) {
                existe_na_uniao = 1;
                break;
            }
        }
        if (existe_na_uniao == 0) {
            uniao_feita[contador] = VETORb[l];
            contador++;
        }
    }
    return contador;
}

void imprimir_uniao(int uniao_feita[], int uniao) {
    for (int u = 0; u < uniao; u++) {
        printf("%d ", uniao_feita[u]);   
    }

}

int main() {
    int TAMvA = definir_TAMvA();
    int TAMvB = definir_TAMvB();
    int VETORa[TAMvA];
    int VETORb[TAMvB];

    receber_valoresVA(TAMvA, VETORa);
    receber_valoresVB(TAMvB, VETORb);

    int uniao_feita[TAMvA + TAMvB];
    int contador = 0;

    int uniao = fazer_uniao(TAMvA, TAMvB, VETORa, VETORb, contador, uniao_feita);
    printf("A uniao entre A e B eh igual a: ");
    imprimir_uniao(uniao_feita, uniao);
    printf("\n");
    return 0;
}