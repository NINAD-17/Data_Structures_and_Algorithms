#include <iostream>
#include <stack>
#include "../lib/print.cpp"
using namespace std;

// SORT A STACK
// time complexity: O(n^2)
// space complexity: O(n)

void sortedInsert(stack<int> &st, int element) {
    // base case: until you don't get st.top smaller than element (or empty), go further in stack by poping top element when you get small top element than our element then push that element on top of stack and then move all the elements on top as it is.
    if(st.empty() || st.top() < element) {
        st.push(element);
        return;
    }

    int currElement = st.top();
    st.pop();

    sortedInsert(st, element);
    st.push(currElement);
}

void sortStack(stack<int> &st) {
    // base case
    if(st.empty()) 
        return;
    
    int currElement = st.top();
    st.pop();

    sortStack(st);
    sortedInsert(st, currElement);
}

// Iterative approach using quick sort
// Time: O(n log n)
// Space: O(n)
int partition(int *arr, int st, int en) {

    // Decide pivot element
    int pivot = arr[st];

    // Count all the numbers which are less than pivot
    int count = 0;
    for(int i = st; i <= en; i++) {
        if(arr[i] < pivot)  
            count++;
    }

    // Put pivot at right position
    int pivotIndex = st + count;
    swap(arr[pivotIndex], arr[st]);

    // Satisfy condition < and > than pivot in left and right parts ( ... < pivot < ...)
    int i = st, j = en;

    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] < pivot) 
            i++;
        
        while(arr[j] > pivot)
            j--;
        
        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quick_sort(int *arr, int st, int en) {
    // Base Case
    if(st >= en)
        return;

    // Partition
    int pivotIndex = partition(arr, st, en);

    // Sort left part
    quick_sort(arr, st, pivotIndex - 1);

    // Sort right part
    quick_sort(arr, pivotIndex + 1, en);
}

void sortStackIteratively(stack<int> &st, string order) {
    int stSize = st.size();
    int *arr = new int[stSize];
    int i = 0;

    while(!st.empty()) {
        arr[i++] = st.top();
        st.pop();
    }

    quick_sort(arr, 0, stSize - 1);

    if(order == "incr") {
        // Ascending order (greater element will be top of stack) Ex - (tos) 2 -> 1 -> 0 (bottom)
        i = 0;
        while(i < stSize) {
            st.push(arr[i++]);
        }
    } else {
        // Descending order (smaller element will be top of stack) Ex - (tos) 0 -> 1 -> 2 (bottom)
        i = stSize - 1;
        while(i >= 0) {
            st.push(arr[i--]);
        }
    }

    delete[] arr;
}

int main() {

    stack<int> st;

    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);
    st.push(2);
    st.push(3);
    printStack(st);

    // Recursive solution
    // sortStack(st);

    // Iterative solution
    string order = "desc"; // use 'incr' for ascending order and 'desc' for descending order
    sortStackIteratively(st, order);
    printStack(st);

    return 0;
}