#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <QString>
#include <ctime>
#include <cstdlib>

class Conjunto
{
public:
private:
    int tamanho;
    int *array;
    int *arraySort;
public:
    Conjunto(int tamanho);
    ~Conjunto();
    QString getConjunto() const;
    QString getConjuntoSort() const;
    void SelectionSort();
    int getTamanho() const;
    int buscar(int num) const;
    int buscaBinaria(int num) const;
    int buscaBinariaRec(int num, int high, int low) const;
};

#endif // CONJUNTO_H
