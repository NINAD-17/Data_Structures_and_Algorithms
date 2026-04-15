#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

int main() {
    string str = "1012";
    int num = 0;

    for(int i = 0; i < str.length(); i++) {
        num = num * 10 + (str[i] - '0');
    }

    cout << num << endl;
    cout << typeid(str).name() << " <-- TO --> " << typeid(num).name() << endl;
    return 0;
}