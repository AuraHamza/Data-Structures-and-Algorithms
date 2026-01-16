#include<iostream>
using namespace std;

int* BruteForce(string text, string pattern){
	
	int n = text.length();
	int m= pattern.length();
	int *count = new int[10];
	int k=0;
	
	
	for(int i=0;i<10;i++){
		count[i]=-1;
	}
	
	
	for(int i=0;i<=n-m;i++){
		
		int j=0;
		
		while(j<m  && text[i+j]==pattern[j]){
			j++;
		}
		
		if(j==m){
			count[k]=i;
			k++;
		}
	}
	
	return count;
}


int main(){
	
	string text = "ABABBBABABABA";
	string pattern = "BAB";

   int *array = BruteForce(text,pattern);
	
	
	for(int i=0;i<10;i++){
		if(array[i]!=-1){
			cout<<"Pattern found at index: "<<array[i]<<endl;
		}
	}
	
	return 0;
}