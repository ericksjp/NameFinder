#ifndef LIMPARBUFFER_H
#define LIMPARBUFFER_H

#include <stdio.h>

void limparBuffer()
{
    if (stdin != NULL){
        int limpador = '0';
        while (limpador != EOF && limpador != '\n')
            limpador = getchar();
    }
}

#endif // LIMPARBUFFER_H
