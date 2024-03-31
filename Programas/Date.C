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