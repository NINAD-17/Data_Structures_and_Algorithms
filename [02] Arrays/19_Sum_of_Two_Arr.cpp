#include <iostream>
#include <algorithm>
using namespace std;

// Time complexity: O(n + m)
// Space complexity: O(1)
int addNumbers(int *num1, int n, int *num2, int m, int *ans) {
    int i = n - 1, j = m - 1, k = 0, carry = 0;

    while(i >= 0 && j >= 0) {
        int sum = num1[i--] + num2[j--] + carry;
        int sumDig = sum % 10;
        carry = sum / 10;
        ans[k++] = sumDig;
    }

    while(i >= 0) {
        int sum = num1[i--] + carry;
        int sumDig = sum % 10;
        carry = sum / 10;
        ans[k++] = sumDig;
    }

    while(j >= 0) {
        int sum = num2[j--] + carry;
        int sumDig = sum % 10;
        carry = sum / 10;
        ans[k++] = sumDig;
    }

    while(carry) {
        int sum = carry;
        int sumDig = sum % 10;
        carry = sum / 10;
        ans[k++] = sumDig;
    }

    reverse(ans, ans + k);
    return k;
}

int addNumberArr(int *num1, int n, int *num2, int m, int *ans) {
    int i = n - 1, j = m - 1;
    int k = max(n, m); // last index for result
    int carry = 0;

    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if(i >= 0) 
            sum += num1[i--];
        
        if(j >= 0)
            sum += num2[j--];

        ans[k--] = sum % 10;
        carry = sum / 10;
    }

    return k + 1; // At the end, k points just before the first valid digit. so add 1 to it.
} 

void printNum(int *num, int n) {
    for(int i = 0; i < n; i++)
        cout << num[i] << " ";
    cout << endl;
}

void inputNum(int *num, int n) {
    for(int i = 0; i < n; i++)
        cin >> num[i];
}

int main() {
    int num1[10], num2[10], num1Size, num2Size, ans[10];

    cout << "Enter total digits of number 1: ";
    cin >> num1Size;

    cout << "Enter total digits of number 2: ";
    cin >> num2Size;

    cout << "Enter number 1: ";
    inputNum(num1, num1Size);

    cout << "Enter number 2: ";
    inputNum(num2, num2Size);

    int sizeOfAns = addNumbers(num1, num1Size, num2, num2Size, ans);
    cout << "Addition of both numbers is ";
    printNum(ans, sizeOfAns);

    int startingIndex = addNumberArr(num1, num1Size, num2, num2Size, ans);
    cout << "Addition of both numbers is ";
    printNum(ans + startingIndex, max(num1Size, num2Size) + 1 - startingIndex); // start from ans + startingIndex means if the returned value is 0 then start from 0the index and if it's 1 then arr + 1 th index. If the starting index is 0 then it'll have max(a, b) elements else max(a, b) + 1

    return 0;
}