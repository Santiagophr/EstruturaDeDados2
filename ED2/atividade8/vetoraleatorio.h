#ifndef VETORALEATORIO_H
#define VETORALEATORIO_H
#include <QString>
#include <ctime>
#include <random>
#include <bits/stdc++.h>

namespace ped{
class VetorAleatorio
{
private:
    int tamanho;
    int *array;
    int *arraySelectionSort;
    int *arrayInsertionSort;
    int *arrayBubbleSort;
    int numExec;
    int numOrdenSelectionSort;
    int numOrdenInsertionSort;
    int numOrdenBubbleSort;
public:
    VetorAleatorio(int tamanho);
    ~VetorAleatorio();

    int getTamanho() const;

    QString getConjunto();
    QString getConjuntoOrdenadoSelectionSort();
    QString getConjuntoOrdenadoInsertionSort();
    QString getConjuntoOrdenadoBubbleSort();

    int buscarNumero(int aux);
    int buscarNumeroMelhorado(int aux);
    int buscarBinaria(int aux);

    void selectionSort();
    void insertionSort();
    void bubbleSort();

    int getNumExec() const;
    int getNumOrdenSelectionSort() const;
    int getNumOrdenInsertionSort() const;
    int getNumOrdenBubbleSort() const;
};
}
#endif // VETORALEATORIO_H
