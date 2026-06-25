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
//  RELATÓRIO DE VENDAS POR FUNCIONÁRIO: RUAN
// ─────────────────────────────────────────

void relatorioFuncionario(int totalFuncionarios, int totalVendas, int totalItens) {

    if (totalVendas == 0) {
        cout << "\nNenhuma venda cadastrada.\n";
        return;
    }

    cout << "\n===== RELATORIO DE VENDAS POR FUNCIONARIO =====\n";

    for (int i = 0; i < totalFuncionarios; i++) {
        int qtdVendas    = 0;
        int qtdIngressos = 0;

        for (int j = 0; j < totalVendas; j++) {
            if (vendas[j].idFuncionario == funcionarios[i].id) {
                qtdVendas++;

                for (int k = 0; k < totalItens; k++) {
                    if (itensVenda[k].idVenda == vendas[j].id) {
                        qtdIngressos++;
                    }
                }
            }
        }

        cout << "\nFuncionario: " << funcionarios[i].nome;
        cout << "\nCargo: "       << funcionarios[i].cargo;
        cout << "\nVendas realizadas: " << qtdVendas;
        cout << "\nIngressos vendidos: " << qtdIngressos << "\n";
    }
}

// ─────────────────────────────────────────
//  MENU PRINCIPAL : Marivaldo
// ─────────────────────────────────────────
double menuPrincipal(){

    double escolha;

    cout << "\n1 - Cadastro de Funcionários\n";
    cout << "2 - Cadastro de Clientes\n";
    cout << "3 - Cadastro de Partidas\n";
    cout << "4 - Cadastro de Ingressos\n";
    cout << "5 - Realizar Venda\n";
    cout << "6 - Consultar Vendas\n";
    cout << "7 - Relatórios\n";
    cout << "0 - Sair\n";

    cout << "Escolha Uma Opção: ";
    cin >> escolha;

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

    if (totalVendas == 0){
        cout << "\nNenhuma Venda Cadastrada\n";
        return;
    }

    cout << "\n===== RELATORIO DE VENDAS POR CLIENTE =====\n";

    for (int i = 0; i < totalClientes; i++){

        int clientesVendas = 0;

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
//  CONSULTAR VENDAS: Breno
// ─────────────────────────────────────────

void consultarVendas() {

    if (vendas.empty()) {
        cout << "\nNenhuma venda cadastrada.\n";
        return;
    }

    cout << "\n===== CONSULTA DE VENDAS =====\n";

    for (int i = 0; i < vendas.size(); i++) {
        cout << "\nID Venda: "        << vendas[i].id;
        cout << "\nData: "            << vendas[i].data;
        cout << "\nID Cliente: "      << vendas[i].idCliente;
        cout << "\nID Funcionario: "  << vendas[i].idFuncionario;
        cout << "\nID Partida: "      << vendas[i].idPartida;
        cout << "\nIngressos da venda:\n";

        for (int j = 0; j < itensVenda.size(); j++) {
            if (itensVenda[j].idVenda == vendas[i].id) {
                cout << "ID Ingresso: "
                     << itensVenda[j].idIngresso
                     << endl;
            }
        }

        cout << "-----------------------------\n";
    }
}

// ─────────────────────────────────────────
//  REALIZAR VENDA: Breno
// ─────────────────────────────────────────

void realizarVenda() {

    if (clientes.empty()) {
        cout << "\nNenhum cliente cadastrado.\n";
        return;
    }

    if (ingressos.empty()) {
        cout << "\nNenhum ingresso cadastrado.\n";
        return;
    }

    Venda novaVenda;
    novaVenda.id = vendas.size() + 1;

    cout << "\nData da venda: ";
    cin >> novaVenda.data;

    cout << "\nClientes cadastrados:\n";

    for (int i = 0; i < clientes.size(); i++) {
        cout << "ID: " << clientes[i].id
             << " | Nome: " << clientes[i].nome << endl;
    }

    cout << "\nID do cliente: ";
    cin >> novaVenda.idCliente;

    cout << "\nID do funcionario: ";
    cin >> novaVenda.idFuncionario;

    cout << "\nPartidas cadastradas:\n";

    for (int i = 0; i < partidas.size(); i++) {
        cout << "ID: " << partidas[i].id
             << " | "
             << partidas[i].timeCasa
             << " x "
             << partidas[i].timeVisitante
             << endl;
    }

    cout << "\nID da partida: ";
    cin >> novaVenda.idPartida;

    vendas.push_back(novaVenda);

    ItemVenda novoItem;
    novoItem.idVenda = novaVenda.id;

    cout << "\nIngressos cadastrados:\n";

    for (int i = 0; i < ingressos.size(); i++) {
        cout << "ID: " << ingressos[i].id
             << " | Setor: " << ingressos[i].setor
             << " | Valor: R$ " << ingressos[i].valor
             << endl;
    }

    cout << "\nID do ingresso: ";
    cin >> novoItem.idIngresso;

    itensVenda.push_back(novoItem);

    cout << "\nVenda realizada com sucesso!\n";
}


// ─────────────────────────────────────────
//  CADASTRO DE FUNCIONÁRIOS : Gabriel
// ─────────────────────────────────────────

void cadastrarFuncionario() {

    Funcionario novoFuncionario;

    novoFuncionario.id = funcionarios.size() + 1;

    cout << "\nNome do funcionario: ";
    cin.ignore();
    getline(cin, novoFuncionario.nome);

    cout << "Cargo do funcionario: ";
    getline(cin, novoFuncionario.cargo);

    funcionarios.push_back(novoFuncionario);

    cout << "\n!!!FUNCIONARIO CADASTRADO COM SUCESSO!!!\n";
}

// ─────────────────────────────────────────

void listarFuncionarios() {

    if (funcionarios.empty()) {
        cout << "\nNenhum funcionario cadastrado.\n";
        return;
    }

    cout << "\n===== FUNCIONARIOS CADASTRADOS =====\n";

    for (int i = 0; i < funcionarios.size(); i++) {
        cout << "\nID: "    << funcionarios[i].id;
        cout << "\nNome: "  << funcionarios[i].nome;
        cout << "\nCargo: " << funcionarios[i].cargo;
        cout << "\n-----------------------------\n";
    }
}

// ─────────────────────────────────────────

void buscarFuncionario() {

    if (funcionarios.empty()) {
        cout << "\nNenhum funcionario cadastrado.\n";
        return;
    }

    int idBusca;

    cout << "\nDigite o ID do funcionario: ";
    cin >> idBusca;

    for (int i = 0; i < funcionarios.size(); i++) {
        if (funcionarios[i].id == idBusca) {
            cout << "\n===== FUNCIONARIO ENCONTRADO =====\n";
            cout << "ID: "    << funcionarios[i].id    << "\n";
            cout << "Nome: "  << funcionarios[i].nome  << "\n";
            cout << "Cargo: " << funcionarios[i].cargo << "\n";
            return;
        }
    }

    cout << "\nFuncionario com ID " << idBusca << " nao encontrado.\n";
}

// ─────────────────────────────────────────

void editarFuncionario() {

    if (funcionarios.empty()) {
        cout << "\nNenhum funcionario cadastrado.\n";
        return;
    }

    listarFuncionarios();

    int idEditar;

    cout << "\nDigite o ID do funcionario que deseja editar: ";
    cin >> idEditar;

    for (int i = 0; i < funcionarios.size(); i++) {
        if (funcionarios[i].id == idEditar) {
            cout << "\nNovo nome (" << funcionarios[i].nome << "): ";
            cin.ignore();
            getline(cin, funcionarios[i].nome);

            cout << "Novo cargo (" << funcionarios[i].cargo << "): ";
            getline(cin, funcionarios[i].cargo);

            cout << "\n!!!FUNCIONARIO ATUALIZADO COM SUCESSO!!!\n";
            return;
        }
    }

    cout << "\nFuncionario com ID " << idEditar << " nao encontrado.\n";
}

// ─────────────────────────────────────────

void removerFuncionario() {

    if (funcionarios.empty()) {
        cout << "\nNenhum funcionario cadastrado.\n";
        return;
    }

    listarFuncionarios();

    int idRemover;

    cout << "\nDigite o ID do funcionario que deseja remover: ";
    cin >> idRemover;

    for (int i = 0; i < funcionarios.size(); i++) {
        if (funcionarios[i].id == idRemover) {
            cout << "\nFuncionario \"" << funcionarios[i].nome << "\" removido com sucesso.\n";
            funcionarios.erase(funcionarios.begin() + i);
            return;
        }
    }

    cout << "\nFuncionario com ID " << idRemover << " nao encontrado.\n";
}

// ─────────────────────────────────────────

void menuFuncionario() {

    int opcao;

    do {
        cout << "\n===== MENU DE FUNCIONARIOS =====\n";
        cout << "1 - Cadastrar Funcionario\n";
        cout << "2 - Listar Funcionarios\n";
        cout << "3 - Buscar Funcionario por ID\n";
        cout << "4 - Editar Funcionario\n";
        cout << "5 - Remover Funcionario\n";
        cout << "0 - Voltar ao Menu Principal\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) cadastrarFuncionario();
        if (opcao == 2) listarFuncionarios();
        if (opcao == 3) buscarFuncionario();
        if (opcao == 4) editarFuncionario();
        if (opcao == 5) removerFuncionario();

    } while (opcao != 0);
}

// ─────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────
int main() {
    // Variáveis clientes
    string NomeClient;
    string cpfClient;

    // Variáveis Partidas
    string data;
    string homeTeam;
    string awayTeam;

    cout << "Sistema de Gestão de Ingressos e Sócio Torcedor" << endl;

    double choose;

    do {
        choose = menuPrincipal();

        if (choose == 1) {
            menuFuncionario();
        }

        if (choose == 2) {
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

        if (choose == 3) {
            cout << "Time Da Casa: ";
            cin >> homeTeam;

            cout << "Time Visitante: ";
            cin >> awayTeam;

            cout << "Data: ";
            cin >> data;

            addmatch(homeTeam, awayTeam, data);

            cout << "!!!PARTIDA CADASTRADA COM SUCESSO!!!";
        }

        if (choose == 4) {
            cadastrarIngresso();
        }

        if (choose == 5) {
            realizarVenda();
        }

        if (choose == 6) {
            consultarVendas();
        }

    } while (choose != 0);

    int totalPartidas   = partidas.size();
    int totalVendas     = vendas.size();

    // relatorioPartida(totalPartidas, totalVendas); -> Utiliza essa função quando o switch for opção 3!
    //ANTONELA SAFADA

    return 0;
}