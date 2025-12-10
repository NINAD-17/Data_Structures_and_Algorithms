# Queue

## 1. Circular Queue:
### Why Circular Queue?

- In a linear array queue:

- If you only do front++ on dequeue, memory before front is wasted.

- If you shift elements left on each dequeue, you reclaim memory but at O(n) cost.

A circular queue solves this:

- Both front and rear move forward modulo size.

- When rear reaches the end, it wraps back to index 0 if space is available.

- This way, freed slots at the beginning are reused.

circular queue reuses memory by wrapping indices.

### Visualization
Let's assume `size = 5`

- **Case 1: Normal** (front <= rear)
    
    ```
    Enqueue 1,2,3
    front = 0, rear = 2
    Queue: [1,2,3,_,_]
    ```
    Print loop (front → rear) works fine.

- **Case 2: Wrap-around** (rear < front)

    ```
    Enqueue 1,2,3,4,5 → full
    Dequeue 1,2,3
    front = 3, rear = 4
    Queue: [_,_,_,4,5]

    Now enqueue 6,7
    rear wraps → rear = 1
    Queue: [6,7,_,4,5]
    front = 3, rear = 1
    ```
    
    Here the queue is logically:
    ```
    (front) 4 -> 5 -> 6 -> 7 (rear)
    ```