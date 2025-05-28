#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void ordenarVetor(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int buscaBinaria(const vector<int>& arr, int valorBuscado) {
    int inicio = 0;
    int fim = arr.size() - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == valorBuscado) {
            return meio;
        }

        if (arr[meio] < valorBuscado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // nao encontrou
}

int main() {
    vector<int> numeros = {12, 11, 13, 5, 6, 7};
    cout << "Original: ";
    for (int x : numeros) {
        cout << x << " ";
    }
    cout << endl;

    ordenarVetor(numeros);

    cout << "Ordenado: ";
    for (int x : numeros) {
        cout << x << " ";
    }
    cout << endl;

    // exemplos de busca:
    cout << "Buscando 13: " << buscaBinaria(numeros, 13) << endl; // Deve encontrar
    cout << "Buscando 9: " << buscaBinaria(numeros, 9) << endl;   // Não deve encontrar
    cout << "Buscando 5: " << buscaBinaria(numeros, 5) << endl;   // Deve encontrar

    return 0;
}