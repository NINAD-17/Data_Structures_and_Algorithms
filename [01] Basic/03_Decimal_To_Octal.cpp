#include <iostream>
#include <math.h>
using namespace std;

int decimalToOctal(int decNum) {
    int octalNum = 0, i = 1;

    while(decNum != 0) {
        int octalDigit = decNum % 8;
        // cout << "Octal Digit: " << octalDigit << endl;
        // octalNum += pow(10, i++) * octalDigit; // pow works with floating point numbers. sometimes it may produce 99.99... which will result in wrong calculation.
        octalNum += i * octalDigit;
        decNum = decNum / 8;
        i *= 10;
    }

    return octalNum;
}

int main() {

    int decNum;
    cout << "Enter a number: ";
    cin >> decNum;

    cout << "Octal representation of " << decNum << " is " << decimalToOctal(decNum) << endl;
    return 0;
}