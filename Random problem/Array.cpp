#include<iostream>
#include<cstring>
using namespace std;
class Store{
	public:
		char* prodname;
		int* quantity;
		int* branch;
		int s;
		Store(){
			this->prodname=NULL;
			this->quantity=NULL;
			this->branch=NULL;
			this->s=0;
		}
		Store(const char* prodname,int* quantity,int* branch,int s){
			this->prodname=new char [strlen(prodname)+1];
			strcpy(this->prodname,prodname);
			this->s=s;
			this->quantity[s]=new int [s];
			this->branch[s]=new int [s];
			for(int i=0;i<s;i++){
				this->quantity=quantity[s];
				this->branch=branch[s];
			}
		}
		Store(const Store& other){
			this->s=other.s;
			for(int i=0;i<s;i++){
				if(other.prodname!=NULL){
				   if(other.quantity!=NULL) {
				    	if(other.branch!=NULL){
					this->prodname=new char [strlen(prodname)+1];
			strcpy(this->prodname,prodname);
					
				for(int i=0;i<s;i++){
					this->quantity[i]=other.quantity[i];
				}
				 for(int i = 0; i < s; i++)
           this->branch[i] = other.branch[i];
					}else{
						branch=NULL;
					}
					
				}
				}else{
						quantity=NULL;
					}
			}
		}
	}
};
int main(){
}
