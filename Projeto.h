#ifndef PROJETO_H
#define PROJETO_H
#define MAXIMO_ATIVIDADES 10
#include "Atividade.h"

class Projeto
{
    public:

        Projeto(string nome);
        //~Projeto();
        string getNome();

        bool adicionar(Atividade* a);
        Atividade** getAtividades();
        int getQuantidadeDeAtividades();

        bool adicionarRecurso(Pessoa* p);
        Pessoa** getPessoas();
        int getQuantidadeDePessoas();

        int getDuracao();
        double getCusto();

        void imprimir();

    private:
        string nome;
        Atividade *atividades[MAXIMO_ATIVIDADES]; //vetor com todas as atividades desse projeto
        int numeroDeAtividades = 0; //criei contador de numero de atividades no projeto
        Pessoa* pessoas[MAXIMO_RECURSOS];
        int numeroDePessoas =0; // similar ao que fiz no "Atividade.h"
};

#endif // PROJETO_H
