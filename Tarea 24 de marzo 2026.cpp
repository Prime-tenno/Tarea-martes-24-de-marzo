#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;

struct producto {
    int id;
    string descripcion;
    int cantidad;
    float precio;
};

bool compararAlfabeticamente(producto *a, producto *b) {
    return a->descripcion < b->descripcion;
}

int main() {
    int n; // Faltaba ;

    cout << "Ingrese cantidad de productos: ";
    cin >> n;

    producto** inventario = new producto*[n];

    for (int i = 0; i < n; i++) {
        inventario[i] = new producto; 
        
        cout << "\nProducto #" << i + 1 << ":" << endl;
        cout << "Id: "; cin >> inventario[i]->id;
        cin.ignore();

        cout << "Descripcion: "; getline(cin, inventario[i]->descripcion);
        cout << "Cantidad: "; cin >> inventario[i]->cantidad;
        cout << "Precio: "; cin >> inventario[i]->precio;
    }

    sort(inventario, inventario + n, compararAlfabeticamente);

    cout << "\n--- Inventario ordenado por Descripcion ---" << endl;
    for (int i = 0; i < n; i++) { 
        cout << "ID: " << inventario[i]->id
             << " | Desc: " << inventario[i]->descripcion
             << " | Cant: " << inventario[i]->cantidad
             << " | Precio: " << inventario[i]->precio << endl;
    }

  
    for (int i = 0; i < n; i++) { 
        delete inventario[i];
    }
    delete[] inventario; 
    return 0;
}
