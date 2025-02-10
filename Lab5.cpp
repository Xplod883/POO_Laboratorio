#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <locale.h>

using namespace std;

class Producto {
private:
    string nombre;
    int codigo;
    float precio;
    int stock;

public:
    Producto(string nom, int cod, float prec, int stk) {
        nombre = nom;
        codigo = cod;
        precio = prec;
        stock = stk;
    }

    void mostrar() {
        cout << "Código: " << codigo << ", Producto: " << nombre
            << ", Precio: Q" << precio << ", Stock: " << stock << endl;
    }

    int obtenerCodigo() {
        return codigo;
    }

    int obtenerStock() {
        return stock;
    }

    void actualizarStock(int cantidad) {
        if (cantidad > stock) {
            cout << "No hay suficiente stock disponible." << endl;
        }
        else {
            stock -= cantidad;
            cout << "Stock actualizado. Nuevo stock: " << stock << endl;
        }
    }

    float obtenerValor() {
        return stock * precio;
    }
};

void agregarProducto(vector<Producto>& inventario) {
    string nombre;
    int codigo, stock;
    float precio;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
    getline(cin, nombre);
    cout << "Ingrese el código: ";
    cin >> codigo;
    cout << "Ingrese el precio: ";
    cin >> precio;
    cout << "Ingrese la cantidad en stock: ";
    cin >> stock;

    inventario.push_back(Producto(nombre, codigo, precio, stock));
}

void mostrarInventario(vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "No hay productos en el inventario." << endl;
        return;
    }
    for (Producto& producto : inventario) {
        producto.mostrar();
    }
}

void buscarProducto(vector<Producto>& inventario) {
    int codigo;
    cout << "Ingrese el código del producto a buscar: ";
    cin >> codigo;

    for (Producto& producto : inventario) {
        if (producto.obtenerCodigo() == codigo) {
            cout << "Producto encontrado: ";
            producto.mostrar();
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void actualizarStock(vector<Producto>& inventario) {
    int codigo, cantidad;
    cout << "Ingrese el código del producto a actualizar: ";
    cin >> codigo;

    for (Producto& producto : inventario) {
        if (producto.obtenerCodigo() == codigo) {
            cout << "Ingrese la cantidad a restar del stock: ";
            cin >> cantidad;
            producto.actualizarStock(cantidad);
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void calcularValorTotal(vector<Producto>& inventario) {
    float total = 0;
    for (Producto& producto : inventario) {
        total += producto.obtenerValor();
    }
    cout << "Valor total del inventario: Q" << total << endl;
}

void eliminarProducto(vector<Producto>& inventario) {
    int codigo;
    cout << "Ingrese el código del producto a eliminar: ";
    cin >> codigo;

    for (size_t i = 0; i < inventario.size(); i++) {
        if (inventario[i].obtenerCodigo() == codigo) {
            inventario.erase(inventario.begin() + i);
            cout << "Producto eliminado exitosamente." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

// Función principal
int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    vector<Producto> inventario;
    int opcion;

    do {
        cout << "\nSistema de inventario\n";
        cout << "1. Agregar producto.\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Buscar producto por código.\n";
        cout << "4. Actualizar stock.\n";
        cout << "5. Calcular valor total del inventario\n";
        cout << "6. Eliminar producto\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregarProducto(inventario);
            break;
        case 2:
            mostrarInventario(inventario);
            break;
        case 3:
            buscarProducto(inventario);
            break;
        case 4:
            actualizarStock(inventario);
            break;
        case 5:
            calcularValorTotal(inventario);
            break;
        case 6:
            eliminarProducto(inventario);
            break;
        case 7:
            cout << "Saliendo del programa, por favor espere...\n";
            break;
        default:
            cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (opcion != 7);

    return 0;
}
