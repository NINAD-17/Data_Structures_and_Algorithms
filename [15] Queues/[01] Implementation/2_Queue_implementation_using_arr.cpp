#include <iostream>
using namespace std;

// QUEUE IMPLEMENTATION USING ARRAY
// all operations have O(n) time complexity.
// note: but the dequeue operation is inefficient in handling memory
//       to solve this inefficiency we can apply logic of shifting elements 1 position back but this will take O(n) time complexity (heavy operation)
//       therefore, we use 'circular queue' instead of this queue implementation.

class Queue {
    // properties
    public:
        int *arr;
        int size;
        int qfront;
        int qrear;

        // constructor
        Queue(int size) {
            this -> size = size;
            arr = new int[size]; // allocate memory to the queue
            qfront = 0; 
            qrear = 0; // rear always points to last element's next position. therefore as the queue is currently empty instead of pointing -1, it points to 0
        }

        // behaviour
        // 1. enqueue: insert in queue
        void enqueue(int data) {
            if(qrear < size) {
                arr[qrear++] = data; // put data in qrear and then qrear++
            } else {
                cout << "queue is full" << endl;
                cout << endl; cout << endl;
                cout << endl;
            }
        }

        // 2. dequeue: remove an element
        // --- inefficient use of space --- after dequeue operation it's not giving that space to others 
        void dequeue() {
            if(qfront == qrear) 
                cout << "queue is empty" << endl;
            else {
                arr[qfront] = -1;
                qfront++;
                if(qfront == qrear) {
                    qfront = 0;
                    qrear = 0;
                }
            }
        }

        // time complexity: O(n) for each deletion of element it will take O(n) time. that's why it's heavy operation
        // in this function we're shifting elements to the front means to current position - 1. 
        // by this we're preventing the problem that occur in dequeue function that is 'inefficient use of memory' with the cost of more time complexity.
        void dequeue_heavy() {
            if(qfront == qrear)
                cout << "queue is empty" << endl;
            else {
                int i = 0;
                while(i < qrear - 1) {
                    arr[i] = arr[i + 1];
                    i++;
                }
                arr[i] = -1; // not needed
                // qrear = i - 1;
                qrear--;
            }
        }

        // 3. qfront
        int front() {
            if(qfront == qrear)
                return -1;
            else
                return arr[qfront];
        }

        // 4. empty
        bool isEmpty() {
            if(qfront == qrear)
                return true;
            else
                return false;
        }
};

void printQueue(Queue &q) {
    cout << "\nqueue: (front) ";
    for(int i = q.qfront; i < q.qrear; i++) // i < q.qrear because the rear is always pointing towards last element's next place
        cout << q.arr[i] << " -> ";
    cout << "(rear)" << endl;
}

int main() {

    Queue q(5);

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7); // queue is full
    printQueue(q);
    cout << "front: " << q.front() << endl;

    q.dequeue_heavy();
    printQueue(q);
    cout << "front: " << q.front() << endl;

    q.dequeue_heavy();
    printQueue(q);
    cout << "front: " << q.front() << endl;

    q.dequeue_heavy();
    printQueue(q);
    cout << "front: " << q.front() << endl;

    // q.dequeue();
    cout << "front: " << q.front() << endl;

    q.enqueue(9);
    printQueue(q);

    q.enqueue(10);
    printQueue(q);

    q.enqueue(11);
    printQueue(q);

    q.enqueue(12);
    printQueue(q);

    return 0;
}