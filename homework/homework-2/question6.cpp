#include <iostream>

using namespace std;

int main() {

    string invalidInput = "Please enter a valid input\n";
    int country, city, price;
    bool southAfrica = false, mexico = false, india = false, costaRica = false;

    cout << "Enter country: 1.South Africa 2.Mexico 3.India 4.Costa Rica" << endl;
    cin >> country;

    switch (country) {
        case 1:
            southAfrica = true;
            cout << "Enter city: 1.Cape Town 2.Johannesburg" << endl;
            break;
        case 2:
            mexico = true;
            cout << "Enter city: 1.Cancun 2.Mexico City" << endl;
            break;
        case 3:
            india = true;
            cout << "Enter city: 1.Manali 2.Kochi" << endl;
            break;
        case 4:
            costaRica = true;
            cout << "Enter city: 1.San Jose 2.San Vicente" << endl;
            break;
        default:
            cout << invalidInput;
            return 1;
    }

    cin >> city;

    if (city < 1 || city > 2) {
        cout << invalidInput;
        return 1;
    }

    if (southAfrica) {
        switch(city) {
            case 1:
                price = 1200;
                break;
            case 2:
                price = 1000;
                break;
        }
    }

    if (mexico) {
        switch(city) {
            case 1:
                price = 950;
                break;
            case 2:
                price = 800;
                break;
        }
    }

    if (india) {
        switch(city) {
            case 1:
                price = 1100;
                break;
            case 2:
                price = 900;
                break;
        }
    }

    if (costaRica) {
        switch(city) {
            case 1:
                price = 800;
                break;
            case 2:
                price = 1300;
                break;
        }
    }

    cout << "Your trip will be $" << price << endl;

    return 0;

}