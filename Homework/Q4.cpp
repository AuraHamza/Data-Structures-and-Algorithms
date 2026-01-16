#include<iostream>
using namespace std;

int countzero(int n){
	if(n==0)
	{
		return 0;
	}
int lastdigit=n%10;
if(lastdigit==0){
	return 1+countzero(n/10);
}
else{
	return countzero(n/10);
}
}


int main(){
int n=1020304;
int p=countzero(n);

cout<<"number of zero: "<<p;
return 0;

}
