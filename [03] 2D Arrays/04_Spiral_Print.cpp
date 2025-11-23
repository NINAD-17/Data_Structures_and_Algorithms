#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/spiral-matrix/

// Time Complexity: O(N * M)
vector<int> spiralMatrix(vector<vector<int>>& arr) {
    int rows = arr.size();
    int cols = arr[0].size();
    int total = rows * cols, count = 0;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = rows - 1;
    int endingCol = cols - 1;

    vector<int> ans;

    while(count < total) {
        // Print starting row
        for (int index = startingCol; count < total && index <= endingCol; index++)
        {
            ans.push_back(arr[startingRow][index]);
            count++;
        }
        startingRow++;

        // Print ending column
        for(int index = startingRow; count < total && index <= endingRow; index++) {
            ans.push_back(arr[index][endingCol]);
            count++;
        }
        endingCol--;

        // Print ending row
        for(int index = endingCol; count < total && index >= startingCol; index--) {
            ans.push_back(arr[endingRow][index]);
            count++;
        }
        endingRow--;

        // Print starting column
        for(int index = endingRow; count < total && index >= startingRow; index--) {
            ans.push_back(arr[index][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

void printVector(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<vector<int>> arr;
    int rows, cols;

    cout << "Enter total number of rows & cols: \nRows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;

    arr.resize(rows);
    for(int i = 0; i < rows; i++)
        arr[i].resize(cols);
    
    cout << "Enter " << rows * cols << " elements: ";
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) 
            cin >> arr[row][col];
    }

    vector<int> ans = spiralMatrix(arr);
    printVector(ans);

    return 0;
}