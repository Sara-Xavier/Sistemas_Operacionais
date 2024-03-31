
# Sistemas Operacionais 
![Badge em Desenvolvimento](http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=GREEN&style=for-the-badge)


Olá, este repositório é destinado a uma atividade da disciplina de Sistemas Operacionais, ministrada pelo professor Jorgiano. 

- Esta atividade consiste em estudar as aplicações de chamada de sistema do Linux. Para tal, desenvolvi alguns programas de sistemas, me baseando nas chamadas de sistemas do site https://linasm.sourceforge.net/docs/syscalls/

- Para compilar e conseguir usar as chamadas de sistemas no ambiente Linux em C/C++, baixei e instalei o Subsistema do Windows para Linux (WSL), utilizando o sistema Ubuntu. Instalei também as ferramentas de build para compilação e depuração, já que apenas o WSL não estava compilando o código C/C++: https://learn.microsoft.com/pt-br/cpp/build/walkthrough-build-debug-wsl2?view=msvc-170

***Detalhando os conceitos dos programas***
[Date](https://github.com/Sara-Xavier/Sistemas_Operacionais/blob/main/Programas/Date.C) - Este programa mostra a hora atual (GMT - 03:00), formato hh:mm:ss <br><br>



***Programa Uptime.c***
Este programa mostra há quanto tempo o computador está ligado. usei a chamada de sistema sysinfo() para obter informações sobre o sistema, incluindo o tempo de inicialização.

```
#include <stdio.h>    // Biblioteca de entrada/saída padrão de C
#include <stdlib.h>   // Biblioteca de informações sobre o sistema, memória dinâmica e processos
#include <time.h>     // Biblioteca de manipulação/gerenciamento de tempo

int main() {
     FILE *uptimeFile = fopen("/proc/uptime", "r"); 
                      //Criamos a variável 'uptimeFile', que é um ponteiro para o arquivo '/proc/uptime', 
                      // que utiliza 'fopen" para abrir tal arquivo
    if (uptimeFile == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo /proc/uptime\n");
        return 1;
    }

    double uptimeSeconds; // Variável do tipo Double para armazenar tempo de atividade do sistema em segundos
    if (fscanf(uptimeFile, "%lf", &uptimeSeconds) != 1) { //"fscanf" lê o tempo de atividade do arquivo uptimeFile.
        fprintf(stderr, "Erro ao ler o tempo de atividade\n");
        fclose(uptimeFile);
        return 1;
    }

    fclose(uptimeFile);

    int uptimeHours = (int)(uptimeSeconds / 3600);
    int uptimeMinutes = (int)((uptimeSeconds - uptimeHours * 3600) / 60);
    int uptimeSecondsRemainder = (int)(uptimeSeconds - uptimeHours * 3600 - uptimeMinutes * 60);

    printf("Tempo de atividade do sistema: %dh %dm %ds\n", uptimeHours, uptimeMinutes, uptimeSecondsRemainder);

    return 0;
}
```



***Programa Cp.c***
Copia conteúdo de um arquivo para outro, e cria arquivo cópia caso ele não exista

```
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


```


***Programa Rm.c***
Remove arquivos

```
// Crie o arquivo temporario: touch /tmp/arquivo.teste

#include <stdio.h>  // Biblioteca de entrada e saída
#include <stdlib.h> // Biblioteca de funções utilitárias
#include <string.h> // Biblioteca de manipulação de strings
#include <errno.h>  // Biblioteca de manipulação de erros
#include <unistd.h> // Biblioteca de chamadas de sistema POSIX (Interface Portável do Sistema Operacional (para Unix))

int main()
{
  if ( unlink("/tmp/arquivo.teste") != 0 )
  {
    fprintf(stderr, "Erro ao tentar remover: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }
  fprintf(stdout, "Arquivo removido com sucesso.\n");
  return EXIT_SUCCESS;
}
```