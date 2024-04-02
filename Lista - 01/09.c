// 9. Escreva um trecho de programa (sequencia de fork()) que crie a árvore de processos a seguir:
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("P1 (pid=%d)\n", getpid()); // Processo inicial (Famoso P1)

    pid = fork();
    if (pid == 0){
        printf("P2 (pid=%d, ppid=%d\n)", getpid(), getppid()); // (Famoso P2)

        pid = fork();
        if (pid == 0){
            printf("P5 (pid=%d, ppid=%d\n)", getpid(), getppid()); // (Famoso P5)
        }

        else if (pid > 0){
            pid = fork();
            if (pid == 0){
                printf("P6 (pid=%d, ppid=%d)/n", getpid(), getppid()); // (Famoso P6)
            }
        }
    }

// Processo 3 (P3)
    else if (pid > 0) {
        pid = fork();
        if (pid == 0) {
            printf("P3 (pid=%d, ppid=%d)\n", getpid(), getppid());
            
            // Processo 7 (P7)
            pid = fork();
            if (pid == 0) {
                printf("P7 (pid=%d, ppid=%d)\n", getpid(), getppid());
            }
        }
        // Processo 4 (P4)
        else if (pid > 0) {
            printf("P4 (pid=%d, ppid=%d)\n", getpid(), getppid());
        }
    }
    
    return 0;

}