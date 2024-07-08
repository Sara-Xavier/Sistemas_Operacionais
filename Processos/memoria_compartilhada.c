#define BUFFER_SIZE 10
typedef struct {
    
} item;

item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

/* produção de dados*/

item next_produced;
while (1){
    /*Produz item e armazena em next_produced*/
    while(((in + 1) % BUFFER_SIZE) == out)
    ;  /*buffer lotado. Espera ocupada fazendo nada*/
    buffer[in] = next_produced;
    in = (in + 1) % BUFFER_SIZE;
}

/* consumo de dados*/

item next_consumed;
while (1){
    while (in == out)
    ; /*Buffer vazio. Espera fazendo nada.*/
    next_consumed = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    /*Consome o item armazenado em next_consumed*/
}