#include <iostream>
using namespace std;

int main() {
    int players,matches;
    cout<<"Enter number of players: ";
    cin>>players;
    cout<<"Enter number of matches: ";
    cin>>matches;

    int **scores=new int*[players];
    for (int i=0;i<players;i++) {
        scores[i]=new int[matches];
    }

    cout<< "Enter scores:";
    for (int i=0;i<players;i++) {
        for (int j=0;j<matches;j++) {
            cout<<"Player "<<i+1<<", Match"<<j+1<<":";
            cin>>scores[i][j];
        }
    }
    int maxTotal=0,bestPlayer=0;
    for (int i=0;i<players;i++) {
        int total=0;
        for(int j=0;j<matches;j++) {
            total += scores[i][j];
        }
        int avg=total/matches;
        cout<<"Player:"<<i+1<<"Total:"<<total<<", Average: "<<avg<<endl;
        if (total>maxTotal) {
            maxTotal=total;
            bestPlayer=i;
        }
    }
    int bestMatch=0; 
	int maxMatchScore=0;
    for (int j=0;j<matches;j++) {
        int sum=0;
        for (int i=0;i<players;i++) {
            sum+=scores[i][j];
        }
        if(sum>maxMatchScore) {
            maxMatchScore=sum;
            bestMatch=j;
        }
    }

    cout<< "Player " <<bestPlayer+1<<" had the highest total score:" << maxTotal <<endl;
    cout<< "Match " <<bestMatch+1<< " had the highest combined score:" <<maxMatchScore<<endl;

    for (int  i=0;i<players;i++) {
        delete[] scores[i];
    }
    delete[] scores;
}

