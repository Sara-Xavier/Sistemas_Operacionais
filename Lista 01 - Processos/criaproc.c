#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> // Adiciona a declaração da função wait()

int main(int argc, char **argv) {
    
    pid_t p1, p2;
    printf("Oi!\n");
    p1 = fork();
    printf("Bom dia!!!\n");
    
    if (p1 == 0) {
        const char *a[3] = {"showparam", "Olha eu aqui!", NULL}; // Usa const char* em vez de char*
        execve("showparam", (char * const *)a, NULL); // Converte para (char * const *) conforme necessário
        printf("Ate a proxima!\n");
    } else {
        wait(NULL);
        printf("Ate mais ver!\n");
        p2 = fork();
        printf("Fui...!\n");
    }
    
    return 0;
}
