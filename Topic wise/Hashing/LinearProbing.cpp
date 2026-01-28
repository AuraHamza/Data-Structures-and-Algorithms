#include<iostream>
using namespace std;

class HashTable{
	//initializing table attributes
	int* table;
	bool* deleted;
	int tableSize;
	int count;
	
	//hashing function
	int hashFunction(int key){
		return key%tableSize;
	}
	
	
	//rehashing 
	void rehash(){
		//intializing old table
		int oldSize=tableSize;
		int* oldTable=table;
		bool* oldDeleted=deleted;
		
		
		//resizeing table 
		tableSize*=2;
		table=new int[tableSize];
		deleted=new bool[tableSize];
	
		for(int i=0;i<tableSize;i++){
			table[i]=-1;
			deleted[i]=false;
		}
		count=0;//reset count which use used in inserting beforee
		
		
		//inserting old values in new hashtable 
		for(int i=0;i<oldSize;i++){
			if(oldTable[i]!=-1){
				insert(oldTable[i]);
			}
		}
		delete[] oldTable;
		delete[] oldDeleted;
	}
	
	public:
		HashTable(int size=10){
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
			rehash();
		}
		
		int index=hashFunction(key);
		int startIndex=index;
		while(table[index]!=-1 && !deleted[index]){
			index=(index+1)%tableSize;
			if(index==startIndex){
				cout<<"Hash table is full";
				return;
			}
		}
		table[index]=key;
		deleted[index]=false;
		count++;
    }
    bool search(int key){
    	int index=hashFunction(key);
    	int startIndex=index;
    	
    	while(table[index]!=-1 || deleted[index]){
    		if(table[index]==key){
    			return true;
			}
			index=(index+1)%tableSize;
			if(startIndex==index){
				break;
			}
		}
		return false;
	}
	
	void remove(int key){
		int index=hashFunction(key);
		int startIndex=index;
		while(table[index]!=-1 || deleted[index]){
			if(table[index]==key){
				table[index]=-1;
				deleted[index]=true;
				count--;
				return;
			}
			index=(index+1)%tableSize;
			if(startIndex==index){
				break;
			}
	}
	cout<<"value: "<<key<<" Not Found"<<endl;
}
	
	void display(){
		for(int i=0;i<tableSize;i++){
				cout<<i<<"->";
			if(table[i]!=-1){
			cout<<table[i];
			}else{
				cout<<"NULL";
			}
			cout<<endl;
		}
		
	}
};
int main() {
    HashTable h;

      // Inserting values to trigger rehash
    h.insert(5);
    h.insert(10);
    h.insert(15);  // load factor now >= 0.7 ? triggers rehash
    h.insert(20);
    h.insert(25);

    // Display final table only
    cout << "TABLE AFTER INSERT:\n";
    h.display();

    cout << "\nSearching 27: ";
    cout << (h.search(27) ? "Found" : "Not Found") << endl;

    cout << "\nRemoving 18" << endl;
    h.remove(18);
    h.display();

    cout << "\nRemoving 20" << endl;
    h.remove(20);
    h.display();

    return 0;
}