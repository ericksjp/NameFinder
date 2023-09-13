#ifndef LIMPAREXEC_H
#define LIMPAREXEC_H

// getch() for linux

/*
 * - termios.h:
 *      - Essa biblioteca fornece a estrutura struct termios e funções 
 *        relacionadas para a manipulação de configurações de terminal. 
 *      - mais sobre -> https://pubs.opengroup.org/onlinepubs/7908799/xsh/termios.h.html
 * 
 * - unistd.h:
 *      - Essa biblioteca fornece funções para manipular descritores de arquivos, 
 *        incluindo descritores de terminal. 
 *        STDIN_FILE é uma constante de unistd.h que representa o descritor de arquivo 
 *        associado à entrada padrão (stdin) no sistema Unix/Linux.
 *      - mais sobre -> https://pubs.opengroup.org/onlinepubs/007908775/xsh/unistd.h.html
 * 
 * - stdio.h:
 *     - Para usar o getch();
 * 
 * - CleanBuffer.h:
 *     - Para usar a func cleanBuffer();
 */
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "limparBuffer.h"

static void configurarTerminal();
static void restaurarTerminal();

void pausarExec()
{
    // limparBuffer();
    configurarTerminal();
    getchar();
    restaurarTerminal();
}


 /*
 * - declaradno duas structs do tipo termios;
 *
 * - A função tcgetattr obtém as configurações atuais do terminal padrão de entrada (stdin)
 *   e as armazena na estrutura terminal;
 * 
 * - desativando duas flags no campo c_lflag da estrutura terminal:
 *      - ICANON: Ao desativar isso, permitimos a leitura de teclas individualmente, 
 *                sem a necessidade de pressionar Enter.
 *      - ECHO: Ao desativá-lo, evitamos que as teclas sejam mostradas 
 *              na tela enquanto o usuário as digita.
 * 
 * - A função tcsetattr define as novas configurações no terminal padrão de entrada (stdin). 
 *   O terceiro argumento é a estrutura terminalModificado que contém as configurações modificadas. 
 *   O segundo argumento TCSANOW indica que as alterações devem ser aplicadas imediatamente.
 */
static void configurarTerminal()
{
    struct termios terminal; 
    tcgetattr(STDIN_FILENO, &terminal); 
    terminal.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
}

static void restaurarTerminal() {
    struct termios terminal;
    tcgetattr(STDIN_FILENO, &terminal);
    terminal.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
}

#endif
