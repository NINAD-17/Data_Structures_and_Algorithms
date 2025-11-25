#include <iostream>
using namespace std;

// Time complexity: O(n)

void convertToOppCase(string &str) {
    for(int i = 0; i < str.length(); i++) {
        if(isupper(str[i])) 
            str[i] = tolower(str[i]);
        else
            str[i] = toupper(str[i]);
    }
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    convertToOppCase(str);
    cout << str << endl;
    return 0;
}