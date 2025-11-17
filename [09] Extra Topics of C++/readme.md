# Macros

- `#include <iostream>` it's called preprocessor directive. It means before compilation of our program, file which you've included will be copied to your code. Code which you've written related to it was reffered from it.
- Ex. `cout` is defined in file called `iostream`
- **Directives:** In C++, a directive is a one-line command that instructs the compiler to preprocess information before compilation. Directives are also known as preprocessors.
- Directives begin with the # (hash) symbol, followed by a pre-processor instruction. For example, #include, #define, #ifdef, #elif, and #error.

## Define a Macro
- Macro is a piece of code in a program that is replaced by value of macro.
- Macro is defined by `#define` directive.
- Example: `#define PI 3.14`. 
- This means that during preprocessing, the preprocessor will replace all occurrences of `PI` with `3.14`. This can be particularly useful for defining constants that are used multiple times throughout your code.
- Example: `#define AREA(l, b) (l * b)` Whenever the compiler finds `AREA(l, b)` in the program it replaces it with the macros definition i.e., `(l*b)`.

- Function-like macros:  These macros are the same as a function call. It replaces the entire code instead of a function name. Pair of parentheses immediately after the macro name is necessary. If we put a space between the macro name and the parentheses in the macro definition, then the macro will not work. 


# Global Variables
- If you've a variable and you wanted to share it between functions then use either reference variable or you also can able to use global variables
- If you've defined a variable in a function then it's a local variable its scope is only in that function. After that function, that variable gets free.
- Don't use globle variables. It's a BAD PRACTICE.
- Its disadvantage is that, it can be changed by any functions. Therefore, always use reference variable instead.

# Tertiary Operator
```
if(condition)
    .....
else
    .....
```
Above code can be written in single line as,
`(condition)? true_answer: false_answer`
If condition gets true then true_answer will print else false_answer


# Inline Functions in C++

- **Purpose**: Inline functions are primarily used to minimize the overhead of function calls. They serve as an optimization technique in C++.

- **Functionality**: When an inline function is called, the entire body of the function gets inserted or substituted at the point of the function call. This substitution is performed by the C++ compiler at compile time.

- **Performance**: When executing a program, functions are stacked in a specific order. For instance:
    ```
    | function2() |
    | function1() |
    |   main()    |
    ```
  Each time `function1()` and `function2()` are called, there is a small performance hit due to the time and memory required to manage the function calls. Inline functions help mitigate this by reducing the need for such calls.

- **Compiler Handling**: It's important to note that declaring a function as inline is merely a request to the compiler, not a command. The compiler has the discretion to ignore this request.

- **Comparison with Macros**: In an inline function, when you've called that function at compilation time, that calling function changes to the actual function body. This behavior is similar to that of macros.

- **Limitations**: If a function body contains only one line, then the compiler will likely accept it as an inline function if you declare it as such. If it contains 2 or 3 lines, then it depends on the compiler whether it will be accepted as an inline function. If it contains more than 3 lines, then the compiler will likely not accept it as an inline function.

# Default Arguments in C++

- **Purpose**: Default arguments are used when you want to make an argument optional. This can simplify function calls and provide sensible defaults.

- **Functionality**: Consider the function `void print(int *arr, int size, int start = 0)`. Here, the `start` argument is optional. We've set its default value as 0. So, if a call to this function doesn't pass a value for the `start` argument, it will use the default value of 0.

- **Order of Arguments**: It's important to note that default arguments should always start from the rightmost argument. For instance, declaring a function as `void print(int *arr, int size = 5, int start)` is not valid in C++. The `start` argument here does not have a default value, which prevents `size` from having a default value.


# Constant Keyword
- Whenever const keyword is attached with any method(), variable, pointer variable, and with the object of a class it prevents that specific object/method()/variable to modify its data items value.
- The const variable cannot be left un-initialized at the time of the assignment.
- It cannot be assigned value anywhere in the program.
- Example: `const int num = 10;`
