#include <stdio.h>

// Simulação da API isBadVersion
int isBadVersion(int version, int bad)
{
    return version >= bad;
}

// Busca Binaria, recebe a lista, o tamanho e a chave a procura
int busca_binaria(int *lista, int tamanho, int chave)
{

    int inicio = 0;
    int fim = tamanho - 1;
    int a = isBadVersion(tamanho, chave);
    while (fim >= inicio)
    {
        int meio = (inicio + fim) / 2;
        if (chave == lista[meio] && a == 1)
        {
            return meio;
        }
        else if (chave > lista[meio])
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}
int main()
{
    int lista[1000] = {}; // vetor

    // Suponha que a versão 4 seja a primeira defeituosa
    int n = 5;
    int bad = 4;
    int tamanho = n;

    // gera a lista de versçao, nesse caso gerou uma lista de 1 até 5
    for (int i = 0; i < n; i++)
    {
        lista[i] = i + 1;
    }

    int a = busca_binaria(lista, tamanho, bad); // resultado da busca
    if (a != -1)
    {
        printf("Versao defeituosa encobtrada na posicao: %d", a);
    }
    else
    {
        printf("versao defeituosa nao encontrada");
    }

    return 0;
}