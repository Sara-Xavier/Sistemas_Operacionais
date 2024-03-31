// gcc Mkdir.c -o Mkdir .
// ./Mkdir teste.txt

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    // Verifica se o número de argumentos está correto
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <nome_do_diretorio>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Cria um novo diretório com permissões padrão (0777)
    if (mkdir(argv[1], 0777) == -1) {
        perror("Erro ao criar diretório");
        return EXIT_FAILURE;
    }

    printf("Diretório '%s' criado com sucesso.\n", argv[1]);
    
    return EXIT_SUCCESS;
}
