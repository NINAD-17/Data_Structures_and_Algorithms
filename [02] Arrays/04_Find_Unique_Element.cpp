#include <iostream>
#include <unordered_map>
using namespace std;

// Using Hashmap (unordered_map) - use if elements can appear any number of times and you want to find the one with frequency 1.
// Time complexity: O(n)
// Space complexity: O(n)
int findUniqueElementUsingMap(int *arr, int size) {
    unordered_map<int, int> freq;

    for(int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    for(int i = 0; i < size; i++) {
        if(freq[arr[i]] == 1) {
            return arr[i];
        }
    }

    return -1;
}

// Using XOR operator (if only one element is unique and others are twice)
// Time Complexity: O(n)
// Space Complexity: O(1)
int findUniqueElement(int *arr, int size) {
    int uniqueElement = 0;
    for(int i = 0; i < size; i++) {
        uniqueElement ^= arr[i];
    }
    return uniqueElement;
}


// Time complexity: O(n^2)
// Space complexity: O(1)
int findUniqueElementNested(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        int element = arr[i];
        int count = 0;

        for(int j = 0; j < size; j++) {
            if(arr[j] == element)
                count++;
        }

        if(count == 1)
            return element;
    }
    return -1; // if no unique element found
}

void takeInputFromUser(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cin >> arr[i];
}

int main() {
    int arr[10];
    int size;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " array elements: ";
    takeInputFromUser(arr, size);

    cout << "Unique element in this array is: " << findUniqueElementNested(arr, size) << endl;
    cout << "Unique element in this array is: " << findUniqueElement(arr, size) << endl;
    cout << "Unique element in this array is: " << findUniqueElementUsingMap(arr, size) << endl;
    return 0;
}