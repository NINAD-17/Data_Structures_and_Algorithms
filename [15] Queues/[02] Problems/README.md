# Queue

## 1. Find 1st Negetive integer
**Time complexity analysis**:
- Outer loop
    - The outer loop runs once for each window.
    - That’s about n iterations (actually n - k + 1, but we treat it as O(n)).

- Inner loop
    - Inside, we sometimes run an inner loop (while) to move the pointer p forward until it points to a negative number inside the current window.
    - At first glance, it looks like:
        - outer loop = 𝑛 × inner loop = up to 𝑛 → 𝑂(𝑛^2).
        - But here’s the trick:

- Key trick
    - The pointer p never moves backward.
    - Every time the inner loop runs, it only advances p forward.
    - Across all outer loop iterations, p can advance at most 𝑛 steps (because there are only 𝑛 elements).
    - So the total work of all inner loops combined is 

- Putting it together
    - Outer loop: O(n)
    - Inner loop (all iterations combined): O(n)
    - Total = O(n) + O(n) = O(n)

- Easy analogy: Think of the inner loop as a person walking forward along the array.
    - Outer loop asks: “Is the walker at the right spot for this window?”
    - Sometimes the walker moves forward a lot (like in the first iteration), sometimes not at all.
    - But the walker can only walk across the array once.
    - So total walking = 𝑛 steps, not 𝑛 steps per window.