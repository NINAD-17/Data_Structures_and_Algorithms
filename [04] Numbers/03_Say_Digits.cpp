#include <iostream>
#include <vector>
using namespace std;

void sayDigits(int num, string *digits) {
    vector<int> digitList;

    while(num != 0) {
        int remainder = num % 10;
        digitList.push_back(remainder);
        num /= 10;
    }

    for(int i = digitList.size() - 1; i >= 0; i--)
        cout << digits[digitList[i]] << " ";
    
    cout << endl;
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