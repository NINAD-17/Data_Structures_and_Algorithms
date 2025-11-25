#include <iostream>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
void replaceSpaces2(string &str) {
    int spaceCount = 0, strSize = str.length();
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ')
            spaceCount++;
    }

    int newLength = str.length() + spaceCount * 2; // SpaceCount = 2 and not 3 because, EX. 2 spaces * 2 = 4, now add those 2 spaces -> 4 + 2 = 6
    str.resize(newLength);
    cout << str << "." << endl;

    for(int i = strSize - 1; i >= 0; i--) { // strSize is original size of String
        if(str[i] == ' ') {
            str[newLength - 1] = '0'; // Start to copy elements from last place of new length of string
            str[newLength - 2] = '4';
            str[newLength - 3] = '@';
            newLength -= 3;
        } else {
            str[newLength - 1] = str[i];
            newLength--;
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)
string replaceSpaces(string str) {
    string ans = "";
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ')
            ans += "@40";
        else
            ans += str[i];
    }
    return ans;
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    string ans = replaceSpaces(str);
    cout << ans << endl;

    replaceSpaces2(str);
    cout << str << endl;

    return 0;
}