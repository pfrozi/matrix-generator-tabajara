#include "../include/main.h"



void help(){

    printf("\n*** Gerador de Matrizes ***\n");
    printf("\n\tGera tres matrizes A, B, M, onde:");
    printf("\n\t\tA e B sao matrizes geradas aleatoriamente;");
    printf("\n\t\tM eh uma matriz criada a partir da multiplicacao A x B.");
    printf("\n\nOptions:");
    printf("\n\t-h\t\tAjuda.");
    printf("\n\t-A NOME\t\tNome do arquivo de saida para matriz A.");
    printf("\n\t-B NOME\t\tNome do arquivo de saida para matriz B.");
    printf("\n\t-M NOME\t\tNome do arquivo de saida para matriz M.");
    printf("\n\t-r n\t\tQuantidade de linhas da matriz M.");
    printf("\n\t-c n\t\tQuantidade de colunas da matriz M.");

    printf("\n\nFormato de saida nos arquivos: ");
    printf("\n{{INICIO DO ARQUIVO}}");
    printf("\nLINHAS = {Quantidade de linhas da matriz}");
    printf("\nCOLUNAS = {Quantidade de colunas da matriz}");
    printf("\na11 a12 ... a1M");
    printf("\na21 a22 ... a2M");
    printf("\n... ... ... ...");
    printf("\naN1 aN2 ... aNM");
    printf("\n{{FINAL DO ARQUIVO}}");

    printf("\n\nSaida do programa (matriz M): ");
    printf("\nLINHAS = {Quantidade de linhas da matriz}");
    printf("\nCOLUNAS = {Quantidade de colunas da matriz}");
    printf("\na11 a12 ... a1M");
    printf("\na21 a22 ... a2M");
    printf("\n... ... ... ...");
    printf("\naN1 aN2 ... aNM\n\n");

}


int main(int argc, char* argv[])
{

    std::string nameA;
    std::string nameB;
    std::string nameM;
    int rowsM=0, columnsM=0;

    srand(time(NULL));

    if (argc < ARGS_MAX || (argc==1 && !(strcmp(argv[1],ARGS_HELP)==0) )) {

        help();
        return (ERROR_INVALID_ARGS);

    } else {

        for (int i = 1; i < argc; i+=2) {

            if (i + 1 != argc)
            {
                std::string arg = argv[i+1];

                if (strcmp(argv[i],ARGS_HELP) == 0) {

                    help();
                    return (RETURN_NOTHING);


                } else if (strcmp(argv[i], ARGS_HELP)==0) {

                    help();

                } else if (strcmp(argv[i], ARGS_NAME_ARQ_A)==0) {

                    nameA = arg;

                } else if (strcmp(argv[i], ARGS_NAME_ARQ_B)==0) {

                    nameB = arg;

                } else if (strcmp(argv[i], ARGS_NAME_ARQ_M)==0) {

                    nameM = arg;

                } else if (strcmp(argv[i], ARGS_ROWS_M)==0) {

                    rowsM = atoi(arg.c_str());

                } else if (strcmp(argv[i], ARGS_COLUMNS_M)==0) {

                    columnsM = atoi(arg.c_str());

                } else {

                    return (ERROR_INVALID_ARGS);

                }
            }
        }

        int n_rdm = (rand() % (rowsM+30))+abs(rowsM-30);

        Matrix* in1 = new Matrix();
        Matrix* in2 = new Matrix();

        in1->setRows(rowsM);
        in1->setColumns(n_rdm);

        in2->setRows(n_rdm);
        in2->setColumns(columnsM);

        in1->initMatrix();
        in2->initMatrix();

        in1->setRandom();
        in2->setRandom();

        Matrix* result = in1->matrixProduct(in2);

        in1->exportToFile(nameA);
        in2->exportToFile(nameB);
        result->exportToFile(nameM);
    }

    return RETURN_SUCCESS;
}
