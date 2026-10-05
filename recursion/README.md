# C - Recursion

Fifth project in C. Every function here calls itself instead of looping. Each
call works on a smaller version of the problem until it reaches a case it can
answer directly.

## Background

### Recursion

A recursive function calls itself. `_strlen_recursion` says the
length of a string is 1 plus the length of the string that starts one
character later.

### Base case

Every recursive function needs a case that returns without
calling itself, or the calls never stop. For the string functions it is the
null byte. For `factorial` and `_pow_recursion` it is 0, where the answer is 1.

### The call stack

Each call gets its own copy of its parameters, and waits
for the call it made to return. `_print_rev_recursion` uses that order: it
calls itself on the rest of the string first and prints its own character
after, so the last character is printed first.

### Helper functions

`_sqrt_recursion` and `is_prime_number` take one
argument, but the search needs a second one, the candidate being tried. Each
has a helper that carries it: `find_sqrt` and `has_divisor`.

### Stopping early

Both helpers stop when the candidate `i` passes the square
root of `n`. The test is `i > n / i` and not `i * i > n`, because `i * i` can
be larger than an `int` can hold.

### No loops

No function in this directory contains a loop statement.

## Files

| File | Description |
|---|---|
| `main.h` | Prototypes for `_putchar` and every function in this project |
| `0-puts_recursion.c` | `_puts_recursion`: prints a string, followed by a new line |
| `1-print_rev_recursion.c` | `_print_rev_recursion`: prints a string in reverse |
| `2-strlen_recursion.c` | `_strlen_recursion`: returns the length of a string |
| `3-factorial.c` | `factorial`: returns the factorial of a number, or -1 if it is lower than 0 |
| `4-pow_recursion.c` | `_pow_recursion`: returns `x` raised to the power of `y`, or -1 if `y` is lower than 0 |
| `5-sqrt_recursion.c` | `_sqrt_recursion`: returns the natural square root of a number, or -1 if it has none |
| `6-is_prime_number.c` | `is_prime_number`: returns 1 if the integer is a prime number, otherwise 0 |

## Usage

```
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 6-main.c 6-is_prime_number.c -o 6-prime
$ ./6-prime
0
0
0
1
0
0
1
1
```

`_putchar.c` and the `N-main.c` test files are not part of this directory. The
checker compiles each task with its own copies of both.

## Environment

Ubuntu 20.04 LTS, gcc, Betty style.

## Author

Wisdom Okechukwu
