#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

// Unique Number of Occurrences
// {1, 2, 2, 2, 3, 3}
// Here, 1: 1
//       2: 3
//       3: 2 // all occurrences are unique


// Optimal Approach
// Time complexity: O(n)
// Space complexity: O(n)
bool findOccurrences_unMap(int *arr, int size) {
    unordered_map<int, int> freq;
    for(int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    // Output
    for(auto it : freq) {
        cout << it.first << " : " << it.second << endl;
    }

    // Check unique occurence
    unordered_map<int, int> occ;
    for(auto it : freq) {
        occ[it.second]++;
        cout << "Occ: " << it.second << " -> " << "Freq: " << occ[it.second] << endl;
        if(occ[it.second] > 1) {
            cout << "Occ: " << it.second << " -> " << "Freq: " << occ[it.second] << endl;
            return false;
        }
    }

    return true;
}

// Optimized approach:
// Time Complexity: This approach has a time complexity of O(n log n) due to the sorting step.
// Space complexity: O(n)
bool areUniqueWithOccurrences(int *arr, int size) {
    // Sort Array
    sort(arr, arr + size);

    int occuranceArr[100] = {0};
    int count = 1, k = 0;

    for(int i = 1; i < size; i++) {
        if(arr[i] == arr[i - 1])
            count++;
        else {
            occuranceArr[k++] = count;
            count = 1;
        }
    }
    occuranceArr[k++] = count; // For last element

    sort(occuranceArr, occuranceArr + k);
    for(int i = 1; i < k; i++) {
        if(occuranceArr[i] == occuranceArr[i - 1])
            return false;
    }

    return true;
}

// Worst Approach
// Time Complexity: O(n^2)  ---- because the function uses two nested for loops to count the number of occurrences of each element in the input array and to check if the number of occurrences of each element is unique.
// Space complexity: O(n) ----  because the function uses an additional occurrencesArr array of size n to store the number of occurrences of each element in the input array.
bool isUniqueArrayByOccaurrences(int *arr, int size) {
    int uniqueNo[100] = {0}; // to store unique number (no duplicates)
    int occurrencesArr[100] = {0}; // to store occurances count of those unique numbers
    
    int count = 0; // to count all occurances of unique number
    int k = 0; // iterator for occurancesArr and uniqueNo array
    int tempSize = 0; // all total unique elements (size of occrancesArr and uniqueNo array) 
    int current = INT_MIN; // to skip already counted elements (optional - you can directly use i = j at last)
    
    // sort(arr, arr + size); // Example: 1, 2, 2, 2, 3, 3

    for(int i = 0; i < size; i++) {
        if(current == arr[i]) // Already counted that number's occurrences
            continue;

        int j;
        for(j = i; j < size; j++) {
            if(arr[i] == arr[j]) // count occurrences
                count++;
            else    
                break;
        }
        uniqueNo[k] = arr[i];
        occurrencesArr[k++] = count;
        tempSize = k;
        count = 0;
        current = arr[i]; // update
        // i = j; // if you don't want to use 'current' keyword you can directly update i with jth postion, so then iteration will run from j-th position (prevent unnecessary breaks for known number)
    }

    for(int i = 0; i < tempSize; i++) {
        for(int j = i + 1; j < tempSize; j++) {
            if(occurrencesArr[i] == occurrencesArr[j])
                return false;
        }
    }

    // Print
    cout << "Array element ----> Occuarances" << endl; 
    for(int i = 0; i < k; i++) {
        cout << uniqueNo[i] << " --------------> " << occurrencesArr[i] << endl;
    }
    return true;
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

    if(findOccurrences_unMap(arr, size)) 
        cout << "Array element has unique number of occurances." << endl;
    else 
        cout << "Array elements hasn't unique number of occurances." << endl;

    return 0;
}