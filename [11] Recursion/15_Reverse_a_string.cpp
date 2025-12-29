#include <iostream>
using namespace std;

// Using only one pointer
// Time: O(n)   Space: O(n)
void reverseString_rec_2(string &str, int i) {
    if(i == str.length()/2)
        return;
    
    swap(str[i], str[str.length() - 1 - i]);
    i++;

    reverseString_rec_2(str, i);
}

// Using two pointers (st and en)
// Time: O(n)   Space: O(n)
void reverseString_rec(string &str, int st, int en) {
    // Base Case
    if(st >= en)
        return;
    
    swap(str[st++], str[en--]);

    reverseString_rec(str, st, en);
}

// Without recursion
// Time: O(n)   Space: O(1)
string reverseString(string str) {
    int st = 0, en = str.length() - 1;
    while(st <= en) 
        swap(str[st++], str[en--]);
    
    return str;
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    // reverseString_rec(str, 0, str.length() - 1);
    reverseString_rec_2(str, 0);
    cout << str << endl;

    return 0;
}