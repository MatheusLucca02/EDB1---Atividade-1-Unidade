#include <stdio.h>

// Aqui lista a lista
int lista_numeros(int *vetor, int tamanho)
{

    printf("Lista: [");
    for (int i = 0; i < tamanho; i++)
    {
        if (i == tamanho - 1)
        {
            printf("%d]\n", vetor[i]);
        }
        else
        {
            printf("%d, ", vetor[i]);
        }
    }
}

// Ordena, utilizando bubblesort, recebendo a lista e o tamanho
int bubblesort(int *lista, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (lista[j] > lista[j + 1])
            {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

// Busca sequenciall, recebe a lista o tamnho e a chave
int busca_seq_ordenada(int *lista, int tamanho, int chave)
{
    for (int i = 0; i < tamanho; i++)
    {

        if (lista[i] == chave)
        {
            return i;
        }
    }
    return -1;
}

// Função da questão, recebe a lista e o tamanho
int conta_especialidades_distintas(int lista[], int tamanho)
{
    bubblesort(lista, tamanho); // Pega a lista ordenada
    int especialidade[tamanho];
    int cont_dife = 0; // Conta a quantidade de especialidades diferentes
    int lista_isolada[1000] = {};

    for (int i = 0; i < tamanho; i++)
    {

        if (busca_seq_ordenada(especialidade, cont_dife, lista[i]) == -1)
        {

            especialidade[cont_dife] = lista[i];
            lista_isolada[cont_dife] = lista[i];
            cont_dife++;
        }
    }
    // Mostra a lista dos elementos unicos
    printf("Lista das Especialidades unicas: [");
    for (int i = 0; i < cont_dife; i++)
    {
        if (i == cont_dife - 1)
        {
            printf("%d]\n", lista_isolada[i]);
        }
        else
        {

            printf("%d, ", lista_isolada[i]);
        }
    }
    return cont_dife;
}
int main()
{
    int lista[] = {1, 2, 3, 1, 2, 3};
    int tamanho = sizeof(lista) / sizeof(int);

    // Ordena lista

    bubblesort(lista, tamanho);
    lista_numeros(lista, tamanho);

    // Busca sequencial
    int quantidade_especialidades = conta_especialidades_distintas(lista, tamanho);
    printf("qauntidade de especialidades diferentes: %d", quantidade_especialidades);

    return 0;
}