#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <QString>
#include <ctime>

namespace ped{
class Conjunto
{
private:
    int tamanho;
    int *array;
    int numeroBuscado;
public:
    Conjunto();
    Conjunto(int tamanho);
    ~Conjunto();

    QString obterVetor();

    int buscar(int numeroBuscado);

    int getTamanho() const;
    int getNumeroBuscado() const;
};
}

#endif // CONJUNTO_H
