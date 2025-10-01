#include <iostream>
using namespace std;

class No{
    public:
        No *proxNo;
        int dado;
    No() {
        proxNo = nullptr;
    }
};

class Fila{
    No *fim;
    No *inicio;

    public:
    Fila() {
        fim = nullptr;
        inicio = nullptr;
    }

    ~Fila() {
        while (!FilaVazia()) {
            Retira();
        }
    }

    bool FilaVazia(){
        return (inicio == nullptr);
    }
    void Insere(int NovoDado){
        No *novoNo = new No();
        novoNo->dado = NovoDado;
        if (FilaVazia() == true){
            inicio = novoNo;
            fim = novoNo;
        }  else {
            fim->proxNo = novoNo; 
            fim = novoNo;
        }
    }

    int Retira() {
        if (FilaVazia()){
            cout << "fila vazia";
            return 0;
        }

        int temp_Dado = 0;
        No *temp_proxNo = nullptr;
        if (FilaVazia() == false){
            temp_Dado = inicio->dado;
            temp_proxNo = inicio->proxNo;
            delete inicio;
            inicio = temp_proxNo;
            if (inicio == nullptr)
                fim = nullptr;
        }
        return temp_Dado;
    }
};

int main(int argc, char *argv[])
{
    Fila p;
    cout << p.FilaVazia() << "\n";
    p.Insere(5);
    p.Insere(56);
    cout << "Dado retirado: " << p.Retira() << "\n";
    cout << "Dado retirado: " << p.Retira() << "\n";

    p.Insere(8);
    p.Insere(10);
    p.Insere(12);
    p.Insere(13);
    cout << "Dado retirado: " << p.Retira() << "\n";
    cout << "Dado retirado: " << p.Retira() << "\n";
    cout << "Dado retirado: " << p.Retira() << "\n";
    cout << "Dado retirado: " << p.Retira() << "\n";
    cout << p.FilaVazia() << "\n";
}