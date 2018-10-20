#include "Atividade.h"
#include <iostream>
#include <cmath>

Atividade::Atividade(string nome, int horasNecessarias) {
    this->nome = nome;
    this->horasNecessarias = horasNecessarias;
}
/*
Atividade::~Atividade()
{
    //dtor
}
*/

using namespace std;


/*void Atividade::setNome(string nome){
    this->nome = nome;
}
*/
string Atividade::getNome(){
    return nome;
}

/*void Atividade::setHorasNecessarias(int horas){
    this->horasNecessarias = hora;
}
*/
int Atividade::getHorasNecessarias(){
    return horasNecessarias;
}

bool Atividade::adicionar(Pessoa* recurso){
    int i;
    for(i=0; i<numeroDePessoas; i++){
        if ( pessoas[i] == recurso ) {
            return false;
        }
    }
    if (numeroDePessoas < MAXIMO_RECURSOS) {
        pessoas[numeroDePessoas] = recurso;
        numeroDePessoas++;
        return true;
    }
    return false;
}

Pessoa** Atividade::getPessoas(){
    return pessoas;
}

int Atividade::getQuantidadeDePessoas(){
    return numeroDePessoas;
}

int Atividade::getDuracao(){
    int horasTotal = 0;
    if (numeroDePessoas == 0) {
        return -1;
    }
    for ( int i=0; i<numeroDePessoas; i++) {
        horasTotal += pessoas[i]->getHorasDiarias();
    }
    return ceil(this->horasNecessarias/horasTotal);
}

double Atividade::getCusto(){
    double custo = 0;
    if (numeroDePessoas == 0) {
        return -1;
    }
    for (int i=0; i<numeroDePessoas; i++){
        custo += pessoas[i]->getCusto(getDuracao());
    }
    return custo;
}

void Atividade::imprimir(){
    cout << nome << " - " << getDuracao() << " dias - R$" << getCusto() << endl;
}
