#include "Pessoa.h"
#include <iostream>

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias) {
    this->nome = nome;
    this->valorPorHora = valorPorHora;
    this->horasDiarias = horasDiarias;
}


/*Pessoa::~Pessoa()
{
    //dtor
}
*/

using namespace std;

/*void Pessoa::setNome(string nome) {
    this->nome = nome;

}*/

string Pessoa::getNome() {
    return nome;

}

/*void Pessoa::setValorPorHora(double valor) {
    this->valorPorHora = valor;

}*/

double Pessoa::getValorPorHora(){
    return valorPorHora;

}

/*void Pessoa::setHorasDiarias(int horas){
    this->horasDiarias = horas;

}*/

int Pessoa::getHorasDiarias(){
    return horasDiarias;

}

double Pessoa::getCusto(int dias){
    return dias*horasDiarias*valorPorHora;

}

void Pessoa::imprimir(){
    cout << nome << " - R$" << valorPorHora << " - " << horasDiarias << "h por dia" << endl;

}
