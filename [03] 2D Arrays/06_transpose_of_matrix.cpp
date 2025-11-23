#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(n * m)
void transposeOfMatrix(vector<vector<int>>& arr) {
    for(int row = 0; row < arr.size(); row++) {
        for(int col = row; col < arr[row].size(); col++) 
            swap(arr[row][col], arr[col][row]);
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

    cout << "Your Matrix: " << endl;
    printVector(arr);

    transposeOfMatrix(arr);
    cout << "\nTranspose of Matrix: \n";
    printVector(arr);

    return 0;
}