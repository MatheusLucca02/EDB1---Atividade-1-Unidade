#include <stdio.h>
#include <string.h>

// Função de busca pela quantidade de letras, recebe a palavra a letra e a posição inicial que a contagem deve começar
int recursao(const char *str, char letra, int posicao)
{

    if (strlen(str) <= posicao)
    {
        return 0; // Caso já tenha erro
    }

    if (letra == str[posicao])
    {

        posicao++;
        return 1 + recursao(str, letra, posicao); // Pula uma "casa" na busca e conta a letra
    }
    else
    {
        posicao++;
        return recursao(str, letra, posicao); // Pula para a proxima "Casa"
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