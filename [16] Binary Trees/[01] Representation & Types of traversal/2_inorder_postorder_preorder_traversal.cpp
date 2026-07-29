#include <iostream> 
using namespace std;

// TRAVERSALS:
// INORDER | PREORDER | POSTORDER

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

// INORDER: LNR (left middle right)
// time: O(n)
// space: O(h) OR O(n) on skew tree and O(log n) on balanced tree
void inorder(Node* &root) {
    // base case
    if(root == NULL)
        return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

// PREORDER: NLR (middle left right)
void preorder(Node* &root) {
    // base case
    if(root == NULL)
        return ;
    
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

// POSTORDER: LRN (left right middle)
void postorder(Node* &root) {
    // base case
    if(root == NULL)
        return ;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int main() {

    Node* root = NULL;

    root = buildTree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\ninorder: ";
    inorder(root);

    cout << "\npreorder: ";
    preorder(root);

    cout << "\npostorder: ";
    postorder(root);

    cout << endl;
    return 0;
}