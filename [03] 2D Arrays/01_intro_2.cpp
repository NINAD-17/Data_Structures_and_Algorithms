#include <iostream>
#include <vector>
using namespace std;

// 1. Print 2D array using pointer arithmetic
// arr is treated as a 1D array internally, so we use formula: row*cols + col
void print2D_UsingPointer(int *arr, int rows, int cols) {
    cout << "Printing using pointer arithmetic:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << *((arr + i*cols) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 2. Print 2D array using normal [][] notation
// Here column size must be given in parameter
void print2D_UsingArray(int arr[][4], int rows) {
    cout << "Printing using [][] notation:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 3. Print 2D array using vector<vector<int>>
void print2D_UsingVector(vector<vector<int>> &v) {
    cout << "Printing using vector<vector<int>>:\n";
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Example 1: Static 2D array
    int arr1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Passing as pointer (flattened)
    print2D_UsingPointer((int*)arr1, 3, 4);

    // Passing as [][] (need to specify column size)
    print2D_UsingArray(arr1, 3);

    // Example 2: Dynamic 2D array using vector
    int rows = 3, cols = 3;
    vector<vector<int>> v(rows, vector<int>(cols));

    // Fill with sample values
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            v[i][j] = i*cols + j; // just for demo
        }
    }

    print2D_UsingVector(v);

    return 0;
}
