
//Lucas Ramos Amaral, Leidiane Santos dos Santos
#ifndef ORDENACAO_H
#define ORDENACAO_H
#include <iostream>
#include <ctime>
#include <cstdlib>

// Estrutura de dados para armazenar os dados de ordenação
struct DadosOrdenacao {
    int* vetor;
    int tamanho;
    int comparacoes;
    int trocas;
    double tempoExecucao;
};

// Funções de ordenação
void selectionSort(DadosOrdenacao& dados);
void quickSort(DadosOrdenacao& dados, int inicio, int fim);
void countingSort(DadosOrdenacao& dados);

// Funções auxiliares
void gerarVetorAleatorio(DadosOrdenacao& dados);
void gerarVetorDecrescente(DadosOrdenacao& dados);
void imprimirVetor(DadosOrdenacao& dados);

#endif // ORDENACAO_H