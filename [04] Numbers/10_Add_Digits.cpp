#include <iostream>
using namespace std;

// Problem: Add number until you get output as only one digit
// Example: 38 --> 3 + 8 = 11; 11 --> 1 + 1 = 2; Therefore ans is 2

// Learn more about Digital Root Formula in readme.md file
// By this formula now Time Complexity is O(1)
int addDigitsUsingDigitalRootFormula(int num) {
    return 1 + ((num - 1) % 9);
}

// Time Complexity: The number of iterations of this loop is equal to the number of digits in the input number, which is O(log n).
//                  Read the explaination of time complexity in readme.md
// Space Complexity: O(1)
int addDigits(int num) {
    int ans = 0;

    while(num != 0) {
        int lastDigit = num % 10;
        ans += lastDigit;
        num /= 10;

        if(num == 0 && ans > 9) {
            num = ans;
            ans = 0;
        }
    }

    return ans;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Addition of digits of " << num << " is " << addDigitsUsingDigitalRootFormula(num) << endl;
    return 0;
}