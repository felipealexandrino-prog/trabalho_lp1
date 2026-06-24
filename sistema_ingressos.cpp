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
//  CADASTRO INGRESSO : Marivaldo
// ─────────────────────────────────────────
void cadastrarIngresso() {

    if (partidas.empty()) {
        cout << "\nNenhuma partida cadastrada.\n";
        cout << "Cadastre uma partida antes de criar ingressos.\n";
        return;
    }

    Ingresso novoIngresso;

    novoIngresso.id = ingressos.size() + 1;

    cout << "\n===== PARTIDAS DISPONIVEIS =====\n";

    for (int i = 0; i < partidas.size(); i++) {
        cout << "ID: " << partidas[i].id
             << " | "
             << partidas[i].timeCasa
             << " x "
             << partidas[i].timeVisitante
             << endl;
    }

    cout << "\nDigite o ID da partida: ";
    cin >> novoIngresso.idPartida;

    cout << "Digite o setor: ";
    cin.ignore();
    getline(cin, novoIngresso.setor);

    cout << "Digite o valor do ingresso: ";
    cin >> novoIngresso.valor;

    ingressos.push_back(novoIngresso);

    cout << "\nIngresso cadastrado com sucesso!\n";
}

// ─────────────────────────────────────────
//  CADASTRO DE CLIENTES: Marivaldo
// ─────────────────────────────────────────
void addClient(string nome, string cpf){
    
    Cliente novoCliente;
    
    novoCliente.id = clientes.size() + 1;
    novoCliente.nome = nome;
    novoCliente.cpf = cpf;
    
    
    clientes.push_back(novoCliente);
}



// ─────────────────────────────────────────
//  CADASTRO DE PARTIDAS : Marivaldo
// ─────────────────────────────────────────
void addmatch(string homeTeam, string awayTeam, string Date){
    
    Partida newMatch;
    
    newMatch.id = partidas.size() + 1;
    newMatch.timeCasa = homeTeam;
    newMatch.timeVisitante = awayTeam;
    newMatch.data = Date;
    
    partidas.push_back(newMatch);
    
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
    //Variaveis clientes
    string NomeClient;
    string cpfClient;
    
    //Variaveis Partidas
    string data;
    string homeTeam;
    string awayTeam;
    
    
    cout << "Sistema de Gestão de Ingressos e Sócio Torcedor" << endl;
    
    double choose;
    
    do{
        
        choose = menuPrincipal();
        
        if(choose == 1){
            cout << "Cadastro de funcionarios";
        }
        
        if(choose == 2){
            
            NomeClient = "";
            cpfClient = "";
            
            cout << "Nome do cliente: ";
            cin >> NomeClient;
            
            cout << "CPF do cliente: ";
            cin >> cpfClient;
            
            addClient(NomeClient, cpfClient);
            
            cout << "!!!CLIENTE ADICIONADO COM SUCESSO!!!\n";
            
            cout << clientes[0].nome << endl;
            cout << clientes[0].id << endl;
            cout << clientes[0].cpf << endl;
            
        }
        
        if(choose == 3){
            
            cout << "Time Da Casa: ";
            cin >> homeTeam;
            
            cout << "Time Visitante: ";
            cin >> awayTeam;
            
            cout << "Data: ";
            cin >> data;
            
            addmatch(homeTeam, awayTeam, data);
            
            cout << "!!!PARTIDA CADASTRADA COM SUCESSO!!!";
        }
        
        if (choose == 4){
            cadastrarIngresso();
        }
        
        
        
    } while(choose != 0);
    
    
    int totalPartidas = partidas.size();
    int totalVendas = vendas.size();

    // relatorioPartida(totalPartidas, totalVendas); -> Utiliza essa função quando o switch for opçãao 3!
    //Isa caça garupa safada

    return 0;
}
