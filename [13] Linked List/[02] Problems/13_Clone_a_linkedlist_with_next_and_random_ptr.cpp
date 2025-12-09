#include <iostream>
#include <unordered_map>
using namespace std;

// CLONE A LINKED LIST WITH NEXT AND RANDOM POINTER
// time complexity: O(n)
// space complexity: O(n)

/********************************************************************** */
class Node {
    public: 
        int data;
        Node* next;
        Node* random;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
            this -> random = NULL;
        }
};

void createNewLL(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);

    head = newNode;
    tail = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);

    if(tail == NULL) {
        createNewLL(head, tail, data);
        return;
    }

    tail -> next = newNode;
    tail = newNode; // Or you can write `tail = tail -> next;`
}

void printLL(Node* &head) { // We're passing it by reference to not create another node for head (for efficiency)
    if(head == NULL) {
        cout << "linked list is empty or not exist :(" << endl;
        cout << "head node: " << head << endl << endl;
        return;
    }

    Node* temp = head;
    cout << "Printing LinkedList: ";
    while(temp != NULL) { // If you write 'temp -> next != NULL' then it will stop before printing last node.
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << "NULL" << endl;
}

void printRandom(Node* &head) {
    Node* curr = head;

    cout << "printing random ptr of all nodes: " << endl;
    while(curr != NULL) {
        cout << "\t" << curr -> data << " -> ";
        cout << curr -> random -> data << endl;
        curr = curr -> next;
    }
    cout << endl;
}
/********************************************************************************** */

Node* copyList(Node* &head) {
    // step 1: create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* tempNode = head;
    while(tempNode != NULL) {
        insertAtTail(cloneHead, cloneTail, tempNode -> data);
        tempNode = tempNode -> next;
    }

    // step 2: create a map (Read the reason: why we use map, in README.md)
    unordered_map<Node*, Node*> oldToNewNode;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL) {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL) {
        cloneNode -> random = oldToNewNode[originalNode -> random];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    return cloneHead;
}

int main() {

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    node1 -> random = node3;
    node2 -> random = node1;
    node3 -> random = node5;
    node4 -> random = node3;
    node5 -> random = node2;

    printLL(node1);
    printRandom(node1);

    Node* cloneHead = copyList(node1);
    printRandom(cloneHead);

    return 0;
}