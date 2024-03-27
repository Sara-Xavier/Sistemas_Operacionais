#include <stdio.h>      // Biblioteca de entrada/saída padrão de C
#include <stdlib.h>     // Biblioteca de informações sobre o sistema, memória dinâmica e processos
#include <dirent.h>     // Biblioteca para manipulação de diretórios em C.


int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "Uso correto> %s <diretório>/n", argv[0]); //Verificando se argumento está correto
        return 1;
    }

    DIR *dir = opendir(argv[1]); // Especificação de argumento para abrir diretório pela linha de comando
    if (dir == NULL){
        perror("Erro ao abrir diretório");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL){
        printf("%s/n", entry->d_name);
    }

    closedir(dir);               // Fecha diretório
    return 0;

}