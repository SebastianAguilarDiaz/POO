#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
#include<chrono>
#include<string.h>
#include<set>
#include <algorithm>

using namespace std;

// Title:     			  Vectors
// Author(s):  			  Sebastian Aguilar, Mauricio Figueroa
// Creation Date:		  02/12/2026
// Last update:			  02/12/2026
// Version:				  1.0.0


int repeatedElements(vector <int> &A,vector<int> &B );



int main(){

    int n,m;

    cout<<"Introduzca es tamano del primer vector\t";
    cin>>n;
    cout<<"Introduzca es tamano del segundo vector\t";
    cin>>m;

    vector <int> A (n);
    vector <int> B (m);
    cout<<"Introduzca los elementos del vector A\n";
    for(int &i:A){
        cout<<"Elemento "<<i+1<<"\t";
        cin>>i;
    }
    cout<<"Introduzca los elementos del vector B\n";
    for(int &i:B){
        cout<<"Elemento "<<i+1<<"\t";
        cin>>i;
    }






    return 0;
}
int repeatedElemts (vector <int> &A, vector <int> &B){
    int i=0,n=A.size(),m=B.size();
    for()
}