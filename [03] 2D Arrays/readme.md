# 2D Arrays

If you want to make tic tac toe like table then you can make it using 3 arrays with each has size 3.
But if you want 1000 * 1000 Matrix then it will be difficult to make big numbers of Arrays
To solve this problem you can use linear Array. 

Ex. 3 * 3 Matrix then you can make array of size 9.
![Visualization](images/image.png)

```
| 0 | 1 | 2 |
| 3 | 4 | 5 |
| 6 | 7 | 8 |
```

You can use `Total Columns(C) * Row(i) + Col(j)` to find that position.
Ex. If you want position of 1st Row and 0th Col then by formula you can get position `3 * 1 + 0 = 3`
`| 0 | 1 | 2 | `**3**` | 4 | 5 | 6 | 7 | 8 |`

Above solution is already implemented and to use this we use 2D Arrays.


## Creation of 2D Arrays
- Creation of Array `int arr[3];`
  | 0 | 1 | 2 |

- Creation of 2D Array `int arr[3][3];`
- ```
  | 0 | 1 | 2 |
  | 3 | 4 | 5 | == But in memory it's stored as ==> | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
  | 6 | 7 | 8 |
  ```


## How to take input and give output?
- use `cin >> arr[row_index][col_index];` for taking input.
- use `cout << arr[row_index][col_index];` for output.


## Passing 2D array as a argument and accessing it as a parameters
- In parameters, we must need to put value of column in `int arr[][col];` otherwise it will give an error. <br>
**Read More ->** <a href="https://stackoverflow.com/questions/12813494/why-do-we-need-to-specify-the-column-size-when-passing-a-2d-array-as-a-parameter">Why do we need to specify the column size when passing a 2D array as a parameter?</a>


## Passing 2D array as a parameter
- You can pass 2D array as parameter by `int arr[rows][cols];`. But it's not recommended to use static values. Because it limits the flexibility of your code. If you hard-code the size of the array into the function, then the function can only handle arrays of that specific size.
- You can pass 2D array using Pointers or by using Vector of vector.
  1. Using **Pass a 2D array to a function using pointers and sizes**
    - In this method, when you're calling any function then you've to pass pointer of array to argument. Ex. `print2D_ArrUsingPtrAndSizes((int *)arr1, 3, 4);`.
    - `(int *)arr1` is a typecast. It’s telling the compiler to treat arr1 as a pointer to an integer. This is necessary because the function `print2D_ArrUsingPtrAndSizes `expects its first argument to be of type `int *`.
    - The reason for this typecast is that in `C++`, arrays decay into pointers when passed to functions. That means if you have an array like `int arr[10]` and you pass it to a function that takes an `int *`, the array will be treated as a pointer to its first element.
    - However, this decay doesn’t work for 2D arrays directly because a 2D array is essentially an array of arrays, and when it decays into a pointer, it becomes a pointer to an array, not a pointer to an integer. So we need to manually cast the 2D array to `int *` with `(int *)arr1`.
  
  2. Using vector of vector
    Ex. Declaring Vector: `vector<vector<int>> arr(3, vector<int>(3));`
        Function: `void print2D_ArrUsingVector(vector<vector<int>> &arr)`
    - The reason we pass arr by reference using the `&` symbol is to avoid making a copy of the 2D array. If we passed it by value (without the &), C++ would create a copy of the entire 2D array for the function to use, which could be slow and use up a lot of memory if the array is large.
    - `vector<vector<int>> arr` declares a 2D vector named arr.
    - The outer vector represents the rows of the 2D array, and the inner `vector<int>` represents the columns of each row.
    -` (3, vector<int>(3))` is a constructor that tells the vector how to initialize itself.
    - The first argument `3` tells the outer vector to create` 3` rows.
    - The second argument `vector<int>(3) `is another vector constructor. It tells the inner `vector<int>` to create 3 columns for each row and initialize all elements to zero.
    - `vector<vector<int>> arr(3, vector<int>(3));` creates a `3x3` 2D vector where all elements are initialized to zero. It’s equivalent to the `int arr[3][3] = {0};`
    
    **Note:** When you declare a vector without specifying its size, it’s initially empty, which means it has no elements and its size is 0. If you try to access an element in an empty vector using the `[]` operator, you’re trying to access memory that hasn’t been allocated, which leads to undefined behavior.
    If you want to do it with same way `vector<vector<int>> arr;` then you've to use `resize()` function. See Example on `1_Intro.cpp` file.

## Resizing `vector<vector<data_type>>`
- `vector<vector<int>> arr;` starts empty.
- When you call `arr.resize(i);`, you create `i` rows (each is an empty vector).
- Then for each row, `arr[i].resize(j);` creates `j` columns initialized to 0.
- Without resizing, `arr[i][j]` would be invalid because the inner vectors don’t exist yet.
- So yes, resizing ensures you can safely access `arr[i][j]`.
👉 Resizing = “allocate memory for rows and columns, fill with 0s.”
  
---
---

## Problems:
### 1. Matrix Multiplication

  - *A<sub>m × n</sub> × B<sub>n × p</sub> = C<sub>m × p</sub>*

  - If `matrix1` has `m` rows and `n` columns,
  
  - And `matrix2` has `n` rows and `p` columns,
  
  - Then the **result (ans) will have m rows and p columns**.

  - 👉 Condition: columns of A = rows of B (the “inner dimensions” must match). <br>
  - 👉 **Result: rows of A × columns of B** (the “outer dimensions” form the result).

  - **Ex** - **Matrix A(2 × 3) & Matrix B(3 × 4)**
    ```
    Matrix A: [ a11  a12  a13 ]  |  Matrix B: [ b11  b12  b13  b14 ]
              [ a21  a22  a23 ]  |            [ b21  b22  b23  b24 ]
                                 |            [ b31  b32  b33  b34 ] 
    ```

    **Result: Matrix C(2 × 4)**
    ```
    Matrix C: [ c11  c12  c13  c14 ]
              [ c21  c22  c23  c24 ]
    ```

  - C has rows = rows of A (2)
  - C has columns = columns of B (4)
  - Each element of C is computed as:
      
      C<sub>ij</sub> = a<sub>i1</sub> • b<sub>1j</sub> + a<sub>i2</sub> • b<sub>2j</sub> + a<sub>i3</sub> • b<sub>3j</sub>

#### Example:
  * **Matrix A (2×2)**:
    ```
    [ 1  2 ]
    [ 3  4 ]
    ```
    Indices: A-00=1, A-01=2, A-10=3, A-11=4

  * **Matrix B (2×3)**:
    ```
    [ 5  6  7 ]
    [ 8  9 10 ]
    ```
    Indices: B-00=5, B-01=6, B-02=7, B-10=8, B-11=9, B-12=10

  - Validity condition: cols(A)=2 must equal rows(B)=2 → valid.
  - Result size: A(m×n) × B(n×p) = C(m×p) → C is 2×3 (not 2×2).

##### Can we swap A and B?
- A×B is defined because 2 (cols of A) = 2 (rows of B). Result is 2×3.
- B×A would require cols(B)=3 to equal rows(A)=2 → not equal → B×A is NOT defined.
- In general, matrix multiplication is not commutative; A×B may exist while B×A doesn’t, and even if both exist, A×B ≠ B×A.

##### How each element of C is computed
  Rule: C[i][j] = dot product of row i of A and column j of B.

  Let’s compute all 6 elements for C (2×3): C-00, C-01, C-02, C-10, C-11, C-12.

  Row 0 of A: [1, 2]

  Row 1 of A: [3, 4]

  Column 0 of B: [5, 8]

  Column 1 of B: [6, 9]

  Column 2 of B: [7, 10]

  * First row of C (i = 0)
    - C-00 = row0(A) ⋅ col0(B) = (1×5) + (2×8) = 5 + 16 = 21
    - C-01 = row0(A) ⋅ col1(B) = (1×6) + (2×9) = 6 + 18 = 24
    - C-02 = row0(A) ⋅ col2(B) = (1×7) + (2×10) = 7 + 20 = 27

  * Second row of C (i = 1)
    - C-10 = row1(A) ⋅ col0(B) = (3×5) + (4×8) = 15 + 32 = 47
    - C-11 = row1(A) ⋅ col1(B) = (3×6) + (4×9) = 18 + 36 = 54
    - C-12 = row1(A) ⋅ col2(B) = (3×7) + (4×10) = 21 + 40 = 61

  * **Final matrix C (2×3)**
    ```
    [ 21  24  27 ]
    [ 47  54  61 ]
    ```
  --- 


- Note: To perform multiplication of two matrices, we should make sure that the **number of columns in the 1st matrix is equal to the rows in the 2nd matrix.**

- if you have two matrices A and B:
```
A = [a b]     B = [e f]
    [c d]         [g h]
```
The resulting matrix C would be:
`C = [ae+bg af+bh] [ce+dg cf+dh]`

### 2. Spiral Print:
  ```
  | 0 | 1 | 2 |
  | 3 | 4 | 5 |
  | 6 | 7 | 8 |
  ```

![Spiral Print](images/image-1.png)

### 3. Transpose of Matrix:
-  Transpose of a matrix is obtained by interchanging all rows to columns and columns to rows.
```
| 1 | 2 | 3 |                     | 1 | 4 | 7 |
| 4 | 5 | 6 |  ==> Transpose ==>  | 2 | 5 | 8 |
| 7 | 8 | 9 |                     | 3 | 6 | 9 |
```
- Transpose of matrix is **only possible for square matrix.** (Number of rows = Number of cols)

### 4. Search in 2D Matrix:
```
| 1 | 2 | 3 |  Index--  0   1   2   3   4   5   6   7   8
| 4 | 5 | 6 |   ==>   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| 7 | 8 | 9 | 
```
- You've to take `st = 0` and `en = (rows * cols) - 1`. Then take `mid = st + (en - st) / 2;`. And then apply binary search algorithm.
- But if you get `arr[mid] = 6`, means index - `mid = 5` then you've to map it with `row` and `col`.
- For that you can do it by, 
 - For col, `index % cols` - Ex. 5%3 = 1
 - For row, `index / cols` - Ex. 5/3 = 2
So `Matrix[2][1] = 6`, and index in linear array is `5`.
