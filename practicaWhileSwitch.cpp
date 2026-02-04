#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
#include<chrono>
#include<string.h>
#include<set>
#include <algorithm>

using namespace std;

// Title:     			  Practica con While y switch
// Author(s):  			  Sebastian Aguilar
// Creation Date:		  01/21/26
// Last update:			  01/21/26
// Version:				  1.0.0

int main(){
    
    // variables 
    int input=0,n;

    // display menu
    cout<<"Escoge una opcion:\n\t1 Pinta pares hasta n\n\t2 Pinta impares hasta n\n\t3 Multiplos de 5 hasta n\n\t4 Dice si el numero n es primo\n\t5 Salir del programa\n";
    
    // ask for one option of the menu
    cin>>input;

    // loop
    while(input!=5){
        

        cout<<"Ingresa un numero n\n";
        cin>>n;
        cout<<"---------------------\n";
        int i;
        switch(input){
            
            // show even numbers untill n
            case 1 :
                i=2;
                while(i<=n){
                    cout<<i<<endl;
                    i+=2;
                }
                break;
            
            // show odd numbers till n
            case 2 :
                i=1;
                while(i<=n){
                    cout<<i<<endl;
                    i+=2;
                }
                break;

            // show numbers that are divisible 5 till n
            case 3 :
                i=5;
                while(i<=n){
                    cout<<i<<endl;
                    i+=5;
                }
                break;
            
            // show if the number is prime
            case 4 :
                i=2;
                bool prime=true;
                if (n==1) prime=false;
                while(i<n){
                    if (n%i==0) prime=false;
                    i++;
                }
                cout<<((prime)?"El numero es primo":"El numero no es primo\n")<<endl;

                break;

        }
        cout<<"---------------------\n";

        // display menu
        cout<<"\nEscoge una opcion:\n\t1 Pinta pares hasta n\n\t2 Pinta impares hasta n\n\t3 Multiplos de 5 hasta n\n\t4 Dice si el numero n es primo\n\t5 Salir del programa\n";

        // ask for one option of the menu
        cin>>input;
    }


    cout<<"-----------------Programa terminado-----------------\n";
    return 0;
}