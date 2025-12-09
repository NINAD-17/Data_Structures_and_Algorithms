#include <iostream>
#include <map>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// 1. REMOVE DUPLICATES FROM LINKED LIST (SORTED LL)
// 2. REMOVE DUPLICATES FROM UNSORTED LINKED LIST

// ------ sorted linkedlist -------
// time complexity: O(n)
// space complexity: O(1)
void removeDuplicates(Node* &head) {
    if(head == NULL) {
        cout << "linked list is empty" << endl;
        return;
    }

    Node* prev = head; // or we can solve this by only curr node. set curr for prev and curr can be access by curr -> next
    Node* curr = prev -> next;

    while(curr != NULL) {
        if(curr -> data == prev -> data) { // if you use only curr node then instead of prev we will write curr -> next -> data
            // remove duplicate node
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
            curr = prev -> next;
            continue;
        }
        prev = curr;
        curr = curr -> next;
    }

}

// ------ unsorted linkedlist --------
// 1. using map 
// time complexity: O(n)
// space complexity: O(n)
void removeDuplicates_mp(Node* &head) {
    if(head == NULL || head -> next == NULL) return;

    map<int, bool> alreadyExist;
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        if(alreadyExist[curr -> data]) {
            // remove node
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
            curr = prev -> next;
        } else {
            alreadyExist[curr -> data] = true;
            prev = curr;
            curr = curr -> next;
        }
    }
}

// 2. by sorting 
void removeDuplicates_sort(Node* &head) {
    if(head == NULL && head -> next == NULL) return;

    // write code here: use gfg's articla to study soriting of linked list
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    printLL(head);

    removeDuplicates_mp(head);
    printLL(head);

    return 0;
}