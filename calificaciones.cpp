#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
#include<chrono>
#include<string.h>
#include<set>
#include <algorithm>
#include <iomanip>

using namespace std;

// Title:     			  Grades
// Author(s):  			  Sebastian Aguilar
// Creation Date:		  01/26/26
// Last update:			  01/28/26
// Version:				  1.0.0


const int STUDENTS =5;
const int SUBJECTS=2;

float students_correct_answers[SUBJECTS][STUDENTS];
float students_grades[SUBJECTS][STUDENTS];
int questions[SUBJECTS];
float average_approved=0;
float average_disapproved=0;
int approved_students=0;
bool requirements[2]={false,false};

void update_grades(){
    for(int i=0;i<STUDENTS;i++){

        for(int j=0;j<SUBJECTS;j++){
            students_grades[j][i]=students_correct_answers[j][i]/questions[j]*10;
        
        }

    }
}

int main(){

    int option=7;
    
    while(option){

        // Desplegar menu
        cout<<"Menu"<<endl;

        cout<<"(0) Salir."<<endl;
        cout<<"(1) Ingresar reactivos de cada materia."<<endl;
        cout<<"(2) Ingresar aciertos por alumno."<<endl;
        cout<<"(3) Desplegar tabla de datos."<<endl;
        cout<<"(4) Promedios."<<endl;
        cout<<"(5) Total de aciertos."<<endl;

        cout<<"Escoja una opcion:\t";
        cin>>option;
        cout<<endl;
        if (!(requirements[0] &&  requirements[1]) && option>2) option=6;
        switch(option){



            // Pedir cantidad de reactivos de cada materia
            case 1:

                for(int i=0;i<SUBJECTS;i++){
                    cout<<"Ingrese la cantidad de reactivos en la materia "<<i+1<<'\t';
                    cin>>questions[i];
                    cout<<endl;
                    requirements[0]=true;
                }
                break;

            // Pedir la cantidad de aciertos por alumno
            case 2:
                cout<<endl;
                for(int i=0;i<STUDENTS;i++){
                    cout<<"Alumno "<<i+1<<", ingrese sus aciertos\n";
                    for(int j=0;j<SUBJECTS;j++){
                        cout<<"Materia "<<j+1<<":\t";
                        cin>>students_correct_answers[j][i];
                        cout<<endl;
                    }
                }
                requirements[1]=true;
                break;

            // Desplegar tabla de datos
            case 3:
                cout<<"Alumno\t\t";
                for(int i=0;i<SUBJECTS;i++)
                    cout<<"|Materia "<<i+1<<"\t";
                cout<<endl;
                for(int i=0;i<47;i++){
                    cout<<"-";
                }
                cout<<endl;
                for(int i=0;i<STUDENTS;i++){
                    cout<<"Alumno "<<i+1<<"\t";
                    for(int j=0;j<SUBJECTS;j++){
                        students_grades[j][i]=students_correct_answers[j][i]/questions[j]*10;
                        cout<<"|"<< fixed << setprecision(2) <<students_grades[j][i]<<((students_grades[j][i]>=6)?" Aprobada":" Reprobada")<<"\t";
                        
                    }
                    cout<<endl;
                }

                break;
            
            // Promedios
            // Promedio de todos los alumnos
            // promedio de aprobados y reprobados en cada materia
            case 4:
                update_grades();
                cout<<"Alumno\t\t|Promedio\n";
                for(int i=0;i<30;i++){
                    cout<<"-";
                }
                cout<<endl;
                for(int i=0;i<STUDENTS;i++){
                    cout<<"Alumno "<<i+1<<"\t|";
                    int average=0;
                    for(int j=0;j<SUBJECTS;j++){
                        average+=students_grades[j][i];
                    }
                    cout<<average/SUBJECTS<<endl;
                }
                cout<<"Aprobados\t|";
                average_approved=0;
                average_disapproved=0;
                approved_students=0;
                for(int i=0;i<STUDENTS;i++){
                    bool approved=true;
                    float temp=0;
                    for(int j=0;j<SUBJECTS;j++){
                        temp+=students_grades[j][i];
                        if(students_grades[j][i]<6) approved=false;
                    }
                    if(approved){
                        average_approved+=temp;
                        approved_students++;
                    }
                    else average_disapproved+=temp;

                }
                cout<<fixed<<setprecision(2)<<average_approved/(approved_students*SUBJECTS)<<endl<<"Reprobados\t|"<<fixed<<setprecision(2)<<average_disapproved/((STUDENTS-approved_students)*SUBJECTS)<<endl;
                cout<<"\nAlumnos que pasan: "<<approved_students<<endl;

                break;

            // Total de aciertos
            case 5:
                cout<<"\t\t";
                for(int i=0;i<SUBJECTS;i++){
                    cout<<"|Materia "<<i+1<<"\t";
                }
                cout<<endl;
                for(int i=0;i<47;i++){
                    cout<<"-";
                }
                cout<<endl<<"Total Aciertos";

                for (int i=0;i<SUBJECTS;i++){
                    int right=0;
                    for (int j=0;j<STUDENTS;j++){
                        right+=students_correct_answers[i][j];
                    }
                    cout<<"\t|"<<right<<"\t";
                }
                cout<<endl<<endl;

                cout<<"Alumno\t\t|Total Aciertos\n";
                for(int i=0;i<30;i++){
                    cout<<"-";
                }
                cout<<endl;
                for(int i=0;i<STUDENTS;i++){
                    cout<<"Alumno "<<i+1<<"\t";
                    int right=0;
                    for(int j=0;j<SUBJECTS;j++){
                        right+=students_correct_answers[j][i];
                    }
                    cout<<"|"<<right<<endl;
                }
                
                break;
            case 6:
                cout<<"\nFavor de introducir los datos necesarios para realizar la peticion.\n";
                break;

        }
        cout<<endl;
    }
    return 0;
}