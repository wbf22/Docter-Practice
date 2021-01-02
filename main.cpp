/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <time.h> 

using namespace std;

class Patient{
    
    private:
    
    string name;
    
    
    public:
    
    Patient(string name){
        this->name = name;
    }
    
    
    string getName(){
        return name;
    }
    
    
    
    
};

class Docter{
    
    private:
    
    vector<Patient> patients;
    string name;
    
    
    public:
    
    Docter(vector<Patient> patients, string name){
        this->patients = patients;
        this->name = name;
    }
    
    vector<Patient> getPatients(){
        return patients;
    }
    
    string getName(){
        return name;
    }
    
    string operate(){
        stringstream ss;
        srand(time(NULL));
        for (auto i : patients) {
            int outcome = rand() % 10;
           
            if(outcome > 3){
                ss << i.getName() << " survived" << endl;
            }
            
        }
        
        return ss.str();
    }
    
    friend ostream& operator<< (ostream& os,  Docter& d){
        
        os << "Docter " << d.getName() << endl;
        os << "Patients: " << endl;
        
        for (auto i : d.getPatients()) {
            os << i.getName() << endl;
        }
        return os;
    }
    
};



int main()
{
    string docterName;
    vector<Patient> patients;
    
    cout << "Enter Docter name" << endl;
    cin >> docterName;
    
    cout << "Enter Patient names and end with '.'" << endl;
    string holder;
    while(cin >> holder){
        if(holder == ".") break;
        patients.push_back(holder);
    }
    
    Docter Baxter(patients, docterName);
    cout << Baxter;
    
    cout << endl << "Operate:" << endl;
    cout << Baxter.operate();
    
    return 0;
}


