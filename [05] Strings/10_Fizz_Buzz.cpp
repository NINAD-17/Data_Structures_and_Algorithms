#include <iostream>
using namespace std;

void fizzBuzz(int n, string *ans) {
    for(int i = 1; i <= n; i++) {
        if((i % 3 == 0) && (i % 5 == 0)) 
            ans[i - 1] = "FizzBuzz";
        else if(i % 3 == 0)
            ans[i - 1] = "Fizz";
        else if(i % 5 == 0)
            ans[i - 1] = "Buzz";
        else 
            ans[i - 1] = to_string(i);
    }
}

int main() {
    int n;
    string ans[100];

    cout << "Enter a number: ";
    cin >> n;

    fizzBuzz(n, ans);
    for(int i = 0; i < n; i++) 
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}