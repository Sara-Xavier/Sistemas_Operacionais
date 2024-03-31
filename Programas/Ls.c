#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h> // Para a função getcwd()

int main(int argc, char *argv[]) {
    char *dir_path;

    // Verifica se o usuário especificou um diretório como argumento
    if (argc == 2) {
        dir_path = argv[1]; // Usa o diretório fornecido como argumento
    } else if (argc == 1) {
        // Se nenhum diretório foi especificado, solicita ao usuário que insira o diretório desejado
        printf("Digite o caminho do diretório (ou pressione Enter para usar o diretório atual): ");
        char input[256];
        fgets(input, sizeof(input), stdin);
        
        // Se o usuário não digitou nada, use o diretório de trabalho atual
        if (strlen(input) == 0) {
            dir_path = getcwd(NULL, 0);
            if (dir_path == NULL) {
                perror("Erro ao obter o diretório de trabalho atual");
                return 1;
            }
        } else {
            dir_path = input; // Usa o diretório fornecido pelo usuário
        }
    } else {
        fprintf(stderr, "Uso correto: %s [diretório]\n", argv[0]);
        return 1;
    }

    // Abre o diretório especificado
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Erro ao abrir o diretório");
        if (argc == 1) {
            free(dir_path);
        }
        return 1;
    }

    // Lê os nomes dos arquivos no diretório e imprime na tela
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Fecha o diretório
    closedir(dir);

    if (argc == 1) {
        free(dir_path);
    }

    return 0;
}
