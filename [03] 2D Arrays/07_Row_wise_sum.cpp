#include <iostream>
#include <vector>
using namespace std;

vector<int> rowWiseSum(vector<vector<int>> arr, int rows, int cols) {
    vector<int> ans;

    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
        ans.push_back(sum);
    }

    return ans;
}

int main() {
    int rows, cols;

    cout << "Enter Number of rows and columns repectively\nRows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;

    vector<vector<int>> arr(rows, vector<int>(cols));

    for(int row = 0; row < rows; row++) {
        cout << "------- Row - " << row << endl;
        for(int col = 0; col < cols; col++) {
            cout << "Col - " << col << ": ";
            cin >> arr[row][col];
        }
    }

    vector<int> ans = rowWiseSum(arr, rows, cols);
    for(int i = 0; i < ans.size(); i++)
        cout << "Sum of " << i + 1 << " row is " << ans[i] << endl;

    return 0;
}