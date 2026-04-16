#include <iostream>
using namespace std;

// Time complexity:
// The function findSqrt uses a binary search algorithm to find the square root of the input number, 
// which has a time complexity of O(log(n)). The function morePrecision uses a loop that runs p times, 
// where p is the precision, and has a time complexity of O(p).
// Therefore, the overall time complexity of this code is O(log(n) + p)

// Get More precise sqrt
// Time complexity: O(p)
double morePrecision(int num, int precision, int tempSoln) {
    double factor = 1;
    double ans = tempSoln;

    for(int i = 0; i < precision; i++) {
        factor /= 10;

        for(double j = ans; j * j < num; j += factor) 
            ans = j;
    }

    return ans;
}

// Here we're using long long because,
// if mid > INT range then our program will not work.
// Time complexity of findSqrt is O(log n)
long long int findSqrt(int num) {
    int st = 0, en = num;
    long long int ans = -1;

    while(st <= en) {
        long long int mid = st + (en - st) / 2;
        if(mid * mid == num)
            return mid;
        else if(mid * mid < num) {
            ans = mid;
            st = mid + 1;
        }
        else 
            en = mid - 1;
    }

    return ans * -1; // multiplied with -1 to signal “not a perfect square” by returning a negative value. so that main function can call morePrecision(). 
}

// Brute Force 
// Time Complexity: O(✓n) root n
double findSqrt_bruteForce(int num) {
    int nonPerfectSQRT = -1;

    // Find integer part of sqrt(n)
    for(int i = 0; i * i <= num; i++) {
        if(i * i == num) {
            return i; // perfect square
        }

        if(i * i > num) {
            nonPerfectSQRT = i - 1;
            break;
        }
    }

    // Refine answer to 2 decimal places
    double root = nonPerfectSQRT;
    double increment = 0.1;

    for(int precision = 1; precision <= 2; precision++) {
        while((root + increment) * (root + increment) <= num) {
            root += increment;
        }
        increment /= 10;
    }

    return root;
}

int main() {
    int num, precision;
    double morePreciseAns;

    cout << "Enter a number: ";
    cin >> num;

    double bruteForceAns = findSqrt_bruteForce(num);
    cout << "Square root of " << num << " is " << bruteForceAns << endl; // internally bruteForceAns is double and has stored int.0 value if it was perfect square. Ex - 5 will be stored as 5.0 but cout prints a double in the shortest representation. If the value has no fractional part, it prints just 5.

    int ans = findSqrt(num);
    if(ans < 0) {
        cout << "Given number has no perfect square root :(" << endl;
        cout << "How many decimal places you want in more precise ans? -> ";
        cin >> precision;
        cout << "Square root of " << num << " is " << morePrecision(num, precision, (ans * -1)) << endl; // ans * -1: multiplied with -1, to restore exact value with correct sign.
    } else 
        cout << "Square root of " << num << " is " << ans << endl;

    return 0;
}