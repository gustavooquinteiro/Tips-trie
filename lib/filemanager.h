#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#define SUGGEST_FILE "suggestions.txt"
#define READ_MODE "r"
#define WRITE_MODE "w"
#define APPEND_MODE "a"
#define TRUE 1
#define FALSE 0


FILE * open(char* mode);
void write(char * text);
void read();
int delete();
void close (FILE * file);
char *append(char *orig, char c);

#endif
