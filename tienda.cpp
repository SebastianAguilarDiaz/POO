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
    float tiempo_de_vida;
    string fecha_de_compra;

};
struct abarrote {

    string nombre;
    float precio;
    string fecha_de_caducidad;

};

struct estantes{
    
    int numero_de_estante;
    string fecha_de_actualizacion;
    string persona_que_actualizo;
    vector<verdura> verduras;
    vector<abarrote> abarrotes;

    // constructor
    estantes(){}

};





int main(){
    




    return 0;
}