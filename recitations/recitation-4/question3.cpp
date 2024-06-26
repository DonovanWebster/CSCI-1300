#include <iostream>
#include <string>
using namespace std;

string address(string street, string apartment)
{
	return "You stay in APT " + apartment + " on " + street + " St.";
}

// Main function prints the address
int main()
{
    cout<<address("Pearl","123")<<endl;
}
