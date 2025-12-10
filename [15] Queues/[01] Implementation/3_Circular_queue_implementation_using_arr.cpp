#include <iostream>
using namespace std;

class CircularQueue {
    public: 
        int *arr;
        int qFront;
        int qRear;
        int size;

        // constructor
        CircularQueue(int size) {
            this -> size = size;
            arr = new int[size];
            qFront = -1;
            qRear = -1;
        }

        // operations
        // 1. enqueue: insert elements
        void enqueue(int data) {
            // is the queue full?
            if((qFront == 0 && qRear == size - 1) || (qRear == qFront - 1)) {
                // or we can use `(qRear + 1) % size == qFront` condition
                cout << "queue is full" << endl;
                return;
            }

            // insert element
            if(qFront == -1) { // 0 elements are present
                qFront = qRear = 0;
            } else if(qFront != 0 && qRear == size - 1) { // to maintain cyclic nature
                qRear = 0;
            } else { // normal condition
                qRear++;
            }

            // we also don't need to use that be if else statement
            // you can use qRear = (qRear + 1) % size
            // to get accurate place of rear element

            arr[qRear] = data; // insert data in queue
        }

        // 2. dequeue
        void dequeue() {
            // check if queue is empty
            if(qFront == -1) {
                cout << "queue is empty" << endl;
                return;
            }

            arr[qFront] = -1; // put -1 in arr[front]

            if(qFront == qRear) { // only one element present in queue
                qFront = qRear = -1;
            } else if(qFront == size - 1) {
                // qFront reach to last position of arr then after dequeue it should came to 0th position
                qFront = 0;
            } else {
                qFront++; // normal case: move front to next position
            }
        }

        // top
        int top() {
            if(qFront != -1)
                return arr[qFront];
            else 
                return -1;
        }

        // is empty?
        bool isEmpty() {
            if(qFront == -1) 
                return true;
            else 
                return false;
        }
};

void printQueue(CircularQueue &q) {
    if(q.qFront == -1) {
        cout << "queue is empty" << endl;
        return;
    }

    cout << "\nqueue: (front) ";
    int i = q.qFront;
    while(true) {
        cout << q.arr[i] << " -> ";
        if(i == q.qRear) break;
        i = (i + 1) % q.size; // wrap around
    }
    cout << "(rear)" << endl;
}

int main() {
    
    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    printQueue(q);
    // (front) 1 -> 2 -> 3 -> 4 -> 5 (rear)

    q.dequeue();
    q.dequeue();
    q.dequeue();
    printQueue(q);
    //  -1 -> -1 -> -1 -> (front) 4 -> 5 (rear)

    q.enqueue(6);
    q.enqueue(7);
    printQueue(q);
    //  6 -> 7 (rear) -> -1 -> (front) 4 -> 5
    //  Front to Rear is 4 -> 5 -> 6 -> 7 and their is 1 place is empty

    return 0;
}