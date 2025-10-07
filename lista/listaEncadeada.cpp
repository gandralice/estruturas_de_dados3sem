#include <iostream>
using namespace std;

class Celula {
    private:
        int conteudo;

    public:
        Celula *prox;
    Celula(int c) {
        conteudo = c;
        prox = NULL;
    }
    int getConteudo() {
        return conteudo;
    }
};

class ListaEncadeada {
    private:
        Celula *primeira;
        Celula *ultima;
        int tamanho;

    public:
    ListaEncadeada() {
        primeira = NULL;
        ultima = NULL;
        tamanho = 0;
    }

    void inserir(int indiceInserir, int conteudo) {
        if (indiceInserir < 0) {
            cout << "erro ao inserir - índice inválido";
            return;
        }
        Celula *nova = new Celula(conteudo);
        if (primeira == NULL) {
            primeira = nova;
            ultima = nova;
        }
        else if (indiceInserir == 0) {
            nova->prox = primeira;
            primeira = nova;
        }
        else if (indiceInserir == tamanho) {
            ultima->prox = nova;
            ultima = nova;
        }
        else {
            Celula *atual = primeira;
            for (int i = 0; i < indiceInserir - 1; ++i) {
                atual = atual->prox;
            }
            nova->prox = atual->prox; 
            atual->prox = nova;
        }
        tamanho++;
    }

    void imprimir() {
        if (primeira == NULL){
            cout << "lista vazia";
            return;
        }
        for (Celula *p = primeira; p != NULL; p = p->prox) {
            cout << p->getConteudo() << "\n"; 
        }
    }

    int remover(int indice) {
        if (primeira == NULL) {
            cout << "lista vazia";
            return -1;
        }
        else if (indice < 0 || indice > tamanho) {
            cout << "índice inválido";
            return -1;
        }

        int conteudoRemover = 0;
        Celula *remover = primeira;
        Celula *anterior = primeira; 

        if (indice == 0) {
            conteudoRemover = remover->getConteudo();
            primeira = primeira->prox;
            if (primeira == NULL){
                ultima = NULL;
            }
        } else {
            for (int i = 0; i < indice - 1; ++i) {
                anterior = anterior->prox; 
            }
            remover = anterior->prox;
            conteudoRemover = remover->getConteudo();
            anterior->prox = remover->prox;
            if (remover == ultima) {
                ultima = anterior;
            }
        }
        tamanho--;
        delete remover;
        return conteudoRemover;
    }
};

int main(int argc, char *argv[]) {
    ListaEncadeada lista;
    lista.inserir(0, 10); 
    lista.inserir(1, 30);     
    lista.inserir(1, 20);    
    lista.inserir(0, 5);  
    lista.imprimir();

    cout << "Removido: " << lista.remover(2) << endl;
    cout << "Removido: " << lista.remover(0) << endl;                         
    cout << "Removido: " << lista.remover(1) << endl;                             
    cout << "Removido: " << lista.remover(0) << endl;              
    cout << "Removido: " << lista.remover(0) << endl;
    lista.imprimir();
    return 0;
}
