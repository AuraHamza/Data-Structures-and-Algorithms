#include<iostream>
using namespace std; 

class HashTable{
	int tableSize;
	int* table;
	bool* deleted;
	int count;
	
	int hashFunction(int key){
		return key%tableSize;
	}
	void rehash(){
		int oldSize=tableSize;
		int* oldtable=table;
		bool* olddeleted=deleted;
		
		tableSize*=2;
		table=new int[tableSize];
		deleted=new bool[tableSize];
		
		for(int i=0;i<tableSize;i++){
			table[i]=-1;
			deleted[i]=false;
		}
		count=0;
		
		for(int i=0;i<oldSize;i++){
			if(oldtable[i]!=-1){
				insert(oldtable[i]);
			}
		}
		delete[] oldtable;
		delete[] olddeleted;
	}
	
	public:
		HashTable(int size=11){
			tableSize=size;
			table=new int[tableSize];
			deleted=new bool[tableSize];
			for(int i=0;i<tableSize;i++){
			table[i]=-1;
			deleted[i]=false;
		}
		count=0;
		}
		
		~HashTable(){
			delete[] table;
			delete[] deleted;
		}
		
		void insert(int key){
			double loadfactor=(double)count/tableSize;
			if(loadfactor>=0.7){
				cout<<"Rehashing bahiya"<<endl;
				rehash();
			}
			int startIndex=hashFunction(key);
			int i=0;
			int index;
			
			while(i<tableSize){
				index=(startIndex+i*i)%tableSize;
				if(table[index]==-1 || deleted[index]){
					table[index]=key;
					deleted[index]=false;
					count++;
					return;
				}
				i++;
			}
			cout << "Hash table is Full\n";		
		}
		
		bool search(int key){
			int startIndex=hashFunction(key);
			int i=0;
			int index;
			
			while(i<tableSize){
				index=(startIndex+i*i)%tableSize;
				if(table[index]==key){
					return true;
				}
				if(table[index]==-1 && !deleted[index]){
					return false;
				}
				i++;
			}
			return false;
		}
		
		void remove(int key){
			int startIndex=hashFunction(key);
			int i=0;
			int index;
			while(i<tableSize){
				index=(startIndex+i*i)%tableSize;
				if(table[index]==key){
					table[index]=-1;
					deleted[index]=true;
					count--;
					return;
				}
				if(table[index]==-1 && !deleted[index]){
					break;
				}
				i++;
			}
			cout<<"Not found";
		}
		void display(){
			for(int i=0;i<tableSize;i++){
				cout<<i<<"->";
				if(table[i]!=-1){
					cout<<table[i];
				}
				else{
					cout<<"NULL";
				}
				cout<<endl;
				
			}
		}
};


int main() {
    HashTable h;

    h.insert(5);
    h.insert(15);
    h.insert(25);
    h.insert(35);
    h.insert(45);
    h.insert(55);  // triggers rehash
    h.insert(65);

    cout << "Initial Table:\n";
    h.display();

    cout << "\nSearch 25: " << (h.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (h.search(100) ? "Found" : "Not Found") << endl;

    h.remove(25);
    cout << "\nTable after removing 25:\n";
    h.display();

    h.remove(100); // testing not found case

    return 0;
}

