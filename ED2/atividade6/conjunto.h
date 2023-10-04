#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <QString>
#include <ctime>
#include <cstdlib>

namespace ped{
class Conjunto
{
private:
    int tamanho;
    int *array;
    int *arrayOrdenado;
    int execucoesOrdencao;
    int execucoesBuscar;
    int execucoesBuscarMelhorado;
    int execucoesBuscarBinario;
public:
    Conjunto(int tamanho);
    ~Conjunto();

    int buscarNumero(int numeroBuscado);
    int buscarNumeroMelhorado(int numeroBuscado);
    int buscarBinario(int numeroBuscado);

    void selectionSort();

    QString getConjunto();
    QString getConjuntoOrdenado();

    int getTamanho() const;

    int getExecucoesOrdencao() const;
    int getExecucoesBuscar() const;
    int getExecucoesBuscarMelhorado() const;
    int getExecucoesBuscarBinario() const;
};
}
#endif // CONJUNTO_H
