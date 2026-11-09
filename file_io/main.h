#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <sys/types.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void cp_fail(int code, char *name);
void cp_close(int fd);

#endif /* MAIN_H */
