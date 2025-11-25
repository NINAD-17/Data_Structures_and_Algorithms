#include <iostream>
using namespace std;

// time complexity: O(n) here, `n` is the number of characters in the string
void reverseString(char *str) {
    int length = 0;

    for(int i = 0; str[i] != '\0'; i++)
        length++;

    int st = 0, en = length - 1;
    while(st < en) {
        char temp = str[st];
        str[st] = str[en];
        str[en] = temp;
        st++, en--;
    }
}

int main() {

    char str[20];

    cout << "Enter a string: ";
    cin >> str;

    cout << "Your string: " << str << endl;

    reverseString(str);
    cout << "Reversed string: " << str << endl;

    return 0;
}