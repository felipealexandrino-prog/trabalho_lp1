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
//  MENU PRINCIPAL : Marivaldo
// ─────────────────────────────────────────
double menuPrincipal(){
    
    double escolha;
    
    cout << "1 - Cadastro de Funcionários\n";
    cout << "2 - Cadastro de Clientes\n";
    cout << "3 - Cadastro de Partidas\n";
    cout << "4 - Cadastro de Ingressos\n";
    cout << "5 - Realizar Venda\n";
    cout << "6 - Consultar Vendas\n";
    cout << "7 - Relatórios\n";
    cout << "0 - Sair\n";
    
    cout << "Escolha Uma Opção: ";
    std::cin >> escolha;
    
    return escolha;
}





// ─────────────────────────────────────────
//  RELATÓRIO DE VENDAS POR CLIENTE: Marivaldo
// ─────────────────────────────────────────

void relatorioCliente(int totalClientes, int totalVendas){
    
    //verificar se ha vendas
    if (totalVendas == 0){
        cout << "\nNenhuma Venda Cadastrada\n";
        return;
        
    }
    
    cout << "\n===== RELATORIO DE VENDAS POR CLIENTE =====\n";
    
    //Percorrendo Todos os clientes
    for (int i = 0; i < totalClientes; i++){
        
        int clientesVendas = 0; //Contador
        
        //Percorrendo Todas As VENDAS
        
        for (int j = 0; j < totalVendas; j++){
            if (vendas[j].idCliente == clientes[i].id){
                
                clientesVendas++;
                
                cout << "\nCliente: " << clientes[i].nome;
                cout << "\nCPF: "<< clientes[i].cpf;
                cout << "\nTotal de vendas: "<< clientesVendas << "\n";
                
            }
        }
        
    }
    
    
    
}



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
    double choose;
    
    do{
        
        choose = menuPrincipal();
        
    } while(choose != 0);

    int totalPartidas = partidas.size();
    int totalVendas = vendas.size();

    // relatorioPartida(totalPartidas, totalVendas); -> Utiliza essa função quando o switch for opçãao 3!
    //maria rita safada traira nunca ira voltar

    return 0;
}
