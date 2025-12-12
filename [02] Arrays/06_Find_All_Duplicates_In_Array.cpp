#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

// Optimal solution using unordered map
// Time complexity: O(n)
// space complexity: O(n) auxillary
void findAllDuplicatesUsingUnorderedMap(int *arr, int size, int *ansArr) {
    unordered_map<int, int> freq;
    int index = 0;
    for(int i = 0; i < size; i++) 
        freq[arr[i]]++;

    cout << "Duplicate elements are: ";
    for(auto it = freq.begin(); it != freq.end(); it++) {
        if(it -> second > 1)
            ansArr[index++] = it -> first;
    }
}


// Brute force solution
// Time complexity: O(n^2)
// Space complexity: O(1) (auxillary space). But outspace is O(n) but we mainly talk about auxillary space only.
void findAllDuplicates(int *arr, int size, int* ansArr) {
    int k = 0;
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] == INT_MIN)
            continue;
        
        int count = 0;
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = INT_MIN;
            }
        }

        if(count > 0)
            ansArr[k++] = arr[i];
    }
}

void takeInputFromUser(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cin >> arr[i];
}

int main() {

    int arr[10], ansArr[10];
    int size;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " array elements: ";
    takeInputFromUser(arr, size);

    for(int i = 0; i < size; i++) 
        ansArr[i] = INT_MIN;
    
    findAllDuplicates(arr, size, ansArr);
    // findAllDuplicatesUsingUnorderedMap(arr, size, ansArr);

    if(ansArr[0] == INT_MIN)
        cout << "No duplicate element is found" << endl;
    else {
        cout << "Duplicate Elements are: ";
        for(int i = 0; i < size; i++) {
            if(ansArr[i] == INT_MIN)
                break;
            cout << ansArr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}