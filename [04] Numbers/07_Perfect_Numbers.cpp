#include <iostream>
using namespace std;

// A perfect number is a positive integer that is equal to the sum of its proper divisors (all divisors excluding the number itself).
// Time Complexity: O(sqrt(n))

int sumOfDivisors(int num) {
    int sum = 0;
    for(int i = 1; i * i <= num; i++) {
        if(num % i == 0) {
            sum += i;  // add the smaller divisor

            // Add the paired larger divisor (num / i),
            // but skip two cases:
            //      1. Skip when i == 1 → avoids adding num itself. Ex - 36 = 1 * 36 (a * b)
            //      2. Skip when i == num/i → avoids double-counting sqrt(num). Ex - 36 = 6 * 6 (a * b)
            if((i != 1) && i != (num / i)) 
                sum += num / i;  // add the paired larger divisor
        }
    }
    return sum;
}

bool isPerfect(int num) {
    return (sumOfDivisors(num) == num);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(isPerfect(num)) 
        cout << num << " is a perfect number." << endl;
    else
        cout << num << " is not a perfect number." << endl;

    return 0;
}
