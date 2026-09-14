# C - Functions, nested loops

Third project in C. Code moves out of `main` into separate functions, every
function is declared in a header file, and loops run inside other loops. The
standard library is off limits for output, so everything is printed one
character at a time with `_putchar`.

## Background

**Nested loops.** A loop inside another loop runs to completion on every pass
of the outer one. `jack_bauer` runs its minute loop 60 times for each of the 24
hours, which makes 1440 lines of output.

**Declaration and definition.** A declaration gives the compiler a function's
name, return type and parameters. A definition is a declaration with a body. A
function can be declared any number of times but defined only once.

**Prototypes.** A prototype is a declaration that ends in `;`, such as
`int add(int a, int b);`. With the course flags, calling a function that has no
prototype in sight stops the build: gcc reports an implicit declaration and
`-Werror` turns the warning into an error.

**Scope.** A variable declared inside a function exists only inside that
function, so two functions can each have their own `n` without a clash. Global
variables are not allowed in this project.

**Header files.** `main.h` holds the prototype of `_putchar` and of every
function here. Each file pulls it in with `#include "main.h"`. The quoted form
searches the directory of the including file first; the angle bracket form, as
in `#include <stdio.h>`, searches only the system directories. The include
guard (`#ifndef MAIN_H`) stops the prototypes being read twice when the header
is included more than once.

**The gcc flags.** `-Wall` and `-Wextra` turn on common and extra warnings,
`-pedantic` adds every warning strict ISO C demands, `-Werror` makes each
warning an error, and `-std=gnu89` selects C89 with GNU extensions. One result:
a variable declared after a statement in the same block does not compile, gcc
reports `ISO C90 forbids mixed declarations and code`.

**Negative last digits.** `-1024 % 10` is `-4` in C, so `print_last_digit`
flips the remainder to positive before printing it. Flipping the remainder
rather than the number keeps `INT_MIN` safe, because `-INT_MIN` overflows.

## Files

| File | Description |
|---|---|
| `main.h` | Prototypes for `_putchar` and every function in this project |
| `0-putchar.c` | Prints `_putchar`, followed by a new line |
| `1-alphabet.c` | `print_alphabet`: prints the lowercase alphabet, using `_putchar` twice |
| `2-print_alphabet_x10.c` | `print_alphabet_x10`: prints the lowercase alphabet 10 times |
| `3-islower.c` | `_islower`: returns 1 if a character is lowercase, 0 otherwise |
| `4-isalpha.c` | `_isalpha`: returns 1 if a character is a letter, 0 otherwise |
| `5-sign.c` | `print_sign`: prints `+`, `0` or `-` and returns 1, 0 or -1 |
| `6-abs.c` | `_abs`: returns the absolute value of an integer |
| `7-print_last_digit.c` | `print_last_digit`: prints the last digit of a number and returns it |
| `8-24_hours.c` | `jack_bauer`: prints every minute of the day, from `00:00` to `23:59` |
| `9-times_table.c` | `times_table`: prints the 9 times table, starting with 0 |
| `10-add.c` | `add`: returns the sum of two integers |
| `11-print_to_98.c` | `print_to_98`: prints every integer from `n` to 98, separated by `, ` |

## Usage

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 9-main.c 9-times_table.c -o times_table
$ ./times_table | head -3 | cat -e
0,  0,  0,  0,  0,  0,  0,  0,  0,  0$
0,  1,  2,  3,  4,  5,  6,  7,  8,  9$
0,  2,  4,  6,  8, 10, 12, 14, 16, 18$
```

`_putchar.c` and the `N-main.c` test files are not part of this directory. The
checker compiles each task with its own copies of both.

## Environment

Ubuntu 20.04 LTS, gcc, Betty style.

## Author

Wisdom Okechukwu
