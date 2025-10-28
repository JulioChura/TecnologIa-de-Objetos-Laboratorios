#include <iostream>
#include <functional>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <memory>

using namespace std;

// Clase template
template<typename T>
class IntegradorTrapecio {
    private:
        function<T(T)> funcion;
        T a, b;
        int n;

        // Función amiga para mostrar info
        template<typename U>
        friend void mostrarInfoIntegrador(const IntegradorTrapecio<U>& integrador);

    public:
        // Constructor
        IntegradorTrapecio(function<T(T)> func, T limite_inf, T limite_sup, int particiones) 
            : funcion(func), a(limite_inf), b(limite_sup), n(particiones) {
            
            // Manejo de excepciones
            if (n <= 0) throw invalid_argument("El número de particiones debe ser positivo");
            if (a >= b) throw invalid_argument("Límite inferior debe ser menor que límite superior");
            if (!funcion) throw invalid_argument("Función no válida");
        }

        // Sobrecarga del operador () para calcular la integral
        T operator()() const {
            return calcularIntegral();
        }

        // Método principal con lambda
        T calcularIntegral() const {
            T h = (b - a) / n;
            T suma = 0.0;

            // Función lambda para calcular f(x) con manejo de excepciones
            auto calcular_fx = [this](T x) -> T {
                try {
                    return this->funcion(x);
                } catch (const exception& e) {
                    throw runtime_error("Error al evaluar función en x=" + to_string(x) + ": " + e.what());
                }
            };

            // Aplicar regla del trapecio
            suma += calcular_fx(a) + calcular_fx(b);
            
            for (int i = 1; i < n; ++i) {
                T x = a + i * h;
                suma += 2 * calcular_fx(x);
            }

            return (h / 2) * suma;
        }

        // Función inline
        inline string obtenerInfo() const {
            return "Integral de " + to_string(a) + " a " + to_string(b) + " con " + to_string(n) + " trapecios";
        }

        // Constantes
        static constexpr T TOLERANCIA = 1e-10;
        static const int PARTICIONES_DEFAULT = 1000;
};

// Función amiga template para mostrar info
template<typename T>
void mostrarInfoIntegrador(const IntegradorTrapecio<T>& integrador) {
    cout << "🔍 Integrador: [" << integrador.a << ", " << integrador.b 
         << "] particiones: " << integrador.n << endl;
}

// Sobrecarga del operador <<
template<typename T>
ostream& operator<<(ostream& os, const IntegradorTrapecio<T>& integrador) {
    os << integrador.obtenerInfo();
    return os;
}

// Función template para calcular error
template<typename T>
T calcularError(const IntegradorTrapecio<T>& integrador, T valor_exacto) {
    T resultado = integrador();
    return abs(resultado - valor_exacto);
}

int main() {
    try {
        cout << "=== MÉTODO DEL TRAPECIO ===" << endl;

        // 1. Integral de x² de 0 a 1 (valor exacto: 1/3)
        auto funcion_cuadratica = [](double x) { return x * x; };
        IntegradorTrapecio<double> integrador1(funcion_cuadratica, 0.0, 1.0, 1000);
        
        cout << "\n1. " << integrador1 << endl;
        double resultado1 = integrador1();
        cout << "\tResultado: " << resultado1 << endl;
        cout << "\tError: " << calcularError(integrador1, 1.0/3.0) << endl;

        // 2. Integral de sin(x) de 0 a π (valor exacto: 2)
        IntegradorTrapecio<double> integrador2([](double x) { return sin(x); }, 0.0, M_PI, 500);
        
        cout << "\n2. " << integrador2 << endl;
        double resultado2 = integrador2();
        cout << "   Resultado: " << resultado2 << endl;
        cout << "   Error: " << calcularError(integrador2, 2.0) << endl;

        // 3. Uso de la función amiga
        cout << "\n3. Información con función amiga:" << endl;
        mostrarInfoIntegrador(integrador1);

        // 4. Uso del operador ()
        cout << "\n4. Usando operador (): " << integrador1() << endl;

        // 5. Manejo de excepciones
        cout << "\n5. Probando manejo de excepciones:" << endl;
        try {
            IntegradorTrapecio<double> integrador_invalido(nullptr, 0, 1, 100);
        } catch (const exception& e) {
            cout << "\tCapturada excepción: " << e.what() << endl;
        }

        // 6. Usando constante estática
        cout << "\n6. Tolerancia del método: " << IntegradorTrapecio<double>::TOLERANCIA << endl;

    } catch (const exception& e) {
        cerr << "ERROR:" << e.what() << endl;
        return 1;
    }

    return 0;
}