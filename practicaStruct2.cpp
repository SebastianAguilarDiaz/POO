#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
#include<chrono>
#include<string.h>
#include<set>
#include <algorithm>
#include<iomanip>

using namespace std;

// Title:     			  Structs 2
// Author(s):  			  Sebastian Aguilar
// Creation Date:		  01/28/26
// Last update:			  02/01/26
// Version:				  1.0.0
string line="-----------------------------------";

struct Car{

    string brand;
    int cylinders;
    float kms;
    


    void askForDetails(){
        cout<<"Introduzca la marca\t\t";
        cin>>this->brand;
        cout<<"Introduzca los cilindros\t";
        cin>>this->cylinders;
        cout<<"Introduzca el kilometraje\t";
        cin>>this->kms;

    }

    void printDetails(){
        cout<<"\t|"<<this->brand<<"\t|"<<this->cylinders<<"\t\t|"<<kms<<endl<<line<<"----------"<<endl;
    }

};

struct Ship{

    string name;
    int dock;
    float large;
    

    void askForDetails(){
        cout<<"Introduzca el nombre\t";
        cin>>this->name;
        cout<<"Introduzca el muelle\t";
        cin>>this->dock;
        cout<<"Introduzca el largo\t";
        cin>>this->large;

    }

    void printDetails(){
        cout<<"\t|"<<this->name<<"\t|"<<this->dock<<"\t|"<<large<<endl<<line<<endl;
    }

};


int main(){
    const int NUMBER_OF_SHIPS=5;
    const int NUMBER_OF_CARS=4;

    Ship ships[NUMBER_OF_SHIPS];
    Car cars[NUMBER_OF_CARS];


    cout<<fixed<<setprecision(2);
    for(int i=0;i<NUMBER_OF_SHIPS;i++){
        cout<<"Barco "<<i+1<<endl;
        ships[i].askForDetails();
        cout<<endl;
    }

    for(int i=0;i<NUMBER_OF_CARS;i++){
        cout<<"Carro "<<i+1<<endl;
        cars[i].askForDetails();
        cout<<endl;
    }
    cout<<"\nBarco\t|Nombre\t|Muelle\t|Largo\n"<<line<<endl;
    for(int i=0;i<NUMBER_OF_SHIPS;i++){
        cout<<i+1;
        ships[i].printDetails();

    }
    cout<<"\nCarro\t|Marca\t|Cilindros\t|Kilometraje\n"<<"----------"<<line<<endl;
    
    for(int i=0;i<NUMBER_OF_CARS;i++){
        cout<<i+1;
        cars[i].printDetails();

    }

    return 0;
}