#include<iostream>
using namespace std;


class Product{
	public:
		string name;
		int price;
		bool availability;
		
		Product(string n,int p,bool a){
			name=n;
			price=p;
			availability=a;
		}
};

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	i++;
	swap(arr[i],arr[high]);
	return i;
}

void Quicksort(int arr[],int low ,int high){
	if(low<high){
		int pivot=partition(arr,low,high);
		Quicksort(arr,low,pivot-1);
		Quicksort(arr,pivot+1,high);
	}
}

int main(){
	Product p1("Product 1",11,true);
	Product p2("Product 2",5,true);
	Product p3("Product 3",2,true);
	Product p[]={p1,p2,p3};
	int arr[]={p1.price,p2.price,p3.price};
	Quicksort(arr,0,2);
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(arr[i]==p[j].price){
				cout<<p[j].name<<"->"<<p[j].price<<endl;
			}
		}
	}
}
