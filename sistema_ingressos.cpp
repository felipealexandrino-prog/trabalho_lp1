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

struct Relatorio {
    // 1 - Total de vendas por Funcionário
    // 2 - Total de vendas por Cliente
    // 3 - Total de vendas por Partida
    // 4 - Partida que mais vendeu ingressos
};

// ─────────────────────────────────────────
//  VETORES DE CONTROLE
// ─────────────────────────────────────────

vector<Funcionario> funcionarios;
vector<Cliente> clientes;
vector<Partida> partidas;
vector<Ingresso> ingressos;
vector<Venda> vendas;
vector<ItemVenda> itensVenda;

// ─────────────────────────────────────────
//  RELATÓRIO DE VENDAS POR PARTIDA : Felipe
// ─────────────────────────────────────────

void relatorioPartida(int totalPartidas, int totalVendas) {

    if (totalVendas == 0) {
        cout << "\nNenhuma venda cadastrada.\n";
        return;
    }

    cout << "\n===== RELATORIO DE VENDAS POR PARTIDA =====\n";

    for (int i = 0; i < totalPartidas; i++) {
        int vendasPartida = 0;

        for (int j = 0; j < totalVendas; j++) {
            if (vendas[j].idPartida == partidas[i].id) {
                vendasPartida++;
            }
        }

        cout << "\nPartida: "
             << partidas[i].timeCasa
             << " x "
             << partidas[i].timeVisitante;

        cout << "\nData: "
             << partidas[i].data;

        cout << "\nTotal de vendas: "
             << vendasPartida
             << "\n";
    }
}

// ─────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────

int main() {
    cout << "Sistema de Gestão de Ingressos e Sócio Torcedor" << endl;

    int totalPartidas = partidas.size();
    int totalVendas = vendas.size();

    // relatorioPartida(totalPartidas, totalVendas); -> Utiliza essa função quando o switch for opçãao 3!
    //maria rita safada traira nunca ira voltar

    return 0;
}
