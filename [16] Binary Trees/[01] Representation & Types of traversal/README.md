# Binary Trees Implementation

## Inorder Preorder Postorder

### Efficiency

- **Recursive**: O(n) time, O(h) space (stack depth = tree height).

- **Iterative**: O(n) time, O(h) space (explicit stack).

- Both are equally efficient in big‑O terms.

- Iterative avoids function call overhead and stack overflow risk for very deep trees.

- Recursive is simpler and more readable.


## Function Call Overhead
- When you call a function (especially recursively), the program must:

- Push a stack frame onto the call stack.

- That frame stores:

    - Return address (where to continue after the function finishes).
    
    - Local variables.
    
    - Parameters passed to the function.

    - Bookkeeping info for the runtime.

This extra work is called **function call overhead**. It’s not just the memory, but also the CPU instructions needed to manage the stack.

### Stack Overflow vs Overhead
- **Overhead** = the small cost of setting up and tearing down each function call.

    - Example: in recursion, every node visited adds a frame, even though the logic is simple.

**Stack Overflow** = when recursion goes too deep (like in a skewed tree with millions of nodes), the call stack exceeds its maximum size and the program crashes.

So:

- Function call overhead ≠ crash.

- Overhead is the extra cost per call.

- Stack overflow is the extreme case when too many calls exceed memory.

### Why Iterative avoids this
- Iterative solutions use an explicit stack data structure (allocated in heap memory).

- Heap is usually larger and more flexible than the call stack.

- So iterative avoids both the overhead of repeated function calls and the risk of stack overflow.

**Function call overhead = the extra CPU + memory work for each recursive call.**

## Time and Space Complexity

### Iterative Inorder `./3_inorder_preorder_postorder_iterative.cpp`

#### Time Complexity:
- Each node is pushed once and popped once.

- Push = O(1), Pop = O(1).

- Printing = O(1).

- Total work = O(n).

👉 Even though it feels like you “visit” nodes twice (once when pushing, once when popping), that’s not O(n²).

It’s still constant work per node, so overall O(n).

#### Space Complexity
- Stack holds nodes along the current path.

- Maximum depth = tree height h.

- So space = O(h).

- Skew tree → O(n).

- Balanced tree → O(log n).

### Why not O(n²)?
- Your confusion is natural:

    - In recursion, you thought “returning” to a node might count as revisiting.

    - In iteration, you thought “push + pop” might count as two visits.

    But in complexity analysis, we count total operations.

    - Each node contributes a fixed number of operations (push, pop, print).

    - That’s O(1) per node.

    - Summed over n nodes → O(n).

So no quadratic blow‑up.