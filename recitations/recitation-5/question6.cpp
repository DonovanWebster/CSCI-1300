#include <iostream>
using namespace std;

int main()
{
	int numbers[10] = {};
    for(int i = 0; i < 10; i++){
    	numbers[i] = i + 1;
        cout << numbers[i] << endl;
    }

    return 0;
}
