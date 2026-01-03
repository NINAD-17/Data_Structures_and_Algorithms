#include <iostream>
using namespace std;

// Implementation of 2 stacks in one array
// ---------------------------
// | 1 | 2 | 3 |  |  | 4 | 5 |
// ---------------------------
// Here, top of stack1 is 3 and top of stack2 is 4

class TwoStack {
    public: 
        int *arr;
        int top1; // for stack 1
        int top2; // for stack 2
        int size;

        TwoStack(int size) {
            this -> size = size;
            arr = new int[size]; // allocate memory in heap
            top1 = -1; // initialize top1
            top2 = size; // initialize top2
        }

        void push1(int element) {
            // atleast an empty space is present
            if((top2 - top1) - 1 >= 1) {
                top1++;
                arr[top1] = element;
            } else {
                cout << "oops! stack overflow" << endl;
            }
        }

        void push2(int element) {
            // atleast an empty space is present
            if((top2 - top1) - 1 >= 1) {
                top2--;
                arr[top2] = element;
            } else  
                cout << "oops! stack overflow" << endl;
        }

        int pop1() {
            // check for atleast one element present or not
            if(top1 >= 0) {
                int ans = arr[top1];
                top1--;
                return ans;
            }
            else 
                return -1;
        }

        int pop2() {
            if(top2 < size) {
                int ans = arr[top2];
                top2++;
                return top2;
            }
            else 
                return -1;
        }
};

void printTwoStack(TwoStack &st) {
    if(st.top1 == -1) {
        cout << "stack 1 is empty" << endl;
        return;
    }

    cout << "printing stack 1: (top) ";
    int topOfSt1 = st.top1;
    while(topOfSt1 != -1) {
        cout << st.arr[topOfSt1] << " -> ";
        topOfSt1--;
    }

    cout << "(bottom)" << endl;

    if(st.top2 == st.size) {
        cout << "stack 2 is empty" << endl;
        return;
    }

    cout << "printing stack 2: (top) ";
    int topOfSt2 = st.top2;
    while(topOfSt2 < st.size) {
        cout << st.arr[topOfSt2] << " -> ";
        topOfSt2++;
    }

    cout << "(bottom)" << endl << endl;
}

int main() {

    TwoStack ts(5);

    ts.push1(1);
    ts.push1(2);
    ts.push1(3);
    ts.push2(4);
    ts.push2(5);
    ts.push2(1);

    printTwoStack(ts);

    return 0;
}