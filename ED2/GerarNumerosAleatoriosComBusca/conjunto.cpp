#include "conjunto.h"

namespace ped{

int Conjunto::getTamanho() const
{
    return tamanho;
}

int Conjunto::getNumeroBuscado() const
{
    return numeroBuscado;
}

Conjunto::Conjunto():
    tamanho(0),
    array(0),
    numeroBuscado(0)
{
}

Conjunto::Conjunto(int tamanho):
    tamanho(tamanho),
    array(0),
    numeroBuscado(0)
{
    if(tamanho <= 0) throw "ERRO! Tamanho não pode se <= 0!";
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

int Conjunto::buscar(int numeroBuscado)
{
    for(int i=0; i < tamanho; i++){
        if(array[i] == numeroBuscado){
            return i;
        }
    }
    throw QString("Número não encontrado no conjunto");
}

}
