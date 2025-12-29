#include <iostream>
using namespace std;

// For iterative solution: go to ../Numbers/Say_Digits.cpp
// if you’re dealing with very large numbers (i.e., numbers with a lot of digits), the recursive function call stack could become quite deep, which might lead to a stack overflow. In that case, an iterative solution might be more appropriate.

// Time complexity: O(log n)  - num is an int and not size of an array. 
// Space complexity: O(log n)
void sayDigits(int num, string *digits) {
    // Base Case
    if(num == 0)
        return;
    
    // Recursive Relation
    sayDigits(num / 10, digits);

    // Processing
    int digit = num % 10;
    cout << digits[digit] << " ";
}

int main() {
    int num;
    string digits[10] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };

    cout << "Enter a number: ";
    cin >> num;

    cout << num << " in words: ";
    sayDigits(num, digits);
    cout << endl;

    return 0;
}