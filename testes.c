#include <stdio.h>
#include <wchar.h>

void main()
{
    char caracteresAcentuados[] = {
        'ç',
        'à',
        'â',
        'ã',
        'ä',
        'ç',
        'é',
        'è',
        'ê',
        'ë',
        'í',
        'ì',
        'î',
        'ï',
        'ó',
        'ò',
        'ô',
        'õ',
        'ö',
        'ú',
        'ù',
        'û',
        'ü',
        'ý',
        'ÿ',
    };

    for (int c = 0; c < 15; c++)
    {
        printf("%d \n", caracteresAcentuados[c]);
    }

  char stringAAA[15] = "aaaaaaaaaaaa";
    wchar_t string[15]; // Declare uma string de caracteres largos com taman    // printf("%lc \n", -89);
    // Converte a sequência multibyte em uma sequência de caracteres largos
    size_t tamanho = mbstowcs(string, stringAAA, sizeof(string) / sizeof(string[0]));

    if (tamanho == (size_t)-1) {
        perror("mbstowcs");
        return 1;
    }

    wprintf(L"A string de caracteres largos é: %ls\n", string);


    // printf("%lc \n", -89);
}