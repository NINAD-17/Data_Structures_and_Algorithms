# Stack Problems

## 1. Reverse Stack using Recursion
- **visualization** (recursive tree):

    For simplicity assume `reverseStack()` as `rS()` and `insertAtBottom()` as `iB()`.

    ```
    rS([6,5,4,1,7])
    ├─ pop 6
    └─ rS([5,4,1,7])
        ├─ pop 5
        └─ rS([4,1,7])
            ├─ pop 4
            └─ rS([1,7])
                ├─ pop 1
                └─ rS([7])
                    ├─ pop 7
                    └─ rS([])
                        └─ base case → return []

                    iB([], 7)
                    └─ push 7 → [7]

                iB([7], 1)
                ├─ pop 7
                └─ iB([], 1)
                    └─ push 1 → [1]
                └─ push back 7 → [7,1]

            iB([7,1], 4)
            ├─ pop 7
            ├─ pop 1
            └─ iB([], 4)
                └─ push 4 → [4]
            └─ push back 1 → [1,4]
            └─ push back 7 → [7,1,4]

        iB([7,1,4], 5)
        ├─ pop 7
        ├─ pop 1
        ├─ pop 4
        └─ iB([], 5)
            └─ push 5 → [5]
        └─ push back 4 → [4,5]
        └─ push back 1 → [1,4,5]
        └─ push back 7 → [7,1,4,5]

    iB([7,1,4,5], 6)
    ├─ pop 7
    ├─ pop 1
    ├─ pop 4
    ├─ pop 5
    └─ iB([], 6)
        └─ push 6 → [6]
    └─ push back 5 → [5,6]
    └─ push back 4 → [4,5,6]
    └─ push back 1 → [1,4,5,6]
    └─ push back 7 → [7,1,4,5,6]
    ```

- **Time and Space complexity**:
    - **Time Complexity** = O(n²)
    - reverseStack(st):
        - Pops all n elements one by one → O(n) calls.
        - For each element popped, it calls insertAtBottom(st, element).
    - insertAtBottom(st, element):
        - In worst case, traverses the entire stack (depth = current size).
        - So for the 1st element, it traverses 1; for the 2nd, traverses 2; … up to n.
    - Total work:
        1 + 2 + 3 + ... + n = n(n + 1) / 2 = O(n<sup>2</sup>)

    --- 
    - **Space Complexity**:
    - When reverseStack calls insertAtBottom, the call stack of reverseStack is paused at that line.
    - Then insertAtBottom builds its own recursion stack.
    - But these aren’t additive in the sense of nested depth — they don’t stack on top of each other infinitely.
    - At any given moment, the maximum depth is bounded by O(n) (not O(n²)).
    - So yes, it’s like O(n + n) → O(n).

## 2. Redundant Brackets
**Complexity Analysis**:
- **Time Complexity**:
    - Outer loop scans the string once → O(n).
    - Inner while loop pops elements, but each element is pushed and popped at most once.
    - Total stack operations = O(n).
    - Final: O(n).

- **Space Complexity**:
    - Stack can hold up to n characters in worst case.
    - Final: O(n).

- **Key Insight**:  
    - Even though there’s a nested loop, the inner loop doesn’t run n times for each character.
    - Instead, across the whole string, every operator/bracket is popped once.
This **amortized analysis** keeps the complexity linear, not quadratic.

### Meaning of Amortized
- Amortized analysis looks at the average cost per operation over a sequence of operations, rather than the worst cost of a single operation.
- Even if some operations are expensive, they don’t happen often enough to make the overall cost high.
- So we “spread out” the expensive cost across many cheap operations.

**Example**:
- Suppose you push n elements onto a stack, then pop them all.
- Each push = O(1).
- Each pop = O(1).
- But if you look at one closing bracket in your redundant bracket problem, it might pop many elements at once. That single step looks costly.
- However, each element is popped only once overall.
- So across the whole string, total pushes + pops = O(n).
- That’s why we say the cost is amortized O(1) per operation.

**Real-world analogy**
- Imagine you buy a car for ₹10,00,000.
- If you look at the cost of “one drive,” it seems huge.
- But if you drive it 50,000 times, the cost per drive is ₹20.
- That’s amortization: spreading a big cost over many uses.