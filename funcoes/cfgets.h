#ifndef CFGETS_h
#define CFGETS_h

#include <stdio.h>
#include <string.h>

void cfgets (char *string, int tam, FILE *stream){
    fgets(string, tam, stream);
    int len = strlen(string);
    if (string[len-1] == '\n'){
        string[len-1] = '\0';
    }
}

#endif