// 2. Explique os passos para criar e usar uma área de memória compartilhada entre dois processos usando a API
// POSIX.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    // Criar ou abrir um objeto de memória compartilhada
    int shm_fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(1);
    }

    // Configurar o tamanho da área de memória compartilhada
    if (ftruncate(shm_fd, 4096) == -1) {
        perror("ftruncate");
        exit(1);
    }

    // Mapear a memória compartilhada no espaço de endereçamento do processo
    void *shm_ptr = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Escrever dados na memória compartilhada
    char *message = "Hello, World!";
    sprintf((char *)shm_ptr, "%s", message);

    // Ler dados da memória compartilhada
    printf("Read from shared memory: %s\n", (char *)shm_ptr);

    // Desmapear a memória compartilhada
    if (munmap(shm_ptr, 4096) == -1) {
        perror("munmap");
        exit(1);
    }

    // Fechar o descritor de arquivo
    if (close(shm_fd) == -1) {
        perror("close");
        exit(1);
    }

    // Remover o objeto de memória compartilhada
    if (shm_unlink("/my_shm") == -1) {
        perror("shm_unlink");
        exit(1);
    }

    return 0;
}
