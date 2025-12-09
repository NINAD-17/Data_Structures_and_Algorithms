# Linked List

## Destructor Logic
- In C++, the destructor `~Node()` is automatically called when you delete a `Node*`.

- If you write `~Node() {}`, then yes, the node’s memory will still be freed when you call delete node;.

- The body { ... } is optional — you only put cleanup logic there if you need to free other resources (like dynamically allocated memory inside the object Ex - `next`).

So:
```cpp
~Node() {}
```
will still delete the node itself. The `{}` block is only for extra cleanup.

- **Destructor Logic**:
    ```cpp
    ~Node() {
        int data = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "memory freed for node with data " << data << endl;
    }
    ```
    - When a node is destroyed, it checks if `next` is not `NULL`.
    - If so, it calls `delete next;`.
    - That triggers the destructor of the `next` node.
    - That node’s destructor will in turn delete its own next.
    - This continues recursively until the end of the list.
    👉 This is a recursive chain deletion. If you delete the head node, the destructor will cascade and delete the entire linked list.

### Default Destructor VS Custom Destructor
* **Default Destructor** (`~Node(){}`):
    - When you call `delete curr;`, only the memory for that single node is freed.
    - Its members (`data`, `next`) are destroyed, but pointers are not followed.
    - So `next` is just a pointer value that becomes invalid (dangling). It does not automatically delete the node it points to.
* **Custom Destructor**
    - We explicitly wrote `if(this->next != NULL) delete next;`.
    - That means when you delete one node, it recursively deletes the entire chain of nodes reachable via `next`.
    - This is why forgetting `curr->next = NULL` before delete curr; wipes out the rest of the list.

### Example
1. Using custom destructor
    Linked List: `20 -> 60 -> 10 -> 30`
    - Here, using `deleteNode()` function we're deleting node `60`.
    - If we skip/comment `curr -> next = NULL` line and used only `delete curr;` then destructor (custom) will called. 
    - As `next` isn't null it'll recursively called deletion of `next`. So, destructor of `next` node will be called. Means `60 -> next` is Node `10`.
    - `10 -> next` is also not NULL so destructor of `30` (`next` node) will be called.
    - `30 -> next` is NULL so it'll be deleted then it'll return to 10 then `this -> next = NULL;` by this line, `10 -> next` will also point to null so it'll also be deleted and similary `60` will be deleted.
    - But now if we try to `print(head)`, it will work incorrectly as `20 -> next = 10` but Node `10` is already freed. Traversing the list leads to undefined behavior (often infinite loop or crash), because you’re following dangling pointers.

2. Using default destructor
- When you call delete curr;, only that single node’s memory is freed.
- The next pointer is destroyed as a member, but it does not delete the node it points to.
- So if you forget curr->next = NULL, the rest of the list is still intact.
- prev->next continues to point to the next node, and traversal works fine.