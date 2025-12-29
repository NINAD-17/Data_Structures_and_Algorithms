#include <iostream>
using namespace std;

// GCD: The gcd function is used to find the greatest common divisor (GCD) of two numbers.
// The GCD of two numbers is the largest positive integer that divides both numbers without a remainder.
// Example: The GCD of 18 and 27 is 9, so we can divide both the numerator and denominator by 9 to get 18/9 = 2 and 27/9 = 3. This gives us the simplified fraction 2/3.

// Time Complexity: The gcd function uses an iterative implementation of the Euclidean algorithm to find the greatest common divisor of two numbers, and its time complexity is O(log(min(num, den))).
// therefore The time complexity of the addFractions function is O(log(min(num, den))) as it's calling simplifyFraction --> gcd functions.
int gcd(int num, int den) {
    while(den != 0) {
        int temp = den;
        den = num % den;
        num = temp;
    }
    return num;
}

void simplifyFraction(int &ansNum, int &ansDen) {
    int commonDivisor = gcd(ansNum, ansDen);
    ansNum /= commonDivisor;
    ansDen /= commonDivisor;
}

void addFractions(int num1, int den1, int num2, int den2, int &ansNum, int &ansDen) {

    if(den1 == den2) {
        ansNum = num1 + num2;
        ansDen = den1;
        simplifyFraction(ansNum, ansDen);
        return;
    } else {
        ansNum = (den2 * num1) + (den1 * num2);
        ansDen = (den1 * den2);
        simplifyFraction(ansNum, ansDen);
        return;
    }
}

int main() {
    int num1, num2, den1, den2, ansNum, ansDen;

    cout << "Enter Numerator and Denometer values of fraction 1 respectively (space in between): " << endl;
    cin >> num1 >> den1;

    cout << "Enter Numerator and Denometer values of fraction 2 respectively (space in between): " << endl;
    cin >> num2 >> den2;

    addFractions(num1, den1, num2, den2, ansNum, ansDen);
    cout << "Addition of " << num1 << "/" << den1 << " + " << num2 << "/" << den2 << " = " << ansNum << "/" << ansDen << endl;

    return 0;
}