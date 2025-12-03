#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
char *create_buffer(const char *file);
void close_file(int fd);
void copy_file(const char *file_from, const char *file_to);
int main(int argc, char *argv[]);

#endif /* MAIN_H */
