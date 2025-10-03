#include <iostream>
using namespace std;

class No {
    public:
        No *proxNo;
        No *anteriorNo;
        int dado;
    No(){
        proxNo = nullptr;
        anteriorNo = nullptr;
    }
};

class Lista {
    No *fim;
    No *inicio;

    public:
    Lista(){
        fim = nullptr;    
        inicio = nullptr; 
    }
    bool ListaVazia() {
        return (inicio == nullptr);
    }
    void InsereNoFim(int NovoDado) {
        No *novoNo = new No();
        novoNo->dado = NovoDado;
        if (ListaVazia() == true){
            inicio = novoNo;
        } else {
            fim->proxNo = novoNo;
            novoNo->anteriorNo = fim;
        }
        fim = novoNo;
    }

    void InsereNoInicio(int NovoDado) {
        No *novoNo = new No();
        novoNo->dado = NovoDado;
        if (ListaVazia() == true)
            fim = novoNo;
        else {
            inicio->anteriorNo = novoNo;
            novoNo->proxNo = inicio;
        }
        inicio = novoNo;
    }

    int RetiraDoInicio() {
        int temp_Dado = 0;
        No *temp_proxNo = nullptr;
        No *temp_anteriorNo = nullptr;
        if (ListaVazia() == false){
            temp_Dado = inicio->dado;
            temp_proxNo = inicio->proxNo;
            temp_anteriorNo = inicio->anteriorNo;
            delete inicio;        
            inicio = temp_proxNo;
            if (inicio != nullptr)
                inicio->anteriorNo = temp_anteriorNo;
            else
                fim = nullptr;
        }
        return temp_Dado;
    }

    int RetiraDoFim() {
        int temp_Dado = 0;
        No *temp_proxNo = nullptr;
        No *temp_anteriorNo = nullptr;
        if (ListaVazia() == false){
            temp_Dado = fim->dado;
            temp_proxNo = fim->proxNo;
            temp_anteriorNo = fim->anteriorNo;
            delete fim;       
            fim = temp_anteriorNo;
            if (fim != nullptr)
                fim->proxNo = temp_proxNo;
            else
                inicio = nullptr;
        }
        return temp_Dado;
    }

    void MostraLista() {
        No *temp;
        temp = inicio;
        while (temp != nullptr)
        {
            cout << temp->dado << "  ";
            temp = temp->proxNo;
        }
    }
};

int main(int argc, char *argv[]) {
    Lista p;
    p.MostraLista();
    p.InsereNoInicio(5);
    p.InsereNoInicio(6);
    p.InsereNoFim(7);
    p.InsereNoInicio(4);
    p.MostraLista();
    cout << "Retirado do Inicio: " << p.RetiraDoInicio() << "\n";
    cout << "Retirado do Fim: " << p.RetiraDoFim() << "\n";
    cout << "Retirado do Inicio: " << p.RetiraDoInicio() << "\n";
    cout << "Retirado do Inicio: " << p.RetiraDoInicio() << "\n";
    p.InsereNoInicio(8);
    p.InsereNoFim(12);
    p.InsereNoFim(0);
    p.InsereNoInicio(-5);
    p.MostraLista();
    cout << "\n";
}
