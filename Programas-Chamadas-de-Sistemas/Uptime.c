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