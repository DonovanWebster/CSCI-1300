#include <iostream>
#include <string>
using namespace std;
int main()
{
	double scores[6] = {85.4, 90.3, 100, 89, 74.5, 95};
	double sum = 0;
	for(int i = 0; i < 6; i++){
		sum += scores[i];
	}
	double avg = sum / 6.0;
	cout << "Average = " << avg << endl;
return 0; 
}
