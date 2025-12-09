## Linked List Problems

### 1. Reverse a linked list using recursion
- Example of `recursiveCall_2()`
- Linked List: `Node(10) -> Node(20) -> Node(30) -> Node(40) -> Node(50) -> NULL`

    ```
    recursiveCall_2(10)
    recursiveCall_2(20)
    recursiveCall_2(30)
    recursiveCall_2(40)
    recursiveCall_2(50) [base case reached 50 -> next == NULL]
    ```

    ```
    recursiveCall_2(50) return newHead = Node 50
    recursiveCall_2(40)
        head = 40, newHead = 50

        head -> next -> next = head;
        40 -> next is 50
        50 -> next = NULL (so attach this next pointer to Node 40)
        50 -> next = 40

        Overall picture of LL: 10 -> 20 -> 30 -> 40 <- 50 (head)
                                            (40 -> next = NULL) 
    ------------------------------------------------------------------
    recursiveCall_2(30)
        head = 30, newHead = 50

        head -> next -> next = head;
        30 -> next is 40
        40 -> next = NULL (so attach this next pointer to Node 30)
        40 -> next = 30

        Overall picture of LL: 10 -> 20 -> 30 <- 40 <- 50 (head)
                                    (Now, 30 -> next = NULL ) 
    -----------------------------------------------------------------
    Final Output: 10 <- 20 <- 30 <- 40 <- 50 (newHead)
    ```

### 2. Reverse Linked List in K Groups (Recursive)
Linked List:
```
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL
```
Group size: `k = 4`

- Step 1: First recursive call (nodes 1–4)
    Reverse first 4 nodes:
    ```
    4 -> 3 -> 2 -> 1 -> NULL
    ```
    - `forward = 5`
    - Connect `1->next = recursiveCall(5, k)`

- Step 2: Second recursive call (nodes 5–8)
    Reverse next 4 nodes:
    ```
    8 -> 7 -> 6 -> 5 -> NULL
    ```
    - `forward = 9`
    - Connect `5->next = recursiveCall(9, k)`

- Step 3: Third recursive call (node 9)
    Only one node left:
    ```
    9 -> NULL
    ```
    - Return node `9`.

- Step 4: Backtracking connections
    - In 2nd call: `5->next = 9` →
        ```
        8 -> 7 -> 6 -> 5 -> 9 -> NULL
        ```
    - In 1st call: `1->next = 8` →
        ```
        4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5 -> 9 -> NULL
        ```
- Final Linked List
    ```
    4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5 -> 9 -> NULL
    ```

Complexity: 
- Time: O(n) (each node visited once)
- Space: O(n/k) recursive calls → O(n) in worst case

### 3. Clone a Linked List
- In your original list, each node’s random points to some other node in the original list.

- When you build the clone list, you create new nodes with the same data, but they are different objects in memory.

- If you simply do: 
    ```cpp
    cloneNode->random = originalNode->random;
    ```
    then the clone’s random will point back to the original node, not the corresponding clone node. 
    
    → That means your cloned list is not independent; it still depends on the original list.

- **What the map does?**
    - The map unordered_map<Node*, Node*> oldToNewNode stores:

        - Key: pointer to an original node.

        - Value: pointer to the corresponding cloned node.

    - So when you set:
    ```cpp
    cloneNode->random = oldToNewNode[originalNode->random];
    ```
    you’re saying:

    - “Take the original node’s random pointer, find the corresponding clone node in the map, and set the clone’s random to that clone node.”

    This ensures the cloned list’s random pointers point within the cloned list, not back into the original list.

Example:
- Without `map`
    ```
    1'.random = 3   (original node!)
    2'.random = 1   (original node!)
    ...
    ```

- With `map`
    ```
    1'.random = 3'   (clone node ✅)
    2'.random = 1'   (clone node ✅)
    3'.random = 5'   (clone node ✅)
    ...
    ```

### 4. Merge two sorted arrays:
- dry run of my approach
    <img src="mergeTwoSortedLL-my approach.jpg" >

- Below method is used in merge sort LL question,
    <img src="mergeTwoSortedLL-loveBabberApproach.jpg" >

### 5. Merge Sort
Example: 

Linked List: `4 -> 1 -> 6 -> 3 -> 5 -> 2 -> NULL`

```
                        4 -> 1 -> 6 -> 3 -> 5 -> 2 -> NULL
                                Mid = Node (6)
                                /            \
            4 -> 1 -> 6 -> NULL              3 -> 5 -> 2 -> NULL
                Mid = Node (1)                   Mid = Node (5)
                /         \                      /            \
    4 -> 1 -> NULL      6 -> NULL        3 -> 5 -> NULL        2 -> NULL
      Mid = Node (4)                       Mid = Node (3)
        /      \                             /       \
4 -> NULL   1 -> NULL                 3 -> NULL     5 -> NULL


---------------- MERGE PHASE (returning) ----------------

   Merge(4,1) → 1 -> 4
   Merge((1->4),6) → 1 -> 4 -> 6

   Merge(3,5) → 3 -> 5
   Merge((3->5),2) → 2 -> 3 -> 5

   Merge((1->4->6), (2->3->5)) → 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
```