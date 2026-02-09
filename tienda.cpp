#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
#include<chrono>
#include<string.h>
#include<set>
#include<algorithm>
#include<iomanip>

using namespace std;

// version bonita

void line(int x=33){while(x--) {cout<<'-';} cout<<endl;}

void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct verdura {

    string nombre;
    float precio;
    float tiempo_de_vida;
    string fecha_de_compra;

    void imprimirDatos(){
        cout<<left<<setw(10)<<nombre<<"|"<<setw(6)<<precio<<"|"<<setw(6)<<tiempo_de_vida<<"|"<<fecha_de_compra<<endl;
        line();
    }

    void pedirDatos(){
        cout<<"Ingrese el nombre: ";
        getline(cin,nombre);
        cout<<"Ingrese el precio: ";
        cin>>this->precio;
        cout<<"Ingrese el tiempo de vida (en dias): ";
        cin>>this->tiempo_de_vida;
        cout<<"Ingrese la fecha de compra: ";
        cin>>this->fecha_de_compra;
        limpiarBuffer();
    }
};

struct abarrote {

    string nombre;
    float precio;
    string fecha_de_caducidad;

    void imprimirDatos(){
        cout<<setw(10)<<nombre<<"|"<<setw(10)<<precio<<"|"<<fecha_de_caducidad<<endl;
        line();
    }

    void pedirDatos(){
        cout<<"Ingrese el nombre: ";
        getline(cin,this->nombre);
        cout<<"Ingrese el precio: ";
        cin>>this->precio;
        cout<<"Ingrese la fecha de caducidad: ";
        cin>>this->fecha_de_caducidad;
        limpiarBuffer();
    }
};

struct estante{

    int numero_de_estante;
    string fecha_de_actualizacion;
    string persona_que_actualizo;
    vector<verdura> verduras;
    vector<abarrote> abarrotes;

    // constructor
    estante(int estante){
        // guardar el numero de estante
        this->numero_de_estante=estante;

        cout<<"Estante "<<estante<<endl;
        actualizarEstante();
    }

    // imprimir lo que contiene el estante
    void imprimirDatos(){
        cout<<"\nESTANTE "<<this->numero_de_estante<<endl;
        cout<<"Fecha de la ultima actualizacion: "<<this->fecha_de_actualizacion<<"\nPersona que lo actualizo: "<<this->persona_que_actualizo<<endl<<endl;
        cout<<"* VERDURAS *\n";
        cout<<setw(10)<<"Nombre"<<"|Precio|Tiempo|Fecha\n";
        line();
        for(verdura &n:this->verduras) n.imprimirDatos();
        cout<<"\n+ ABARROTES +\n";
        cout<<setw(10)<<"Nombre"<<"|Precio    |Caducidad\n";
        line();
        for(abarrote &n:this->abarrotes) n.imprimirDatos();
    }

    // para ingresar productos al estante
    void actualizarEstante(){
        cout<<"Quien actualiza el estante? ";
        getline(cin>>ws,this->persona_que_actualizo);

        cout<<"Ingrese la fecha actual: ";
        cin>>this->fecha_de_actualizacion;

        cout<<"Cantidad de productos del estante "<< this->numero_de_estante << ": ";
        int cantidad_de_productos;
        cin>>cantidad_de_productos;
        limpiarBuffer();

        // minimo deben haber 8 productos en el estante
        while(cantidad_de_productos<8){
            cout<<"Deben ser al menos 8 productos.\n";
            cout<<"Ingrese cuantos productos contendra el estante: "<< this->numero_de_estante <<endl;
            cin>>cantidad_de_productos;
            limpiarBuffer();
        }
        verdura v1;
        abarrote a1;

        // vacia el estante
        verduras.clear();
        abarrotes.clear();

        // ingresa los productos
        while(cantidad_de_productos){
            char tipo;
            cout<<"\nProductos restantes: "<<cantidad_de_productos--<<endl;
            cout<<"Verdura(v) o abarrote(a)?\t";
            cin>>tipo;
            limpiarBuffer();

            if (tipo=='a'){
                a1.pedirDatos();
                this->abarrotes.push_back(a1);
            }

            else if(tipo=='v'){
                v1.pedirDatos();
                this->verduras.push_back(v1);
            }
            // si no ingreso ninguno de los dos tipos mencionados no cunta el intento
            else cantidad_de_productos++;
            //cout<<endl;
        }
    }
};

struct tienda{
    vector<estante> estantes;
    tienda(int cantidad_de_estantes){
        int i=1;
        while(cantidad_de_estantes--){
            cout<<endl;
            estante n(i++);
            cout<<endl;
            estantes.push_back(n);
        }
    }

    void actualizarEstante(){
        cout<<"\nIngrese que estante desea actualizar: ";
        int n;
        cin>>n;
        limpiarBuffer();
        this->estantes.at(n-1).actualizarEstante();
    }

    void imprimirInventario(){
        for(estante &n:estantes){
            n.imprimirDatos();
            cout<<endl;
        }
    }
};

int CANTIDAD_DE_ESTANTES;

int main(){
    cout<<"---------- INVENTARIO ----------\nIngrese la cantidad de estantes: ";
    cin>>CANTIDAD_DE_ESTANTES;
    
    while(CANTIDAD_DE_ESTANTES<4){
        cout<<"Deben ser minimo 4 estantes.\n";
        cout<<"Ingrese la cantidad de estantes: ";
        cin>>CANTIDAD_DE_ESTANTES;
    }

    tienda t1(CANTIDAD_DE_ESTANTES);
    int opcion;
    do{
        cout<<"Escoja una opcion:\n(0) Salir\n(1) Ver inventario\n(2) Actualizar estante\n";
        cin>>opcion;
        limpiarBuffer();
        switch(opcion){
            case 1:
                t1.imprimirInventario();
                break;
            case 2:
                t1.actualizarEstante();
        }
        cout<<endl;
    }while(opcion);

    cout<<"Buen dia.\n";
    return 0;
}