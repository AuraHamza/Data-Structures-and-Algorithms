#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter numbers of student: ";
	cin>>n;
	int studentid[n];
	int* marks[n];
	int courseCount[n];
	
	for(int i=0;i<n;i++){
		cout<<"Enter student ID:";
		cin>>studentid[i];
		
		cout<<"Enter number of cource for student for batch 21k- "<<studentid[i]<<":";
		cin>>courseCount[i];
		
		marks[i]=new int[courseCount[i]];
		
		
		cout<<"Enter marks for "<<courseCount[i]<<":";
		for(int j=0;j<courseCount[i];j++){
			cin>>marks[i][j];
		}
	}
	    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Student ID: 21K-" << studentid[i] << " | Marks: ";
        for (int j = 0; j < courseCount[i]; j++) {
            cout << marks[i][j];
            if (j < courseCount[i] - 1) cout << ", ";
        }
        cout << endl;
    }
        for (int i = 0; i < 5; i++) {
        delete[] marks[i];
    }

    return 0;


}
