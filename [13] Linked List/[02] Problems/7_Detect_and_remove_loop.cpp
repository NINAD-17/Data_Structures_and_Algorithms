#include <iostream>
#include <map>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// 1. DETECT CYCLE IN LINKED LIST
// 2. REMOVE CYCLE FROM LINKED LIST
// 3. GIVE START NODE OF LOOP IN LINKED LIST

// -------------- floyd's cycle detection algorithm --------------
// time complexity: O(n)
// space complexity: O(1)
Node* floydDetectLoop(Node* &head) {
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) 
            fast = fast -> next;
        slow = slow -> next;

        if(slow == fast)
            return fast;
    }

    return NULL;
}

Node* getStartingNode(Node* &head) {
    if(head == NULL) return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    cout << "Intersection point (fast and slow): " << intersection -> data << endl;
    if(intersection == NULL) return NULL;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    cout << "Loop causing node is " << slow -> data << endl;
    return slow; // both pointers reached to the same node (starting node)
}

void floydRemoveLoop(Node* &head) {
    if(head == NULL) return;

    Node* startOfLoop = getStartingNode(head);
    Node* tempNode = startOfLoop;

    while(tempNode -> next != startOfLoop) {
        tempNode = tempNode -> next;
    }

    tempNode -> next = NULL;
}

// -------------- optimised approach -----------------------
// time complexity: O(n)
// space complexity: O(1)
void removeCycle_2(Node* &tail) {
    if(tail == NULL) return;

    Node* tempNode = tail -> next;
    while(tempNode != tail) {
        tempNode = tempNode -> next;
    }

    tail -> next = NULL;
}

Node* detectCycle_2(Node* &tail) {
    if(tail == NULL) return NULL; // empty linked list

    // only one node present
    if(tail -> next == tail) return tail;

    Node* tempNode = tail -> next;
    while(tempNode != NULL && tempNode != tail) {
        tempNode = tempNode -> next;
    }

    if(tempNode == NULL)
        return NULL;
    
    if(tempNode -> next != NULL)
        return tail -> next;
}   

// -------------------- not optimised (using map) ----------------------
// time complexity: O(n)
// space complexity: O(n) .. to store each (n nodes) node in map.
void removeCycle(Node* &head, Node* &tail) {
    if(head == NULL) return;

    Node* prevNode = NULL;
    Node* currNode = head;
    map<Node*, bool> visited;

    while(currNode != NULL && visited[currNode] != true) {
        visited[currNode] = true;
        
        prevNode = currNode;
        currNode = currNode -> next;
        
        // cout << "CurrNode: " << currNode -> data << "\tPrevNode: " << prevNode -> data << endl;
    }

    if(visited[currNode]) { // Loop detected
        prevNode -> next = NULL;
        tail = prevNode;
    }

    return; // No loop (cycle)
}

Node* detectCycle(Node* &head) {
    // if linkedlist is empty
    if(head == NULL) return NULL;

    Node* tempNode = head;
    map<Node*, bool> visited;

    while(tempNode != NULL && visited[tempNode] != true) {
        // cout << "DEBUG: " << tempNode -> data << " - " << visited[tempNode] << endl;
        visited[tempNode] = true;
        // cout << "DEBUG: " << tempNode -> data << " - " << visited[tempNode] << endl << endl;
        tempNode = tempNode -> next;
    }

    if(visited[tempNode]) {
        return tempNode;
    }
    
    return NULL;
}

void printLoop(Node* &tail) {
    Node* temp = tail;

    if(tail == NULL) {
        cout << "linked list is empty or not exist :(" << endl;
        cout << "tail node: " << tail << endl << endl;
        return;
    }

    cout << "printing Loop: ";
    do {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    } while (temp != tail);

    cout << "... continue again from 60 to 50" << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // 1) CREATE A SINGLY LINKED LIST
    // Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    Node* tempNode_1 = tail; // Node 30

    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    Node* tempNode_2 = tail; // Node 60
    printLL(head); 
    
    // 2) CREATE A LOOP IN A LINKED LIST
    // Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    //                           ^                 |
    //                           |_________________|
    
    tempNode_2 -> next = tempNode_1; // Node 60 -> next = Node 30 (loop)
    printLoop(tail);
    cout << endl;


    // 3) DETECT AND REMOVE LOOP
    // - i. Brute force
    Node* loopCausingNode = detectCycle(head);
    if(loopCausingNode) {
        cout << "Loop causing node is " << loopCausingNode -> data << endl;
        cout << "Head: " << head -> data << "\tTail: " << tail -> data << endl;

        removeCycle(head, tail);
        cout << "Loop (cycle) has removed!" << endl;

        cout << "Head: " << head -> data << "\tUpdated Tail: " << tail -> data << endl;
    } else {
        cout << "No loop present in LL" << endl;
    }

    // Again creating loop for next algorithm
    cout << "\n--------------\nAgain adding loop to test next function" << endl;
    tempNode_2 -> next = tempNode_1;
    printLoop(tail);
    cout << "--------------" << endl << endl;
    
    // - ii. Floyd's Algorithm
    Node* isLoopDetected = floydDetectLoop(head);
    if(isLoopDetected) {
        cout << "Loop Detected. Point of intersection of fast and slow is at node " << isLoopDetected -> data << endl;

        floydRemoveLoop(head);
        cout << "Loop removed successfully" << endl;
    }

    return 0;
}