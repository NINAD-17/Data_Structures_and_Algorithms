#include <iostream>
using namespace std;

// NOTE: To see iterative solutino of fibonacci series, go to -> ../Basic/Fibonaci_Series.cpp
// Time: O(2^n);   Space: O(n)

// If you're considering fibonacci series as 0, 1, 1, 2.... 
int fibNumFromOne(int n) {
    // Base Case
    // if(n == 1) return 0; if(n == 2) return 1; <--- Long If statement
    if(n == 1 || n == 2) // Short
        return n - 1;

    // Recursive Relation
    return fibNumFromOne(n - 1) + fibNumFromOne(n - 2);
}

// If you're considering fibonacci series as 1, 1, 2, 3....
int fibNum(int n) {
    // Base Case
    if(n == 0 || n == 1)
        return n;

    // Recursive relation
    return fibNum(n - 1) + fibNum(n - 2);
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci number if you consider series from 0: " << fibNum(n) << endl;
    cout << "Fibonacci number if you consider series from 1: " << fibNumFromOne(n) << endl;
 
    return 0;
}