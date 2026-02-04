#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
#include<chrono>
#include<string.h>
#include<set>
#include <algorithm>

using namespace std;

// Title:     			  Structs
// Author(s):  			  Sebastian Aguilar
// Creation Date:		  01/28/26
// Last update:			  01/28/26
// Version:				  1.0.0


struct Subject{
    string name;
    float grade;
};
struct CalifAlumno{
    string name;
    vector<Subject> subjects;

    float average(){
        float av;
        for(Subject n:this->subjects){
            av+=n.grade;
        }
        av/=this->subjects.size();
        return av;
    }

    void addSubject(Subject subject1){
        this->subjects.push_back(subject1);
        
    }

    // Given an array adds all the subjects in the array
    void addSubjects(Subject *subjects,int number_of_subjects){
        for(int i=0;i<number_of_subjects; i++){
            this->subjects.push_back(subjects[i]);
        }
    }

    
};



const int NUMBER_OF_SUBJECTS=2;
const int NUMBER_OF_STUDENTS=3;


int main(){
    Subject subjects[NUMBER_OF_SUBJECTS];
    subjects[0].name="Matematicas";
    subjects[1].name="Fisica\t";
    
    CalifAlumno alumnos[NUMBER_OF_STUDENTS];
    int i=1;
    for(CalifAlumno &n:alumnos){
        n.addSubjects(subjects,NUMBER_OF_SUBJECTS);
        cout<<"Introduce tu nombre alumno "<<i++<<"\t";
        cin>>n.name;
        for(Subject &m:n.subjects){
            cout<<"Introduce tu calificacion de "<<m.name<<"\t";
            cin>>m.grade;
        }
        cout<<endl;
    }

    for(CalifAlumno &n:alumnos){
        cout<<"Alumno "<<n.name<<endl;
        for(Subject &m:n.subjects){
            cout<<"Calificacion de "<<m.name<<"\t"<<m.grade<<endl;
        }
        cout<<"Promedio\t"<<n.average()<<endl<<endl;

    }

    return 0;
}