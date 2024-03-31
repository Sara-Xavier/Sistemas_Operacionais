#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <origem> <destino>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (rename(argv[1], argv[2]) != 0) {
        perror("Erro ao mover arquivo");
        return EXIT_FAILURE;
    }

    printf("Arquivo movido com sucesso.\n");
    return EXIT_SUCCESS;
}
