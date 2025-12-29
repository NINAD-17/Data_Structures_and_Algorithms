#include <iostream> 
using namespace std;

// Time Complexity: O(n)
//      - Per-call work: O(1)
//      - Recurrence: T(n) = T(n−1) + O(1), with T(0) = O(1) → T(n) = O(n).
// Space Complexity: O(n)
//      - Each frame = O(1), depth = n → O(n)

void birthdayTimer(int n) {
    // Base Case
    if(n == 0) {
        cout << "Happy Birthday!" << endl;
        return ;
    }

    if(n == 1)
        cout << n << " day left for Birthday!" << endl;
    else
        cout << n << " days left for Birthday!" << endl;

    birthdayTimer(n - 1);
}

int main() {
    int daysLeftForBirthday = 9;

    birthdayTimer(daysLeftForBirthday);

    return 0;
}