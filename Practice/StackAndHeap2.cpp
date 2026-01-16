class Test {
public:
    int* ptr;   // yeh member variable hai
    
    void display(){
    	cout<<"value of ptr: "<<*ptr<<" Address: "<<ptr <<endl;
	}
};

int main() {
    Test* obj = new Test;  // obj heap pe ban gaya
    obj->ptr = new int(20); // ptr bhi obj ke sath heap pe hai
    obj->display();
    cout << *(obj->ptr)<<endl;   // 20
    cout<<(obj->ptr)<<endl;
    delete obj->ptr;
    delete obj;
}

