#include <stdio.h>
#include <time.h>

int main() {
  time_t currentTime; //Get time in seconds
  time(&currentTime);

  struct tm *localTime = localtime(&currentTime);
    
  printf("Hora atual: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

  return 0;

}