#include <iostream>
using namespace std;

class No {
    public: 
    No *proxNo;
    int dado;
    No (){
        proxNo = nullptr; 
    } 
};

class Pilha{
    No *topo;

    public:     
    Pilha (){
        topo = nullptr;
    }

    ~Pilha() {
        while (!PilhaVazia()) {
            Desempilha();
        }
    }

    bool PilhaVazia(){
        return (topo == nullptr);  
    }

    void Empilha (int NovoDado){
        No *novoNo = new No();
        novoNo->dado = NovoDado;
        novoNo->proxNo = topo;
        topo = novoNo;
    }

    int Desempilha() {
        int temp_Dado = 0;
        No *temp_proxNo = nullptr;
        if (PilhaVazia()== false){
            temp_Dado = topo->dado;
            temp_proxNo = topo->proxNo;

            delete topo; 
            topo  = temp_proxNo;
        }
        return temp_Dado;
    }   

    void Mostrar(){
        No* n = topo;
        if(PilhaVazia()){
            cout << "pilha vazia";
        } else {
            while(n != nullptr){
                cout << n->dado << " ";
                n = n->proxNo;
            }
        }
    }

};

int main(int argc, char *argv[]){
    Pilha p;
    cout << p.PilhaVazia()<<"\n";
    p.Empilha(5);
    p.Empilha(8);
    p.Empilha(10);
    p.Empilha(15);
    p.Mostrar();
    cout <<"Dado desempilhado: "<< p.Desempilha()<< "\n";
    cout <<"Dado desempilhado: "<< p.Desempilha()<< "\n";
    cout <<"Dado desempilhado: "<< p.Desempilha()<< "\n";
    cout <<"Dado desempilhado: "<< p.Desempilha()<< "\n";
    cout << p.PilhaVazia()<<"\n";
    return 0;
}
