#ifndef PESSOA_H
#define PESSOA_H
#include <string>
using namespace std;

class Pessoa
{
    public:
         Pessoa(string nome, double valorPorHora, int horasDiarias); //substitui os setters
        //virtual ~Pessoa();
        //void setNome(string nome);
        string getNome();
        //void setValorPorHora(double valor);
        double getValorPorHora();
        //void setHorasDiarias(int horas);
        int getHorasDiarias();
        double getCusto(int dias);

        void imprimir();


   //protected:

    private:
        string nome;
        double valorPorHora;
        int horasDiarias;
};

#endif // PESSOA_H
