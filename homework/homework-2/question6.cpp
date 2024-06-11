// Homework 2 - Problem 6

#include <iostream>

using namespace std;

int main() {

    string invalidInput = "Please enter a valid input.\n";
    int country, city, price;

    cout << "Enter country: 1.South Africa 2.Mexico 3.India 4.Costa Rica" << endl;
    cin >> country;

    switch (country) {
        case 1:
            cout << "Enter city: 1.Cape Town 2.Johannesburg" << endl;
            cin >> city;

            switch(city) {
                case 1:
                    price = 1200;
                    break;
                case 2:
                    price = 1000;
                    break;
                default:
                    cout << invalidInput;
                    return 1;
            }
            break;
        case 2:
            cout << "Enter city: 1.Cancun 2.Mexico City" << endl;
            cin >> city;

            switch(city) {
                case 1:
                    price = 950;
                    break;
                case 2:
                    price = 800;
                    break;
                default:
                    cout << invalidInput;
                    return 1;
            }

            break;
        case 3:
            cout << "Enter city: 1.Manali 2.Kochi" << endl;
            cin >> city;

            switch(city) {
                case 1:
                    price = 1100;
                    break;
                case 2:
                    price = 900;
                    break;
                default:
                    cout << invalidInput;
                    return 1;
            }

            break;
        case 4:
            cout << "Enter city: 1.San Jose 2.San Vicente" << endl;
            cin >> city;

            switch(city) {
                case 1:
                    price = 800;
                    break;
                case 2:
                    price = 1300;
                    break;
                default:
                    cout << invalidInput;
                    return 1;
            }
            
            break;
        default:
            cout << invalidInput;
            return 1;
    }

    cout << "Your trip will be $" << price << "." << endl;

    return 0;

}