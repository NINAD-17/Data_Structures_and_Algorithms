#include <iostream>
#include <math.h>
using namespace std;

// Time Complexity: O(log(n))   while loop iterates once for each digit in the number, and the number of digits in a base-10 number is log10(n).
// Space Complexity: O(1)

int replaceZeros(int num) {
    int newNum = 0, i = 1;
    if(num == 0) 
        return 5;

    while(num != 0) {
        int lastDig = num % 10;
        if(lastDig == 0)
            lastDig = 5;

        newNum += i * lastDig;
        
        num /= 10;
        i *= 10;
    }

    return newNum;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "New number in which 0 is replaced with 5: " << replaceZeros(num) << endl;
    return 0;
}