#include <iostream>
using namespace std;

// Time and Space Complexity: O(1)

bool isEven(int num) {
    if(num % 2 == 0) return true;
    else return false;
}

bool isPositiveNum(int num) {
    return num >= 1;
}

bool result(int num) {
    bool posNum = isPositiveNum(num);
    bool evenNum = isEven(num);

    if(posNum && evenNum) cout << num << " is Positive and Even number." << endl;
    else if(posNum && !evenNum) cout << num << " is Positive and Odd number." << endl;
    else if(!posNum && evenNum) cout << num << " is Negetive and Even number." << endl;
    else cout << num << " is Negetive and Odd number." << endl;
}

int main() {
    int num; 

    cout << "Enter a number: ";
    cin >> num;

    if(num == 0)
        cout << "Given number is Zero." << endl;
    else 
        result(num);

    return 0;
}