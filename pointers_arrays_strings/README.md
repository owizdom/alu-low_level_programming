# C - Pointers, arrays and strings

Fourth project in C. Functions receive addresses instead of values, so they can
change variables that belong to the caller. Strings are handled as arrays of
`char` ending in a null byte, walked one character at a time.

## Background

**Pointers.** A pointer holds the address of another variable. `&n` gives the
address of `n`, and `*p` reads or writes the value at the address in `p`.
`reset_to_98` and `swap_int` change their caller's variables this way. A
function that took plain `int` parameters would only change its own copies.

**Arrays.** An array is a fixed block of elements of one type, stored one after
another. `a[i]` is the same as `*(a + i)`. When an array is passed to a
function it decays to a pointer to its first element, which is why
`print_array` needs `n` to know where to stop.

**Pointers and arrays differ.** An array name is not a variable and cannot be
assigned to. `sizeof` on an array gives the size of the whole block, while
`sizeof` on a pointer gives the size of an address. A string literal such as
`"My School"` may sit in read-only memory, so `rev_string` is called on a
`char s[10]` array, which is a writable copy.

**Strings.** A C string is a `char` array ending in `'\0'`. Its length is not
stored anywhere, so `_strlen` counts characters until it reaches the null byte.
`_strcpy` copies that null byte too, or `dest` would not end where `src` does.

**Scope.** A variable declared inside a function exists only inside that
function. Global variables are not allowed in this project.

**Output.** Every task prints with `_putchar`, except `print_array`, where the
task allows `printf` and the checker's build line does not include
`_putchar.c`.

## Files

| File | Description |
|---|---|
| `main.h` | Prototypes for `_putchar` and every function in this project |
| `0-reset_to_98.c` | `reset_to_98`: sets the int a pointer points to, to 98 |
| `1-swap.c` | `swap_int`: swaps the values of two integers |
| `2-strlen.c` | `_strlen`: returns the length of a string |
| `3-puts.c` | `_puts`: prints a string, followed by a new line |
| `4-print_rev.c` | `print_rev`: prints a string in reverse, followed by a new line |
| `5-rev_string.c` | `rev_string`: reverses a string in place |
| `6-puts2.c` | `puts2`: prints every other character of a string, starting with the first |
| `7-puts_half.c` | `puts_half`: prints the second half of a string |
| `8-print_array.c` | `print_array`: prints `n` integers from an array, separated by `, ` |
| `9-strcpy.c` | `_strcpy`: copies a string, null byte included, and returns `dest` |

## Usage

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 4-main.c 4-print_rev.c -o 4-print_rev
$ ./4-print_rev
vomisA caasI - meht fo kcal eht raef I .sretupmoc raef ton od I
```

`_putchar.c` and the `N-main.c` test files are not part of this directory. The
checker compiles each task with its own copies of both.

## Environment

Ubuntu 20.04 LTS, gcc, Betty style.

## Author

Wisdom Okechukwu
