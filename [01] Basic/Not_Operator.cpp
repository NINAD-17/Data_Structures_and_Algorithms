#include<iostream>
using namespace std;

int main() {

    // Bitwise Operators
    int a = 4, b = 6;
    // a = 0100 and b = 0110
    
    cout << "a & b: " << (a & b) << endl; // 0100 & 0110 = 0100(4)
    cout << "a | b: " << (a | b) << endl; // 0100 | 0110 = 0110(6)
    cout << "a ^ b: " << (a ^ b) << endl; // 0100 ^ 0110 = 0010(2)
    cout << "~a and ~b: " << ~a << " and " << ~b << endl;


    // Printing Negetive Number
    int num = 2;
    cout << "NOT(~) of " << num << " --> " << ~num << endl;
    // Here 1st we took 1's compliment of integer 2.
    // 000....0010 ----> 1's compliment ----> 111....1101
    // 111....1101 is the value of ~num. So, this is an answer of our question.
    // But we want it in decimal number. So, now we've to convert it in decimal number.

    // In answer 111....1101, 1st bit is 1 which is showing that number is negetive
    // To display negetive number we've to take its 2's compliment.
    // For 2's compliment, we take 1's compliment and then add 1 to it.
    // And finally we give -ve sign to that output number.

    // 2's compliment process...
    // To print this negetive number, you've to take 2's compliment of that value(111....1101)
    // We're ignoring 1st bit, because it's showing that the number is negetive.
    // Now take 1's compliment of remaining bits --> (00....0010) remember that we ignored 1st bit.
    // Now add 1 to this value --> 00....0010 + 1 = 00....0011
    // 00....0011 So by (bin to decimal) value is 3
    // So answer is -ve 3 (-3)
}