#include <iostream>
#include <vector>
using namespace std;

// Passing static size to 2D array in parameters is not recommended by C++.
// Instead you can use
// 1. Pass a 2D array to a function using pointers and sizes
void print2D_ArrUsingPtrAndSizes(int *arr, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(j == col - 1) 
                cout << "| " << *((arr + (i * col)) + j) << " |";
            else 
                cout << "| " << *((arr + (i * col)) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 2. Using Vector of vector
void print2D_ArrUsingVector(vector<vector<int>> &arr) {
    for(int row = 0; row < arr.size(); row++) {
        for(int col = 0; col < arr[row].size(); col++) {
            if(col == arr[row].size() - 1)
                cout << "| " << arr[row][col] << " |";
            else
                cout << "| " << arr[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isPresent(int arr[][4], int row, int col, int target) {
    // Read reason of why we must have to include column size in parameters on readme.md
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 4; col++) {
            if(arr[row][col] == target)
                return true;
        }
    }
    return false;
}

int main() {

    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // 3 * 4 = 12 elements
    int arr2[3][4] = {{5, 7, 8, 9}, {1, 2, 3, 4}, {6, 10, 12, 11}}; // To put specific values in specific columns and rows
    print2D_ArrUsingPtrAndSizes((int *)arr1, 3, 4);
    print2D_ArrUsingPtrAndSizes((int *)arr2, 3, 4);

    // Using Vector
    // vector<vector<int>> arr3(3, vector<int>(3));
    
    int arr[10][10];
    cout << "addr" << &arr << endl;
    // Take Input
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            cout << "Enter an element for Row = " << row << " && Col = " << col << " --> ";
            cin >> arr[row][col];
        }
    }

    // Output
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(col == 2)
                cout << "| " << arr[row][col] << " |";
            else
                cout << "| " << arr[row][col] << " ";
        }
        cout << endl;
    }

    // Using vector but without using `(3, vector<int>(3));`
    vector<vector<int>> v;
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    v.resize(rows);
    for(int i = 0; i < rows; i++)
        v[i].resize(cols);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) 
            v[i][j] = i * j;
    }
    print2D_ArrUsingVector(v);

    // Search an element
    int target;
    cout << "Enter an element to search: ";
    cin >> target;

    if(isPresent(arr1, 3, 4, target))
        cout << "Element found :)" << endl;
    else 
        cout << "Element is not found :(" << endl;

    return 0;
}