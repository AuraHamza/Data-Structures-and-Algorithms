#include <iostream>
using namespace std;


int main() {
    int wards, days;
    cout<<"Enter number of wards: ";
    cin>>wards;
    cout<<"Enter number of days: ";
    cin>>days;

    int** patients=new int*[wards];
    for (int i=0;i<wards;i++) {
        patients[i]=new int[days];
    }

    cout<<"\nEnter admission data:"<<endl;
    for(int i=0;i<wards;i++) 
	{
        for(int j=0;j<days;j++) 
		{
            cout<<"Ward "<<i+1<<", Day "<<j+1<<": ";
            cin>>patients[i][j];
        }
        cout<<endl;
    }

    int maxWard = 0, maxDay = 0, maxPatients = patients[0][0];
    for (int i=0;i<wards;i++)
	 {
        for(int j= 0; j < days; j++) {
            if (patients[i][j] > maxPatients) {
                maxPatients = patients[i][j];
                maxWard = i;
                maxDay = j;
            }
        }
    }

    for (int i=0;i<wards;i++) {
        int sum = 0;
        for (int j=0;j<days;j++) {
            sum+=patients[i][j];
        }
        int avg = sum / days;
        cout << "Average patients in Ward " <<i+1<<":"<<avg<<endl;
    }

    cout<<maxWard+1 <<" had the highest admissions"<<endl; 
    cout<<"Max Patient are: "<< maxPatients<<endl;

    for (int i = 0; i < wards; i++) {
        delete[] patients[i];
    }
    delete[] patients;
}

