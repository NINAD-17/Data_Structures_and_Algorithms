#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void sortByFrequency(int *arr, int n) {
    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++) freq[arr[i]]++;

    sort(arr, arr + n, [&](int a, int b) {
        if(freq[a] == freq[b]) return a < b;
        return freq[a] > freq[b];
    });

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

vector<int> sortByFreqUsingMap(int *arr, int n) {
    unordered_map<int, int> um;

    for(int i = 0; i < n; i++) {
        um[arr[i]]++;
    }

    map<int, int> mp;
    for(pair<int, int> value: um) {
        mp[value.second] = value.first;
    }

    vector<int> sortedByFreq;
    for(pair<int, int> value: mp) {
        int i = value.first;
        while(i > 0) {
            cout << value.second << " ";
            sortedByFreq.push_back(value.second);
            i--;
        }
    }

    cout << endl;
    return sortedByFreq;
}

void sortByFreqInPlace(int *arr, int n) {
    unordered_map<int,int> freq;
    for (int i = 0; i < n; i++) freq[arr[i]]++;

    stable_sort(arr, arr + n, [&](int a, int b) {
        if (freq[a] == freq[b]) return a < b;   // tie: smaller value first
        return freq[a] > freq[b];               // higher frequency first
    });
}

void sortElementsByFreq(int *arr, int n) {
    unordered_map<int, int> freq;

    // Step 1: count frequencies
    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    // Step 2: move to vector
    vector<pair<int, int>> vec(freq.begin(), freq.end());

    // Step 3: sort by frequency (descending), then by element (ascending)
    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        if(a.second == b.second)
            return a.first < b.first; // tie-breaker: smaller element first
        
        return a.second > b.second; // primary: higher frequency first
    });

    // Step 4: print sorted by frequency
    for(auto &p : vec) {
        for(int i=0; i<p.second; i++) {
            cout << p.first << " ";
        }
    }
    cout << endl;
}

int main() {
    int arr[8] = {2, 5, 2, 8, 5, 6, 8, 8};
    int n = 8;

    sortElementsByFreq(arr, n);

    vector<int> ans = sortByFreqUsingMap(arr, n);
    for(auto value: ans) {
        cout << value << " ";
    }

    cout << endl;
    return 0;
}