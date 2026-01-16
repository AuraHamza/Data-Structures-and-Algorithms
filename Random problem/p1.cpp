#inlcude<iostream> 
using namespace std;

void permutation(int arr[],int left, int right){
	if(left==right){
		print(arr,right+1);
		return;
	}
	for(int i=left;i<=right;i++){
		swap(left[i],right[i]);
		permutation(arr,left+1,right);
		swap(left[i],right[i]);
	}
}

int main(){
	int arr[]={1,2,3};
	int n=sizeof(arr)/(sizeof(arr[0]));
	permutation(arr,0,n-1);
	
}
