
# Sistemas Operacionais 


Olá, este repositório é destinado a uma atividade da disciplina de Sistemas Operacionais, ministrada pelo professor Jorgiano. 

- Esta atividade consiste em estudar as aplicações de chamada de sistema do Linux. Para tal, desenvolvi alguns programas de sistemas, me baseando nas chamadas de sistemas do site https://linasm.sourceforge.net/docs/syscalls/

- Para compilar e conseguir usar as chamadas de sistemas no ambiente Linux em C/C++, baixei e instalei o Subsistema do Windows para Linux (WSL), utilizando o sistema Ubuntu. Instalei também as ferramentas de build para compilação e depuração, já que apenas o WSL não estava compilando o código C/C++: https://learn.microsoft.com/pt-br/cpp/build/walkthrough-build-debug-wsl2?view=msvc-170

# Detalhando os conceitos dos programas

***Programa Date.c***

Este programa mostra a hora atual. Utilizei a chamada de sistema time() para obter o tempo atual em segundos desde a época (00:00:00 UTC em 1 de janeiro de 1970).
 ```
#include <stdio.h>          //Esta é a biblioteca padrão de entrada e saída <br>
#include <time.h>           // Esta é a biblioteca de manipulação/gerenciamento de tempo

int main() { 
  time_t currentTime;       // usamos a biblioteca time com a unidade t de tempo. Criamos a variável currentTime  
  time(&currentTime);       // O current indica que estamos falando de tempo atual do sistema  
                            // o operador de endereço '&' que passa o endereço de memoria da variável para a função time 
  
  struct tm *localTime = localtime(&currentTime);</b> 
//Aqui, a estrutura 'struct' da biblioteca <time.h> armazena a hora local no endereço de memória da variável 'currentTime'
    
  
  printf("Hora atual: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);  

                            // formatei a hora em '%02d:%02d:%02d\n"', o 'd' ficou com dois dígitos, preenchendo com 2 '0' se necessário. 
                            // 'localTime' acessa o membro 'tm_hour' da estrutura apontada por "localTime".  
                           // O print vai ser feito com a hora atual fomatada como "HH:MM:SS" 
   return 0; 

}
```



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



***Programa Ls.c***
Copia conteúdo de um arquivo para outro. Não consigo compilar o programa sem que ele caia na mensagem de erro que criei, mesmo colocando os argumentos na linha de comando.

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