#include <iostream>
using namespace std;

// DOUBLY ENDED QUEUE IMPLEMENTATION USING ARRAY

// some information -
// with doubly ended queue, you can able to implement both stack and queue.
// it's basically used in CPU scheduling, process scheduling

// conditions:
//      1. push_rear: insert element from rear
//      2. push_front: insert element from front
//      3. pop_rear: remove element from rear
//      4. pop_front: remove element from front

class Deque {
    public: 
        int *arr;
        int size;
        int front;
        int rear;

        // constructor
        Deque(int size) {
            this -> size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        // operations 
        // 1. push_rear
        void push_rear(int data) {
            // is the queue full?
            if(front == (rear + 1) % size) {
                cout << "deque is full, try again after removing some elements" << endl;
                return;
            }

            if(rear == -1) {
                front = rear = 0;
            } else if(rear == size - 1) {
                rear = 0;
            } else {
                rear++;
            }

            arr[rear] = data;
        }

        void push_front(int data) {
            // is the queue is full?
            if(front == (rear + 1) % size) {
                cout << "deque is full, try again after removing some elements" << endl;
                return ;
            }

            if(front == -1) {
                front = rear = 0;
            } else if(front == 0) {
                front = size - 1;
            } else {
                front--;
            }

            arr[front] = data;
        }

        void pop_rear() {
            if(front == -1) {
                cout << "deque is empty" << endl;
                return ;
            }

            arr[rear] = -1;

            if(rear == front) {
                rear = front = -1;
            } else if(rear == 0) {
                rear = size - 1;
            } else {
                rear--;
            }
        }

        void pop_front() {
            if(front == -1) {
                cout << "deque is empty" << endl;
                return ;
            }

            arr[front] = -1;

            if(front == rear) {
                front = rear = -1;
            } else if(front == size - 1) {
                front = 0;
            } else {
                front++;
            }
        }

        int getFront() {
            if(front == -1) {
                cout << "deque is empty, front: -1" << endl;
                return -1;
            }
            else 
                return arr[front];
        }

        int getrear() {
            if(rear == -1) {
                cout << "deque is empty, rear: -1" << endl;
                return -1;
            }
            else 
                return arr[rear];
        }

        bool isEmpty() {
            if(front == -1)
                return true;
            else 
                return false;
        }
};

void printDeque(Deque &dq) {
    cout << "\nArray state: ";
    for(int i = 0; i < dq.size; i++) {
        cout << dq.arr[i] << " ";
    }
    cout << "(end)\n";

    if(dq.front == -1) {
        cout << "deque is empty\n" << endl;
        return;
    }

    cout << "Logical deque: (front) ";
    int i = dq.front;
    while(true) {
        cout << dq.arr[i] << " ";
        if(i == dq.rear) break;
        i = (i + 1) % dq.size;
    }
    cout << "(rear)\n\n";
}

int main() {
    Deque dq(6);

    // Case 1: Push at rear
    dq.push_rear(2);
    dq.push_rear(5);
    printDeque(dq);
    // Array: 2 5 _ _ _ _ (end)
    // Logical: (front) 2 -> 5 (rear)

    // Case 2: Push at front
    dq.push_front(1);
    dq.push_front(3);
    printDeque(dq);
    // Array: 2 5 _ _ 3 1 (end)
    // Logical: (front) 3 -> 1 -> 2 -> 5 (rear)

    // Case 3: Fill completely
    dq.push_front(4);
    dq.push_front(6);
    printDeque(dq);
    // Array: 2 5 6 4 3 1
    // Logical: (front) 6 -> 4 -> 3 -> 1 -> 2 -> 5 (rear)

    // Case 4: Overflow attempt
    dq.push_front(1);
    dq.push_front(2); // should print "deque is full"
    printDeque(dq);

    // Case 5: Pop from rear
    dq.pop_rear();
    printDeque(dq);

    dq.pop_rear();
    printDeque(dq);

    // Case 6: Pop from front
    dq.pop_front();
    printDeque(dq);

    dq.pop_front();
    printDeque(dq);

    // Case 7: Mix pops until empty
    dq.pop_rear();
    printDeque(dq);

    dq.pop_rear();
    printDeque(dq);

    dq.pop_front(); // should show empty
    printDeque(dq);

    return 0;
}