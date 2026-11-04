# C - Function pointers

Eighth project in C. A function pointer holds the address of a function, so a function can be passed as an argument, stored in a variable or in a structure, and called later through that pointer.

## Background

### Declaring a function pointer

`void (*f)(char *)` declares `f` as a pointer to a function that takes a `char *` and returns nothing. The parentheses around `*f` matter: without them, `void *f(char *)` declares a function that returns a `void *`. A function's name on its own evaluates to its address, so `print_name("Bob", print_name_as_is)` and `array_iterator(array, 5, &print_elem)` both pass a pointer.

### Calling through a pointer

`f(name)` calls the function `f` points to. Tasks 0 to 2 never print or compare anything themselves. They call the function they are given, so the caller decides what happens to each value. Each one does nothing, or returns `-1`, when a pointer argument is `NULL`.

### A table of functions

The calculator in task 3 keeps an array of `op_t` structures, each pairing an operator string with the function that performs it. `get_op_func` walks the array until the operator matches and returns that entry's function. The last entry is `{NULL, NULL}`, so an unknown operator stops the walk there and returns `NULL`. The return type `int (*get_op_func(char *s))(int, int)` reads as: a function taking a `char *` that returns a pointer to a function taking two `int`s and returning an `int`.

### calc errors

`calc` prints `Error` and exits with status 98 when it does not get exactly three arguments, 99 when the operator is not one of `+ - * / %`, and 100 when `/` or `%` has a divisor of 0. Each check runs before any operation, so nothing divides by zero.

## Files

| File | Description |
|---|---|
| `function_pointers.h` | Prototypes for tasks 0 to 2 and `_putchar` |
| `0-print_name.c` | `print_name`: prints a name with the function given |
| `1-array_iterator.c` | `array_iterator`: runs a function on each element of an array |
| `2-int_index.c` | `int_index`: returns the index of the first element a comparison function accepts |
| `3-calc.h` | The `op_t` structure and every prototype for the calculator |
| `3-op_functions.c` | `op_add`, `op_sub`, `op_mul`, `op_div` and `op_mod` |
| `3-get_op_func.c` | `get_op_func`: returns the function that matches an operator |
| `3-main.c` | `main` for the `calc` program |

## Usage

```
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-op_functions.c 3-get_op_func.c -o calc
$ ./calc 1024 '*' 98
100352
$ ./calc 1024 '\*' 98
Error
$ ./calc 1 / 0
Error
$ echo $?
100
```

The `N-main.c` test files for tasks 0 to 2 are not part of this directory. The checker compiles each task with its own copies.

## Environment

Ubuntu 20.04 LTS, gcc, Betty style.

## Author

Wisdom Okechukwu
