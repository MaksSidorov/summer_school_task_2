#ifndef UNTITLED3_ONEGIN_H
#define UNTITLED3_ONEGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static const char DEFAULT_INPUT_FILENAME[] = "C:\\Users\\maks_\\CLionProjects\\untitled3\\yevgeniy-onegin.txt";
static const char DEFAULT_OUTPUT_FILENAME[] = "C:\\Users\\maks_\\CLionProjects\\untitled3\\sorted-yevgeniy-onegin.txt";

static const int MAX_STRING_LENGTH = 70;
static const int MAX_NUMBER_STRINGS = 100;

enum ERRORS {
    READ_FILE_ERROR = 1,
};

char *my_fgets(char buffer_string[], int number_symbols, FILE *stream);
int cmpfunc(const void * a, const void * b);
int get_all_text(char line_buffer[], const char file_path[]);

#endif //UNTITLED3_ONEGIN_H
