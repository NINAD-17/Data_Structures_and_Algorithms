#include <iostream>
#include <vector>
using namespace std;

// This solution is for both cases
// 1. Square matrix (Number of rows = Number of cols)
// 2. Non-square matrix (Number of rows != Number of cols)
// Time Complexity: O(n * m)
// Space Complexity: O(n * m) => The space complexity of this code is also O(n*m), as a new matrix of size n*m is created to store the rotated matrix.
vector<vector<int>> rotateBy90Deg(vector<vector<int>> arr) {
    int rows = arr.size();
    int cols = arr[0].size();

    vector<vector<int>> v;
    v.resize(cols);

    for(int i = 0; i < cols; i++)
        v[i].resize(rows);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            v[j][(rows - 1) - i] = arr[i][j];
    }

    return v;
}

// This solution is for only square matrix
// This is an inplace approach (without using any extra space.)
// Time complexity of this function is O(n^2)
// Space complexity is O(1)
void rotateBy90Deg_forSqMatrix(vector<vector<int>>& v) {

    // Transpose of Matrix
    for(int row = 0; row < v.size(); row++) {
        for(int col = row; col < v[row].size(); col++) 
            swap(v[row][col], v[col][row]);
    }

    // Reverse Matrix
    for(int row = 0; row < v.size(); row++) {
        int st = 0, en = v[row].size() - 1;
        while(st < en)
            swap(v[row][st++], v[row][en--]);
    }
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

    cout << "Your Matrix: " << endl;
    printVector(arr);

    cout << "\nRotated Matrix: \n";
    if(rows == cols) {
        rotateBy90Deg_forSqMatrix(arr);
        printVector(arr);
    }
    else  {  
        vector<vector<int>> v = rotateBy90Deg(arr);
        printVector(v);
    }

    return 0;
}