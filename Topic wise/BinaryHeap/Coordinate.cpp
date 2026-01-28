#include<iostream>
using namespace std;

class Coordinates{
	public:
		int x;
		int y;
		int dis;
		Coordinates() {   // ? FIXED: default constructor required
            x = 0;
            y = 0;
            dis = 0;
        }
		Coordinates(int x,int y){
			this->x=x;
			this->y=y;
			dis=(x*x)+(y*y);
		}
};
class MinHeap{
	public:
		Coordinates arr[100];
		int size=0;
		
		void insert(Coordinates c){
			size++;
			arr[size]=c;
			int i=size;
			while(i>1){
				int parent=i/2;
				if(arr[parent].dis>arr[i].dis){
					swap(arr[parent],arr[i]);
					i=parent;
				}else{
					break;
				}
			}
		}
		Coordinates Delete(){
			if(size==0){
				cout<<"Nt"<<endl;
				return Coordinates(0,0);
			}
			Coordinates value=arr[1];
			arr[1]=arr[size];
			size--;
			int i=1;
			while(true){
				int left=i*2;
				int right=i*2+1;
				int smallest=i;
				if(left<=size && arr[left].dis<arr[smallest].dis){
				
					smallest=left;
				}
				if(right<=size && arr[right].dis<arr[smallest].dis){
				
					smallest=right;
				}
				if(smallest==i){
					break;
				}
				swap(arr[i],arr[smallest]);
				i=smallest;
			}
			return value;
		}
};
int main() {

    MinHeap h;

    h.insert(Coordinates(1, 3));
    h.insert(Coordinates(2, -2));
    h.insert(Coordinates(5, 8));
    h.insert(Coordinates(0, 1));
    h.insert(Coordinates(7, 6));

    int k = 3;

    cout << "K Closest Towers: ";

    for (int i = 0; i < k; i++) {
        Coordinates c = h.Delete();
        cout << "(" << c.x << ", " << c.y << ") ";
    }

    return 0;
}