//Lucas Ramos Amaral, Leidiane Santos dos Santos
#include "ordenacao.h"
using namespace std;

// Função de ordenação Selectionsort
void selectionSort(DadosOrdenacao& dados) {
    int i, j, min;
    for (i = 0; i < dados.tamanho - 1; i++) {
        min = i;
        for (j = i + 1; j < dados.tamanho; j++) {
            dados.comparacoes++;
            if (dados.vetor[j] < dados.vetor[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(dados.vetor[i], dados.vetor[min]);
            dados.trocas++;
        }
    }
}

// Função de ordenação Quicksort
void quickSort(DadosOrdenacao& dados, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = dados.vetor[inicio];
        int i = inicio + 1;
        int j = fim;
        while (i <= j) {
            while (i <= j && dados.vetor[i] <= pivo) {
                i++;
                dados.comparacoes++;
            }
            while (i <= j && dados.vetor[j] > pivo) {
                j--;
                dados.comparacoes++;
            }
            if (i <= j) {
                swap(dados.vetor[i], dados.vetor[j]);
                dados.trocas++;
            }
        }
        swap(dados.vetor[inicio], dados.vetor[j]);
        dados.trocas++;
        quickSort(dados, inicio, j - 1);
        quickSort(dados, j + 1, fim);
    }
}

// Função de ordenação Counting Sort
void countingSort(DadosOrdenacao& dados) {
    int max = dados.vetor[0];
    int min = dados.vetor[0];
    for (int i = 1; i < dados.tamanho; i++) {
        if (dados.vetor[i] > max) {
            max = dados.vetor[i];
        } else if (dados.vetor[i] < min) {
            min = dados.vetor[i];
        }
    }
    int range = max - min + 1;
    int* count = new int[range];
    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < dados.tamanho; i++) {
        count[dados.vetor[i] - min]++;
        dados.comparacoes++;
    }
    int j = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            dados.vetor[j] = i + min;
            j++;
            count[i]--;
            dados.trocas++;
        }
    }
    delete[] count;
}

// Função para gerar um vetor aleatório
void gerarVetorAleatorio(DadosOrdenacao& dados) {
    srand(time(0));
    for (int i = 0; i < dados.tamanho; i++) {
        dados.vetor[i] = rand() % 1000;
    }
}

// Função para gerar um vetor decrescente
void gerarVetorDecrescente(DadosOrdenacao& dados) {
    for (int i = 0; i < dados.tamanho; i++) {
        dados.vetor[i] = dados.tamanho - i;
    }
}

// Função para imprimir o vetor
void imprimirVetor(DadosOrdenacao& dados) {
    for (int i = 0; i < dados.tamanho; i++) {
        cout << dados.vetor[i] << " ";
    }
    cout << endl;
}