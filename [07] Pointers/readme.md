# Pointers

## Mapping of Variable Name and Address
- A **Symbol Table** is a crucial data structure created and maintained by the compiler to keep track of the semantics of variables. It stores information about the scope and binding information about names, instances of various entities such as variable and function names, classes, objects, etc.
- For example, `int num = 5;` Here, `num` is mapped to the address of a memory location where `5` is stored.  `num ----> address`
- `cout << num << endl;` In this case, it first finds the address mapped to the `num` variable and then prints the content from that address (here it is `5`).
- It maps names (like num) to metadata:
    - Variable type (int, double, etc.)
    - Scope (local, global, class member…)
    - Storage class (static, extern…)
    - Address (where in memory the variable lives at runtime)
- Example: 
    ```cpp
    int num = 5;
    ```
    Symbol Table Entry:
    ```
    name: num
    type: int
    scope: local
    address: 0x61fee4
    ```

## 'Address of' Operator (&) 
- It can be used to find the address of any variable mapped to it.
- It provides the address in Hexadecimal format.
- For example: `cout << "Address of num: " << &num << endl;`

## Pointers (*)
- Pointers are used to store addresses in a variable.
- Example: `int *ptr = &num;`
- *Note: Do not create pointers without initializing them.* If you do so, it will point to an unknown memory location (which is a BAD PRACTICE).
For example: `int *ptr;`
- Instead, if you don't know where to point, initialize that pointer with zero.
For example: `int *ptr = 0;` After that, if you want to point it to a location then use `ptr` only. Don't give `*` before it. For example: `ptr = &var_name;`
- `int *ptr` means that `ptr` is a pointer to the `int` data type.

## De-reference Operator (*)
- It means that whenever you access `*var_name` then it will give you content stored in that address (which is stored in pointer variable).
For example: `cout << *ptr << endl;` means it will give you output `5` if `int num = 5;`.

- For any data types, a pointer will always store the address of a memory location, therefore its **size will always be `8 bytes`**. 
    - On modern 64‑bit systems, a pointer is 8 bytes because it must hold a 64‑bit memory address.
    - On 32‑bit systems, a pointer is 4 bytes.
    - Important: pointer size is independent of the type it points to.
        - int*, char*, double* → all 8 bytes on 64‑bit.

- **Copying a Pointer into Another Pointer**:
```
int *e = &num;
int *f = e;
```

- **If You Increment an Address Then**:
    - For example: `int *ptr = &num;`
    - If you did `ptr = ptr + 1;` and assume the address of `ptr` as `101`;
    - Then it will become `105`, meaning it will move to the next integer (the size of an integer is 4 bytes therefore `101 + 4 = 105`)


## Pointers in Array
- `int arr[10];` Here size of array is `10 * 4 (size of int) = 40 bytes`.
- Name of the array points to first location of that array. 
    Example: Here array name is `arr` which is point to `arr[0]` memory location.
- You can also access memory location by using **Address of** operator as `&arr[0]` or `&arr`.

**How compiler computes `arr[i]`?**
- Formula: `arr[i] = *(arr + i)`
- Example: Assume first location of array as `102`. So now `arr[2] = *(102 + (2 * 4))` Here `4` is the size of `int`. So `arr[2] = *(110)`. And `110` is the address of 2nd index of array.
- OR above formula can also be written as, `i[arr] = *(arr + i)`
- *Note: `arr[i]` & `i[arr]` both are same.*

- **NOTE**: Content of symbol table can't be changed.
    - Example: `arr = arr + 1;` It's not possible. (ERROR)
    ```
    int *ptr = &arr[0];
    ptr = arr + 1; // It's possible
    ```

## Pointers in Char Arr
- For `int` array and `char` arr, `cout` function is differently implemented.
- For `int` array, `cout << arr;` will print address of 1st array element. But in case of `char` array, `cout << ch;` will print all characters from `char` array.
- In `char` array if you create a pointer and point it to `char` array's first element and if you use `cout << pointer_name;` then it will not show you address of first element of `char` array but it will show you all characters from that array until it gets '\0' element.

```
    char ch2 = 'A';
    char *chPtr2 = &ch2;
    cout << "Printing content of ch2 using pointer: " << chPtr2 << endl; 
```
- As we know, &ch2 give value of ch2 and not address of ch2. So when we try to print chPtr2, then compiler will start to show all the content from ch2 until it get `'\0'` character. So it will give you random output after printing ch2 content. Ex. `A��a`.
- Behind the scenes -> 
    1. `char ch[6] = 'ABCDE';`: In this case, ABCDE will first stored in temporary memory as `ABCDE\0` and then it will copy to ch;
    2. `char *ptr = &ch[0];`: In this case, `ABCDE\0` stored in temp memory. and then first element's address will be given to `ptr`.
- So don't do this -> `*charPtr = &ch`;

- **Why cout << ch prints the whole string**
    - cout has an overload for const char* that treats it as a C-string (sequence of chars ending with '\0'). It prints characters until the null terminator.
    - cout << (void*)ch forces printing the address instead (no string interpretation).
    - **To force address printing for any pointer (including char*), cast to void**
        - Ex - `cout << (void*)ptr;`
- **Why cout << chPtr2 prints garbage after 'A'**
    - char ch2 = 'A'; is a single char, not a C-string (no '\0').
    - char* chPtr2 = &ch2; points to 'A' only. cout assumes char* is a C-string and keeps reading memory past 'A' until it randomly encounters '\0'. That’s why you see garbage.
- Concept used: 
    1. **C-String**: A C-string is a contiguous array of characters terminated by a null character '\0'.
    2. **Overloading**: Overloading is defining multiple functions/operators with the same name but different parameter types or counts.

## Pointers in functions
- When you pass array in a function then it not copy full array to that function but it passes a pointer of that array to function.
- So if you find size of that `arr` in function then it will give you output `8` because pointer stores memory address.
- You can also able to use `*arr` in parameter instead of `arr[size]`;
- Benefit of this (array can pass as pointer) is that we can also able to pass only part of array to a function as (arr + index). Index is a from which index you want to pass an array.


## Why we use pointers as `data_type *` & not as `pointer ptr`?
- As we define a variable as `int num;` we don't have option to create pointer as `pointer ptr = &num;`, we have to use `int *ptr = &num` only.
- We use `int *ptr` because it shows,
    - Which type of data stored in it?
    - How many bytes should consider to allocate memory   

# Double Pointers

- If you want to create pointer corresponding to a value Ex. `int i = 5` then you've to use `int* ptr = &i` and if you want to create a pointer corresponding to `ptr` then you've to use `int**`.
```
int i = 5;
int *ptr = &i;
int **Ptr2 = &ptr; // Double pointer
int ***ptr3 = &ptr2; // you can also able to use this three pointer and so on.
```
<img width=300 src="double_pointer.png" alt="Double pointer" />
 
In symbol table, <br>
<img width=300 src="symbol_table.png" alt="Symbol Table" />
