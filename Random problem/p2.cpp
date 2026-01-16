#include<iostream>
using namespace std;

void Subset(int arr[],int n, int index,int subset[],int subsetsize){
	if(index==n){
		cout<<"{";
		for(int i=0;i<subsize;i++){
			cout<<subset[i]<<" ";
		}
		cout<<" }\n";
		return;
	}
	Subset(arr,n,index+1,subset,subsetsize);
	subset[subsetsize]=arr[index];
	Subset(arr,n,index+1,subset,subsetsize+1);
}
