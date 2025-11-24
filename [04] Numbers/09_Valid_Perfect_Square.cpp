#include <iostream>
using namespace std;

// Perfect Squares: 1 * 1, 2 * 2, 3 * 3, and 4 * 4, respectively.
//                  1, 4, 9, 16, ...


// Optimized Approach:
// Time Complexity: O(log(n)) as it is using binary search

bool isPerfectSquareUsingBinarySrch(int num) {
    int st = 0, en = num;

    while(st <= en) {
        int mid = st + (en - st)/2;
        if(mid * mid == num)
            return true;
        else if(mid * mid < num)
            st = mid + 1;
        else
            en = mid - 1;
    }

    return false;
}


// Brute Force Approach:
// The time complexity of the given code is O(√n), where n is the value of the input number.
// This is because the function isPerfectSquare checks all numbers from 2 to √n to see 
// if any of them is a divisor of n.
// The space complexity is O(1), as the function uses a constant amount of space to store its variables.

bool isPerfectSquare(int num) {
    for(int i = 2; (i * i) <= num; i++) {
        if(num == (i * i)) {
            cout << num << "\t" << i << "*" << i << "\t" << num % (i * i) << endl;
            return true;
        }
    }
    
    return false;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(isPerfectSquareUsingBinarySrch(num)) 
        cout << num << " is a Perfect Square." << endl;
    else 
        cout << num << " is not a Perfect Square." << endl;

    return 0;
}