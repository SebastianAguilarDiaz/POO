#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <iomanip>
using namespace std;

void line(int x=55){while(x--) {cout<<'-';} cout<<endl;}

void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

class libro {
    private:
    string nombre;
    int id = 0;
    int unidades = 0;
    float precio = 0;

    public:
    libro() {}
    libro(string n) {
        nombre = n;
    }
    libro(string n, int i, float p) {
        nombre = n;
        id = i;
        precio = p;
    }
    libro(string n, int i, float p, int u) {
        nombre = n;
        id = i;
        precio = p;
        unidades = u;
    }
    void imprimirDetalles(){
        cout << left<< setw(30) << this->nombre << "|" << setw(5);
        if(this->id == 0) cout << "N/A  |" << setw(8);
        else cout << this->id << "|" << setw(8);
        if(this->precio == 0) cout << "N/A     |";
        else cout << this->precio << "|";
        if(this->unidades == 0) cout << "N/A" << endl;
        else cout << this->unidades << endl;
        line();
    }
};

vector<libro> libros;

int main() {
    bool continuar = true;
    int contador = 1;
    cout << "------------ LIBROS ------------\n";

    while(continuar){
        cout << "\nSeleccione una opcion:\n  1. Ingresar datos del libro " << contador++ << "\n  2. Imprimir datos\n  0. Salir\n";
        int opcion;
        cin >> opcion;
        limpiarBuffer();
        cout << endl;
        
        switch(opcion) {
            case 1:
                cout << "Ingrese el numero de datos que desea ingresar:\n"
                << "  1: nombre\n  3: nombre, ID, precio\n  4: nombre, ID, precio, unidades\n";
                int cantidadDeDatos;
                cin >> cantidadDeDatos;
                limpiarBuffer();
                cout << endl;
                
                switch(cantidadDeDatos) {
                    case 1:{
                        string nombre;
                        cout << "Ingrese el nombre del libro: ";
                        getline(cin, nombre);
                        libro l1(nombre);
                        libros.push_back(l1);
                        break;}

                    case 3:
                        {string nombre;
                        int id;
                        float precio;
                        cout << "Ingrese el nombre del libro: ";
                        getline(cin, nombre);
                        cout << "Ingrese el ID del libro: ";
                        cin >> id;
                        limpiarBuffer();
                        cout << "Ingrese el precio del libro: ";
                        cin >> precio;
                        limpiarBuffer();
                        libro l2(nombre, id, precio);
                        libros.push_back(l2);
                        break;}

                    case 4:
                        {string nombre;
                        int id;
                        float precio;
                        int unidades;
                        cout << "Ingrese el nombre del libro: ";
                        getline(cin, nombre);
                        cout << "Ingrese el ID del libro: ";
                        cin >> id;
                        limpiarBuffer();
                        cout << "Ingrese el precio del libro: ";
                        cin >> precio;
                        limpiarBuffer();
                        cout << "Ingrese las unidades del libro: ";
                        cin >> unidades;
                        limpiarBuffer();
                        libro l3(nombre, id, precio, unidades);
                        libros.push_back(l3);
                        break;}

                    default:
                        cout << "Opcion no valida\n";
                        contador--;
                        break;
                }
                break;

            case 2:
                cout << "Nombre                        |ID   |Precio  |Unidades\n";
                line();
                for(libro l3:libros) {
                    l3.imprimirDetalles();
                }
                contador--;
                break;

            case 0:
                cout << "chao\n";
                continuar = false;
                break;

            default:
                cout << "Opcion no valida\n";
                contador--;
                break;
        }
    }
}