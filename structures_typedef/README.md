# C - Structures, typedef

Seventh project in C. A structure groups several values of different types under one name, and `typedef` gives that type a shorter name. Every file here works with one structure, `struct dog`.

## Background

### struct dog

`struct dog` holds three members: `name` (`char *`), `age` (`float`) and `owner` (`char *`). It is declared in `dog.h` along with every prototype in this project. Members are reached with `.` on a structure and with `->` on a pointer to one.

### typedef

`typedef struct dog dog_t;` makes `dog_t` another name for `struct dog`. Both names refer to the same type, so a `dog_t *` can be passed wherever a `struct dog *` is expected.

### Pointers and copies

`init_dog` stores the pointers it is given, so the dog points at the caller's strings. `new_dog` allocates the dog and its own copies of `name` and `owner`, so the dog stays valid after the caller's strings change or go away. `free_dog` frees both copies and then the dog itself, which is 3 of the 4 heap blocks valgrind counts in task 5 (the 4th is the `stdout` buffer `printf` allocates).

### NULL handling

`print_dog` prints `(nil)` for a `NULL` name or owner and prints nothing for a `NULL` dog. `new_dog` returns `NULL` when `name` or `owner` is `NULL` or when any allocation fails, and it frees whatever it had already allocated before returning. `init_dog` and `free_dog` do nothing when given `NULL`.

## Files

| File | Description |
|---|---|
| `dog.h` | `struct dog`, the `dog_t` typedef and every prototype in this project |
| `1-init_dog.c` | `init_dog`: sets the members of an existing `struct dog` |
| `2-print_dog.c` | `print_dog`: prints a `struct dog`'s name, age and owner |
| `4-new_dog.c` | `new_dog`: allocates a new dog holding copies of name and owner |
| `5-free_dog.c` | `free_dog`: frees a dog created by `new_dog` |

## Usage

```
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-print_dog.c -o c
$ ./c
Name: Poppy
Age: 3.500000
Owner: Bob
```

The `N-main.c` test files are not part of this directory. The checker compiles each task with its own copies.

## Environment

Ubuntu 20.04 LTS, gcc, Betty style.

## Author

Wisdom Okechukwu
