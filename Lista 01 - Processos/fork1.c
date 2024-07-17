#include <sys/types.h>  // Biblioteca para tipos de dados relacionados ao sistema
#include <sys/wait.h>   // Biblioteca para funções relacionadas ao wait
#include <stdio.h>      // Biblioteca padrão de entrada e saída
#include <unistd.h>     // Biblioteca para chamadas de sistema relacionadas ao processo

int valor = 5;          // Variável global 'valor' inicializada com 5

int main(int argc, char **argv) {  // Função principal

    pid_t pid;              // Variável para armazenar o ID do processo
    valor += 1;             // Incrementa o valor global 'valor' em 1

    pid = fork();           // Cria um novo processo e armazena o ID do processo filho no 'pid'

    valor += 1;             // Incrementa o valor global 'valor' em 1

    if (pid == 0) {         // Verifica se o processo é o filho (processo recém-criado)
        valor += 3;         // Incrementa o valor global 'valor' em 3 no processo filho
        return 0;           // Retorna 0 para indicar que o processo filho terminou com sucesso
    }
    else if (pid > 0) {     // Verifica se o processo é o pai (processo original)
        valor += 5;         // Incrementa o valor global 'valor' em 5 no processo pai
        wait(NULL);         // Aguarda o término do processo filho
        printf("Processo pai: valor = %d\n", valor);  // Imprime o valor final de 'valor' no processo pai (LINHA A)
        return 0;           // Retorna 0 para indicar que o processo pai terminou com sucesso
    }
}

