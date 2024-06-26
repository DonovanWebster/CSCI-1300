#include <iostream>

using namespace std;

int main(){
	int *ptr; 
	int x; 
	double *doublePtr;
	double y;

	ptr = &x; 
	*ptr = 5;

	cout<< "x: " << x<<endl;
	cout<< "ptr: "<<*ptr<<endl; 

	y = 3.5;
	doublePtr = &y; 

	cout<<"doublePtr: "<<*doublePtr<<endl;

    int **ptr2; 
    ptr2 = &ptr;
    *ptr += 5;
    (**ptr2)++;

    cout << "ptr2: " << **ptr2 << endl;

    return 0;
}