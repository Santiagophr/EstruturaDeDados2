#include "conjunto.h"

namespace ped{

int Conjunto::getTamanho() const
{
    return tamanho;
}

Conjunto::Conjunto(int tamanho):
    tamanho(tamanho),
    array(0)

{
    if(tamanho <= 0) throw "ERRO! Tamanho não pode ser <= 0!";
    try
    {
        array = new int[tamanho];
        this->tamanho = tamanho;

        srand(static_cast<unsigned int>(time(nullptr)));

        for(int i=0; i < tamanho; ++i)
        {
            array[i] = rand() % 1001;

            if(array[i] < 0)
            {
                array[i] *= -1;
            }
        }

    } catch (std::bad_alloc &erro)
    {
        throw QString("Impossivel criar o vetor");
    }
}

Conjunto::~Conjunto()
{
    if(array) delete[]array;
}

QString Conjunto::obterVetor()
{
    QString saida;
    saida += "| ";
    for(int i=0; i < tamanho; i++){
        saida += QString::number(array[i]) + " | ";
    }
    return saida;
}

}
