#include<iostream>
#include<cstring>
using namespace std;

class Employe{
public:
    char* name;
    double* salary;
    int months;

    Employe(){
        name = NULL;
        salary = NULL;
        months = 0;
    }

    Employe(const char* na, double sa[], int m){
        name = new char[strlen(na)+1];
        strcpy(name, na);
        months = m;

        salary = new double[m];
        for(int i=0; i<months; i++){
            salary[i] = sa[i];
        }
    }

    Employe(const Employe& other){
        name = new char[strlen(other.name)+1];
        strcpy(name, other.name);
        months = other.months;

        salary = new double[months];
        for(int i=0; i<months; i++){
            salary[i] = other.salary[i];
        }
    }

    Employe& operator=(const Employe& other){
        if(this != &other){
            delete[] name;
            delete[] salary;

            name = new char[strlen(other.name)+1];
            strcpy(name, other.name);
            months = other.months;

            salary = new double[months];
            for(int i=0; i<months; i++){
                salary[i] = other.salary[i];
            }
        }
        return *this;
    }

    ~Employe(){
        cout<<"Destructor called for "<<this<<" -> "<<name<<endl;
        delete[] name;
        delete[] salary;
    }

    double avg(){
        double sum = 0;
        for(int i=0; i<months; i++){
            sum += salary[i];
        }
        return sum/months;
    }

    void display(){
        cout << "Name: " << name << "\nSalaries: ";
        for(int i=0; i<months; i++){
            cout << salary[i] << " ";
        }
        cout << "\nAverage: " << avg() << endl << endl;
    }
};

int main() {
    double salary1[] = {5000, 5200, 5400};
    Employe e1("John", salary1, 3);

    Employe e2 = e1; // Copy constructor

    double salary2[] = {4000, 4500, 4700};
    Employe e3("Mike", salary2, 3);

    e3 = e1; // Copy assignment

    e1.display();
    e2.display();
    e3.display();

    return 0;
}

