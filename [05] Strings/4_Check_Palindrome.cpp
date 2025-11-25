#include <iostream>
#include <ctype.h>
using namespace std;

void capitalizeStr(char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') 
            str[i] = toupper(str[i]); // Learn more about convertion of char in readme.md file.
    }
}

int findLength(char *str) {
    int length = 0;

    for(int i = 0; str[i] != '\0'; i++)
        length++;
    
    return length;
}

// Problem: Don't consider white spaces and special symbols
// Time complexity: O(n)
bool isPalindrome2(char *str) {
    int st = 0, en = findLength(str) - 1;
    while(st < en) {
        
        // Ignore non-alphanumeric characters
        while(st < en && !((str[st] >= 'a' && str[st] <= 'z') || (str[st] >= 'A' && str[st] <= 'Z') || (str[st] >= '0' && str[st] <= '9'))) st++;
        while(st < en && !((str[en] >= 'a' && str[en] <= 'z') || (str[en] >= 'A' && str[en] <= 'Z') || (str[en] >= '0' && str[en] <= '9'))) en--;

        // Compare characters case-insensitively
        if(toupper(str[st]) != toupper(str[en]))
            return false;

        st++, en--;
    }
    return true;
}

// time complexity: O(n)
bool isPalindrome(char *str) {
    int length = findLength(str);

    capitalizeStr(str);
    cout << str << endl;
    int st = 0, en = length - 1;
    while(st < en) {
        if(str[st] == str[en])
            st++, en--;
        else    
            return false;
    }

    return true;
}

int main() {

    char str[20];

    cout << "Enter a string: ";
    cin >> str;

    cout << "Your string: " << str << endl;

    if(isPalindrome2(str))
        cout << "Given string is a palindrome :)" << endl;
    else
        cout << "Given string is not a palindrome :(" << endl;
        

    return 0;
}