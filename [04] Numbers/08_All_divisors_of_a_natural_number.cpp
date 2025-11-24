#include <iostream>
#include <algorithm>
using namespace std;

// Time Complexity: 
// The time complexity of the findDivisorsUsingSqrtMethod function in this 
// code is O(sqrt(n)), where n is the value of the input number. This is because the function checks 
// if the input number is divisible by any integer from 1 to sqrt(n), which takes sqrt(n) iterations. 
// The time complexity of the sort function is O(k log k), where k is the number of divisors found. 
// Since k can be at most sqrt(n), the time complexity of the sort function is also O(sqrt(n) log(sqrt(n))). 
// Therefore, the overall time complexity of the findDivisorsUsingSqrtMethod function, including the sorting step,
// is O(sqrt(n) log(sqrt(n))).

int findDivisorsUsingSqrtMethod(int num, int allDivisors[]) {
    int it = 0;
    for(int i = 1; i * i <= num; i++) {
        if(num % i == 0) {
            allDivisors[it++] = i;  // add the smaller divisor (a)
            if (i != num / i) { 
                allDivisors[it++] = num / i;  // add the paired larger divisor (num / i) but skip it if (i == num / i) -> Ex - 36 = 6 * 6, here i is 6 and num/6 = 6. So that only one divisor will be added.
            }
        }
    }
    sort(allDivisors, allDivisors + it);
    return it;
}

// Time complexity: O(n)
int findDivisors(int num, int allDivisors[]) {
    int it = 0;
    for(int i = 1; i <= num; i++) {
        if(num % i == 0)
            allDivisors[it++] = i;
    }
    return it;
}

int main() {
    int num, allDivisors[100];

    cout << "Enter a number: ";
    cin >> num;

    int count = findDivisorsUsingSqrtMethod(num, allDivisors);
    for(int i = 0; i < count; i++) {
        cout << allDivisors[i] << " ";
    }

    cout << endl;
    return 0;
}