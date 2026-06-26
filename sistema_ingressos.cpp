#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ─────────────────────────────────────────
//  STRUCTS
// ─────────────────────────────────────────

struct Funcionario
{
    int id;
    string nome;
    string cargo;
};

struct Cliente
{
    int id;
    string nome;
    string cpf;
};

struct Partida
{
    int id;
    string timeCasa;
    string timeVisitante;
    string data;
};

struct Ingresso
{
    int id;
    string setor;
    float valor;
    int idPartida;
};

struct Venda
{
    int id;
    string data;
    int idCliente;
    int idFuncionario;
    int idPartida;
};

struct ItemVenda
{
    int idVenda;
    int idIngresso;
};

struct Relatorio
{
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

void relatorioFuncionario(int totalFuncionarios, int totalVendas, int totalItens)
{

    if (totalVendas == 0)
    {
        cout << "\nNenhuma venda cadastrada.\n";
        return;
    }

    cout << "\n===== RELATORIO DE VENDAS POR FUNCIONARIO =====\n";

    for (int i = 0; i < totalFuncionarios; i++)
    {
        int qtdVendas = 0;
        int qtdIngressos = 0;

        for (int j = 0; j < totalVendas; j++)
        {
            if (vendas[j].idFuncionario == funcionarios[i].id)
            {
                qtdVendas++;

                for (int k = 0; k < totalItens; k++)
                {
                    if (itensVenda[k].idVenda == vendas[j].id)
                    {
                        qtdIngressos++;
                    }
                }
            }
        }

        cout << "\nFuncionario: " << funcionarios[i].nome;
        cout << "\nCargo: " << funcionarios[i].cargo;
        cout << "\nVendas realizadas: " << qtdVendas;
        cout << "\nIngressos vendidos: " << qtdIngressos << "\n";
    }
}

// ─────────────────────────────────────────
//  MENU PRINCIPAL : Marivaldo
// ─────────────────────────────────────────
int menuPrincipal()
{

    int escolha;

    cout << "\n1 - Cadastro de Funcionarios\n";
    cout << "2 - Cadastro de Clientes\n";
    cout << "3 - Cadastro de Partidas\n";
    cout << "4 - Cadastro de Ingressos\n";
    cout << "5 - Realizar Venda\n";
    cout << "6 - Consultar Vendas\n";
    cout << "7 - Relatorios\n";
    cout << "0 - Sair\n";

    cout << "Escolha Uma Opcao: ";
    cin >> escolha;

    return escolha;
}

// ─────────────────────────────────────────
//  MENU RELATORIOS : Marivaldo
// ─────────────────────────────────────────

int menuRelatorios()
{
    int escolha;
    cout << "\n===== MENU DE RELATORIOS =====\n";
    cout << "1 - Relatorio de Vendas por Funcionario\n";
    cout << "2 - Relatorio de Vendas por Cliente\n";
    cout << "3 - Relatorio de Vendas por Partida\n";
    cout << "4 - Partida que mais vendeu ingressos\n";
    cout << "0 - Voltar ao Menu Principal\n";
    cout << "Escolha uma opcao: ";
    
    cin >> escolha;
    
	return escolha;
 
}



// ─────────────────────────────────────────
//  CADASTRO INGRESSO : Marivaldo
// ─────────────────────────────────────────
void cadastrarIngresso()
{

    if (partidas.empty())
    {
        cout << "\nNenhuma partida cadastrada.\n";
        cout << "Cadastre uma partida antes de criar ingressos.\n";
        return;
    }

    Ingresso novoIngresso;

    novoIngresso.id = ingressos.size() + 1;

    cout << "\n===== PARTIDAS DISPONIVEIS =====\n";

    for (int i = 0; i < partidas.size(); i++)
    {
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
//  CADASTRO DE FUNCIONÁRIOS : Gabriel
// ─────────────────────────────────────────

void addworker()
{
	string nome, cargo;


    Funcionario novoFuncionario;

    novoFuncionario.id = funcionarios.size() + 1;

	cin.ignore(); // Limpa o buffer do cin antes de usar getline

	cout << "\nDigite o nome do funcionário: ";
	getline(cin, novoFuncionario.nome);

	cout << "Digite o cargo do funcionário: ";
	getline(cin, novoFuncionario.cargo);

    funcionarios.push_back(novoFuncionario);

    cout << "\n!!!FUNCIONARIO CADASTRADO COM SUCESSO!!!\n";
}

// ─────────────────────────────────────────


// ─────────────────────────────────────────
//  CADASTRO DE CLIENTES: Marivaldo
// ─────────────────────────────────────────
void addClient()
{

    Cliente novoCliente;
    novoCliente.id = clientes.size() + 1;
    
	cin.ignore(); // Limpa o buffer do cin antes de usar getline
    
	cout << "\nDigite o nome do cliente: ";
	getline(cin, novoCliente.nome);
    
	cout << "Digite o CPF do cliente: ";
	cin >> novoCliente.cpf;


    clientes.push_back(novoCliente);
}

// ─────────────────────────────────────────
//  CADASTRO DE PARTIDAS : Marivaldo
// ─────────────────────────────────────────
void addmatch()
{

    Partida newMatch;

    newMatch.id = partidas.size() + 1;

	cin.ignore(); // Limpa o buffer do cin antes de usar getline

	cout << "\nDigite o nome do time da casa: ";
	getline(cin, newMatch.timeCasa);

	cout << "Digite o nome do time visitante: ";
	getline(cin, newMatch.timeVisitante);

	cout << "Digite a data da partida (dd/mm/aaaa): ";
	cin >> newMatch.data;

    partidas.push_back(newMatch);
}

// ─────────────────────────────────────────
//  RELATÓRIO DE VENDAS POR CLIENTE: Marivaldo
// ─────────────────────────────────────────
void relatorioCliente(int totalClientes, int totalVendas)
{

    if (totalVendas == 0)
    {
        cout << "\nNenhuma Venda Cadastrada\n";
        return;
    }

    cout << "\n===== RELATORIO DE VENDAS POR CLIENTE =====\n";

    for (int i = 0; i < totalClientes; i++)
    {

        int clientesVendas = 0;

        for (int j = 0; j < totalVendas; j++)
        {
            if (vendas[j].idCliente == clientes[i].id)
            {

                clientesVendas++;

                cout << "\nCliente: " << clientes[i].nome;
                cout << "\nCPF: " << clientes[i].cpf;
                cout << "\nTotal de vendas: " << clientesVendas << "\n";
            }
        }
    }
}

// ─────────────────────────────────────────
//  RELATÓRIO DE VENDAS POR PARTIDA : Felipe
// ─────────────────────────────────────────
void relatorioPartida(int totalPartidas, int totalVendas)
{

    if (totalVendas == 0)
    {
        cout << "\nNenhuma venda cadastrada.\n";
        return;
    }

    cout << "\n===== RELATORIO DE VENDAS POR PARTIDA =====\n";

    for (int i = 0; i < totalPartidas; i++)
    {
        int vendasPartida = 0;

        for (int j = 0; j < totalVendas; j++)
        {
            if (vendas[j].idPartida == partidas[i].id)
            {
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

// ─────────────────────────────────────────────────────
//  RELATÓRIO PARTIDA QUE MAIS VENDEU INGRESSO: Felipe
// ─────────────────────────────────────────────────────

void toppartida()
{

    if (itensVenda.size() == 0)
    {
        cout << "Nenhum ingresso vendido." << endl;
        return;
    }

    int maiorQuantidade = 0;
    int indiceMaior = -1;

    for (int i = 0; i < partidas.size(); i++)
    {

        int quantidadeIngressos = 0;

        for (int j = 0; j < vendas.size(); j++)
        {

            if (vendas[j].idPartida == partidas[i].id)
            {

                for (int k = 0; k < itensVenda.size(); k++)
                {

                    if (itensVenda[k].idVenda == vendas[j].id)
                    {
                        quantidadeIngressos++;
                    }

                }

            }

        }

        if (quantidadeIngressos > maiorQuantidade)
        {
            maiorQuantidade = quantidadeIngressos;
            indiceMaior = i;
        }
    }

    if (indiceMaior != -1)
    {
        cout << "A partida com maior numero de ingressos vendidos foi: "
            << partidas[indiceMaior].timeCasa
            << " x "
            << partidas[indiceMaior].timeVisitante
            << " com "
            << maiorQuantidade
            << " ingressos vendidos."
            << endl;
    }

}

// ─────────────────────────────────────────
//  CONSULTAR VENDAS: Breno
// ─────────────────────────────────────────

void consultarVendas()
{

    if (vendas.empty())
    {
        cout << "\nNenhuma venda cadastrada.\n";
        return;
    }

    cout << "\n===== CONSULTA DE VENDAS =====\n";

    for (int i = 0; i < vendas.size(); i++)
    {
        cout << "\nID Venda: " << vendas[i].id;
        cout << "\nData: " << vendas[i].data;
        cout << "\nID Cliente: " << vendas[i].idCliente;
        cout << "\nID Funcionario: " << vendas[i].idFuncionario;
        cout << "\nID Partida: " << vendas[i].idPartida;
        cout << "\nIngressos da venda:\n";

        for (int j = 0; j < itensVenda.size(); j++)
        {
            if (itensVenda[j].idVenda == vendas[i].id)
            {
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

void realizarVenda()
{

    if (clientes.empty())
    {
        cout << "\nNenhum cliente cadastrado.\n";
        return;
    }

    if (ingressos.empty())
    {
        cout << "\nNenhum ingresso cadastrado.\n";
        return;
    }

    Venda novaVenda;
    novaVenda.id = vendas.size() + 1;

    cout << "\nData da venda: ";
    cin >> novaVenda.data;

    cout << "\nClientes cadastrados:\n";

    for (int i = 0; i < clientes.size(); i++)
    {
        cout << "ID: " << clientes[i].id
            << " | Nome: " << clientes[i].nome << endl;
    }

    cout << "\nID do cliente: ";
    cin >> novaVenda.idCliente;


	cout << "\nFuncionarios cadastrados:\n";

    for (int i = 0; i < funcionarios.size(); i++)
    {
        cout << "ID: " << funcionarios[i].id << " | Nome: " << funcionarios[i].nome << endl;
    }

    cout << "\nID do funcionario: ";
    cin >> novaVenda.idFuncionario;

    cout << "\nPartidas cadastradas:\n";

    for (int i = 0; i < partidas.size(); i++)
    {
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

    for (int i = 0; i < ingressos.size(); i++)
    {
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
//  MAIN
// ─────────────────────────────────────────
int main()
{

    //Variáveis Funcionarios
	string workerName;
	string workerPosition;

    // Variáveis clientes
    string NomeClient;
    string cpfClient;

    // Variáveis Partidas
    string data;
    string homeTeam;
    string awayTeam;

    cout << "Sistema de Gestão de Ingressos e Sócio Torcedor" << endl;

    int choose;
	int relatorioEscolha;

    do
    {
        choose = menuPrincipal();

        switch (choose)
        {
        case 1:
			addworker();
			break;

        case 2:
			addClient();
			break;

        case 3:
			addmatch();
            break;

        case 4:
            cadastrarIngresso();
			break;

        case 5:
            realizarVenda();
			break;

        case 6:
			consultarVendas();
            break;

        case 7:
            do
            {
				relatorioEscolha = menuRelatorios();

                switch (relatorioEscolha)
                {  
                
                  case 1:
					  relatorioFuncionario(funcionarios.size(), vendas.size(), itensVenda.size());
					  break;

                  case 2:
					  relatorioCliente(clientes.size(), vendas.size());
					  break;

				  case 3:
                      relatorioPartida(partidas.size(), vendas.size());
                      break;

                  case 4:
                      toppartida();
					  break;
                    
                  default:
                      cout << "\nOpcao invalida. Tente novamente.\n";
					  break;
                }
				break;
        
        default:
			cout << "\nOpcao invalida. Tente novamente.\n";
			break;


            } while (relatorioEscolha != 0);

        }

        
  

    } while (choose != 0);


    return 0;
}
