#include <iostream>
#include <math.h>
using namespace std;

// Find total digits in a number
int findNumOfDigits(int num) {
    int numOfDigits = 0;

    while(num != 0) {
        numOfDigits++;
        num /= 10;
    }

    return numOfDigits;
}

// Calculate power
int intPow(int base, int exp) {
    int result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

bool isArmstrong(int num) {
    int digSum_with_raised_power = 0, inputNum = num;
    int totalDigits = findNumOfDigits(num);

    while(num != 0) {
        int lastDig = num % 10;
        // digSum_with_raised_power += pow(lastDig, totalDigits); // `pow` works with floating point values. If you add floating values in `int` then it may sometimes rounding errors can occur. So don't use it.
        digSum_with_raised_power += intPow(lastDig, totalDigits);
        num /= 10;
    }

    cout << "Total Digits: " << totalDigits << "\nDigits sum with raised power: " << digSum_with_raised_power << endl;
    return (digSum_with_raised_power == inputNum);
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(isArmstrong(num))
        cout << num << " is an Armstrong number.";
    else
        cout << num << " is not an Armstrong number.";
    
    return 0;
}