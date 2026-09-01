# include <stdio.h>
# include <stdlib.h>
# define TAM 10

void receber_vetor(int vetor[TAM]) {
    for (int i=0; i<TAM; i++) {
        printf("Digite o %d° numero inteiro do vetor: ", i+1);
        scanf("%d", &vetor[i]);
    }
    printf("\n");
}

int verificar_quantidade_diferentes(int vetor[TAM], int contador, int vetor_diferentes[TAM]) {
    for (int j=0; j<TAM; j++) {
    int existe_igual = 0;
        for (int l=0; l<j;l++) {
            if (vetor[j] == vetor[l]) {
                existe_igual = 1;
                break;
            }
        }
        if (existe_igual == 0) {
            vetor_diferentes[j] = vetor[j];
            contador++;
        }
    }
    return contador;
}

void imprimir_vetor(int vetor[TAM], int vetor_diferentes[TAM], int numeros_diferentes) {
    printf("Os valores diferentes encontrador foram: ");
    for (int c=0; c<numeros_diferentes; c++) {
        printf("%d ", vetor_diferentes[c]);
    }
}

int main() {
    int vetor_diferentes[TAM];
    int vetor[TAM];
    int contador = 0;

    receber_vetor(vetor);
    int numeros_diferentes = verificar_quantidade_diferentes(vetor, contador, vetor_diferentes);
    imprimir_vetor(vetor, vetor_diferentes, numeros_diferentes);
    printf("\nForam encontrados %d valores diferentes", numeros_diferentes);
    printf("\n\n");
    return 0;
}