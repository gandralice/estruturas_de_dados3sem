#include <iostream>
using namespace std;

class PilhaDeArray{
     private: 
          int *VET;
          int ProximaPosicaoLivre;
          int MAX;
     public:
          PilhaDeArray(int qtde){
               MAX = qtde;
               VET = new int[MAX];
               ProximaPosicaoLivre = 0;
          }
          ~PilhaDeArray() {
               delete[] VET;
          }

          void Empilha(int n){
                if(ProximaPosicaoLivre < MAX) VET[ProximaPosicaoLivre++] = n;
          }

          void Mostra(){
               for(int i = 0; i<ProximaPosicaoLivre; i++){
				cout <<VET[i] <<"\n";
               }
          }

          int Desempilha(){ 
               if(ProximaPosicaoLivre > 0) {return VET[--ProximaPosicaoLivre];}
               else {cout << "erro: pilha está vazia" ; return -1;}
          }
};
int main(int argc, char *argv[]){
     PilhaDeArray pilha(5);
     pilha.Empilha(3);
     pilha.Empilha(5);
     pilha.Empilha(7);
     pilha.Empilha(1);
     pilha.Mostra();
     cout <<"\nDesempilha " <<pilha.Desempilha() <<".\n";
     cout <<"\nDesempilha " <<pilha.Desempilha() <<".\n";
     pilha.Mostra();
     return 0;
}
