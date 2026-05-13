#include <iostream>
using namespace std;

// Problem: https://leetcode.com/problems/count-binary-substrings/description/

int countBinSubstrings(string str) {
    string temp = "";
    int subStrCount = 0;
    
    for(int i = 0; i < str.length(); i++) {
        int count_0 = 0, count_1 = 0;
        bool itContain_1 = false, itContain_0 = false;

        for(int j = i; j < str.length(); j++) {
            if(str[j] == '0') {
                if(itContain_1) break;
                temp += '0';
                count_0++;
                itContain_0 = true;
            } else {
                if(itContain_0 && count_0 == count_1) {
                    subStrCount++;
                    cout << temp << endl;
                    temp = "";
                    break;
                }
                temp += '1';
                count_1++;
                itContain_1 = true;
            }

            if(count_0 == count_1) {
                cout << temp << endl;
                temp = "";
                subStrCount++;
            }
        }
    }

    return subStrCount;
}

int main() {
    string str = "10101";

    int count = countBinSubstrings(str);
    cout << "\nTotal Binary Substrings are " << count << endl;

    return 0;
}