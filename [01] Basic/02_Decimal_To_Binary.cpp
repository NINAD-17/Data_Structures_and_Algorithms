#include <iostream>
#include <math.h>
#include <string>
#include <bitset>
using namespace std;

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
    int binary = 0, i = 0;
    
    while(decNum != 0) {
        int remainder = decNum % 2;
        binary += (pow(10, i) * remainder);
        i++;
        decNum /= 2;
    }

    return binary;
}

// Using AND operator
int decToBin(int decNum) {
    int binaryNumber = 0, i = 0;

    while(decNum != 0) {
        int binDigit = decNum & 1;
        binaryNumber += (pow(10, i) * binDigit);
        i++;
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
    cout << "Binary of " << decNum << " using bitset is " << usingBitset(decNum) << endl;
    cout << "Binary of " << decNum << " using bitset manual implementation is " << manualBitsetLike(decNum) << endl;
    return 0;
}