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
public:
    Conjunto(int tamanho);
    ~Conjunto();
    QString obterVetor();
    int getTamanho() const;
};
}
#endif // CONJUNTO_H
