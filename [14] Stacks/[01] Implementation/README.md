# Stack

## `std::stack`
- `std::stack` in C++ is a container adaptor.

- By default, it uses `std::deque` as the underlying container (though you can choose `std::vector` or `std::list`).

- So the complexity of stack operations depends on the underlying container.

- With deque (the default), all stack operations are amortized **O(1)**.

- Space: Each operation uses O(1) extra space. The total space of the stack is **O(n)**, where n = number of elements stored.