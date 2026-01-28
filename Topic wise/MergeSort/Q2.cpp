#include<iostream>
using namespace std;

class Participant{
	public:
		string name;
		int time;
		Participant(string n,int t){
			name=n;
			time=t;
		}
};

void Merge(int arr[],int start,int mid,int end){
	int temp[100];
	int	i=start;
	int j=mid+1;
	int k=0;
	while(i<=mid && j<=end){
		if(arr[i]<arr[j]){
			temp[k]=arr[i];
			i++;
			k++;
		}
		else{
			temp[k]=arr[j];
			j++;
			k++;
		}
	}
	while(i<=mid){
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=end){
		temp[k]=arr[j];
		j++;
		k++;
	}
	for(int t=0;t<k;t++){
		arr[start+t]=temp[t];
	}
        
}

void Mergesort(int arr[],int start,int end){
	if(start<end){
		int mid=start+(end-start)/2;
		Mergesort(arr,start,mid);
		Mergesort(arr,mid+1,end);
		Merge(arr,start,mid,end);
	}
}


int main(){
	Participant p1("Hamza",1);
	Participant p2("Ibrahim",4);
	Participant p3("Noman",2);
	Participant p4("Ali",90);
	Participant p5("Faizan",34);
	Participant p6("Babar",18);
	Participant pa[]={p1,p2,p3,p4,p5,p6};
	int arr[]={p1.time,p2.time,p3.time,p4.time,p5.time,p6.time};
	Mergesort(arr,0,5);
	
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(arr[i]==pa[j].time){
				cout<<arr[i]<<"->";
			}
	}
}
}
