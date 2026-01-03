#include <iostream>
#include <stack>
using namespace std;

// DELETE MIDDLE ELEMENT FROM STACK
// time complexity: O(n)
// space complexity: O(n)

// Both (Iterative and Recursive) take O(n) time and O(n) space.
// Recursive uses the function call stack, iterative uses an explicit temporary stack.
// Recursive is more elegant but can cause stack overflow for large n.
// Iterative is safer and more practical in production.

void deleteElement(stack<int> &st, int count, int size) {
    // base case
    if(count == size / 2) {
        st.pop(); // pop mid element
        return ;
    }

    int currElement = st.top();
    st.pop();

    // recursive call
    deleteElement(st, count + 1, size);

    st.push(currElement);
}

void deleteMid(stack<int> &st) {
    int count = 0;
    int size = st.size();

    deleteElement(st, count, size);
}

// --- iterative solution ---
// time: O(n)
// space: O(n)
void deleteMid_iterative(stack<int> &st) {

    // make temp stack to store popped elements
    stack<int> tempStack;
    int mid = st.size() / 2;

    // traverse till mid - 1 and add popped elements in new stack
    for(int cnt = 0; cnt < mid; cnt++) {
        tempStack.push(st.top());
        st.pop();
    }

    // remove middle element
    st.pop();

    // push element from tempStack to original stack
    while(!tempStack.empty()) {
        st.push(tempStack.top());
        tempStack.pop();
    }
}

void printStack(stack<int> st) {
    cout << "\nprinting stack: (top) ";
    while(!st.empty()) {
        cout << st.top() << " -> ";
        st.pop();
    }
    cout << "(bottom)" << endl << endl;
}

int main() {
    stack<int> st;

    st.push(5);
    st.push(9);
    st.push(12);
    st.push(8);
    st.push(4);
    printStack(st);

    deleteMid(st);
    // deleteMid_iterative(st);
    printStack(st);
    
    return 0;
}