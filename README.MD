<h1>Bem vindos!</h1>

<hr>

<p> Olá, este repositório é destinado a uma atividade da disciplina de Sistemas Operacionais, ministrada pelo professor Jorgiano. </p>
<p> Esta atividade consiste em estudar as aplicações de chamada de sistema do Linux. Para tal, desenvolvi alguns programas de sistemas, me baseando nas chamadas de sistemas do site https://linasm.sourceforge.net/docs/syscalls/ </p>
<p> Para compilar e conseguir usar as chamadas de sistemas no ambiente Linux em C/C++, baixei e instalei o Subsistema do Windows para Linux (WSL), utilizando o sistema Ubuntu. Instalei também as ferramentas de build para compilação e depuração, já que apenas o WSL não estava compilando o código C/C++: https://learn.microsoft.com/pt-br/cpp/build/walkthrough-build-debug-wsl2?view=msvc-170 </p>

<hr>
<br>

<h2> Detalhando os conceitos dos programas </h2>
<h3> Programa Date.c </h3>
<p>  A proposta do programa Date.c é de mostrar hora e data atual. Vamos passar linha por linha, explicando os conceitos do programa:

<br>
<br>
<hr>
<b>
#include <stdio.h>      //Esta é a biblioteca padrão de entrada e saída <br>
#include <time.h>       // Esta é a biblioteca de manipulação/gerenciamento de tempo <br>

int main() { <br>
  time_t currentTime; // usamos a biblioteca time com a unidade t de tempo. Criamos a variável currentTime<br>  
  time(&currentTime); // O current indica que estamos falando de tempo atual do sistema <br> 
  // o operador de endereço '&' que passa o endereço de memoria da variável para a função time <br>

  struct tm *localTime = localtime(&currentTime); //Aqui, a estrutura 'struct' da biblioteca <time.h> armazena a hora local no endereço de memória da variável 'currentTime'<br>
    
  printf("Hora atual: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec); <br>
  // formatei a hora em '%02d:%02d:%02d\n"', o 'd' ficou com dois dígitos, preenchendo com 2 '0' se necessário. <br>
  // 'localTime' acessa o membro 'tm_hour' da estrutura apontada por "localTime".  <br>
  // O print vai ser feito com a hora atual fomatada como "HH:MM:SS" <br>
  return 0; <br>

}
</b>
<hr>
<br>
<br>

 </p>
