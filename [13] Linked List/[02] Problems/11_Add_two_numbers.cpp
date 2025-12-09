#include <iostream>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// ADD 2 NUMBERS REPRESENTED BY LINKED LIST
// time complexity: O(m + n)
// space complexity: O(m + n)

// --- 1. by reversing the linked list ---
Node* revList(Node* &head) {
    // base case
    if(head == NULL || head -> next == NULL)
        return head;
    
    Node* newHead = revList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return newHead;
}

Node* addTwoNum(Node* &head1, Node* &head2) {
    // one list is empty
    if(head1 == NULL) return head1;
    if(head2 == NULL) return head2;

    Node* revHead1 = revList(head1);
    Node* revHead2 = revList(head2);
    Node* ansListHead = NULL;
    Node* ansListTail = NULL;

    int carry = 0;

    while(revHead1 != NULL && revHead2 != NULL) {
        int sum = carry + revHead1 -> data + revHead2 -> data; // carry + dig1 + dig2
        int sumDig = sum % 10;
        carry = sum / 10;

        insertAtHead(ansListHead, ansListTail, sumDig);
        revHead1 = revHead1 -> next;
        revHead2 = revHead2 -> next;
    }

    while(revHead1 != NULL) {
        int sum = carry + revHead1 -> data;
        int sumDig = sum % 10;
        carry = sum / 10;
        insertAtHead(ansListHead, ansListTail, sumDig);
        revHead1 = revHead1 -> next;
    }

    while(revHead2 != NULL) {
        int sum = carry + revHead2 -> data;
        int sumDig = sum % 10;
        carry = sum / 10;
        insertAtHead(ansListHead, ansListTail, sumDig);
        revHead2 = revHead2 -> next;
    }

    while(carry != 0) {
        int sum = carry;
        int sumDig = sum % 10;
        insertAtHead(ansListHead, ansListTail, sumDig);
        carry = sum / 10;
    }

    return ansListHead;
} 


// --- 2. another method -----
// time complexity: O(m + n) here, for while loop it's max(m, n) and ans list is need to reverse therefore O(m + n) it's size of ans list therefore max iterations are m + n
// space complexity: O(m + n) here, ans is new linkedlist which can be of maximum size m + n
void insertAtAnsLLTail(Node* &ansHead, Node* &ansTail, int data) {
    // create a new node to store sumDig
    Node* newNode = new Node(data);

    // if ans LL isn't exist
    if(ansHead == NULL) {
        ansHead = newNode;
        ansTail = newNode;
    } else {
        ansTail -> next = newNode;
        ansTail = newNode;
    }
}

Node* add(Node* first, Node* second) {
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    /* below code is using 3 loops but we can able to solve this problem by only one while loop */
    /*
    while(first != NULL && second != NULL) {
        int sum = carry + first -> data + second -> data;
        int sumDig = sum % 10;
        carry = sum / 10;

        // create and insert that in tail of the ans linked list
        insertAtAnsLLTail(ansHead, ansTail, sumDig);

        // update first and second pointer
        first = first -> next;
        second = second -> next;
    }

    while(first != NULL) {
        int sum = carry + first -> data;
        int sumDig = sum % 10;
        carry = sum / 10;
        insertAtAnsLLTail(ansHead, ansTail, sumDig);
        first = first -> next;
    }

    while(second != NULL) {
        int sum = carry + second -> data;
        int sumDig = sum % 10;
        carry = sum / 10;
        insertAtAnsLLTail(ansHead, ansTail, sumDig);
        second = second -> next;
    }

    while(carry != 0) {
        int sum = carry;
        int sumDig = sum % 10;
        carry = sum / 10;
        insertAtAnsLLTail(ansHead, ansTail, sumDig);
    }
    */

    while(first != NULL || second != NULL || carry != 0) {
        int val1 = 0;
        if(first != NULL) val1 = first -> data;

        int val2 = 0;
        if(second != NULL) val2 = second -> data;

        int sum = val1 + val2 + carry;
        int sumDig = sum % 10;
        carry = sum / 10;

        // create and add sumDig in ans list
        insertAtAnsLLTail(ansHead, ansTail, sumDig);

        if(first != NULL) first = first -> next;
        if(second != NULL) second = second -> next;
    }

    return ansHead;
}

Node* addTwoLists(Node* first, Node* second) {
    // step 1: reverse the input LL
    first = revList(first);
    second = revList(second);

    // step 2: add both LL
    Node* ans = add(first, second);

    // step 3: reverse the answer
    ans = revList(ans);
    return ans;
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(head1, tail1, 9);
    insertAtTail(head1, tail1, 4);

    insertAtTail(head2, tail2, 9);
    insertAtTail(head2, tail2, 8);
    insertAtTail(head2, tail2, 7);

    printLL(head1);
    printLL(head2);

    cout << "\nans: " << endl;
    Node* ansHead = addTwoNum(head1, head2);
    printLL(ansHead);

    return 0;
}