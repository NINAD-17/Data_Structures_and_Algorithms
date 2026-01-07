#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// FIRST NON-REPEATING CHARACTER IN STREAM
// time complexity: O(n)
// space complexity: O(n)

string firstNonRepeatingChar(string &str) {
    // create a map to store all the char counts
    unordered_map<char, int> count;

    // create a queue
    queue<int> q;

    string ans = "";

    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // increment the count for char
        count[ch]++;

        // push the char into queue
        q.push(ch);

        while(!q.empty()) {
            if(count[q.front()] > 1) {
                // repeating character
                q.pop();
            } else {
                // non-repeating character
                ans += q.front();
                break;
            }
        }

        if(q.empty()) {
            ans += "#";
        }
    }
    return ans;       
}

int main() {

    string str = "aabcebd"; // aabc

    cout << str << endl;
    cout << firstNonRepeatingChar(str) << endl;

    return 0;
}