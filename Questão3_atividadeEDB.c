#include <stdio.h>
#include <string.h>

// Função de busca pela quantidade de letras
int recursao(const char *str, char letra, int posicao)
{

    if (strlen(str) <= posicao)
    {
        return 0;
    }

    if (letra == str[posicao])
    {

        posicao++;
        return 1 + recursao(str, letra, posicao); // Pula uma "casa" na busca
    }
    else
    {
        posicao++;
        return recursao(str, letra, posicao);
    }
}

int main()
{
    char string[] = "Banana";
    char letra = 'a';
    int posicao = 0; // Posição inicial na string
    int a = recursao(string, letra, posicao);
    printf("Existem %d letras As na palavra Banana", a);
    return 0;
}