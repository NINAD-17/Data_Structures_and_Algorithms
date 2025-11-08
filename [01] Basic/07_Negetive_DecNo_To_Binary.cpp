#include <iostream>
#include <math.h>
using namespace std;

// Below code is wrong. Refer 02_Decimal_To_Binary.cpp
int makeItPositiveNum(int num) {
    return num * (-1);
}

int decToBin(int num) {
    int binaryNumber = 0, i = 0;

    while(num != 0) {
        int bit = num & 1;
        binaryNumber += (pow(10, i++) * bit);
        num = num >> 1;
    }

    return binaryNumber;
}

int negetiveNumToBinary(int num) {
    int positiveNum = makeItPositiveNum(num);
    int binaryOfPositiveNum = decToBin(positiveNum);
    cout << "Binary of positive Num: " << binaryOfPositiveNum << endl;

    // 2's compliment process
    int twosComp = ~binaryOfPositiveNum;
    cout << "1's compliment of positive number: " << twosComp << endl;
    twosComp = twosComp + 1;

    return twosComp;
}

int main() {

    int negetiveNum;

    cout << "Enter a negetive decimal number: ";
    cin >> negetiveNum;

    cout << "Binary of " << negetiveNum << " is " << negetiveNumToBinary(negetiveNum) << endl;
    return 0;
}