//
// Created by ok on 9/27/17.
//

#include <iostream>

using namespace std;

class Student {
    int roll_number;
    float percentage;
    char name[50];
public:
    Student() {
        this->get_data();
    }
    void get_data() {
        cout << "Enter Roll number, Name, Percentage : ";
        cin >> roll_number >> percentage >> name;
    }
    void put_data() {
        cout << roll_number << "\t" << percentage << "\t" << name;
    }
};

int main() {
    fstream fstream1;
}
