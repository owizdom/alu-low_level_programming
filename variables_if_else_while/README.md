# C - Variables, if, else, while

Second project in C. It covers variable declaration and assignment, the
arithmetic, relational and logical operators, branching with `if` and
`if ... else`, and looping with `while`.

## Background

**Truth in C.** There is no boolean type in C89. `0` is false and every other
value is true, so `if (n)` and `if (n != 0)` are the same test.

**The ASCII character set.** A `char` is a small integer holding a character
code, so characters can be counted through: `'a' + 1` is `'b'`, and `'z' - 'a'`
is 25. That is what makes a whole alphabet printable with a single `putchar`
inside a loop. Digits work the same way, which is why `n + '0'` turns the
integer `7` into the character `'7'` without needing a `char` variable.

**Remainder keeps the sign of the dividend.** In C, `-3 % 10` is `-3`, not `7`.
The last-digit program prints negative digits for negative numbers for exactly
this reason.

**`-m32` and `-m64`** ask gcc to build a 32-bit or a 64-bit binary. Pointers and
`long` are 4 bytes under `-m32` and 8 bytes under `-m64`; `char`, `int`,
`unsigned int` and `float` are the same size either way.

## Files

| File | Description |
|---|---|
| `0-positive_or_negative.c` | Prints whether a random number is positive, zero or negative |
| `1-last_digit.c` | Prints the last digit of a random number and compares it to 5 and 0 |
| `2-print_alphabet.c` | Prints the lowercase alphabet, using `putchar` twice |
| `3-print_alphabets.c` | Prints the alphabet in lowercase then uppercase, using `putchar` three times |
| `4-print_alphabt.c` | Prints the lowercase alphabet without `e` and `q` |
| `5-print_numbers.c` | Prints the single digits of base 10 with `printf` |
| `6-print_numberz.c` | Prints the single digits of base 10 without any `char` variable |
| `7-print_tebahpla.c` | Prints the lowercase alphabet in reverse |
| `8-print_base16.c` | Prints the digits of base 16 in lowercase |
| `9-print_comb.c` | Prints every single-digit number separated by `, ` |

## Usage

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 8-print_base16.c -o base16
$ ./base16
0123456789abcdef

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 9-print_comb.c -o comb
$ ./comb | cat -e
0, 1, 2, 3, 4, 5, 6, 7, 8, 9$
```

`0-positive_or_negative` and `1-last_digit` seed from `time(0)`, so two runs in
the same second print the same number.

## Environment

Ubuntu 20.04 LTS, gcc, Betty style.

## Author

Wisdom Okechukwu
