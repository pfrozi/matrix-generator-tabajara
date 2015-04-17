
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include "c_matrix.h"

/*
    CONSTS
*/

#define RETURN_NOTHING     1
#define ERROR_INVALID_ARGS 2
#define RETURN_SUCCESS     0

#define ARGS_MAX 6

#define ARGS_HELP       "-h"  // Option para imprimir a lista de opcoes
#define ARGS_NAME_ARQ_A "-A"  // Option com o nome do primeiro arquivo
#define ARGS_NAME_ARQ_B "-B"  // Option com o nome do segundo arquivo
#define ARGS_NAME_ARQ_M "-M"  // Option para informar o nome do arquivo com o resutado da multiplic
#define ARGS_ROWS_M     "-r"  // Option para indicar a quantidade de linhas da matrix resutado
#define ARGS_COLUMNS_M  "-c"  // Option para indicar a quantidade de colunas da matrix resutado

using namespace std;

void help();
