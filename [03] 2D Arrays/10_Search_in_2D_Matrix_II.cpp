#include <iostream>
#include <vector>
using namespace std;

// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

// Note:
// Each row is sorted left → right.
// Each column is sorted top → bottom.
// But the whole matrix is not globally sorted if flattened.

// Ex - [1  4  7  11 15]
//      [2  5  8  12 19]
//      [3  6  9  16 22]
//      [10 13 14 17 24]
//      [18 21 23 26 30]

// Time complexity: O(rows + cols)
// Staircase Search
bool searchIn2DMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int rowIndex = 0;
    int colIndex = cols - 1;

    while(rowIndex < rows && colIndex >= 0) {
        int element = matrix[rowIndex][colIndex];

        if(element == target)
            return true;
        else if(element < target)
            rowIndex++;
        else 
            colIndex--;
    }

    return false;
}

void printVector(vector<vector<int>> v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) 
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> arr = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int rows = 5, cols = 5, target = 5;


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

    cout << "Your Matrix: " << endl;
    printVector(arr);
    cout << endl;

    // cout << "Search an element: ";
    // cin >> target;

    if(searchIn2DMatrix(arr, target))
        cout << "Element found" << endl;
    else 
        cout << "Element not found" << endl;
    
    return 0;
}