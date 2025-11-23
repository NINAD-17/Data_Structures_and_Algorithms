#include <iostream>
#include <vector>
using namespace std;

// For more understanding read below function
vector<vector<int>> matrixMult(vector<vector<int>> &mat_A, vector<vector<int>> &mat_B) {
    vector<vector<int>> mat_ans; // Size of ans vector of vector would be total rows of mat_A × total cols of mat_B

    int mat_A_rows = mat_A.size(); // rows of mat_A
    int mat_B_cols = mat_B[0].size(); // cols of mat_B
    int common_dim = mat_A[0].size(); // mat_A cols = mat_B rows - common dimension
    int mat_ans_rows = mat_A_rows; // The answer matrix has dimensions: ROWs of mat_A × COLs of mat_B
    int mat_ans_cols = mat_B_cols; // The answer matrix has dimensions: ROWs of mat_A × COLs of mat_B

    mat_ans.resize(mat_ans_rows); // resize rows of mat_ans
    for(int mat_ans_row = 0; mat_ans_row < mat_ans_rows; mat_ans_row++) { // iterate through matric_ans rows so that for each row it can resize column size (total elements of rows)
        mat_ans[mat_ans_row].resize(mat_ans_cols); // resize cols of mat_ans
    }

    for(int mat_A_row = 0; mat_A_row < mat_A_rows; mat_A_row++) { // iterate through mat_A rows
        for(int mat_B_col = 0; mat_B_col < mat_B_cols; mat_B_col++) { // iterate through mat_B cols
            mat_ans[mat_A_row][mat_B_col] = 0; // it'll form all elements of mat_ans - 00, 01, 02, 10, 11, 12 ... etc
            for(int k = 0; k < common_dim; k++) { // iterate through common dimensions
                mat_ans[mat_A_row][mat_B_col] += mat_A[mat_A_row][k] * mat_B[k][mat_B_col]; // mat_ans[0][0] += mat_A[0][0] + mat_B[0][0] -> mat_A[0][1] + mat_B[1][0] // it'll ensure that each row of A elements will multiply with col elements of B like A[0][0] with B[0][0] and A[0][1] with B[1][0]
            }
        }
    }

    return mat_ans;
}

// Time complexity: O(n^3)
// Space complexity: O(n^2)

vector<vector<int>> matrixMultiplication(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
    vector<vector<int>> ans;
    ans.resize(matrix1.size()); // Rows of matrix 1
    for(int i = 0; i < matrix1.size(); i++)
        ans[i].resize(matrix2[0].size()); // Column of matrix 2

    for(int row = 0; row < matrix1.size(); row++) {
        for(int col2 = 0; col2 < matrix2[0].size(); col2++) {
            for(int col1 = 0; col1 < matrix1[0].size(); col1++)
                ans[row][col2] += matrix1[row][col1] * matrix2[col1][col2];
        }
    }

    return ans;
}

void printVector(vector<vector<int>> v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) 
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;

    int rows1, cols1, rows2, cols2;

    cout << "Enter number of rows and cols for matrix 1: ";
    cin >> rows1 >> cols1;

    matrix1.resize(rows1);
    for(int row = 0; row < rows1; row++)
        matrix1[row].resize(cols1);

    cout << "Enter " << rows1 * cols1 << " elements: ";
    for(int row = 0; row < rows1; row++) {
        for(int col = 0; col < cols1; col++) 
            cin >> matrix1[row][col];
    }

    cout << "Enter number of rows and cols for matrix 2: ";
    cin >> rows2 >> cols2;

    matrix2.resize(rows2);
    for (int row = 0; row < rows2; row++)
        matrix2[row].resize(cols2);

    cout << "Enter " << rows2 * cols2 << " elements: ";
    for(int row = 0; row < rows2; row++) {
        for(int col = 0; col < cols2; col++) 
            cin >> matrix2[row][col];
    }

    if(cols1 != rows2) {
        cout << "Error: Matrix multiplication needed column of matrix 1 = rows of matrix 2" << endl;
        cout << "Try Again!" << endl;
        exit(0);
    }

    cout << "Matrix1: \n" << endl;
    printVector(matrix1);

    cout << "\nMatrix2: \n" << endl;
    printVector(matrix2);

    cout << "\nMultiplication: \n" << endl;
    vector<vector<int>> ans = matrixMultiplication(matrix1, matrix2);
    printVector(ans);

    return 0;
}