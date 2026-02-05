#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
#include<chrono>
#include<string.h>
#include<set>
#include <algorithm>

using namespace std;

// ***** PASOS *****
// git pull
// hacer cambios en el codigo
// guardarlos
// git add .
// git commit -m "detalles de las modificaciones"
// git push

struct verdura {

    string nombre;
    float precio;
    float tiempo_de_vida; // por que float? como se piensa ingresar el tiempo de vida
    string fecha_de_compra;

    void imprimirDatos(){
        cout<<nombre<<"\t"<<precio<<tiempo_de_vida<<"\t"<<fecha_de_compra<<endl;
    }


    void pedirDatos(){

        cout<<"Ingrese el nombre\t";
        cin>>this->nombre;
        cout<<"Ingrese el precio\t";
        cin>>this->precio;
        cout<<"Ingrese el tiempo de vida (en dias)\t";
        cin>>this->tiempo_de_vida;
        cout<<"Ingrese la fecha de compra\t";
        cin>>this->fecha_de_compra;
    }
};
struct abarrote {

    string nombre;
    float precio;
    string fecha_de_caducidad;

    void imprimirDatos(){
        cout<<nombre<<"\t"<<precio<<"\t"<<fecha_de_caducidad<<endl;


    }
    void pedirDatos(){

        cout<<"Ingrese el nombre\t";
        cin>>this->nombre;
        cout<<"Ingrese el precio\t";
        cin>>this->precio;
        cout<<"Ingrese la fecha de caducidad\t";
        cin>>this->fecha_de_caducidad;

    }
};

struct estantes{

    int numero_de_estante;
    string fecha_de_actualizacion;
    string persona_que_actualizo;
    vector<verdura> verduras;
    vector<abarrote> abarrotes;

    // constructor
    estantes(int estante){

        // guardar el numero de estante
        this->numero_de_estante=estante;

        cout<<"Estante "<<estante<<endl;
        actualizarEstante();
    }

    // imprimir lo que contiene el estante
    void imprimirDatos(){
        cout<<"Estante "<<this->numero_de_estante<<endl;
        cout<<"Verduras\n";
        cout<<"Nombre\tPrecio\tTiempo\tFecha\n";
        for(verdura n:verduras) n.imprimirDatos();
        cout<<"\nAbarrotes\n";
        cout<<"Nombre\tPrecio\tCaducidad\n";
        for(abarrote n:abarrotes) n.imprimirDatos();
        
    }

    // para ingresar productos al estante
    void actualizarEstante(){
        cout<<"Quien actualiza el estante?\n";
        cin>>this->persona_que_actualizo;

        cout<<"Ingrese la fecha actual\n";
        cin>>this->fecha_de_actualizacion;


        cout<<"Ingrese cuantos productos contendra el estante "<< this->numero_de_estante <<endl;
        int cantidad_de_productos;
        cin>>cantidad_de_productos;

        // minimo deben haber 8 productos en el estante
        while(cantidad_de_productos<8){
            cout<<"Minimo deben ser 8 productos\n";
            cout<<"Ingrese cuantos productos contendra el estante "<< this->numero_de_estante <<endl;
            cin>>cantidad_de_productos;
        }
        verdura v1;
        abarrote a1;

        // vacia el estante
        verduras.clear();
        abarrotes.clear();



        // ingresa los productos
        while(cantidad_de_productos--){
            char tipo;
            cout<<"Productos restantes "<<cantidad_de_productos<<endl;
            cout<<"Verdura(v) o abarrotes(a)\t";
            cin>>tipo;

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
        }
    }
};



const int cantidad_de_estantes=2;

int main(){





    return 0;
}