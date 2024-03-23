<h1>Bem vindos!</h1>

<hr>

<p> Olá, este repositório é destinado a uma atividade da disciplina de Sistemas Operacionais, ministrada pelo professor Jorgiano. </p>
<p> Esta atividade consiste em estudar as aplicações de chamada de sistema do Linux. Para tal, desenvolvi alguns programas de sistemas, me baseando nas chamadas de sistemas do site https://linasm.sourceforge.net/docs/syscalls/ </p>
<p> Para compilar e conseguir usar as chamadas de sistemas no ambiente Linux em C/C++, baixei e instalei o Subsistema do Windows para Linux (WSL), utilizando o sistema Ubuntu. Instalei também as ferramentas de build para compilação e depuração, já que apenas o WSL não estava compilando o código C/C++: https://learn.microsoft.com/pt-br/cpp/build/walkthrough-build-debug-wsl2?view=msvc-170 </p>

<hr>
<br>

<h2> Detalhando os conceitos dos programas </h2>
<h3> Programa Date.c </h3>
<p>  A proposta do programa DAte.c é de mostrar hora e data atual. Vamos passar linha por linha, explicando os conceitos do programa:

#include <stdio.h> //Esta é a biblioteca padrão de entrada e saída
#include <time.h>  // Esta é a biblioteca de manipulação/gerenciamento de tempo 

int main() {
  time_t currentTime; //Get time in seconds
  time(&currentTime);

  struct tm *localTime = localtime(&currentTime);
    
  printf("Hora atual: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

  return 0;

}

 </p>
