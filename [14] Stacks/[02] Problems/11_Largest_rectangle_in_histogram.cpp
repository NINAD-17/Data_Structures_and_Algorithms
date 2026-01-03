#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;

// LARGEST RECTANGULAR AREA IN HISTOGRAM (hard)

// ---- optimized approach with stack ----
// time complexity: O(n)
// space complexity: O(n)
vector<int> nextSmallerElementIndex(vector<int> &arr, int n) {
    stack<int> st;
    st.push(-1); // first element is -1

    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--) {
        while(st.top() != -1 && arr[st.top()] >= arr[i]) 
            st.pop();
        
        ans[i] = st.top();
        st.push(i); // as we're pushing index to stack make sure in while you're accessing value from index arr[st.top()] instead of st.top()
    }

    return ans;
}

vector<int> prevSmallerElementIndex(vector<int> &arr, int n) {
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for(int i = 0; i < n; i++) {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
            st.pop();
        
        ans[i] = st.top();
        st.push(i); // as we're pushing index to stack make sure in while you're accessing value from index arr[st.top()] instead of st.top()
    }

    return ans;
}

int largestRecArea(vector<int> &heights, int size) {
    // store next large indexes
    vector<int> next(size);
    next = nextSmallerElementIndex(heights, size);

    // store prev small indexes
    vector<int> prev(size);
    prev = prevSmallerElementIndex(heights, size);

    int area = INT_MIN;

    for(int i = 0; i < size; i++) {
        if(next[i] == -1)
            next[i] = size; // because next can't be -1

        int length = heights[i];
        int breadth = next[i] - prev[i] - 1;

        int newArea = length * breadth;
        area = max(area, newArea);
    }

    return area;
}

// ---- brute force approach ----
// time complexity: O(n^2)
// space complexity: O(1)
int largestRectangle(vector<int> &arr, int size) {
    // make a var to store max rectangle's size
    int max = 0;

    // traverse array from left to right
    for(int i = 0; i < arr.size(); i++) {
        // store temp max by the current bar
        int tempMax = arr[i]; // initialize with current bar's length

        // check left bar (if exist -> first bar don't have left bar)
        int leftCntr = i - 1; // starts from prev bar
        while(leftCntr >= 0 && arr[leftCntr] > arr[i]) {
            tempMax += arr[i];
            leftCntr--;
        }
        
        // check right bar (if exist -> last bar don't have right bar)
        int rightCntr = i + 1; // starts from next bar
        while(rightCntr < size && arr[rightCntr] > arr[i]) {
            tempMax += arr[i];
            rightCntr++;
        }

        // if tempMax is greater than maximum rectangle then update it
        if(tempMax > max)
            max = tempMax;
    }

    return max;
}

int main() {

    // histogram's heights of each bar in an array
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // find largest rectangle in histogram
    // int ans = largestRectangle(heights, heights.size());
    int ans = largestRecArea(heights, heights.size());

    cout << "The area of largest rectangle in a histogram is " << ans << endl;

    return 0;
}