#include <stdio.h>
#include <stdlib.h> #Biblioteca de informações sobre o sistema
#include <time.h>

int main() {
    FILE *uptimeFile = fopen("/proc/uptime", "r");
    if (uptimeFile == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo /proc/uptime\n");
        return 1;
    }

    double uptimeSeconds;
    if (fscanf(uptimeFile, "%lf", &uptimeSeconds) != 1) {
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