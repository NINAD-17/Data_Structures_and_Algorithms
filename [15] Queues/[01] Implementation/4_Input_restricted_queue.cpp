#include <iostream>
using namespace std;

// INPUT RESTRICTED QUEUE IMPLEMENTATION USING ARRAY
// conditions:
//      1. insertion of elements can be done on rear side only
//      2. removal of element is possible on both side (front and rear)

class InputRestrictedQueue {
    // note: we're using logic of circular queue and not normal queue because of efficient memory use
    public: 
        int *arr;
        int size;
        int qFront;
        int qRear;

        // constructor
        InputRestrictedQueue(int size) {
            this -> size = size;
            arr = new int[size];
            qFront = -1;
            qRear = -1;
        }

        // behaviour
        void enqueue(int data) {
            // check if the queue is full or not
            if((qRear + 1) % size == qFront) {
                // if the above output is equal to front then queue is full
                cout << "queue is full" << endl;
                return ;
            }

            // insert element
            if(qFront == -1) {
                qFront = 0;
                qRear = 0;
            } else if(qFront != 0 && qRear == size - 1) {
                qRear = 0;
            } else {
                qRear++;
            }

            arr[qRear] = data;
        }

        // we can dequeue from both sides - front and rear
        void dequeue_front() {
            // check if the queue is empty or not
            if(qFront == -1) {
                cout << "queue is empty" << endl;
                return;
            }

            arr[qFront] = -1;

            if(qFront == qRear) {
                qRear = qFront = -1;
            } else if(qFront == size - 1) {
                qFront = 0;
            } else {
                qFront++;
            }
        }

        void dequeue_rear() {
            // check if queue is empty or not
            if(qRear == -1) {
                cout << "queue is empty" << endl;
                return ;
            }

            arr[qRear] = -1;

            if(qFront == qRear) {
                qFront = qRear = -1;
            } else if(qRear == 0) {
                qRear = size - 1;
            } else {
                qRear--;
            }
        }
};

void printQueue(InputRestrictedQueue &q) {
    if(q.qFront == -1) {
        cout << "queue is empty" << endl;
        return;
    }

    cout << "\nqueue: (front) ";
    int i = q.qFront;
    while(true) {
        cout << q.arr[i] << " -> ";
        if(i == q.qRear) break;          // stop when rear is reached
        i = (i + 1) % q.size;            // wrap around
    }
    cout << "(rear)" << endl;
}

int main() {
    InputRestrictedQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    printQueue(q);
    // Array: 1 -> 2 -> 3 -> 4 -> 5 -> (end)
    // Logical: (front) 1 -> 2 -> 3 -> 4 -> 5 -> (rear)

    q.dequeue_front();
    q.dequeue_front();
    printQueue(q);
    // Array: -1 -> -1 -> 3 -> 4 -> 5 -> (end)
    // Logical: (front) 3 -> 4 -> 5 -> (rear)

    q.enqueue(6);
    q.enqueue(7);
    printQueue(q);
    // Array: 6 -> 7 -> 3 -> 4 -> 5 -> (end)
    // Logical: (front) 3 -> 4 -> 5 -> 6 -> 7 -> (rear)

    q.dequeue_rear();
    printQueue(q);
    // Array: 6 -> -1 -> 3 -> 4 -> 5 -> (end)
    // Logical: (front) 3 -> 4 -> 5 -> 6 -> (rear)

    q.dequeue_front();
    printQueue(q);
    // Array: 6 -> -1 -> -1 -> 4 -> 5 -> (end)
    // Logical: (front) 4 -> 5 -> 6 -> (rear)

    q.dequeue_rear();
    printQueue(q);
    // Array: -1 -> -1 -> -1 -> 4 -> 5 -> (end)
    // Logical: (front) 4 -> 5 -> (rear)

    q.dequeue_front();
    q.dequeue_front();
    printQueue(q);
    // Array: -1 -> -1 -> -1 -> -1 -> -1 -> (end)
    // queue is empty

    return 0;
}
