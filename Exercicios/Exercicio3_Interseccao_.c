#include <stdio.h>
#include <stdlib.h>

// definir o tamanho do Vetor A
int definir_tamA() {
    int TAMa;
    printf("Digite um numero para o tamanho do vetor A: ");
    scanf("%d", &TAMa); 
    return TAMa;
}   
// definir o tamanho do Vetor B
int definir_tamB() {
    int TAMb;
    printf("Digite um numero para o tamanho do vetor B: ");
    scanf("%d", &TAMb);
    return TAMb;
}

// aqui recebe os valores para o Vetor A
void receberVetorA(int TAMa, int VETORa[TAMa]) {
    for (int i = 0; i < TAMa; i++) {
        printf("Digite o %d° numero para o vetor A: ", i+1);
        scanf("%d", &VETORa[i]);
    }
}

// aqui recebe os valores para o Vetor B
void receberVetorB(int TAMb, int VETORb[TAMb]) {
    for (int j = 0; j < TAMb; j++) {
        printf("Digite o %d° numero para o vetor B: ", j+1);
        scanf("%d", &VETORb[j]);
    }
}

/* aqui é feito a intersecção dos valores entre A e B, armazenando em vetor_interseccao[]
    é a contagem de quantos valores tem dentro de vetor_interseccao[] */

int fazer_intersec(int TAMa, int TAMb, int VETORa[TAMa], int VETORb[TAMb], int vetor_interseccao[], int contador) {
    for (int k = 0; k < TAMa; k++) {
        for (int l = 0; l < TAMb; l++) {
            if (VETORa[k] == VETORb[l]) {
                vetor_interseccao[contador] = VETORa[k];
                contador++;
                break;
            } 
        }
    }
    return contador;
}

// aqui imprime o vetor_interseccao[] 
void imprimir_intersec(int vetor_interseccao[], int intersec) {
    for (int u = 0; u < intersec; u++) {
        printf("%d ", vetor_interseccao[u]);
    } 
}

int main (){

    // primeiro, define como inteiro as funções
    int TAMa = definir_tamA();
    int TAMb = definir_tamB();

    // depois, define como inteiro os vetores A e B, a interseccao entre eles, e a contagem da quantidade de elementos em vetor_interseccao[], começando em 0
    int VETORa[TAMa];
    int VETORb[TAMb];
    int vetor_interseccao[TAMa + TAMb]; 
    int contador = 0;
    
    // executa as funções void, passando os parametros junto
    receberVetorA(TAMa, VETORa);
    receberVetorB(TAMb, VETORb);

    /* aqui guarda a função fazer_intersec() na variável intersec, ja que ela retorna *contador*
    assim podendo ser usada pra verificar quantos elementos contém dentro de vetor_interseccao[]
    */

    int intersec = fazer_intersec(TAMa, TAMb, VETORa, VETORb, vetor_interseccao, contador);
    printf("A interseccao entre A e B eh igual a: ");
    imprimir_intersec(vetor_interseccao, intersec);
    printf("\n");
    return 0;
}