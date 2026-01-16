#include<iostream>
using namespace std;

void ShellSort(int arr[],int n){
	for(int gap=n/2;gap>0;gap/=2){
		for (int i=gap;i<n;i++){
		    int temp=arr[i];
		    int j;
		    for(j=i;j>=gap && arr[j-gap]>temp;j-=gap){
		    arr[j]=arr[j-gap];
			}
			arr[j]=temp;
		}
	}
}
int main(){
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter element in array:";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<"Before Sorting: "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	ShellSort(arr,n);
	cout<<"After Sorting: "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
