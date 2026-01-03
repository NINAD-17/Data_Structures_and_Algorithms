#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

// FIND NEXT SMALLER ELEMENT
// For each index i, the next smaller element is the first element to the right of i that is strictly smaller than arr[i].

// Example: [2, 1, 4, 3]
//      i = 0; for element 2 find next smallest element than 2 in next window [1 to 3];
//              Found 1
//      i = 1; for element 1 find next smallest element than 1 in next window [4 - 3];
//              Not found any. So -1.
//      i = 2; for element 4 find next smallest element than 4 in next window [3];
//              Found 3
//      i = 3; for element 3 find next smallest element than 3 in next window [];
//              Not found any. So -1.
// Final answer: [1, -1, 3, -1]


// Time complexity: O(n)
// Space complexity: O(n)

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> st;
    st.push(-1); // 1st element of stack is -1

    vector<int> ans(n); // vector to store ans // vector is of size n

    // traverse vector from last element to first element
    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        
        // while top element of stack is greater than curr then pop
        while(st.top() >= curr) {
            st.pop();
        }

        // ans is top of stack
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

// PREVIOUS SMALLER ELEMENT 
vector<int> prevSmallerElement(vector<int> &arr, int n) {
    stack<int> st;
    st.push(-1); // 1st element of stack is -1

    vector<int> ans(n); // vector to store ans // vector is of size n

    // traverse vector from first element to last element
    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        
        // while top element of stack is greater than curr then pop
        while(st.top() >= curr) {
            st.pop();
        }

        // ans is top of stack
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

// Brute force solution
// Time: O(n^2)
vector<int> nextSmallerElement_bruteForce(vector<int> &arr, int n) {
    vector<int> ans;

    for(int i = 0; i < n - 1; i++) {
        int currElem = arr[i];
        int currMin = -1;
        
        for(int j = i + 1; j < n; j++) {
            // if(arr[j] < currElem && arr[j] > currMin) {
            //     currMin = arr[j];
            // }

            if(arr[j] < currElem) {
                currMin = arr[j];
                break;
            }
        }

        ans.push_back(currMin);
        cout << "For " << arr[i] << " next smaller element is " << currMin << endl;
    }

    ans.push_back(-1); // For last element which will have no window
    cout << "For " << arr[n - 1] << " next smaller element is " << -1 << endl;

    return ans;
}

void printArr(vector<int> &arr, int n) {
    cout << "--> [";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main() {

    vector<int> arr;
    
    // arr.push_back(2);
    // arr.push_back(1);
    // arr.push_back(4);
    // arr.push_back(3);

    // arr.push_back(4);
    // arr.push_back(3);
    // arr.push_back(5);
    // arr.push_back(3);
    // arr.push_back(2);
    // arr.push_back(1);

    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);
    printArr(arr, arr.size());
    
    vector<int> bruteForce_ans = nextSmallerElement_bruteForce(arr, arr.size());
    printArr(bruteForce_ans, bruteForce_ans.size());

    vector<int> ans = nextSmallerElement(arr, arr.size());
    printArr(ans, ans.size());

    ans = prevSmallerElement(arr, arr.size());
    printArr(ans, ans.size());

    return 0;
}