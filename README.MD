
# Sistemas Operacionais 
![Badge em Desenvolvimento](http://img.shields.io/static/v1?label=STATUS&message=CONCLUÍDO&color=GREEN&style=for-the-badge)


Olá, este repositório é destinado a uma atividade da disciplina de Sistemas Operacionais, ministrada pelo professor Jorgiano. 

- Esta atividade consiste em estudar as aplicações de chamada de sistema do Linux. Para tal, desenvolvi alguns programas de sistemas, me baseando nas chamadas de sistemas do site https://linasm.sourceforge.net/docs/syscalls/

- Para compilar e conseguir usar as chamadas de sistemas no ambiente Linux em C/C++, baixei e instalei o Subsistema do Windows para Linux (WSL), utilizando o sistema Ubuntu. Instalei também as ferramentas de build para compilação e depuração, já que apenas o WSL não estava compilando o código C/C++: https://learn.microsoft.com/pt-br/cpp/build/walkthrough-build-debug-wsl2?view=msvc-170         



***Detalhando os conceitos dos programas***   

[Date](https://github.com/Sara-Xavier/Sistemas_Operacionais/blob/main/Programas/Date.c) - Este programa mostra a hora atual (GMT - 03:00), formato hh:mm:ss.

[Uptime](https://github.com/Sara-Xavier/Sistemas_Operacionais/blob/main/Programas/Uptime.c) - Este programa mostra há quanto tempo o computador está ligado.

[Cp](https://github.com/Sara-Xavier/Sistemas_Operacionais/blob/main/Programas/Cp.c) - Este programa copia conteúdo de um arquivo para outro, e cria arquivo cópia caso ele não exista.

[Rm](https://github.com/Sara-Xavier/Sistemas_Operacionais/blob/main/Programas/Rm.c) - Este programa remove arquivos previamente criados pelo usuário.

[Mv](https://github.com/Sara-Xavier/Sistemas_Operacionais/blob/main/Programas/Mv.c) - Este programa move arquivos.

[Cat](https://github.com/Sara-Xavier/Sistemas_Operacionais/blob/main/Programas/Cat.c) - Este programa abre um txt, lê seus caracteres de acordo com a tabela ASCII e imprime este resultado.

[Mkdir](https://github.com/Sara-Xavier/Sistemas_Operacionais/blob/main/Programas/Mkdir.c) - Este programa cria um diretório com um nome escolhido.



# Algumas das funções de sistemas utilizadas:
- Date: utilizei a chamada de sistema time() para obter o tempo atual em segundos desde a época (00:00:00 UTC em 1 de janeiro de 1970). Também utilizei a localtime() para converter o tempo em segundos para uma estrutura de tempo local, para ajustar o fuso. A strftime() formata a estrutura de tempo local em uma string com formato desejado (hh:mm:s).

- Uptime: utilizei a chamada de sistema sysinfo() para obter informações sobre o sistema, incluindo o tempo de inicialização.

- Cp: open() abre o arquivo de origem para leitura, também pode criar arquivo de destino para escrita. read() lê dados do arquivo de origem. write() escreve dados no arquivo de destino, e close() fecha os descritores de arquivo. 

- Rm: unlink() foi usado para remover um arquivo.

- Mv: open() abre o arquivo de origem para leitura, também pode criar arquivo de destino para escrita. read() lê dados do arquivo de origem. write() escreve dados no arquivo de destino, e close() fecha os descritores de arquivo, unlink() foi usado para remover um arquivo.

- Cat: fopen() abriu arquivo especificado, fgetc() lê carecteres dos arquivos, byte a byte e fclose() fecha os arquivos após a leitura.

- Mkdir: mkdir() cria um novo diretório com o nome.