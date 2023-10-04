#include "conjunto.h"

namespace ped{

int Conjunto::getTamanho() const
{
    return tamanho;
}

int Conjunto::getExecucoesOrdencao() const
{
    return execucoesOrdencao;
}

int Conjunto::getExecucoesBuscar() const
{
    return execucoesBuscar;
}

int Conjunto::getExecucoesBuscarMelhorado() const
{
    return execucoesBuscarMelhorado;
}

int Conjunto::getExecucoesBuscarBinario() const
{
    return execucoesBuscarBinario;
}

Conjunto::Conjunto(int tamanho):
    tamanho(0),
    execucoesOrdencao(0)
{
    if(tamanho <= 0) throw QString ("tamanho não pode ser negativo ou 0");
    try
    {
        array = new int[tamanho];
        arrayOrdenado = new int[tamanho];
        this->tamanho = tamanho;
        unsigned int seed = static_cast<unsigned int> (std::time(nullptr));
        std::srand(seed);

        for(int i = 0; i < tamanho; i++)
        {
            int numeroAleatorio = std::rand() %1000 + 1;
            array[i] = numeroAleatorio;
            arrayOrdenado[i] = numeroAleatorio;
        }

    }
    catch(std::bad_alloc &erro)
    {
        throw QString ("Erro ao gerar número aleatório");
    }

}

Conjunto::~Conjunto()
{
    delete array;
}

int Conjunto::buscarNumero(int numeroBuscado)
{
    execucoesBuscar = 0;
    for(int i = 0; i < tamanho; i++)
    {
        execucoesBuscar++;
        if(numeroBuscado == array[i])
        {
            return i;
        }
    }
    return -1;
}

int Conjunto::buscarNumeroMelhorado(int numeroBuscado)
{
    execucoesBuscarMelhorado = 0;
    for(int i = 0; i < tamanho; i++)
    {
        execucoesBuscarMelhorado++;
        if(numeroBuscado == arrayOrdenado[i])
        {
            return i;
        }
        if(numeroBuscado < arrayOrdenado[i])
        {
            return -1;
        }
    }
    return -1;
}

int Conjunto::buscarBinario(int numeroBuscado)
{
    execucoesBuscarBinario = 0;
    int inicio = 0;
    int fim = tamanho - 1;
    while(inicio <= fim)
    {
        int meio = (inicio+fim)/2;
        if(arrayOrdenado[meio] == numeroBuscado)
        {
            return meio;
        }
        if(arrayOrdenado[meio] <numeroBuscado)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
        execucoesBuscarBinario++;
    }
    return -1;
}

QString Conjunto::getConjunto()
{
    QString saida = " | ";
    for(int i = 0; i < tamanho; i++)
    {
        saida += QString::number(array[i]) + " | ";
    }
    return saida;
}

QString Conjunto::getConjuntoOrdenado()
{
    QString saida = " | ";
    for(int i = 0; i < tamanho; i++)
    {
        saida += QString::number(arrayOrdenado[i]) + " | ";
    }
    return saida;
}

void Conjunto::selectionSort()
{
    execucoesOrdencao = 0;
    for(int step = 0; step < getTamanho() - 1; step++)
    {
        int num_min = step;
        for(int i = step + 1; i <getTamanho(); i++)
        {
            execucoesOrdencao++;
            if(arrayOrdenado[i] < arrayOrdenado[num_min])
            {
                num_min = i;
            }
        }
        int temp = arrayOrdenado[step];
        arrayOrdenado[step] = arrayOrdenado[num_min];
        arrayOrdenado[num_min] = temp;
    }
}

}
