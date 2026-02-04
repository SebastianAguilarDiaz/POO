struct Ship{

    string name;
    float dock;
    float large;
    


    // constructors
    Ship(){}

    Ship (string name, float dock, float large){
        
        this->name=name;
        this->dock=dock;
        this->large=large;

    }

    void askForDetails(){
        cout<<"Introduzca el nombre\t\t";
        cin>>this->name;
        cout<<"Introduzca el muelle\t";
        cin>>this->dock;
        cout<<"Introduzca el largo\t";
        cin>>this->large;

    }

    void printDetails(){
        cout<<"Nombre:\t"<<this->name<<"\nMuelle\t"<<this->dock<<"\nLargo\t"<<large<<endl;
    }

};
