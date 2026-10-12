# alu-low_level_programming

Low-level programming and algorithms in C, written for the ALU Software
Engineering programme.

Each directory is one project. Code is compiled on Ubuntu 20.04 LTS with:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

All C source follows the Betty coding style, checked with `betty-style.pl`
and `betty-doc.pl`.

## Projects

| Directory | Description |
|---|---|
| `hello_world` | The C compilation process, and printing with `printf`, `puts` and `putchar` |
| `variables_if_else_while` | Variables, operators, `if`/`else`, `while` loops and the ASCII table |
| `functions_nested_loops` | Functions, prototypes, header files and nested loops |
| `pointers_arrays_strings` | Pointers, arrays, strings and how they differ |
| `recursion` | Recursive functions: base cases, the call stack and helper functions |
| `malloc_free` | Dynamic memory with `malloc` and `free`: allocating at run time and freeing it |
