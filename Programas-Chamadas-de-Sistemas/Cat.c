#include <stdio.h>  //Biblioteca de entrada padrão C
#include <stdlib.h> // Biblioteca de informações do sistema 

int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    int byte;
    while ((byte = fgetc(file)) != EOF){
        printf("%d ", byte);
        }

    fclose(file);
    return EXIT_SUCCESS;
}
