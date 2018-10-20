#include "Projeto.h"
#include <iostream>
using namespace std;


Projeto::Projeto(string nome) {
    this->nome = nome;
}

/*Projeto::~Projeto()
{
    //dtor
}
*/


string Projeto::getNome() {
    return nome;
}

bool Projeto::adicionar(Atividade* a){

    if (numeroDeAtividades < MAXIMO_ATIVIDADES) {
        atividades[numeroDeAtividades] = a;
        numeroDeAtividades++;
        return true;
    }
    return false;
}


Atividade** Projeto::getAtividades(){
    return atividades;
}

int Projeto::getQuantidadeDeAtividades(){
    return numeroDeAtividades;

}

bool Projeto::adicionarRecurso(Pessoa* p){
    int i;
    for(i=0; i<this->numeroDePessoas; i++){ //nao sei se precisa do this, mas coloquei pra garantir
        if ( pessoas[i] == p ) {
            return false;
        }
    }
    if (this->numeroDePessoas < MAXIMO_RECURSOS) { //nao sei se precisa do this, mas coloquei pra garantir
        pessoas[this->numeroDePessoas] = p;
        this->numeroDePessoas++;
        return true;
    }
    return false;
}


Pessoa** Projeto::getPessoas(){
    return pessoas;

}

int Projeto::getQuantidadeDePessoas(){
    return numeroDePessoas;

}

int Projeto::getDuracao(){
    int duracao = 0;
    int i;
    for(i=0; i< numeroDeAtividades; i++) {
        duracao += atividades[i]->getDuracao();
    }
    return duracao;

}

double Projeto::getCusto(){
    int custo = 0;
    int i;
    for(i=0; i< numeroDeAtividades; i++) {
        custo += atividades[i]->getCusto();
    }
    return custo;

}

void Projeto::imprimir(){
    int i;
    cout << nome << " - " << getDuracao() << " dias - R$" << getCusto() << endl;
    cout << "----" << endl;
    for(i=0; i<numeroDeAtividades; i++) {
        atividades[i]->imprimir();
    }
}
