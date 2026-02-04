#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
#include<chrono>
#include<string.h>
#include<set>
#include <algorithm>

using namespace std;




struct verdura {

    string nombre;
    float precio;
    float tiempo_de_vida;
    string fecha_de_compra;


};
struct abarrotes {

    string nombre;
    float precio;
    string fecha_de_caducidad;

};

struct estantes{
    int numero_de_estante;
    string fecha_de_actualizacion;
    string persona_que_actualizo;
    vector<verdura> verduras;
    vector <abarrotes> prod_abarrotes;


    // constructor
    estantes(){}
    //hola

};






int main(){
    




    return 0;
}