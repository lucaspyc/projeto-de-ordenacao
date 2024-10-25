//Lucas Ramos Amaral, Leidiane Santos dos Santos
#include <iostream>
#include "ordenacao.h"
using namespace std; 

int main() {
    int tamanho;
    cout << "Escolha o tamanho do vetor (10, 100, 1000, 10000): ";
    cin >> tamanho;

    DadosOrdenacao dados;
    dados.tamanho = tamanho;
    dados.vetor = new int[tamanho];

    int opcao;
    cout << "Escolha a disposição dos valores (1 - Aleatório, 2 - Decrescente): ";
    cin >> opcao;
    if (opcao == 1) {
        gerarVetorAleatorio(dados);
    } else if (opcao == 2) {
        gerarVetorDecrescente(dados);
    }

    cout << "Vetor original: ";
    imprimirVetor(dados);

    int escolhaAlgoritmo;
    cout << "Escolha o algoritmo de ordenação (1 - Selectionsort, 2 - Quicksort, 3 - Counting Sort): ";
    cin >> escolhaAlgoritmo;

    clock_t inicio = clock();
    if (escolhaAlgoritmo == 1) {
        selectionSort(dados);
    } else if (escolhaAlgoritmo == 2) {
        quickSort(dados, 0, dados.tamanho - 1);
    } else if (escolhaAlgoritmo == 3) {
        countingSort(dados);
    }
    clock_t fim = clock();

    dados.tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    cout << "Vetor ordenado: ";
    imprimirVetor(dados);
    cout << "Tempo de execução: " << dados.tempoExecucao << " segundos" << endl;
    cout << "Número de comparações: " << dados.comparacoes << endl;
    cout << "Número de trocas: " << dados.trocas << endl;

    delete[] dados.vetor;
    return 0;
}