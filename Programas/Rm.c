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