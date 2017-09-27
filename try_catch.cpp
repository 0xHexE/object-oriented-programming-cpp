//
// Created by ok on 9/27/17.
//

#include <iostream>
using namespace std;

#define DIVIDE_BY_ZERO 0

int divider() {
    double first, second;
    cout << "Enter two number: ";
    cin >> first >> second;
    try {
        if (second == 0) {
            throw DIVIDE_BY_ZERO;
        }
        cout << "Result: " << first / second;
    } catch (int ex) {
        if (ex == DIVIDE_BY_ZERO) {
            cout << "You are trying to divide the number by ZERO";
        }
    }
}

int main() {
    divider();
}
