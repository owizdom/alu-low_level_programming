# C - File I/O

Ninth project in C. A program reaches files through file descriptors: small integers the kernel hands back from `open`. Every later `read`, `write` and `close` names the file by that number. These calls are system calls, not part of the C standard library.

## Background

### File descriptors

Every process starts with three open descriptors: `STDIN_FILENO` (0), `STDOUT_FILENO` (1) and `STDERR_FILENO` (2), defined in `<unistd.h>`. `open` returns the lowest free number, so the first file a program opens usually gets 3. It returns -1 when it fails.

### Flags and permissions

The second argument to `open` combines flags with a bitwise OR. `O_RDONLY`, `O_WRONLY` and `O_RDWR` set the access mode. `O_CREAT` creates the file if it is missing, `O_TRUNC` empties an existing file, and `O_APPEND` moves every write to the end. With `O_CREAT`, the third argument sets the permissions of a new file: `0600` is `rw-------` and `0664` is `rw-rw-r--`. The process umask clears bits from that mode, so `0664` under umask 022 gives `rw-r--r--`. An existing file keeps the permissions it already has.

### Short reads and writes

`read` returns the number of bytes it read, 0 at the end of the file, and -1 on error. `write` can write fewer bytes than asked. Every function here compares the count `write` returns with the count it was given and treats any difference as a failure.

### cp exit codes

`cp` exits with 97 when it does not get exactly two arguments, 98 when it cannot open or read `file_from`, 99 when it cannot create or write `file_to`, and 100 when `close` fails. It opens `file_from` first, so a missing source never creates or truncates `file_to`. It reads in blocks of 1024 bytes.

## Files

| File | Description |
|---|---|
| `main.h` | Prototypes for every function and `_putchar` |
| `0-read_textfile.c` | `read_textfile`: prints up to `letters` bytes of a file and returns the count |
| `1-create_file.c` | `create_file`: creates or truncates a file with mode `rw-------` and writes a string |
| `2-append_text_to_file.c` | `append_text_to_file`: appends a string to an existing file |
| `3-cp.c` | `cp`: copies one file to another, 1024 bytes at a time |

## Usage

```
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-cp.c -o cp
$ ./cp incitatous Incitatous
$ ls -l Incitatous
-rw-rw-r-- 1 julien julien 158 Dec  3 15:39 Incitatous
$ ./cp nosuchfile copy
Error: Can't read from file nosuchfile
$ echo $?
98
```

The `N-main.c` test files for tasks 0 to 2 are not part of this directory. The checker compiles each task with its own copies.

## Environment

Ubuntu 20.04 LTS, gcc, Betty style.

## Author

Wisdom Okechukwu
