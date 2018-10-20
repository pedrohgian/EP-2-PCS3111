#include "Projeto.h"
#include <iostream>

using namespace std;

void escolha1 (Projeto* projeto);
void escolha2 (Projeto* projeto);
void escolha3 (Projeto* projeto);

int main () {

int escolha;
string nome;
cout << "Digite o nome do projeto:  ";
cin >> nome;
Projeto *projeto = new Projeto(nome); //eh assim que tem q usar construtor, como se fosse funcao
//cout << projeto->getNome(); //Nat mudei de p para projeto pra ficar menos confuso blz?



do {
    cout << "1 - Adicionar pessoa" << endl;
    cout << "2 - Adicionar atividade" << endl;
    cout << "3 - Imprimir projeto" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha a opcao:  ";
    cin >> escolha;
    /* cout << escolha; Precisa disso Nat? Lembra que td q ta em vermelho é o q o usuario insere */
    if (escolha == 1) {
        escolha1 (projeto);
    }else if (escolha == 2) {
        escolha2 (projeto);
    }else if (escolha == 3) {
        escolha3 (projeto);
    }
} while (escolha); // enquanto escolha!=0
return 0;
}


void escolha1 (Projeto* projeto) {
    string nome;
    double valor;
    int horas;
    bool pessoaAdicionada;

    cout << "Nome:  ";
    cin >> nome;
    //Acho que nao precisa do -1, dps da uma checada nisso
    //Lembra que o que tá em vermelho eh o usuario que inseriu, entao n tem q imprimir
    cout << "Valor por hora (em R$):  ";
    cin >> valor;
    cout << "Horas Diarias:  ";
    cin >> horas;
    Pessoa* pessoa = new Pessoa(nome,valor,horas);
    pessoaAdicionada = projeto->adicionarRecurso(pessoa);
    if (pessoaAdicionada == false) {
        cout << "Nao eh possivel adicionar uma nova pessoa";
    }

}

void escolha2 (Projeto* projeto) {
    string nome;
    char opcao; //opcao = s ou n
    int horas;
    int numero; //numero da pessoa a ser adicionada ou 0
    bool atividadeAdicionada; //se foi possivel add a atividade ao projeto
    bool pessoaAdicionada; //se foi possivel add a pessoa à atividade
    Pessoa* pessoas[MAXIMO_RECURSOS];


    cout << "Nome:  ";
    cin >> nome;
    //Acho que nao precisa do -1, dps da uma checada nisso
    //Lembra que o que tá em vermelho eh o usuario que inseriu, entao n tem q imprimir
    cout << "Horas necessarias:  ";
    cin >> horas;
    Atividade* atividade = new Atividade(nome,horas);
    atividadeAdicionada = projeto->adicionar(atividade);
    if (atividadeAdicionada == false) {
        cout << "Nao eh possivel adicionar uma nova atividade" << endl;
    } else {
        while ( 1 ) {
            cout << "Deseja adicionar um recurso (s/n)? ";
            cin >> opcao; //opcao é s ou n
            if ( opcao == 'n') {
                    return; //encerra aqui essa função void
            } else {

                    for (int i=0; i<projeto->getQuantidadeDePessoas(); i++) {
                        pessoas[i] = projeto->getPessoas()[i];
                        cout << i+1 << " - ";
                        pessoas[i]->imprimir();
                    }
                    cout << "Escolha uma pessoa ou 0 para cancelar  ";
                    cin >> numero;
                    pessoaAdicionada = atividade->adicionar(pessoas[numero-1]);
                    if (pessoaAdicionada == false) {
                        cout << "Nao eh possivel adicionar a pessoa" << endl;
                    }
            }

        }


    }


}

void escolha3 (Projeto* projeto) {
    projeto->imprimir();

}




