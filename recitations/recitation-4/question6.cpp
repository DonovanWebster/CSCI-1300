#include <iostream>
using namespace std;

string concatenate(string a="default", string b="default");

int main()
{
    cout << concatenate("csci","1300") << endl;
    return 0;
}

string concatenate(string a, string b)
{
    string c = a + b;
	return c;
}
