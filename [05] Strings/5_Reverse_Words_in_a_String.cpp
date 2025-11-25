#include <iostream>
#include <string>
using namespace std;

// Time Complexity: O(n)
// - The outer loop runs once per character in the sentence (O(n)).
// - reverseString(temp) runs in O(m) for each word of length m,
//   but across the whole sentence the total of all m = n,
//   so all reversals together cost O(n).
// - String appends (ans += ...) can be O(n) in worst case,
//   but amortized across all operations they remain O(n).
// Overall: O(n) time, O(1) extra space.


string reverseString(string temp) {
    int st = 0, en = temp.size() - 1;
    
    while(st < en) 
        swap(temp[st++], temp[en--]);
    
    return temp;
}

string reverseWords(string str) {
    string temp = "", ans = "";

    for(int i = 0; i < str.length(); i++) {   // Avoid: for(int i = 0; i <= str.length(); i++) // Works, but technically unsafe because str[str.length()] is undefined.

        if(str[i] == ' ') {  // str[i] == ' ' || str[i] == '\0' Read more about this condition in readme.md as it's not good code
            temp = reverseString(temp);
            ans += temp + " ";
            temp = "";
            continue;
        }

        temp += str[i];
    }

    // For last word of sentence you need to manually reverse it and attach to answer
    temp = reverseString(temp);
    ans += temp;

    return ans;
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);
    cout << str << endl;

    string ans = reverseWords(str);
    cout << "Reversed words in a sentence: " << ans << endl;

    return 0;
}