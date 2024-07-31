#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <errno.h>

int main() {
    // Definir os atributos da fila de mensagens
    struct mq_attr attr;
    attr.mq_flags = 0; // 0 para operações de bloqueio
    attr.mq_maxmsg = 10; // Capacidade máxima de 10 mensagens
    attr.mq_msgsize = 256; // Tamanho máximo de cada mensagem: 256 bytes
    attr.mq_curmsgs = 0; // Número atual de mensagens na fila

    // Criar ou abrir uma fila de mensagens
    mqd_t mqd = mq_open("/my_queue", O_CREAT | O_RDWR, 0666, &attr);
    if (mqd == (mqd_t) -1) {
        perror("mq_open");
        exit(1);
    }

    // Enviar mensagem para a fila
    char *message = "Hello, World!";
    if (mq_send(mqd, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        exit(1);
    }

    // Receber mensagem da fila
    char buffer[256];
    if (mq_receive(mqd, buffer, 256, NULL) == -1) {
        perror("mq_receive");
        exit(1);
    }
    printf("Received message: %s\n", buffer);

    // Fechar a fila de mensagens
    if (mq_close(mqd) == -1) {
        perror("mq_close");
        exit(1);
    }

    // Remover a fila de mensagens
    if (mq_unlink("/my_queue") == -1) {
        perror("mq_unlink");
        exit(1);
    }

    return 0;
}
