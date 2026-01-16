#include <iostream>
#include <cstring>
using namespace std;

class Exam {
    char* name;
    char* date;
    int* score;

public:
    Exam() {
        name=NULL;
        date=NULL;
        score=NULL;
    }

    void setData(char* n,const char* d,int s) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        date = new char[strlen(d) + 1];
        strcpy(date, d);
        score=new int(s);
    }

    void display() {
        cout<<"Name: "<<name<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Score: "<<*score<<endl;
    }

    ~Exam() {
        delete[] name;
        delete[] date;
        delete score;
    }
};

int main() {
    Exam e1;
    e1.setData("Rafay","01-08-2025",85);
    cout << "Original Object e1:"<<endl;
    e1.display();
    Exam e2=e1;
    cout << "\nCopied Object:"<<endl;
    e2.display();

    return 0;
}

