#include "conjunto.h"

int Conjunto::getTamanho() const
{
    return tamanho;
}

Conjunto::Conjunto(int tamanho):
    tamanho(0),
    array(0)
    {
    if(tamanho <= 0) throw QString("O tamanho não pode ser <= 0");
    try {
        array = new int[tamanho];
        arraySort = new int[tamanho];
        this->tamanho = tamanho;
        } catch (std::bad_alloc &erro) {
        throw QString("Conjunto não foi criado");
        }
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for(int i=0;i<tamanho;i++)
    {
        int randomNumber = std::rand() % 1001;
        if(randomNumber<0)
        {
            randomNumber*=-1;
        }
        array[i]= randomNumber;
        arraySort[i]=randomNumber;
    }
    }

QString Conjunto::getConjunto() const{
    QString saida = "";
    for(int pos = 0; pos < tamanho; pos++){
        saida += QString::number(*(array+pos)) + " | ";
    }
    return saida;
}

QString Conjunto::getConjuntoSort() const{
    QString saida = "";
    for(int pos = 0; pos < tamanho; pos++){
        saida += QString::number(*(arraySort+pos)) + "|";
    }
    return saida;
}

void Conjunto::SelectionSort(){
    for(int s = 0; s < tamanho-1; s++){
        int posmenor = s;
        for(int i = s+1; i < tamanho; i++){
            if(arraySort[i] < arraySort[posmenor]){
                posmenor = i;
            }
        }
        int aux = arraySort[s];
        arraySort[s] = arraySort[posmenor];
        arraySort[posmenor] = aux;
    }
}

int Conjunto::buscar(int num) const{
    for(int i = 0; i < tamanho; i++){
        if(*(arraySort+i) > num){
            throw QString("Não existe");
        }
            if(*(arraySort+i) == num){
                return i;
            }
    }
    throw QString("Não existe");
}

int Conjunto::buscaBinaria(int num) const{
    int low = 0, high = tamanho-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arraySort[mid]==num) return mid;
        if(arraySort[mid]<num) low=mid+1;
        else high=mid-1;
    }
    throw QString("Não existe");
}

int Conjunto::buscaBinariaRec(int num, int low, int high) const{
    if(high>=low)
    {
        int mid = low+(high-low)/2;
        if(arraySort[mid]==num)
            return mid;
        if(arraySort[mid]>num)
            return buscaBinariaRec(num, low, mid-1);
        return buscaBinariaRec(num, mid+1, high);
    }
    throw QString("Não existe");
}

Conjunto::~Conjunto()
{
    if(array)delete[] array;
    if(arraySort) delete arraySort;
}
