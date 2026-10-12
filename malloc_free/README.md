# C - malloc, free

Sixth project in C. Every function here asks the system for memory at run time
with `malloc`, uses it, and gives it back with `free`. The size of each block is
decided while the program runs, not when it is compiled.

## Background

### The heap

Automatic variables live on the stack and disappear when a function returns.
When a function must return memory that outlives the call, such as a new string
or a grid, it takes that memory from the heap with `malloc` and returns a
pointer to it. The caller owns it until it calls `free`.

### Allocating

`malloc(n)` reserves `n` bytes and returns a pointer to the first one, or `NULL`
when the request cannot be met. Every allocation is multiplied by the size of
its element, for example `malloc(sizeof(int) * width)`, so the count is right on
any platform. Each function checks the returned pointer against `NULL` before
using it.

### Freeing

Each block from `malloc` is freed exactly once. `create_array`, `_strdup` and
`str_concat` return one block, so the caller frees one pointer. `alloc_grid`
returns an array of row pointers, so `free_grid` frees every row first and then
the array itself, in that order.

### Failure in the middle

`alloc_grid` allocates the row array and then one row at a time. When a row
allocation fails partway through, the rows already allocated are freed and the
row array is freed before returning `NULL`, so a failed call leaks nothing.

### Empty and null input

A size of 0 returns `NULL`. A `NULL` string passed to `_strdup` returns `NULL`.
A `NULL` string passed to `str_concat` is treated as the empty string, so
concatenating with `NULL` copies the other string.

## Files

| File | Description |
|---|---|
| `main.h` | Prototypes for every function in this project |
| `0-create_array.c` | `create_array`: allocates an array of chars set to one char |
| `1-strdup.c` | `_strdup`: returns a newly allocated copy of a string |
| `2-str_concat.c` | `str_concat`: returns a new string holding `s1` then `s2` |
| `3-alloc_grid.c` | `alloc_grid`: returns a 2D grid of ints, each element set to 0 |
| `4-free_grid.c` | `free_grid`: frees a grid created by `alloc_grid` |

## Usage

```
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-alloc_grid.c -o 3-alloc_grid
$ ./3-alloc_grid
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 

0 0 0 98 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 402 0 
```

The `N-main.c` test files are not part of this directory. The checker compiles
each task with its own copies.

## Environment

Ubuntu 20.04 LTS, gcc, Betty style.

## Author

Wisdom Okechukwu
