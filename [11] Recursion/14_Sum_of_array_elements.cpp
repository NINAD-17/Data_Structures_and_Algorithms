#include <iostream>
using namespace std;

// Time: O(n)   Space: O(n)
int sumOfElements(int *arr, int size) {
    // Base Case
    if(size == 0)
        return 0;

    if(size == 1)
        return arr[0];

    return arr[0] + sumOfElements(arr + 1, size - 1);
}

int main() {
    int arr[10];
    int n;

    cout << "Enter lastIndex of array: "; cin >> n;
    cout << "Enter " << n << " elements: ";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Sum of array elements is: " << sumOfElements(arr, n) << endl;

    return 0;
}