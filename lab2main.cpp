/*
* Lab 2
* Harmony Trinh & Jayne Tan
* The purpose of this lab is to demonstrate currency conversion using different classes, inheritance, and polymorphism.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include "pound.cpp"
using namespace std;

int main() {
    Currency* currencies[2];
    currencies[0] = new Pound(0.00);
    currencies[1] = new Dollar(0.00);
    while (true) {
        currencies[0]->print();
        currencies[1]->print();
        cout << endl;

        char oprtr;
        char oprnd;
        double value;
        string currency;
        cout << "Enter <a or s> <p or d> <value> <currency>" << endl;
        cin >> oprtr;
        if (oprtr == 'q') {
            break;
        }
        cin >> oprnd >> value >> currency;
        try {
            if (oprtr == 'a') {
                if (oprnd == 'p' && currency == "pound")
                    currencies[0]->add(new Pound(value));
                else if (oprnd == 'd' && currency == "dollar")
                    currencies[1]->add(new Dollar(value));
                else
                    throw "Invalid addition";
            }
            else if (oprtr == 's') {
                if (oprnd == 'p' && currency == "pound")
                    currencies[0]->subtract(new Pound(value));
                else if (oprnd == 'd' && currency == "dollar")
                    currencies[1]->subtract(new Dollar(value));
                else
                    throw "Invalid subtraction";
            } else{
                throw "Invalid operator";
            }
        }
        catch (const char e[]) {
            cout << e << endl;
        }
    }
}