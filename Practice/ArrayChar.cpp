#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char C[20]="Ibrahim";
	C[7]=',';
	C[8]='H';
	C[9]='a';
	C[10]='m';
	C[11]='z';
	C[12]='a';
	C[13]='\0';
	cout<<"Name: "<<C<<endl;
	int len=strlen(C);
	cout<<"Length: "<<len;
}
