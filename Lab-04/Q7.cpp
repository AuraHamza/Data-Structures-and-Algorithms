#include<iostream>
using namespace std;

class Node{
public:
    int seatNo;     
    bool reserved;  
    Node* next;

    Node(int num) {
        seatNo=num;
        reserved=false; 
        next=NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;
    int totalSeats;

    CircularLinkedList(int n) {
        head=NULL;
        totalSeats=n;
        createSeats(n);
    }

    void createSeats(int n) {
        Node* prev=NULL;
        for (int i=1;i<=n;i++) {
            Node* newNode=new Node(i);
            if(head==NULL) {
                head=newNode;
            } else 
			{
                prev->next=newNode;
            }
            prev=newNode;
        }
        prev->next=head;
    }

    void reserveSeat(int num) {
        Node* temp=head;
        do 
		{
            if(temp->seatNo==num) {
                if (temp->reserved) {
                    cout<<"Seat "<<num<<"is already reserved."<<endl;
                } else {
                    temp->reserved=true;
                    cout<<"Seat"<<num<<" reserved successfully."<<endl;
                }
                return;
            }
            temp=temp->next;
        } while(temp!=head);
        cout<<"Invalid seat number."<<endl;
    }

    void displaySeats() {
    Node* temp = head;
    if (head==NULL) {
        cout<<"No seats available!" <<endl;
        return;
    }

    cout<<"Ride Seats Status:"<<endl;
    do {
       cout<<"Seat "<<temp->seatNo;
        if (temp->reserved){
            cout<<"Reserved"<<endl;
        }
        else{
            cout<<"Available"<<endl;
        }
        temp=temp->next;
    } while(temp!=head);
}
};

int main() {
    int n;
    cout<<"Enter total number of ride seats: ";
    cin>>n;

    CircularLinkedList ride(n);

    ride.displaySeats();

    ride.reserveSeat(2);
    ride.reserveSeat(4);
    ride.reserveSeat(2);

    ride.displaySeats();
}

