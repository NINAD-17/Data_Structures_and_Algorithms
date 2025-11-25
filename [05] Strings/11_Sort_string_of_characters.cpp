#include <iostream>
using namespace std;

// Time Complexity: O(n)
// The time complexity of the sortStringOfChars function is O(n), where n is the length of the input string str. This is because the function iterates over the input string once to count the frequency of each character, and then iterates over the alphabates array, which has a constant size of 26. The inner loop that appends characters to the ans string runs a total of n times over all iterations of the outer loop. Therefore, the overall time complexity of the function is O(n)

// Space complexity: O(1)
//  The alphabates array has a constant size of 26, and the ans string has a maximum length equal to the length of the input string str. Therefore, the space complexity of the program is constant, or O(1).
string sortStringOfChars(string str) {
    int alphabates[26] = {0};
    string ans = "";

    for(int i = 0; i < str.length(); i++)
        alphabates[str[i] - 'a']++;
    
    for(int i = 0; i < 26; i++) {
        if(alphabates[i] == 0)
            continue;

        for(int j = 0; j < alphabates[i]; j++) 
            ans += ('a' + i); // static_cast<char>('a' + i) it convert ASCII to char
        
    }

    return ans;
}

int main() {
    string str = "bbccdefbbaa";

    string sortedCharStr = sortStringOfChars(str);
    cout << sortedCharStr << endl;

    return 0;
}