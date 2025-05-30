#include <iostream>
using namespace std;

class Conta {
    public:
    int numero;
    double saldo, limite;

    Conta(int num, double sld, double lim) {
        this->numero = num;
        this->saldo = sld;
        this->limite = lim;
    }

    bool saca(double valor) {
        if (valor < saldo && valor < limite) {
            saldo -= valor;
            cout << "Saque: R$" << valor << ". Conta: "<< numero << ". Novo saldo: R$"<< saldo<< endl;
            return true;
        }else {
            cout << "erro" << endl;
            return false;
        }
    }
    void deposita(double valor) {
        saldo += valor;
        cout << "Deposito: R$" << valor << ". Conta: "<< numero << ". Novo saldo: R$"<< saldo<< endl;
    }
    bool transfere(double valor, int conta) {
        if (valor < saldo && valor < limite) {
            saldo -= valor;
            cout << "Transferencia: R$" << valor << ". Conta de origem: "<< numero <<" .Conta de destino: " << conta <<". Novo saldo: R$"<< saldo<< endl;
            return true;
        }else {
            cout << "erro" << endl;
            return false;
        }
    }
};
int main() {
    Conta conta(1, 2000.00, 800.00);
    conta.saca(50);
    conta.deposita(20);
    conta.transfere(100,2);
}