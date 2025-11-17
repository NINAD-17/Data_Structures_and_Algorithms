# CPP STL Library

## What is STL?
- STL (Standard Template Library) is a collection of generic classes and functions in C++ that provide common data structures and algorithms.
- It saves you from writing everything from scratch — you get ready‑made, efficient implementations of containers, iterators, and algorithms.
- STL is built on three pillars:
    - **Containers** → data structures (like arrays, vectors, sets, maps).
    - **Iterators** → objects that behave like pointers, used to traverse containers.
    - **Algorithms** → functions like sort, find, count, reverse, etc., that work with containers via iterators.

### Containers
A container is simply an object that stores a collection of elements. They are implemented as class templates, so you can store any type (int, string, custom class, etc.).

In C++, a container is a holder object that stores a collection of other objects (its elements). Containers are implemented as class templates, which allows great flexibility in the types supported as elements. The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers).

- 1. **Sequence Container**
    - Array, Vector, Deque, List ...
- 2. **Container Adaptors**
    - Stack, Queue, Priority Queue ...
- 3. **Associative Containers**
    - Set, Map, Multimap ...
- 4. **Unordered Associative**
    - Unordered Set, Unordered Map, Unordered Multiset ...


### Implementation

1. **Array**
    - First include `<array>` liabrary.
    - Normal Array ==> `int basic[3] = {4, 5, 6};`
    - STL Array ==> `array<int, 4> arr = {1, 2, 3, 4};`
    - As both are same(static arrays) we're not using STL Array.

2. **Vector**
    - It's a dynamic array. Like array, it's also store data in contiguous memory locations. 
    - When vector gets full, vector will double its size (one vector is fully filled then new vector will be created that will be double its size and then old will be copied to new one and the old one will be deleted)
    - 'Shrink to fit' operation is used to decrease the size.

3. **Double Ended Queue**
    - It means you can apply push and pop, insertion and deletion at the begining and end.
    - Data isn't stored in contiguous memeory location, instead it has multiple fixed static arrays and tracking takes place that your data is stored in which array. (Complex implementation)
    - It's dynamic, so size can increase.

4. **List**
    - By the use of Double Linked List, 'List' STL has been made.
    - We can't able to access an element directly, we need to travel to reach there.

5. **Iterators**
    - An iterator is an object that can be used to traverse a container, such as a list or vector, and access its elements. Iterators are a major feature of the Standard Template Library (STL) in C++, and they provide a way to abstract the process of accessing elements in a container, regardless of the underlying data structure.
    - `Name.begin()` points at 1st position.
    - `Name.end()` points at last + 1 position.

    - Difference between `i+1` and `i++`
    In vector it++ == it+1 cause contiguous, hence next position is same, but
    For non-contiguous (maps, sets) if you use it+1 it gives you compilation error cause next location isn’t always vectors location.

6. **Pairs**
    - To use the pair class from the C++ Standard Template Library (STL), you need to include the `<utility>` header file in your code.

7. **Stack**
    - Last in First out

8. **Queue**
    - First in First out

9. **Priority Queue** 
    -  It is a type of container adapter, specifically designed such that the **first element of the queue is either the greatest or the smallest** of all elements in the queue, depending on the ordering used
    - Priority queues are implemented using a heap data structure, and use an array or vector as an internal structure

10. **Set**
    - `set` is a type of associative container in which each element has to be unique because the value of the element identifies it.
    - The values are stored in a specific sorted order i.e. either ascending or descending.
    - By default, the std::set is sorted in ascending order. However, we have the option to change the sorting order by using the following syntax: `std::set <data_type, greater<data_type>> set_name;`
    - `set` is slower than `unordered set`. In unordered set elements are not in sorted order.
    - std::map and std::set use bidirectional iterators, which do not support the it+1 operation. Attempting to use it+1 with a bidirectional iterator will result in a compilation error.
        Example:
        ```
        s.erase(s.begin() + 2); // It will not work

        s.erase(next(s.begin(), 2)); // Instead use this method
        ```
    - `s.count(5)` this method checks that if 5 is present or not.
    - `s.find(5)` if element is exist then it will return iterator of that element.

11. **Map**
    - Map can store data in key value form.
    - All keys are unique and each key will point only one value.

12. **Unordered Map**
    - If in any question order isn’t matter then use unordered only cause time complexity is O(1).

13. **Algorithm**
    - `sort` function is based on intro sort. 
    - Intro sort is a combination of quick sort, heap sort and insertion sort.
    - To sort array in decreasing order -> `sort(arr, arr + n, greater<int>());`

    `max` VS `max_element`
    - `std::max` is a function that returns the maximum value of two or more elements. It can be used with any type that supports comparison using the `<` operator or a custom comparison function. For example, you can use `std::max` to find the maximum value of two integers like this: `int max_value = std::max(3, 5);`
    - `std::max_element` is a function that returns an iterator pointing to the maximum element in a range of elements. It is defined in the `<algorithm>` header and can be used with any container that supports forward iterators, such as arrays, vectors, lists, etc. The comparisons can be performed either using the `<` operator or a custom comparison function. For example, you can use `std::max_element` to find the maximum value in a vector of integers like this: `auto max_value = *std::max_element(v.begin(), v.end());`
    - `std::max` is used to find the maximum value of two or more elements, while `std::max_element` is used to find the maximum element in a range of elements.

14. **Lower and Upper Bound**
    - Array or Vector must be sorted to work in O(log(n)) complexity otherwise it'll work as O(n) complexity.
    - `std::lower_bound` and `std::upper_bound` are two functions in the C++ Standard Template Library (STL) that can be used to perform binary searches on sorted ranges
    - `std::lower_bound` returns an iterator pointing to the first element in the range `[first, last)` that is not less than (i.e. greater or equal to) the given value. If no such element is found, the function returns an iterator pointing to the end of the range.
    - `std::upper_bound`, on the other hand, returns an iterator pointing to the first element in the range` [first, last)` that is greater than the given value. If no such element is found, the function also returns an iterator pointing to the end of the range.
    - both functions return location/ iterator of that element.
    - **Note:** 
        For `set` and `map` don't use `suto it = upper_bound(s.begin(), s.end(), num);` because it's `O(n)` function for set and map.
        Instead use it as `auto it = s.lower_bound(num);`
        For `map` lower and upper bound only applies to key.


## Lambda Function
```
    // Lambda Function
    // Ex. If you want to add 2 in an integer
    // [](int x){return x + 2;} is the function
    // (2) is for call
    cout << "Lamda Function -> sum: " << [](int x, int y){return x + y;}(2, 3) << endl;

    // To reuse this function, assign it to a variable
    auto sumL = [](int x, int y){return x + y;};
    cout << "Lamda Function -> sum function: " << sumL(2, 6) << endl;
```


15. **all_of**
    - return true if all element satisfy a condition
    ```
    vector<int> v_l = {2, 3, 5};
    cout << "All Of: " << all_of(v_l.begin(), v_l.end(), [](int x){return x > 0;}); // ans is true
    ```

    Or you can use,
    ```
    bool isPositive(int x) {
        return x > 0;
    }

    int main() {
        vector<int> v_l = {2, 3, 5};
        cout << "All Of: " << all_of(v_l.begin(), v_l.end(), isPositive); 
    }
    ```

16. **any_of**
    - If any element satisfy a condition then o/p is true

17. **none_of**
    - If all elements not satisfied a condition then only o/p is true.


### Iterator: 
- An iterator is an object that behaves like a pointer but is not always a raw memory address.
- It’s a general mechanism in C++ STL to traverse containers (like vector, set, map).
- Think of it as: “a cursor pointing to an element inside a container.”
- For simple containers like vector, iterators are often implemented as raw pointers internally (so yes, they directly represent memory addresses).
- For complex containers like set or map (which are tree-based), iterators are objects that internally store information about the node in the tree. They aren’t just plain addresses, but they still behave like pointers.
- So: iterators act like pointers, but they may be more complex under the hood.
    - Without *, itr itself is just the iterator object (like a pointer variable).
    - With *, you dereference it to get the actual element.