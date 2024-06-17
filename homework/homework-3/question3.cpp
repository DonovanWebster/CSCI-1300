// Homework 3 - Problem 3

#include <iostream>

using namespace std;

void printMenu() {
    cout << "Select a numerical option:" << endl;
    cout << "=== menu ===" << endl;
    cout << "1. BLT sandwich" << endl;
    cout << "2. Caprese sandwich" << endl;
    cout << "3. Veggie sandwich" << endl;
    cout << "4. Quit" << endl;
}

double validateUserInput(string str) {
    double choice;
    cin >> choice;
    while (choice < 0.0) {
        cout << "Invalid input." << endl;
        cout << str << endl;
        cin >> choice;
    }
    return choice;
}

void blt() {
    double neededIngredients[4] = {5, 4, 3, 0.51};
    double ownedIngredients[4];
    string questions[4] = {
        "How many bacon strips do you have?\n",
        "How many tomato slices do you have?\n",
        "How many lettuce leaves do you have?\n",
        "How many ounces of mayonnaise do you have?\n"
    };
    for (int i = 0; i < 4; i++) {
        cout << questions[i];
        ownedIngredients[i] = validateUserInput(questions[i]);
    }
    bool canMake = true;
    for (int i = 0; i < 4; i++) {
        if (ownedIngredients[i] < neededIngredients[i]) {
            canMake = false;
            break;
        }
    }
    if (canMake) {
        cout << "You can make a BLT sandwich." << endl;
    } else {
        cout << "You don't have enough for a BLT sandwich." << endl;
    }
}

void caprese() {
    double neededIngredients[4] = {6, 2, 10, 0.12};
    double ownedIngredients[4];
    string questions[4] = {
        "How many mozzarella slices do you have?\n",
        "How many tomato slices do you have?\n",
        "How many basil leaves do you have?\n",
        "How many ounces of balsamic glaze do you have?\n"
    };
    for (int i = 0; i < 4; i++) {
        cout << questions[i];
        ownedIngredients[i] = validateUserInput(questions[i]);
    }
    bool canMake = true;
    for (int i = 0; i < 4; i++) {
        if (ownedIngredients[i] < neededIngredients[i]) {
            canMake = false;
            break;
        }
    }
    if (canMake) {
        cout << "You can make a Caprese sandwich." << endl;
    } else {
        cout << "You don't have enough for a Caprese sandwich." << endl;
    }
}

void veggie() {
    double neededIngredients[4] = {5, 4, 3, 0.51};
    double ownedIngredients[4];
    string questions[4] = {
        "How many red onion rings do you have?\n",
        "How many cucumber do you have?\n",
        "How many ounces of diced roasted peppers do you have?\n",
        "How many ounces of hummus do you have?\n"
    };
    for (int i = 0; i < 4; i++) {
        cout << questions[i];
        ownedIngredients[i] = validateUserInput(questions[i]);
    }
    bool canMake = true;
    for (int i = 0; i < 4; i++) {
        if (ownedIngredients[i] != neededIngredients[i]) {
            canMake = false;
            break;
        }
    }
    if (canMake) {
        cout << "You can make a Veggie sandwich." << endl;
    } else {
        cout << "You don't have enough for a Veggie sandwich." << endl;
    }
}

int main() {

    printMenu();
    int choice;
    cin >> choice;
    
    while (choice != 4) {
        switch (choice) {
            case 1:
                blt();
                break;
            case 2:
                caprese();
                break;
            case 3:
                veggie();
                break;
            case 4:
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
        printMenu();
        cin >> choice;
    }

    cout << "Goodbye!" << endl;

    return 0;

}