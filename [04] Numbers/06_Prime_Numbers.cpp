#include <iostream>
using namespace std;

// Time Complexity: O(sqrt(n)), Space Complexity: O(1)
// A more efficient approach would be to check for divisibility only up to the square root 
// of the input number, as any factor greater than the square root must have a corresponding 
// factor less than the square root.

bool isPrimeUsingSqrtApproach(int num) {
    if(num <= 1) return false;

    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }

    return true;
}

bool isPrime(int num) {
    // Time Complexity: O(n) because it iterates from 2 to (n - 1)
    for(int i = 2; i < num; i++) {
        if(num % i == 0) 
            return false;
    }

    return true;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(isPrimeUsingSqrtApproach(num))
        cout << num << " is a prime number." << endl;
    else 
        cout << num << " is not a prime number." << endl;
    
    return 0;
}