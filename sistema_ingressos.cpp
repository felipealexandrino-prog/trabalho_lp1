#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ─────────────────────────────────────────
//  STRUCTS
// ─────────────────────────────────────────

struct Funcionario {
    int id;
    string nome;
    string cargo;
};

struct Cliente {
    int id;
    string nome;
    string cpf;
};

struct Partida {
    int id;
    string timeCasa;
    string timeVisitante;
    string data;
};

struct Ingresso {
    int id;
    string setor;
    float valor;
    int idPartida;
};

struct Venda {
    int id;
    string data;
    int idCliente;
    int idFuncionario;
    int idPartida;
};

struct ItemVenda {
    int idVenda;
    int idIngresso;
};

// ─────────────────────────────────────────
//  VETORES DE CONTROLE (dinâmicos)
// ─────────────────────────────────────────

vector<Funcionario> funcionarios;
vector<Cliente>     clientes;
vector<Partida>     partidas;
vector<Ingresso>    ingressos;
vector<Venda>       vendas;
vector<ItemVenda>   itensVenda;

// ─────────────────────────────────────────
//  MAIN (placeholder)
// ─────────────────────────────────────────

int main() {
    cout << "Sistema de Gestão de Ingressos e Sócio Torcedor" << endl;
    return 0;
}
