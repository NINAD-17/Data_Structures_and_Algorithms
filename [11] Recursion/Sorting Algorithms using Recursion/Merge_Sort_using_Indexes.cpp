#include <iostream>
using namespace std;

// In‑place merge sort reduces space to O(log n), 
// but increases time complexity (can degrade to O(n²)).

void inplaceMerge(int arr[], int st, int mid, int en) {
    int i = st;
    int j = mid + 1;

    while (i <= mid && j <= en) {
        if (arr[i] <= arr[j]) {
            i++;
        } else {
            int value = arr[j];
            int index = j;

            // Shift all elements between i and j-1 right by one
            while (index > i) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[i] = value;

            // Update pointers
            i++;
            mid++;
            j++;
        }
    }
}

void inplaceMergeSort(int arr[], int st, int en) {
    if (st >= en) return;

    int mid = st + (en - st) / 2;

    inplaceMergeSort(arr, st, mid);
    inplaceMergeSort(arr, mid + 1, en);

    inplaceMerge(arr, st, mid, en);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = 7;

    inplaceMergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
