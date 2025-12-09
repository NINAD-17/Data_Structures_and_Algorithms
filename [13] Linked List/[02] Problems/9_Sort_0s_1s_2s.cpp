#include <iostream>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// SORT 0s 1s 2s IN LINKED LIST

// ----- 1. by updating the data -----
// time complexity: O(n)
// space complexity: O(1)
void sort012(Node* &head) {
    if(head == NULL || head -> next == NULL) return ;

    int cntOfZero = 0;
    int cntOfOne = 0;
    int cntOfTwo = 0;

    Node* tempNode = head;
    while(tempNode != NULL) {
        if(tempNode -> data == 0) cntOfZero++;
        else if(tempNode -> data == 1) cntOfOne++;
        else cntOfTwo++;
        tempNode = tempNode -> next;
    }

    tempNode = head;
    while(tempNode != NULL && cntOfZero--) { // cntOfZero-- means it will post-decrement value and also check if the cntOfZero is greater than 0 or not.
        tempNode -> data = 0;
        tempNode = tempNode -> next;
    }

    while(tempNode != NULL && cntOfOne--) {
        tempNode -> data = 1;
        tempNode = tempNode -> next;
    }

    while(tempNode != NULL && cntOfTwo--) {
        tempNode -> data = 2;
        tempNode = tempNode -> next;
    }
}

// ----- 2. by making separate linkedlist for 3 elements and merging it -----
// time complexity: O(n)
// space complexity: O(n)

/* // this is the function for our code written in "lib/singly_linkedlist.cpp"
   // with this logic you don't need to make dummy nodes. (shown by youtube video)
void insert(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
*/

Node* sort012_separateLL(Node* &head) {
    if(head == NULL || head -> next == NULL) return NULL;

    // linked list for data 0
    Node* zeroHead = NULL;
    Node* zeroTail = NULL;

    // linked list for data 1
    Node* oneHead = NULL;
    Node* oneTail = NULL;

    // linked list for data 2
    Node* twoHead = NULL;
    Node* twoTail = NULL;

    Node* tempNode = head;

    while(tempNode != NULL) {
        if(tempNode -> data == 0)
            insertAtTail(zeroHead, zeroTail, 0);
        else if(tempNode -> data == 1)
            insertAtTail(oneHead, oneTail, 1);
        else 
            insertAtTail(twoHead, twoTail, 2);
        
        tempNode = tempNode -> next;
    }

    // merge all the linked lists. // we're not considering twoHead because if it's NULL then it can't create any problem
    if(zeroHead != NULL && oneHead != NULL) {
        zeroTail->next = oneHead;
        oneTail->next = twoHead;
    } else if(zeroHead == NULL && oneHead != NULL) {
        oneTail -> next = twoHead;
    } else if(zeroHead != NULL && oneHead == NULL) {
        zeroTail -> next = twoHead;
    }

    if(zeroHead != NULL) return zeroHead;
    if(oneHead != NULL) return oneHead;
    return twoHead;
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 1);
    // insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    printLL(head);

    // sort012(head);
    // printLL(head);

    Node* newHead = sort012_separateLL(head);
    printLL(newHead);

    return 0;
}