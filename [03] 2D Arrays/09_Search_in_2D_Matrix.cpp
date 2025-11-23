#include <iostream>
#include <vector>
using namespace std;

// Link: https://leetcode.com/problems/search-a-2d-matrix/description/
// Note:
// - Each row is sorted in non-decreasing order.
// - The first integer of each row is greater than the last integer of the previous row.
// Ex - [1 2 3]
//      [4 5 6]
//      [7 8 9]


// Time complexity: O(log(rows•cols))
bool searchIn2DMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int st = 0, en = (rows * cols) - 1;

    while(st < en) {
        int mid_index = st + (en - st) / 2; // mid index - 1D
        
        // 2D index - row and col
        int row_index = mid_index / cols; // row index
        int col_index = mid_index % cols; // col index

        int element = matrix[row_index][col_index];

        if(element == target)
            return true;
        else if(element < target) 
            st = mid_index + 1;
        else 
            en = mid_index - 1;
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
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3, cols = 3, target = 5;

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

    // cout << "Search an element: ";
    // cin >> target;

    if(searchIn2DMatrix(arr, target))
        cout << "Element found" << endl;
    else 
        cout << "Element not found" << endl;
    
    return 0;
}