#include <iostream>
#include <cstdlib>
#include <ctime>   
#include <vector>

using namespace std;

void generarVector(vector<int>& v, int n);
void imprimirVector(const vector<int>& v);
vector<int> filtrar(const vector<int>& v);
void mostrarResultado(const vector<int>& filtrados);

int main() {
    srand(time(0));
    const int n = 100;
    vector<int> v;

    cout << "PROGRAMA: FILTRAR NUMEROS IMPARES Y MENORES DE 20 " << endl << endl;

    generarVector(v, n);
    cout << "Vector generado (" << n << " elementos):" << endl;
    imprimirVector(v);
    cout << endl;

    vector<int> filtrados = filtrar(v);
    mostrarResultado(filtrados);

    return 0;
}

void generarVector(vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        v.push_back(rand() % 100);
    }
}

void imprimirVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> filtrar(const vector<int>& v) {
    vector<int> filtrados;
    auto esCorrecto = [](int numero) {
        return numero % 2 != 0 && numero < 20;
    };
    for (int n : v) {
        if (esCorrecto(n)) {
            filtrados.push_back(n);
        }
    }
    return filtrados;
}

void mostrarResultado(const vector<int>& filtrados) {
    cout << "Cantidad de numeros impares y menores de 20: " << filtrados.size() << endl;

    if (filtrados.empty()) {
        cout << "No se encontraron numeros impares menores de 20 en el vector." << endl;
    } else {
        cout << "Numeros impares menores de 20 encontrados:" << endl;
        for (int num : filtrados) {
            cout << num << " ";
        }
        cout << endl;
    }
}
