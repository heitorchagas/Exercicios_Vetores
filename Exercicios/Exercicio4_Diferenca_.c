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

/*Aqui fiz a diferença entre A e B. Utilizando uma flag chamada valor_encontrado
é possível fazer a verificação. Se valor_encontrado for igual a 1, é cortada a execução
e parte para a próxima. Se for igual a 0, significa que o valor no indice [k] do Vetor A
não existe no Vetor B, adicionando no vetor_diferena[], e incrementando na contagem contador*/

int fazer_diferenca(int TAMa, int TAMb, int VETORa[TAMa], int VETORb[TAMb], int vetor_diferenca[], int contador) {
    int valor_encontrado = 0;
    for (int k = 0; k < TAMa; k++) {
        for (int l = 0; l < TAMb; l++) {
           if (VETORa[k] == VETORb[l]) {
            valor_encontrado = 1;
            break;
           }
        } 
        if (valor_encontrado == 0) {
            vetor_diferenca[contador] = VETORa[k];
            contador++;
        }
    return contador;
    }
}
// aqui imprime o vetor_diferenca[] 
void imprimir_diferenca(int vetor_diferenca[], int diferenca) {
    for (int u = 0; u < diferenca; u++) {
        printf("%d ", vetor_diferenca[u]);
    } 
}

int main (){

    // primeiro, define como inteiro as funções
    int TAMa = definir_tamA();
    int TAMb = definir_tamB();

    // depois, define como inteiro os vetores A e B, a Diferenca entre eles, e a contagem da quantidade de elementos em vetor_diferenca[], começando em 0
    int VETORa[TAMa];
    int VETORb[TAMb];
    // fiz isso apenas para não ultrapassar o limite de elementos em cada um, colocando a soma deles como teto
    int vetor_diferenca[TAMa + TAMb]; 
    int contador = 0;

    // executa as funções void, passando os parametros junto
    receberVetorA(TAMa, VETORa);
    receberVetorB(TAMb, VETORb);

    /* aqui guarda a função fazer_diferenca() na variável diferenca, ja que ela retorna *contador*
    assim podendo ser usada pra verificar quantos elementos contém dentro de vetor_diferenca[]
    */

    int diferenca = fazer_diferenca(TAMa, TAMb, VETORa, VETORb, vetor_diferenca, contador);
    printf("A diferenca entre A e B eh igual a: ");
    imprimir_diferenca(vetor_diferenca, diferenca);
    printf("\n");
    return 0;
}