#include <bits/stdc++.h> 
using namespace std;

// Iterative approach

class Node {
    public: 
        int data;
        Node* left;
        Node* right;

        // constructor
        Node(int data) {
            this -> data = data;
            this -> left = this -> right = NULL;
        }
};

Node* buildTree(Node* &root) {
    // initially the root is NULL
    int data;

    if(root == NULL)
        cout << "enter data for root node: ";
    else 
        cout << "enter data: ";
    cin >> data;
    cout << endl;

    if(data == -1)
        return NULL;

    root = new Node(data);

    cout << "-> enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "-> enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}


// Time Complexity: Go to README.md
void inorder_it(Node* &root) {
    if(root == NULL) return ;
    stack<Node*> st;
    Node* curr = root;

    while(curr != NULL || !st.empty()) {
        // go as left as possible (curr -> left)
        while(curr != NULL) {
            st.push(curr);
            curr = curr -> left;
        }

        // print middle node
        curr = st.top();
        st.pop();
        cout << curr -> data << " ";

        // go right
        curr = curr -> right;
    }
}

void preorder_it(Node* &root) {
    if(root == NULL) return ;
    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {
        Node* curr = st.top();
        st.pop();
        cout << curr -> data << " ";

        // push right first so left is processed first
        if(curr -> right) st.push(curr -> right);
        if(curr -> left) st.push(curr -> left);
    }
}

void postorder_it(Node* &root) {
    if(root == NULL) return ;
    stack<Node*> st1, st2;
    st1.push(root);

    while(!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if(curr -> left) st1.push(curr -> left);
        if(curr -> right) st1.push(curr -> right);
    }

    while(!st2.empty()) {
        cout << st2.top() -> data << " ";
        st2.pop();
    }
}