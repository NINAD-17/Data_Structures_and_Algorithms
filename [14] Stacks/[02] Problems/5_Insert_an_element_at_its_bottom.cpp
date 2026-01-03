#include <iostream>
#include <stack>
#include "../lib/print.cpp"
using namespace std;

// INSERT AN ELEMENT AT ITS BOTTOM IN A GIVEN STACK
// time complexity: O(n)
// space complexity: O(n)

void insertAtBottom(stack<int> &st, int element) {
    // base case
    if(st.empty()) {
        st.push(element);
        return;
    }

    int currElement = st.top();
    st.pop();

    insertAtBottom(st, element);
    st.push(currElement);
}

void insertAtBottom_iterative(stack<int> &st, int element) {
    stack<int> tempSt;

    while(!st.empty()) {
        tempSt.push(st.top());
        st.pop();
    }

    tempSt.push(element);

    while(!tempSt.empty()) {
        st.push(tempSt.top());
        tempSt.pop();
    }
}

int main() {

    stack<int> st;

    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);
    printStack(st);

    int element = 12;

    cout << "Recursive Way: " << endl;
    insertAtBottom(st, element);
    printStack(st);

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);
    
    cout << "Iterative way: " << endl;
    insertAtBottom_iterative(st, element);
    printStack(st);

    return 0;
}