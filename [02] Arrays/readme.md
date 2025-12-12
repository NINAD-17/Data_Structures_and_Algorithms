# Arrays

An array is a collection of items of same data type stored at contiguous memory locations.

## Why?
To store multiple values in one variable.
Example: 
```
10000 values ---> 10000 variables
10000 values ---> 1 variable
```

## Declaring Arrays

`int arr[10];`
Here 'arr' is the name of array as well as it's locates address of 1st element of array.

If you declared array without initializing it then it will contain garbage values.
`int arr[10];`

- Arrays are contiguous memory locations.
- Indexing start with 0. `arr[0]` is the first location.
  ```
  arr[1] ==> 100 + 4 * 1    // Here 1 is the 2nd memory location and assume 100 as memory location. 4 is the size of int
  ```
- `int arr[10000] = {0}` Here all array elements is initialized with 0.
  `int arr[10000] = {1}` But here this will not work. It only works for 0.

- **Note: Bad Practice**
Always initialize array with some value not by input value
Why? -----> See Pointer topic for detailed explaination.
```
int size;
cin >> size;

int arr[size]; // 💀⚠️
```


## Scopes in Array
- When an array is passed as a parameter to a function, it is not passed as a full copy of the array. Instead, the base address of the array is passed as a pointer, for example: `void updateArr(int *arr, int size)`.
- This means that any changes made to the elements of the array within the function will modify the original array.
- As a result, it is important to be cautious when modifying array elements within a function, as these changes will persist even after the function returns.


## Inplace Algorithms:
- Inplace means don't take extra space/memory
- The input is usually overwritten by the output as the algorithm executes. An in-place algorithm updates its input sequence only through replacement or swapping of elements.
- In other words, an in-place algorithm operates directly on the input data structure without requiring extra space proportional to the input size. It modifies the input in place, without creating a separate copy of the data structure. This can be useful when working with large data sets, as it can help reduce memory usage and improve performance.
- Examples: Sorting algorithms, Reversing an array ...


## **Find Duplicates in an Array**:
1. **XOR method**: 
  - This method is only works if the array contains elements from 1 to n and there is exactly one duplicate element. If these conditions are not met, this approach will not work.
  - Time Complexity is O(N) and Space complexity is O(1)
  - **Explaination**:  The idea is to XOR all the elements in the array and then XOR the result with all numbers from 1 to n. Since XOR is both commutative and associative, the order in which we perform the XORs does not matter. Also, since a XOR a = 0 for any number a, all the elements in the array except for the duplicate element will cancel out. The final result will be the duplicate element.

  -  The `XOR` of all elements in the **array** and all **numbers** from 1 to n is computed. The result is the duplicate number.

2. **Unordered Map**:
  - The unordered_map::count() is a builtin method in C++ which is used to count the number of elements present in an unordered_map with a given key.
  - Note: As unordered_map does not allow to store elements with duplicate keys, so the count() function basically checks if there exists an element in the unordered_map with a given key or not.
  - This function returns 1 if there exists a value in the map with the given key, otherwise it returns 0.
  - Refer this artical on <a href="https://www.geeksforgeeks.org/unordered_map-count-in-c/">GeekForGeeks -> Unordered_Map</a>

  - Why use `unordered_map` instead of `map`:
   Both unordered_map and map in C++ can be used to count the frequency of elements in an array. The main difference between them is that unordered_map provides average constant-time complexity for search, insert, and delete operations, while map provides logarithmic time complexity for these operations. This is because unordered_map is implemented as a hash table, while map is implemented as a self-balancing binary search tree (like Red-Black Tree). Therefore, if order of elements does not matter, unordered_map is usually a better choice because of its lower time complexity.


## **Binary Search**:
Binary search is only applicable on Monotonic functions. A monotonic function is a mathematical concept that refers to a function that follows a particular order.
Don't use **`(st + en) / 2`** to find middle element.
Explaination:
  - Maximum value of int is `2<sup>31</sup>-1`
  - If `st = 2<sup>31</sup>-1` and `en = 2<sup>31</sup>-1`, then addition of `st` and `en` is not in range of `int`.
  - Therefore, use **`st + (en - st) / 2`**


### 1. **Peak Index in Mountain:** 
  - `[7, 9, 1, 2, 3]` In this array `7, 9` are can be describe as `arr[i] < arr[i + 1]` means each element is smaller than next element & `1, 2, 3` can be describe as `arr[i] > arr[i + 1]` means each element is greater than next element.
  - In this array peak element `arr[i - 1] < arr[i] > arr[i + 1] ` is `9` .


### 2. **Find Pivot in an Array:**
- **Rotated Sorted Array:** A rotated sorted array is an array that was originally sorted in ascending order, but has been rotated by some number of positions. For example, if we have a sorted array `[1, 2, 3, 4, 5]` and rotate it by two positions to the right, we get the rotated sorted array `[4, 5, 1, 2, 3]`.

- **Pivot element:** In a rotated sorted array, the pivot element is the only element that is smaller than its previous element. It is the point at which the array was rotated. For example, if we have a sorted array `[1, 2, 3, 4, 5]` and rotate it by two positions to the right, we get the rotated sorted array `[4, 5, 1, 2, 3]`. In this case, the pivot element is `1`, as it is the only element that is smaller than its previous element `(5)`.


### 3. More Precision of Square Root
- The function takes three arguments: num, precision, and tempSoln.
- It returns a more precise approximation of the square root of num.
- factor controls the precision of the approximation.
    On the first iteration, factor is set to 1 / 10 = 0.1.
    On the second iteration, factor is set to 0.1 / 10 = 0.01.
    And so on…
- ans is the initial approximation of the square root of num.
- The outer loop iterates precision times to increase precision.
- The inner loop increments ans by factor until the square of ans is greater than or equal - to num.
    - For example, if num = 4, tempSoln = 1, and precision = 1, then:
    - On the first iteration, ans is incremented by 0.1 until it reaches a value greater    than - or equal to 2.
    - The final value of ans is approximately 2, which is a more precise approximation of     the - square root of 4.
- The final value of ans is returned as the result.


### 4. Book Allocation
You've to allocate the book to m students such that **the maximum number of pages assigned to a student is minimum.**

Example: <br>
<img src="book_allocation.png" width=350px height=300px />
<br>
Here our answer is 60 because it's minimum.


## Rotate an Array

If you `%` any number with `n`, then your answer/output will always come in range of `0 .... (n - 1)`.
Example: `num % 10` ---> answer will be in range of `(0 ... 9)`
          43 % 10 = 3, 69 % 10 = 9
        
Shift ith term in cyclic way using following formula -
**Formula:** - **`arr[(i + k) % n] = arr[i]`** ... where, i = index, k = rotate by num, n = size of array 

### In‑place Rotation Using Reversal Algorithm
- **Right rotation by k**:
  - Reverse the whole array.
  - Reverse the first k elements.
  - Reverse the remaining n−k elements (indices k … n−1).

- **Left rotation by k**:
  - Reverse the first k elements.
  - Reverse the remaining n−k elements.
  - Reverse the whole array.

Example: `Array: [1,2,3,4,5,6,7,8,9,10], n = 10, k = 2` (rotate right)
- Reverse all → `[10,9,8,7,6,5,4,3,2,1]`
- Reverse first k=2 → `[9,10,8,7,6,5,4,3,2,1]`
- Reverse remaining n−k = 8 elements (indices 2..9) → `[9,10,1,2,3,4,5,6,7,8]`

#### Why use k = ((k % n) + n) % n;
This line normalizes `k` so it always falls in the range `[0, n-1]`.
- `k % n` handles cases where `k > n`. 

  Example: rotating by 12 on an array of size 5 is the same as rotating by `12 % 5 = 2`.

- `+ n` and then `% n` handles negative `k`. 
  
  Example: rotating right by `-2` is the same as rotating left by `2`. 
  
  Without this normalization, negative values would break the index math.

So this formula makes your function robust for:
  - Large k values (`k > n`)
  - Negative k values (interpreted as left rotation)

**Step Breakdown**
1. `k % n`
  - Reduces k into range [-(n-1), n-1].
  - Keeps sign (negative stays negative).

2. `+ n`
  - Shifts negative results into positive range.
  - Example: `-2 % 5 = -2 → -2 + 5 = 3`

3. `% n` (final clamp)
  - Ensures result is strictly within `[0, n-1]`.
  - Prevents out-of-range cases like n itself.
  - Example: `(10 % 5 + 5) = 5 → 5 % 5 = 0`.

**Example**:
- Case 1: `k = 2` (right rotation)
  - Normalization: `(2 % 5 + 5) % 5 = 2`.
  - Rotate right by `2 → [4,5,1,2,3]`.

- Case 2: `k = -2` (left rotation)
  - Normalization: `(-2 % 5 + 5) % 5`.
    - `-2 % 5 = -2` (C++ keeps the sign).
    - `-2 + 5 = 3`.
    - `3 % 5 = 3`.
  - So `k = 3`.
  - Rotate right by 3 → `[3,4,5,1,2]`.
  - Which is exactly the same as left rotation by 2.

## Peak index in mountain
### Why en = mid instead of en = mid - 1

**The loop invariant**

We maintain that the peak is always between st and en.

  - If arr[mid] < arr[mid+1], we know peak is strictly to the right → st = mid+1.

  - Else (arr[mid] >= arr[mid+1]), the peak could be at mid itself or to the left. So we set en = mid, not mid-1.

**Example walk‑through**
Array: [1,3,5,7,6,4,2]

- st=0, en=6, mid=3 → arr[3]=7, arr[4]=6 
  
  Condition: arr[mid] >= arr[mid+1] → peak could be at mid=3. 
  
  If we did en = mid-1, we’d throw away index 3 (the actual peak). 
  
  By doing en = mid, we keep it in the search range.

## Pascal Triangle

In this solution, when you're accessing previous rows elements to take sum and add to current position. 

```
temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
```
Here, temp is a current row and `temp[j]` is current position. To add value in it we need to calculate sum of previous row's `j`th position and `j - 1`th position.
`ans` is the main vector which stores a vector. So we're going to previous vector by `ans[i - 1]` and access particular position by `ans[i - 1][j]` jth element.

## Map

```cpp
    for(int j = 0; j < m; j++) {
        if(mp[arr2[j]] > 0) {
            intersection[k++] = arr2[j];
            mp[arr2[j]]--;
        }
    }
```

- What mp[arr2[j]] does?
  - unordered_map::operator[] has two roles:
    - **Read**: If the key exists, it returns a reference to its value (so you can read or modify).
    - **Insert**: If the key does not exist, it inserts the key with a default‑initialized value (0 for int) and then returns a reference to that.

    Example:
    ```
    mp[5] = 2;        // inserts key 5 with value 2
    mp[5]++;          // if 5 not present, inserts with 0, then increments to 1
    cout << mp[5];    // if 5 not present, inserts with 0, then prints 0
    ```

- Why your code works without `.count`
  ```cpp
  if (mp[arr2[j]] > 0) {
      intersection[k++] = arr2[j];
      mp[arr2[j]]--;
  }
  ```
  - When you built the map from `arr1`, every element got a positive frequency (>=1).

  - So when you check `mp[arr2[j]] > 0`, you’re reading the frequency.

  - If `arr2[j]` wasn’t in `arr1`, then operator[] inserts it with 0. The condition fails, so nothing happens.

  - That’s why you don’t need `.count` here — the > 0 check naturally handles both cases.

  - If you only want to know **“does this key exist?” → use .count**.

  - If you want to r**ead/update frequency → use operator[]**.

## Triplet Sum
**Example 1: Array = `{0, 3, 2, 4, 1}`, reqSum = 5**

We want triplets that sum to 5.

**Outer loop**: `i = 0` → `arr[i] = 0`
- `currSum = 5 - 0 = 5`
- Inner loop starts with `j = 1` → `arr[j] = 3`
  - target = 5 - 3 = 2
  - seen is empty → no match
  - Insert 3 into `seen`

- `j = 2 → arr[j] = 2`
  - `target = 5 - 2 = 3`
  - Is 3 in `seen`? Yes → triplet found: `(0, 2, 3)`

- `j = 3 → arr[j] = 4`
  - `target = 5 - 4 = 1`
  - Not in `seen` → insert 4

- `j = 4` → `arr[j] = 1`
  - `target = 5 - 1 = 4`
  - Is 4 in `seen`? Yes → triplet found: `(0, 1, 4)`

**Output**: `(0,2,3)` and `(0,1,4)`

## Counting frequencies of Array Elements
### What lower_bound and upper_bound return
- Both functions return an iterator (in your case, a raw pointer because you’re using a plain array).

- That iterator points to the position in the sorted range where the value fits.

Example: 
```cpp
int arr[] = {5, 10, 10, 10, 20, 20, 20, 20};
auto it = lower_bound(arr, arr+n, 10);
```
Here `it` is a pointer to `arr[1]`.

### Why you saw an address
When you print lower_bound(...) directly:
```cpp
cout << lower_bound(arr, arr+n, arr[i]);
```
You’re printing the pointer value (the memory address). That’s why you saw `0x61fef4`.

### How subtracting `arr` gives an index
In C++, pointer arithmetic works like this:

- `lower_bound(...)` returns a pointer to some element inside `arr`.

- Subtracting `arr` (which itself is a pointer to the first element) gives the offset in terms of elements.

Example:
```cpp
int* p = lower_bound(arr, arr+n, 10); // points to arr[1]
int index = p - arr;                  // (arr+1) - arr = 1
```
So `p - arr` is the index.

### Why `- arr - 1` for upper bound
- `lower_bound(arr, arr+n, x)` → first index where x could be inserted (i.e. first occurrence of x).

- `upper_bound(arr, arr+n, x)` → first index where a value greater than x could be inserted (i.e. one past the last occurrence of x).

So:

- `lower_bound(...) - arr` → gives the first index of `x`.

- `upper_bound(...) - arr` → gives the index of the element after the last occurrence of `x`.

- To get the actual last index of x, subtract 1:
  ```cpp
  int lastIndex = upper_bound(arr, arr+n, x) - arr - 1;
  ```

## Sort elements by frequency
### What is a comparator?
A comparator is a function that tells sort (or stable_sort) how to order two elements.

- Normally, sort uses the < operator (ascending order).

- If you want a custom order (like sort by frequency, or descending order), you pass a comparator function.

The comparator must return true if the first argument should come before the second in the sorted order.

### Your example with sort(vec.begin(), vec.end())
- If you write just sort(vec.begin(), vec.end()), it will sort the vector using the default < operator.

- For vector<pair<int,int>>, the default < compares first, then second (lexicographic order). Example: (2,2) < (5,2) because 2 < 5.

- That means it sorts by element value, not by frequency.