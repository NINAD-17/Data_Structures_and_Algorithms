#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(n * m)

void wavePrint(vector<vector<int>>& arr, int rows, int cols) {
    for(int col = 0; col < cols; col++) {
        if(col % 2 == 0) {
            for(int row = 0; row < rows; row++) 
                cout << arr[row][col] << " ";
        } else {
            for(int row = rows - 1; row >= 0; row--) 
                cout << arr[row][col] << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3, cols = 3;

    // cout << "Enter total number of rows & cols: \nRows: ";
    // cin >> rows;
    // cout << "Cols: ";
    // cin >> cols;

    // arr.resize(rows);
    // for(int i = 0; i < rows; i++)
    //     arr[i].resize(cols);
    
    // cout << "Enter " << rows * cols << " elements: ";
    // for(int row = 0; row < rows; row++) {
    //     for(int col = 0; col < cols; col++) 
    //         cin >> arr[row][col];
    // }

    wavePrint(arr, rows, cols);
    return 0;
}