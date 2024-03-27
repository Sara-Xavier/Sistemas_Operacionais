#include <stdio.h>      // Biblioteca de entrada/saída padrão de C
#include <stdlib.h>     // Biblioteca de informações sobre o sistema, memória dinâmica e processos
#include <dirent.h>     // Biblioteca para manipulação de diretórios em C.
#include <unistd.h>     // Biblioteca da função 'getcwd'


int main(int argc, char *argv[]){
    char *dir_path;

    if (argc == 1){
        dir_path = getcwd(NULL, 0); //Verificando se diretorio está como argumento, se nenhumn for verificado abre o diretorio atual
        if (dir_path == NULL){
            perror("Erro ao abrir diretório de trabalho atual");
            return 1;
        }
        
    }

    else if(argc == 2){
        dir_path == argv[1];
    }

    else{ //Else criado para não receber mais de um argumento. Caso isso aconteça, dará erro
        fprintf(stderr, "Uso correto: %s [diretorio]/n", argv[0]);
        return 1;
    }

    DIR *dir = opendir(dir_path):
    if (dir == NULL){
        perror("Erro ao abrir diretório");
        free(dir_path);  //Liberando memória alocada por 'getcwd()'
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL){
        printf("%s/n", entry->d_name);
    }

    closedir(dir);               // Fecha diretório
    free(dir_path);              // Libera memória alocada
    return 0;

}