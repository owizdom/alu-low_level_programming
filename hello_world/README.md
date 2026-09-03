# C - Hello, World

First project in C. It covers the four stages of the compilation process and
the basic ways of writing text to standard output.

## Background

Running `gcc main.c` is four steps, not one:

1. **Preprocessor** (`gcc -E`) resolves `#include` and `#define` and produces
   expanded source.
2. **Compiler** (`gcc -S`) turns that source into assembly.
3. **Assembler** (`gcc -c`) turns assembly into an object file.
4. **Linker** joins object files and libraries into an executable.

The default executable name when none is given is `a.out`.

## Files

| File | Description |
|---|---|
| `0-preprocessor` | Runs `$CFILE` through the preprocessor only, output to `c` |
| `1-compiler` | Compiles `$CFILE` without linking, producing a `.o` file |
| `2-assembler` | Generates the assembly of `$CFILE`, producing a `.s` file |
| `3-name` | Compiles `$CFILE` into an executable named `cisfun` |
| `4-puts.c` | Prints a line using `puts` |
| `5-printf.c` | Prints a line using `printf` |
| `6-size.c` | Prints the size in bytes of the basic C types using `sizeof` |

The shell scripts read the source file name from the environment variable
`CFILE` and are each exactly two lines long.

## Usage

```
$ export CFILE=main.c
$ ./3-name
$ ./cisfun

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 5-printf.c -o printf_demo
$ ./printf_demo
with proper grammar, but the outcome is a piece of art,
```

`6-size.c` reports the sizes of the machine it is compiled for, so `-m32` and
`-m64` give different answers for `long int`.

## Environment

Ubuntu 20.04 LTS, gcc, Betty style.

## Author

Wisdom Okechukwu
