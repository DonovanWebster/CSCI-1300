#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    string invalidInput = "Please enter a valid input.\n";
    int option1, option2, option3;
    double price;
    bool drink = false, meal = false, dessert = false;
    bool boba = false, soda = false, tacos = false, burger = false, iceCream = false, cookies = false, cake = false;

    cout << "What would you like? 1.Drink 2.Meal 3.Dessert" << endl;
    cin >> option1;
    
    switch (option1) {
        case 1:
            price = 3.00;
            cout << "Select one: 1.Boba 2.Soda" << endl;
            drink = true;
            break;
        case 2:
            price = 10.00;
            cout << "Select one: 1.Tacos 2.Burger" << endl;
            meal = true;
            break;
        case 3:
            price = 6.50;
            cout << "Select one: 1.Ice cream 2.Cookies 3.Cake" << endl;
            dessert = true;
            break;
        default:
            cout << invalidInput;
            return 1;
    }

    cin >> option2;
    
    if (drink) {
        switch (option2) {
            case 1:
                price += 2.00;
                boba = true;
                cout << "Select one: 1.Tapioca 2.Popping 3.Crystal" << endl;
                break;
            case 2:
                soda = true;
                cout << "Select one: 1.Sprite 2.Coke" << endl;
                break;
            default:
                cout << invalidInput;
                return 1;
        }
    }

    if (meal) {
        switch (option2) {
            case 1:
                tacos = true;
                cout << "Select one: 1.Pork 2.Chicken" << endl;
                break;
            case 2:
                price += 2.50;
                burger = true;
                cout << "Select one: 1.Cheeseburger 2.Veggie Burger" << endl;
                break;
            default:
                cout << invalidInput;
                return 1;
        }
    }

    if (dessert) {
        switch (option3) {
            case 1:
                iceCream = true;
                cout << "Select one: 1.Rocky road 2.Vanilla" << endl;
                break;
            case 2:
                cookies = true;
                cout << "Select one: 1.Chocolate Chip 2.Snickerdoodle" << endl;
                break;
            case 3:
                price += 2.00;
                cake = true;
                cout << "Select one: 1.Tiramisu 2.Cheesecake" << endl;
                break;
            default:
                cout << invalidInput;
                return 1;
        }
    }

    cin >> option3;

    if (boba) {
        if (option3 < 1 || option3 > 3) {
            cout << invalidInput;
            return 1;
        }

        if (option3 == 2 || option3 == 3) {
            price += 1.50;
        }
    } else {
        if (option3 < 1 || option3 > 2) {
            cout << invalidInput;
            return 1;
        }
    }

    if (burger && option3 == 2) {
        price += 2.00;
    }

    if (iceCream && option3 == 1) {
        price += 0.50;
    }

    if (cake && option3 == 1) {
        price += 1.00;
    }

    cout << "Order total is $" << fixed << setprecision(2) << price << endl;

    return 0;

}