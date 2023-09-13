#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include "./funcoes/cfgets.h"
#include "./funcoes/pausarExec.h"

void formatarPalavra(char original[], char modificada[])
{
    int len = strlen(original);

    int tamanhoModificada = 0;
    for (int c = 0; c < len; c++)
    {
        char temp = tolower(original[c]);
        if (isalpha(temp))
        {
            modificada[tamanhoModificada] = temp;
            tamanhoModificada++;
        }
    }

    modificada[tamanhoModificada] = '\0';
}
int contarPalavra(char palavra[], char path[])
{
    FILE *file;
    char palavraBusca[101];
    formatarPalavra(palavra, palavraBusca);

    char palavraArquivo[101];
    file = fopen(path, "r");

    int repeticoes = 0;

    if (file)
    {
        while (fscanf(file, "%s", palavraArquivo) == 1)
        {
            char fPalavra[100] = "";

            int len = strlen(palavraArquivo);
            int primeiraLetra = 0;

            int conversor = 0;

            for (int i = 0; i < len; i++)
            {
                if (!isalpha(palavraArquivo[i]))
                {
                    primeiraLetra++;
                }
                else
                    break;
            }
            // printf("%d \n", primeiraLetra);

            for (int i = primeiraLetra; i < len; i++)
            {
                if ((int) palavraArquivo[i] < 0){
                    primeiraLetra++;
                    continue;
                }
                if (isalpha(palavraArquivo[i]))
                {
                    char temp[3] = "";
                    sprintf(temp, "%c", tolower(palavraArquivo[i]));
                    strcat(fPalavra, temp);
                }
                else
                {
                    // printf("%s - %s\n",fPalavra,palavraBusca);
                    if (strcmp(fPalavra, palavraBusca) == 0)
                    {
                        repeticoes++;
                    }
                    strcpy(fPalavra, "");
                }

                if (i == len - 1)
                {
                    // printf("%s - %s\n",fPalavra,palavraBusca);
                    if (strcmp(fPalavra, palavraBusca) == 0)
                    {
                        repeticoes++;
                    }
                }
            }
            // printf("\n");
        }
    }
    else
    {
        printf("\n\t--> ERRO ao abrir arquivo!\n");
        return -1;
    }

    fclose(file);

    return repeticoes;
}

int main()
{
    setlocale(LC_ALL, "pt_BR");
    char palavra[101] = "érick";
    char path[1000] = "txts/acent.txt";
    FILE *arq;

    printf("--- Informe a palavra que quer encontrar com presicao!\n");
    printf("--- ' Frodo' != 'Frodo'\n--- 'Análise' != 'Analise'\n\n");

    printf("Informe o caminho do arquivo txt em que deseja fazer a busca: ");
    cfgets(path, 1001, stdin);

    arq = fopen(path, "r");

    if (arq != NULL){
            printf("Informe uma palavra: ");
            cfgets(palavra, 101, stdin);
            int contador = contarPalavra(palavra, path);
            printf("\nA palavra %s aparece %dx vezes em %s.", palavra, contador,path);
    } else {
        printf("Não foi possivel abrir o arquivo. Tente novamente...");
    }
    // limparBuffer();
    pausarExec();
    printf("\n");
    return 0;
}