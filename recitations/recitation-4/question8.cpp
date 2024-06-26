#include <iostream>

using namespace std;
    
void hello();
void kenobi(string name);
    
int main() {
    hello();
    return 0;
}

void hello() {
    cout << "Hello there!" << endl;;
    kenobi("Kenobi!");
    return;
}
    
void kenobi(string name){
    cout << "General " << name << endl;
    return;
}
