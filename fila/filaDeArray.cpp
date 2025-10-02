#include <iostream>
using namespace std;

class FilaDeArray{
    private:
        int *VET;
        int ProximaPosicaoLivre;
        int MAX;

    public:
    FilaDeArray(int qtde) {
        MAX = qtde;
        VET = new int[MAX];
        ProximaPosicaoLivre = 0;
    }

    ~FilaDeArray() {
        delete[] VET;
    }

    void Inserir(int n){
        if (ProximaPosicaoLivre < MAX)
            VET[ProximaPosicaoLivre++] = n;
    }

    void Mostra(){
        for (int i = 0; i < ProximaPosicaoLivre; i++){
            cout << VET[i] << "\n";
        }
    }

    int Remover(){
        if (ProximaPosicaoLivre > 0){
            int saiu = VET[0];
            for (int i = 0; i < ProximaPosicaoLivre; i++){
                VET[i] = VET[i + 1];
            }
            ProximaPosicaoLivre--;
            return saiu;
        };
    }
};

int main(int argc, char *argv[])
{
    FilaDeArray fila(50);
    fila.Inserir(3);
    fila.Inserir(5);
    fila.Inserir(7);
    fila.Inserir(1);
    fila.Mostra();
    cout << "\nRemover " << fila.Remover() << ".\n";
    cout << "\nRemover " << fila.Remover() << ".\n";
    fila.Mostra();
    cout << "\n";
    fila.Inserir(2);
    fila.Inserir(0);
    fila.Mostra();
}
