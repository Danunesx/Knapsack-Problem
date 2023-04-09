/// MOCHILA BINÁRIA
/*
Aluno: Daniel Pereira Nunes
Universidade Federal do Espírito Santo
Engenharia da Computação

Knapsack problem.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int TAM = 5;
const int PESO_MAX = 15;

int verificaPeso(int *peso, int *mochila){
    int pesoTotal = 0;

    for(int i = 0; i < TAM; i++){
        if(mochila[i] == 1){
            pesoTotal = pesoTotal + peso[i];
        }
    }
    return pesoTotal;
}

int verificaValor(int *valor, int *mochila){
    int valorTotal = 0;

    for(int i = 0; i < TAM; i++){
        if(mochila[i] == 1){
            valorTotal = valorTotal + valor[i];
        }
    }
    return valorTotal;
}

void Solucao(int *valor, int *peso, int *solucao){
    int j = 0;
    int *mochila = calloc(TAM, sizeof(int));
    int pesoTotal, valorTotal;
    int pesoAtual = 0, valorAtual = 0;

    while(j != (int)pow(2,TAM)){
        for(int i = 0; i < TAM; i++){
            if((j == (int)pow(2,i)) || (j % (int)pow(2,i)) == 0){
                if(mochila[i] == 0) mochila[i] = 1;
                else mochila[i] = 0;
            }
        }

        pesoTotal = verificaPeso(peso, mochila);
        valorTotal = verificaValor(valor, mochila);

        if(pesoTotal <= PESO_MAX) {
            if((pesoTotal > pesoAtual) && (valorTotal > valorAtual)){
                pesoAtual = pesoTotal;
                valorAtual = valorTotal;
                for(int i = 0; i < TAM; i++){
                    solucao[i] = mochila[i];
                }

            }
        }
        j++;
    }
}

int main(){
    int valor[5] = {4, 2, 10, 1, 2};
    int peso[5] = {12, 1, 4, 1, 2};
    int *solucao = calloc(TAM, sizeof(int));
    int melhorValor, melhorPeso;

    Solucao(valor, peso, solucao);
    melhorValor = verificaValor(valor, solucao);
    melhorPeso = verificaPeso(peso, solucao);

    printf("Vetor Solucao: ");
    for(int i = 0; i < TAM; i++){
        printf("%d ", solucao[i]);
    }

    printf("\nMelhor valor: %d", melhorValor);
    printf("\nMelhor peso: %d\n", melhorPeso);

    return 0;
}
