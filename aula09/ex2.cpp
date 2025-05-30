//Crie uma classe chamada Triangulo onde crie variáveis da classe e os métodos que são 2, o primeiro é para ver se é triangulo e o segundo é para ver
//que tipo de triangulo é/ Obs Não esquecer de verificar primeiramente se é triangulo

#include <iostream>
using namespace std;
class triangulo {
public:
    int a, b, c;

    void entrada() {
        cout << "Digite a: ";
        cin >> a;
        cout << "Digite b: ";
        cin >> b;
        cout << "Digite c: ";
        cin >> c;
    }
    bool verificaTriangulo() {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }
    void tipoTriangulo() {
        if (verificaTriangulo()) {
            if(a==b && b==c){
                cout<<"triangulo equilatero"<<endl;
            }else if(a!=b && b!=c && c!=a){
                cout<<"triangulo escaleno"<<endl;
            }else{
                cout<<"triangulo isosceles"<<endl;
            }
        }else {
            cout<<"as medidas nao formam um triangulo"<<endl;
        }
    }
};
int main() {
    triangulo triangulo;
    triangulo.entrada();
    triangulo.tipoTriangulo();
    return 0;
}