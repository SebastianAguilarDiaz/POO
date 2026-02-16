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
// Last update:			  02/15/2026
// Version:				  1.0.0


int findElement(vector <int> &A, int element, int left, int right);

int elementsRepeated( vector <int> &A,vector <int> &B);

int elementNotRepeated(vector <int> &A, vector <int> &B);

vector <int> elementsJustOnA(vector<int> &A, vector <int> &B);

// requirements 
// 1 how many elements in A are also in B
// 2 elements in B that aren't on A
// 3 vector with elements in A that aren't in B
// 4 vector with elements in B that aren't in A
int main(){

    // n>=m;

    int n,m;

    cout<<"Introduzca el tamano del primer vector\t";
    cin>>n;
    cout<<"Introduzca el tamano del segundo vector\t";
    cin>>m;

    vector <int> A (n);
    vector <int> B (m);
    cout<<"\nIntroduzca los elementos del vector A\n";
    int j=0;
    for(int &i:A){
        cout<<"Elemento "<<++j<<"\t";
        cin>>i;
    }
    cout<<"\nIntroduzca los elementos del vector B\n";
    j=0;
    for(int &i:B){
        cout<<"Elemento "<<++j<<"\t";
        cin>>i;
    }


    cout<<"\nCantidad de elementos en A que tambien estan en B\t"<<elementsRepeated(A,B)<<endl;
    cout<<"Cantidad de elementos que estan en B pero no en A\t"<<elementNotRepeated(B,A)<<endl;

    cout<<"\nElementos en A pero no en B\n";
    vector<int> C=elementsJustOnA(A,B);
    for(int &n:C)
        cout<<n<<", ";
    cout<<endl<<endl;

    cout<<"Elementos en B pero no en A\n";
    vector<int> D=elementsJustOnA(B,A);
    for(int &n:D)
        cout<<n<<", ";
    cout<<endl<<endl;

    



    return 0;
}


// binary search
int findElement(vector <int> &A, int element, int left, int right){
    int n=right-left+1;

    if (left>right)return -1;
    // base case
    if(element==A[left + n/2]){return left + n/2;}
    
    // if not found
    if(n==1 && element!=A[left + n/2]) return -1;
    
    else if(A[left + n/2]<element){
        return findElement(A,element,left + n/2 +1,right);
    }
    else if (A[left + n/2]>element){
        return findElement(A,element,left,left+n/2-1);
    }
    return -1;



}

// counts how many elements in A are also in B
int elementsRepeated( vector <int> &A,vector <int> &B){
    int i=0;
    for(int &n:A){

        if (findElement(B,n,0,B.size()-1)!=-1) i++;
    }
    return i;
}

// counts how many elements in A aren't in B
int elementNotRepeated(vector <int> &A, vector <int> &B){
    return A.size()-elementsRepeated(A,B);
}

// Returns a vector with the elements that are in A but not in B
vector <int> elementsJustOnA(vector<int> &A, vector <int> &B){
    vector <int> x;
    for(int &n: A){
        // if not in B
        if (findElement(B,n,0,B.size()-1)==-1) x.push_back(n); 
    }
    return x;
}

