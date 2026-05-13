#include <iostream>
using namespace std;

int main() {
    char str[10];

    cout << "Enter a String: ";
    cin >> str;

    int length = 0;
    for(int i = 0; str[i] != '\0'; i++) 
        length++;

    cout << "Length of string " << str << " is " << length << endl;
    
    return 0;
}