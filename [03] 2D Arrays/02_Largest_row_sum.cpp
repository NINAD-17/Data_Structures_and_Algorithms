#include <iostream>
using namespace std;

int largestRow(int arr[10][10], int rows, int cols) {
    int maxSum = -1, rowNo;
    for(int i = 0; i < rows; i++) {
        int sum = 0; 
        for(int j = 0; j < cols; j++) 
            sum += arr[i][j];
        if(sum > maxSum) {
            maxSum = sum;
            rowNo = i;
        }
    }
    return rowNo;
}

int main() {
    int arr[10][10] = {0};
    int rows, cols;

    cout << "Enter Number of rows and columns repectively\nRows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;

    for(int i = 0; i < rows; i++) {
        cout << "------- Row - " << i << endl;
        for(int j = 0; j < cols; j++) {
            cout << "Col - " << j << ": ";
            cin >> arr[i][j];
        }
    }

    int largest = largestRow(arr, rows, cols);

    switch(largest) {
        case 1: cout << "Largest Row is " << largest << "st row" << endl;
                break;
        case 2: cout << "Largest Row is " << largest << "nd row" << endl;
                break;
        case 3: cout << "Largest Row is " << largest << "rd row" << endl;
                break;
        default:
        cout << "Largest Row is " << largest << "th row" << endl;
        break;
    }

    return 0;
}