#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sstream>
#include <vector>

using namespace std;

// Extrai o comando do input do usuário
string extrair_comando(string input) {
    stringstream ss(input);
    string comando;
    ss >> comando;
    return comando;
}

// Extrai os argumentos do comando
vector<string> extrair_argumentos(string input) {
    stringstream ss(input);
    string palavra;
    vector<string> argumentos;

    while (ss >> palavra)
        argumentos.push_back(palavra);

        // Remove o comando da lista de argumentos
    argumentos.erase(argumentos.begin());
    return argumentos;
}

void executar_comando(string input) {
    string comando = extrair_comando(input);
    vector<string> argumentos = extrair_argumentos(input);
    
    // Verifica se o comando é para rodar em segundo plano
    if (!argumentos.empty() && argumentos.back() == "&") {
        cout << "Executando em background!" << endl;
        argumentos.pop_back();  // Remove o "&" dos argumentos
    }

    // Verifica se o comando é interno
    if (comando == "exit") {
        exit(0);
    }

    // Verifica se é um comando externo
    string caminho_absoluto = "/bin/" + comando;

    if (access(caminho_absoluto.c_str(), F_OK) == 0) { // Comando existe
        if (access(caminho_absoluto.c_str(), X_OK) == 0) { // Comando é executável
            pid_t pid = fork();
            if (pid < 0) { // Falha na criação do processo
                cerr << "Erro ao tentar executar o comando!" << endl;
                return;
            } else if (pid == 0) { // Processo filho
                vector<char*> args;
                args.push_back((char*)comando.c_str());
                for (auto &arg : argumentos) {
                    args.push_back((char*)arg.c_str());
                }
                args.push_back(nullptr);
                execve(caminho_absoluto.c_str(), args.data(), nullptr);
            } else { // Processo pai
                waitpid(pid, nullptr, 0); // Aguarda o processo filho terminar
            }
        } else {
            cerr << "Permissão negada: " << comando << endl;
        }
    } else {
        cerr << "Comando não encontrado: " << comando << endl;
    }
}

int main() {
    while (true) {
        cout << "$ "; // Exibe o prompt
        string input;
        getline(cin, input);
        executar_comando(input);
    }
    return 0;
}