#include<iostream>
#include <cstring>
using namespace std;

class Document {
public:
    char* Title;
    char* info;
    // Default constructor
    Document() {
        Title = new char[2];
        strcpy(Title, " ");
        info = new char[2];
        strcpy(info, " ");
    }

    Document(char *t, char *in) {
        Title=new char [strlen(t)+1];
        strcpy(Title,t);
        info=new char [strlen(in)+1];
        strcpy(info,in);

    }
      ~Document() {
        cout<<"Destrutor called";
        delete[] Title;
        delete[] info;
}
    void Display() {
        cout << "The title is: " << Title << endl;
        cout << "The info is: " << info << endl;
    }

    Document(const Document &other) {
        Title=new char[strlen(other.Title)+1];
        strcpy(Title,other.Title);
        info=new char[strlen(other.info)+1];
        strcpy(info,other.info);
    }
     

    Document& operator=(const Document &other) {
        if (this != &other) {
        	delete [] Title;
        	delete [] info;
            Title =new char[strlen(other.Title)+1];
            strcpy(Title ,other.Title);
            info = new char[strlen(other.info)+1];
            strcpy(info,other.info);
        }
        return *this;
    }
  

   
};

int main() {
    Document d1("Today's news", "Rain is expected");
    Document d2=d1;
    d1.Display();
    d2.Display();
	Document d3;
	d3=d1;




    d1.info="Thenderstrom";
    d1.Display();
    d2.Display();
    
    return 0;
}

