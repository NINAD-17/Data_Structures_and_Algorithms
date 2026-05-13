#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
using namespace std;

// Time Complexity: O(n)
// space complexity: O(1)
void printAllDuplicatesEfficientSoln(string str) {
    int alphabates[26] = {0};

    for(int i = 0; i < str.length(); i++) {
        alphabates[tolower(str[i]) - 'a']++;

        if(alphabates[tolower(str[i]) - 'a'] >= 2)
            str[i] = '$';
    }
    
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '$')
            continue;

        if(alphabates[tolower(str[i]) - 'a'] > 1) 
            cout << str[i] << ", count = " << alphabates[str[i] - 'a'] << endl;
    }
}


// Time Complexity: O(n)
// The time complexity of inserting an element into an unordered_map is O(1) on average, and O(n) in the worst case when a collision occurs. Since the function inserts each character of the input string into the unordered_map, the total time complexity of this operation is O(n) on average, and O(n^2) in the worst case. However, hash collisions are rare, so we usually consider the time complexity to be O(n). The rest of the operations in the function, such as iterating over the elements of the unordered_map and printing the results, also take linear time

// Space Complexity: O(n)
//  because in the worst case (when all characters are unique), the function will create an entry in the unordered_map for each character in the input string. Therefore, the space required by the function grows linearly with the size of the input string.
void printAllDuplicatesUsingUOMap(string str) {
    unordered_map<char, int> uoMp;

    for(int i = 0; i < str.length(); i++) 
        uoMp[str[i]]++;
    
    for(auto value: uoMp) {
        if(value.second > 1)
            cout << value.first << ", count = " << value.second << endl;
    }
}

// Time Complexity: O(n log n)
// The time complexity of inserting an element into a map is O(log n), where n is the number of elements in the map. Since the function inserts each character of the input string into the map, the total time complexity of this operation is O(n log n). The rest of the operations in the function, such as iterating over the elements of the map and printing the results, take linear time, so they do not affect the overall time complexity.
// Space complexity: O(n)
void printAllDuplicatesUsingMap(string str) {
    map<char, int> mp;

    for(int i = 0; i < str.length(); i++)
        mp[str[i]]++;
    
    for(auto value: mp) {
        if(value.second > 1) 
            cout << value.first << ", count = " << value.second << endl;
    }
}

// Time Complexity: O(n^2)
// Auxillary space: O(1)
void printAllDuplicates(string str) {
    
    for(int i = 0; i < str.length(); i++) {
        int count = 1;

        if(str[i] == '$')
            continue;

        for(int j = i + 1; j < str.length(); j++) {
            if(str[j] == str[i]) {
                count++;
                str[j] = '$';
            }
        }

        if(count == 1)
            continue;

        cout << str[i] << ", count = " << count << endl;
    }
}

int main() {
    string str = "geeksforgeeks";

    printAllDuplicatesEfficientSoln(str);
    cout << endl;

    return 0;
}