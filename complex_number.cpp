//
// Created by ok on 9/27/17.
//
#include <iostream>

using namespace std;

class Complex {
    int real, imaginary;
public:
    Complex() {
        this->get_data();
    }

    Complex(int real,int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    void get_data() {
        cout << "Enter the Real, Imaginary: ";
        cin >> real >> imaginary;
    }

    Complex operator + (Complex second) {
        second.imaginary += this->imaginary;
        second.real += this->real;
        return second;
    }

    friend Complex Addition(int , int);
};

Complex Addition(Complex complex1, Complex complex2) {
    Complex result(0, 0);
    result.imaginary = complex1.imaginary + complex2.imaginary;
    result.real = complex1.real + complex2.real;
}

int main() {
    Complex c;
}

