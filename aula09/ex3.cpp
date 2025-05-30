//Crie uma classe Estacionamento que tenha como atributos da classe dia, horaEntrada, horaSaida, e dois métodos o primeiro
// Solicita os dados para o usuário e o outro métod calcule o valor a ser pago sendo que cada hora equivale a 5 reais
#include <iostream>
using namespace std;

class estacionamento{
public:
    int dia, horaEntrada, horaSaida;
    void entrada(){
        cout<<"Dia: ";
        cin>>dia;
        cout<<"Entrada: ";
        cin>>horaEntrada;
        cout<<"Saida: ";
        cin>>horaSaida;
    }
    double val(){
        int total= horaSaida-horaEntrada;
        return total*5.0;
    }
    void saida(){
        cout<<"Dia: "<<dia<<" Valor a pagar: $"<<val();
    }
};


int main()
{
    estacionamento obj;
    obj.entrada();
    obj.saida();

    return 0;
}