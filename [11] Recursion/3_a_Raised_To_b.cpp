#include <iostream>
using namespace std;

// optimized solution
// note: see image from readme file to understand the solution
// Time: O(log num2), Space: O(log num2)
int exponentiation_rec(int num1, int num2) {
    if(num2 == 0)
        return 1;
    if(num2 == 1)
        return num1;

    int ans = exponentiation_rec(num1, num2/2);

    if(num2 & 1) { // Bitwise operations are generally faster than arithmetic operations Ex - (n % 2 == 0). Read from readme.md
        return num1 * ans * ans;
    } else 
        return ans * ans;
}

// Both methods below will take number of iterations equal to num2
// Normal method using recursion (similar to solution of iterative method)
// Time: O(num2), Space: O(num2)
int exponentiation_rec_2(int num1, int num2) {
    if(num2 == 0)
        return 1;

    return num1 * exponentiation_rec_2(num1, num2 - 1);
}


// Not a good solution, Use Fast Exponentiation method instead --> /Maths \For \DSA/fast_exponentiation.cpp
// Time: O(num2), Space: O(1)
int exponentiation(int num1, int num2) {
    int ans = 1;
    for(int i = 0; i < num2; i++) 
        ans *= num1;
    
    return ans;
}

int main() {
    int num1, num2;

    cout << "Enter num1: ";
    cin >> num1;

    cout << "Enter num2: ";
    cin >> num2;

    cout << num1 << " raised to " << num2 << " is " << exponentiation_rec(num1, num2) << endl;
    cout << num1 << " raised to " << num2 << " is " << exponentiation_rec_2(num1, num2) << endl;

    return 0;
}