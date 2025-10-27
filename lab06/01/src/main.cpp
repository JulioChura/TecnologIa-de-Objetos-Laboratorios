#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

// Función para demostrar el uso con diferentes tipos
void demostrarListaEdades() {
    cout << "=== PRUEBA CON LISTA DE EDADES (int) ===" << endl;
    LinkedList<int> edades;
    
    // Insertar edades
    cout << "\nInsertando edades..." << endl;
    edades.insert(25);
    edades.insert(30);
    edades.insert(22);
    edades.insert(35);
    
    // Mostrar lista
    cout << "Lista de edades: ";
    edades.toString();
    cout << "Tamaño: " << edades.size() << ", Vacía: " << (edades.isEmpty() ? "Sí" : "No") << endl;
    
    // Buscar elementos
    cout << "\nBuscando elementos..." << endl;
    int buscarEdad = 30;
    int posicion = edades.find(buscarEdad);
    if (posicion != -1) {
        cout << "Edad " << buscarEdad << " encontrada en posición " << posicion << endl;
    } else {
        cout << "Edad " << buscarEdad << " no encontrada" << endl;
    }
    
    // Obtener elemento por índice
    cout << "\nObteniendo elementos por índice..." << endl;
    try {
        cout << "Elemento en posición 0: " << edades.get(0) << endl;
        cout << "Elemento en posición 2: " << edades.get(2) << endl;
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Insertar en posición específica
    cout << "\nInsertando edad 18 en posición 0..." << endl;
    edades.insertAt(18, 0);
    cout << "Lista después de insertar al inicio: ";
    edades.toString();
    
    cout << "Insertando edad 28 en posición 2..." << endl;
    edades.insertAt(28, 2);
    cout << "Lista después de insertar en posición 2: ";
    edades.toString();
    
    // Eliminar elementos
    cout << "\nEliminando elementos..." << endl;
    try {
        int eliminado = edades.remove(1);
        cout << "Elemento eliminado en posición 1: " << eliminado << endl;
        cout << "Lista después de eliminar: ";
        edades.toString();
        
        eliminado = edades.remove(0);
        cout << "Elemento eliminado en posición 0: " << eliminado << endl;
        cout << "Lista después de eliminar: ";
        edades.toString();
    } catch (const out_of_range& e) {
        cout << "Error al eliminar: " << e.what() << endl;
    }
}

void demostrarListaPalabras() {
    cout << "\n\n=== PRUEBA CON LISTA DE PALABRAS (string) ===" << endl;
    LinkedList<string> palabras;
    
    // Insertar palabras
    cout << "\nInsertando palabras..." << endl;
    palabras.insert("Hola");
    palabras.insert("Mundo");
    palabras.insert("C++");
    palabras.insert("Template");
    
    // Mostrar lista
    cout << "Lista de palabras: ";
    palabras.toString();
    cout << "Tamaño: " << palabras.size() << ", Vacía: " << (palabras.isEmpty() ? "Sí" : "No") << endl;
    
    // Buscar elementos
    cout << "\nBuscando elementos..." << endl;
    string buscarPalabra = "C++";
    int posicion = palabras.find(buscarPalabra);
    if (posicion != -1) {
        cout << "Palabra '" << buscarPalabra << "' encontrada en posición " << posicion << endl;
    } else {
        cout << "Palabra '" << buscarPalabra << "' no encontrada" << endl;
    }
    
    // Obtener elemento por índice
    cout << "\nObteniendo elementos por índice..." << endl;
    try {
        cout << "Elemento en posición 1: " << palabras.get(1) << endl;
        cout << "Elemento en posición 3: " << palabras.get(3) << endl;
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Insertar en posición específica
    cout << "\nInsertando 'Inicio' en posición 0..." << endl;
    palabras.insertAt("Inicio", 0);
    cout << "Lista después de insertar al inicio: ";
    palabras.toString();
    
    cout << "Insertando 'Medio' en posición 3..." << endl;
    palabras.insertAt("Medio", 3);
    cout << "Lista después de insertar en posición 3: ";
    palabras.toString();
    
    // Eliminar elementos
    cout << "\nEliminando elementos..." << endl;
    try {
        string eliminado = palabras.remove(2);
        cout << "Elemento eliminado en posición 2: '" << eliminado << "'" << endl;
        cout << "Lista después de eliminar: ";
        palabras.toString();
        
        eliminado = palabras.remove(0);
        cout << "Elemento eliminado en posición 0: '" << eliminado << "'" << endl;
        cout << "Lista después de eliminar: ";
        palabras.toString();
    } catch (const out_of_range& e) {
        cout << "Error al eliminar: " << e.what() << endl;
    }
}

void pruebaCasosEspeciales() {
    cout << "\n\n=== PRUEBA DE CASOS ESPECIALES ===" << endl;
    
    // Lista vacía
    LinkedList<int> listaVacia;
    cout << "Lista vacía - Tamaño: " << listaVacia.size() << ", Vacía: " << (listaVacia.isEmpty() ? "Sí" : "No") << endl;
    
    // Insertar un solo elemento
    listaVacia.insert(100);
    cout << "Después de insertar un elemento - Tamaño: " << listaVacia.size() << endl;
    cout << "Lista con un elemento: ";
    listaVacia.toString();
    
    // Eliminar el único elemento
    try {
        int valor = listaVacia.remove(0);
        cout << "Elemento eliminado: " << valor << endl;
        cout << "Lista después de eliminar: ";
        listaVacia.toString();
        cout << "Tamaño: " << listaVacia.size() << ", Vacía: " << (listaVacia.isEmpty() ? "Sí" : "No") << endl;
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Prueba con búsqueda de elemento no existente
    LinkedList<string> frutas;
    frutas.insert("Manzana");
    frutas.insert("Pera");
    
    int pos = frutas.find("Banana");
    cout << "\nBuscando 'Banana' en lista de frutas: " << (pos != -1 ? "Encontrado" : "No encontrado") << endl;
}

int main() {
    cout << "DEMOSTRACIÓN DE LISTA ENLAZADA TEMPLATE" << endl;
    cout << "=======================================" << endl;
    
    // Prueba con lista de edades (int)
    demostrarListaEdades();
    
    // Prueba con lista de palabras (string)
    demostrarListaPalabras();
    
    // Prueba de casos especiales
    pruebaCasosEspeciales();
    
    cout << "\n\n=== PRUEBA COMPLETADA ===" << endl;
    
    return 0;
}