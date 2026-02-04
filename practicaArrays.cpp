#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
#include<chrono>
#include<string.h>
#include<set>
#include <algorithm>

using namespace std;

// Title:     			  Practica Arrays
// Author(s):  			  Sebastian Aguilar
// Creation Date:		  01/21/26
// Last update:			  01/21/26
// Version:				  1.0.0

int main(){
    
    // array
    int array[10];
    cout<<"Ingrese 10 numeros:\n";
    
    // giving a value to each number on the array
    for (int &i:array)
        cin>>i;


    // printing twice the array
    for (int i=0;i<2;i++){
        
        // printing the array
        for (int j:array)
            cout<<j<<" ";
    }

    return 0;
}