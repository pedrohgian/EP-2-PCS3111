#ifndef ATIVIDADE_H
#define ATIVIDADE_H
#define MAXIMO_RECURSOS 10
#include "Pessoa.h"

class Atividade
{
    public:

        Atividade(string nome, int horasNecessarias);
        //virtual ~Pessoa();

        //void setNome(string nome);
        string getNome();
        //void setHorasNecessarias(int horas);
        int getHorasNecessarias();


        bool adicionar(Pessoa* recurso);
        /*(add pessoa na atividade, informando que ela trabalhará na atividade)*/
        /*(retorna true se a pessoa foi add e false se não (MAXIMO_RECURSOS completos ou pessoa ja foi add))*/

        Pessoa** getPessoas();
        //retorna vetor com tdas as pessoas add à atividade

        int getQuantidadeDePessoas();
        //retorna numero de pessoas no vetor getPessoas

        int getDuracao();

        double getCusto();

        void imprimir();



   //protected:

    private:
        string nome;
        int horasNecessarias;
        Pessoa *pessoas[MAXIMO_RECURSOS];
        int numeroDePessoas = 0; //contador para o numero de pessoas na atividade

};

#endif // ATIVIDADE_H


