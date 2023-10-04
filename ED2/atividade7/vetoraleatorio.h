#ifndef VETORALEATORIO_H
#define VETORALEATORIO_H
#include <QString>
#include <ctime>
#include <random>

namespace ped{
class VetorAleatorio
{
private:
    int tamanho;
    int *array;
    int *arraySelectionSort;
    int *arrayInsertionSort;
    int numExec;
    int numOrdenSelectionSort;
    int numOrdenInsertionSort;
public:
    VetorAleatorio(int tamanho);
    ~VetorAleatorio();

    int getTamanho() const;

    QString getConjunto();
    QString getConjuntoOrdenadoSelectionSort();
    QString getConjuntoOrdenadoInsertionSort();

    int buscarNumero(int aux);
    int buscarNumeroMelhorado(int aux);
    int buscarBinaria(int aux);

    void selectionSort();
    void insertionSort();

    int getNumExec() const;
    int getNumOrdenSelectionSort() const;
    int getNumOrdenInsertionSort() const;
};
}
#endif // VETORALEATORIO_H
