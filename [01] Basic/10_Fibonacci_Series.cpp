#include <iostream>
using namespace std;

int generateFibonacciNum(int num, bool includeZero) {
    int num1 = 0, num2 = 1;

    if (!includeZero)
        num1 = 1, num2 = 1;

    if(num == 1) return num1;
    else if(num == 2) return num2;

    for(int i = 3; i <= num; i++) {
        int sum = num1 + num2;
        num1 = num2;
        num2 = sum;
    }
    return num2;
}
 
void fibonacciSeriesGenerator(int num, int fNum, int sNum) {
    cout << fNum << " " << sNum << " ";
    while(num != 2) {
        cout << fNum + sNum << " ";
        int temp = fNum;
        fNum = sNum;
        sNum = temp + sNum;
        num--;
    }
}

int main() {
    
    int num, fNum, sNum, responseNum; // fNum = first number, sNum = Second number
    char response;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Do you want a full fibonacci series(1) or only fibonacci number from that place(2)? [choose(1 or 2)] -> ";
    cin >> responseNum;

    if(responseNum != 1) {
        bool includeZero;
        cout << "Can we include 0 while generating fib num from position " << num << "? [repond with 1 for Yes and 0 for No]: ";
        cin >> includeZero;
        
        cout << "Fibonacci Number at position " << num << " is -> " << generateFibonacciNum(num, includeZero) << endl;
        return 0;
    }

    cout << "You want 0 in Fibonnaci series? (Y/N): ";
    cin >> response;

    cout << "Fibonacci Series of 1st " << num << " numbers --> \n";
    if(response == 'Y') {
        fNum = 0, sNum = 1;
        fibonacciSeriesGenerator(num, fNum, sNum);
    } else {
        fNum = 1, sNum = 1;
        fibonacciSeriesGenerator(num, fNum, sNum);
    }

    return 0;
}

// -- Using For Loop --------------
// for(int i = num; i > 0; i--) {
//     cout << fNum + sNum << " ";
//     int temp = fNum;
//     fNum = sNum;
//     sNum = temp + sNum;
// }