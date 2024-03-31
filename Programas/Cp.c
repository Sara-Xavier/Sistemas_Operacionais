#include <stdio.h>      // Biblioteca de entrada/saída padrão de C
#include <stdlib.h>     // Biblioteca de informações sobre o sistema, memória dinâmica e processos

#define BUFFER_SIZE 4096// Buffer de tamanho fixo de 4096 bytes para realizar operações de leitura e escrita nos arquivos

int main(int argc, char *argv[]){
    
    if (argc != 3){
        fprintf(stderr,"Usage: %s <source> <destination>\n", argv[0]); //Stderr é o ponteiro de saída de erro padrão 
        return 1;
    }

    FILE *source_file = fopen(argv[1],"rb"); //Ponteiro do tipo FILE, 'rb' indica leitura binária
    if (source_file == NULL){
        perror("Error opening destination file");
        return 1;
    }

    FILE *dest_file = fopen(argv[2], "wb");
    if (dest_file == NULL) {
        perror("Error opening destination file");
        fclose(source_file); // É importante fechar o arquivo de origem se o arquivo de destino não puder ser aberto
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        size_t bytes_written = fwrite(buffer, 1, bytes_read, dest_file);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            fclose(source_file);
            fclose(dest_file);
            return 1;
        }
    }

    fclose(source_file);
    fclose(dest_file);
    
    printf("File copied successfully.\n");

    return 0;
}