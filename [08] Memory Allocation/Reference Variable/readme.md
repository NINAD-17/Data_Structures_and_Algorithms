# Reference Variable

## Reference Variable
- Same memory but can have different names.
- Create
```
int i = 5;
int &j = i; // Reference variable j is created
```
In this example, the memory block where `5` contain for that block 2 names are mapped `i` and `j` in symbol table.

- **Why we need Reference Variable?**
    - In functions, whenever we pass values from argument they *pass by value*. In *pass by value* it always create copy of that value in function. So changes made in that function for that value doesn't change in original value but it only change in that copied value which is limited to that function.
    - To directly change value (which pass to function) after function execution we need to use reference variable.
    Example:
    ```
    void passByReference(int &n) {
        n++; // Change directly in main function's 'a' variable.
    }
    ```
    Here variable `n` is passed by reference means it's a variable which is pointing to same memory location which is in the main function.
    Means, if `passByReference(a);` is a call then `n` and `a` are two names of that same memory location.

## Pass by value VS Pass by Reference
- In *pass by ref.* no new memory is created. But in *pass by value* a copy is created.
- In *pass by ref* memory is same but name is different.

## Using reference variable as return in output
**Note: It's a bad practice** reason given below.
```
int& update(int n) {
    int a = 10;
    int &ans = a; // Storing value of a i.e 10 in ans variable.
    return ans; // returning ans variable as a reference.
}
```
Here, `ans` variable is returning as a reference means, when in main function variable `a` in which output value is going to be store it's now second name of `ans` variable.

- Here is a big mistake is that, lifespan of local variable is limited to the function only. After that they will not be able to accessible. So when `update()` function's block gets over and memory gets cleared, there is nothing remaining to pass. So it's very dangerous. 


## Extra Notes:
- **Case 1:** Keep `foo(int &p)` and call with `foo(*p)`
    ```cpp
    void foo(int &p) {}

    int main() {
        int i = 5;
        int *p = &i;

        foo(*p);   // dereference pointer, pass the int itself
    }
    ```
    - `*p` gives you the actual int stored at the address.
    - `foo(int &p)` expects a reference to an int.
    - So `p` inside `foo` becomes an alias for `i`.
    - No new memory, just another name for `i`.

- **Case 2:** Change function to take a pointer
    ```cpp
    void foo(int *p) {}

    int main() {
        int i = 5;
        int *p = &i;

        foo(p);   // pass the pointer itself
    }
    ```
    - `foo(int *p)` expects a pointer to int.
    - You pass `p`, which is already an `int*`.
    - Inside `foo`, you can access the value with `*p`.
    - Here you’re passing the address, not the int itself.

- Key difference:
    - `foo(int &p)` → parameter is an alias for the int variable.
    - `foo(int *p)` → parameter is a pointer storing the address of the int.
    Both are valid, but they mean different things:
    - Reference version: “I want direct access to the variable itself.”
    - Pointer version: “I want the address, and I’ll dereference it if I need the value.”