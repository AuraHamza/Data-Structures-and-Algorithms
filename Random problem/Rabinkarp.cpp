#include<iostream>
using namespace std;

const int d = 26;
const int q=101;

  void RabinKarp(string text,string pattern){
  	
  	int h=1;
  	int p=0;
  	int t=0;
  	
  	int n=text.length();
  	int m=pattern.length();
  	
  	for(int i=0;i<m-1;i++){
  		h = (h * d) % q;
	  }
	  
	  for(int i=0;i<m;i++){
	  	
	  	t= ( d * t + text[i]) % q;
	  	p=(d * p +pattern[i]) % q;
	  }
	  
	  
	  for(int i=0;i<=n-m;i++){
	  	
	  	if(p==t){
	  		bool match =true;
	  		
	  		for(int j=0;j<m;j++){
	  			if(text[i+j]!= pattern[j]){
	  				match =false;
	  				break;
				  }
			  }
			  
			  if(match){
			  	cout<<"Match found at index: "<<i<<endl;
			  }
		  }
		  
		  if(i < n-m){
		  	 t = ( d * (t - text[i] *h) +  text[i + m]) % q;
		  	 
		  	 if(t < 0){
		  	 	t= t+q;
			   }
		  }
	  }
	  
	  
  }
  
  int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    RabinKarp(text, pattern);
}