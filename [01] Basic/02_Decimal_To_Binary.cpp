#include <iostream>
#include <math.h>
#include <string>
#include <bitset>
#include <typeinfo>
using namespace std;

// Note:
// - std::bitset<32> is a C++ standard library class template for fixed-size bit sequences.
//   It’s not an int; it internally manages 32 Boolean values. Printing shows all 32 bits.
// - In manual bitset-like representation, we use std::string to store bits. Using int here
//   would overflow because INT_MIN/INT_MAX (-2147483648 to 2147483647) are far smaller than
//   the maximum 32-bit binary string (≈ 1e32). String avoids this limit.
// - The divide-by-2 and '&' operator methods work correctly for small numbers, but for large
//   inputs they overflow int and produce garbage values instead of crashing. This is due to
//   two’s complement wraparound on most systems.

// Using bitset - for getting correct binary of all signed/unsigned int
bitset<32> usingBitset(int decNum) {
    return bitset<32>(decNum); 
}

string manualBitsetLike(int decNum) {
    string bits = "";
    
    for(int i = 31; i >=0; i--) {
        int bit = (decNum >> i) & 1;
        bits += (bit ? "1": "0");
    }

    return bits;
}

// Time complexity for both functions is O(log(n))
// Space complexit is O(1)

// Using division by 2 method
int usingDivBy2Method(int decNum) {
    int binary = 0;
    // int i = 0;
    int i = 1;
    
    while(decNum != 0) {
        int remainder = decNum % 2;
        // binary += (pow(10, i) * remainder);
        binary += (i * remainder);
        i *= 10;
        decNum /= 2;
    }

    return binary;
}

// Using AND operator
int decToBin(int decNum) {
    int binaryNumber = 0;
    // int i = 0;
    int i = 1;

    while(decNum != 0) {
        int binDigit = decNum & 1;
        binaryNumber += (i * binDigit);
        i *= 10;
        decNum = decNum >> 1;
    }

    return binaryNumber;
}

int main() {

    int decNum;

    cout << "----- Convert Decimal Number into Binary -----\n";
    cout << "Enter a number: ";
    cin >> decNum;

    if(decNum >= 0) {
        // if number is not -ve then only run following functions
        cout << "Binary of " << decNum << " is " << decToBin(decNum) << endl;
        cout << "Binary of " << decNum << " is " << usingDivBy2Method(decNum) << endl;
    }
    cout << "Binary of " << decNum << " using bitset is " << usingBitset(decNum) << "\tType of bitset" << typeid(usingBitset(decNum)).name() << endl;
    cout << "Binary of " << decNum << " using bitset manual implementation is " << manualBitsetLike(decNum) << endl;
    return 0;
}