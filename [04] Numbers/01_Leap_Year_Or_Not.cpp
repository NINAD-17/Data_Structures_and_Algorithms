#include <iostream>
using namespace std;

// The time complexity of this algorithm is O(1) because it performs a fixed number of 
// operations regardless of the value of the input year. The space complexity is also O(1) 
// because it uses a fixed amount of memory to store the input year and a few additional variables.

bool isMultipleOf100(int year) {
    return year % 100 == 0;
}

bool isMultipleOf4(int year) {
    return year % 4 == 0;
}

bool isMultipleOf400(int year) {
    return year % 400 == 0;
}

bool isLeapYear(int year) {
    if(isMultipleOf400(year) || isMultipleOf4(year) && !isMultipleOf100(year)) 
        return true;
    else 
        return false;
}

int main() {

    int year;

    cout << "Enter a year: ";
    cin >> year;

    if(isLeapYear(year)) 
        cout << year << " is a leap year." << endl;
    else 
        cout << year << " is not a leap year." << endl;
    
    return 0;
}