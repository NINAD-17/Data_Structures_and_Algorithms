#include <iostream>
#include <queue>
#include <stack>
#include "../lib/print.cpp"
using namespace std;

// REVERSE FIRST K ELEMENTS
// time complexity: O(n)
// space complexity: O(n)

// Example: [1 2 3 4 5]
//      pop from queue 1 2 3 and add it in the stack as 1 -> 2 -> 3 (tos). Queue is [4 5]
//      pop from stack 3 5 4 and add it in the queue as [4 5 3 2 1]
//      pop first n - k element and push back at last in the queue. [3 2 1 4 5]

void reverseElements(queue<int> &q, int k) {
    // create a stack to store 1st k elements of queue
    stack<int> st;
    
    int remainingElements = q.size() - k;

    // step 1: push first k elements in stack
    while(q.size() != remainingElements) {
        st.push(q.front());
        q.pop(); // pop from front
    }

    // step 2: add elements from stack in queue
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // step 3: fetch first n - k elements from queue and push_back 
    while(remainingElements--) {
        int frontElement = q.front();
        q.pop(); // pop the front element
        q.push(frontElement); // push that element from rear side
    }
}

int main() {

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    printQueue(q);

    reverseElements(q, 3); // reverse 1st 3 elements
    printQueue(q);

    return 0;
}