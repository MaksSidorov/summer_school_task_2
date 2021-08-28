#include "onegin.h"

char *my_fgets(char buffer_string[], int number_symbols, FILE *stream) {
    int c, is_only_back_n = 0;
    char *pointer = buffer_string;
    while ((c = getc(stream)) != EOF && number_symbols--) {
        *pointer = c;
        pointer++;
        if (c == '\n' && is_only_back_n)
            break;
        if (c == '\n')
            return NULL;
        is_only_back_n++;
    }
    *pointer = '\0' ;

    return (c == EOF && pointer == buffer_string && buffer_string) ? NULL : buffer_string;
}

int cmpfunc(const void * a, const void * b) {
    const char *p1 = (const char *) a, *p2 = (const char *) b;
    while (*p1 != '\0' && *p2 != '\0') {
        while (!isalpha (*p1) && !isdigit(*p1)) {
            p1++;
        }
        while (!isalpha (*p2) && !isdigit(*p2)) {
            p2++;
        }
        if (*p1 == *p2) {
            p1++;
            p2++;
        }
        else {
            if (*p1 > *p2) {
                return 1;
            }
            else {
                return -1;
            }
        }
    }
    if (*p1 == '\0') {
        return 1;
    }
    else if (*p1 != '\0' && *p2 == '\0') {
        return -1;
    }
    return 0;
}

int get_all_text(char line_buffer[], const char file_path[]) {
    FILE *input_file_pointer = fopen(file_path, "r");

    if (!input_file_pointer) {
        return READ_FILE_ERROR;
    }
    char line_buf[MAX_NUMBER_STRINGS][MAX_STRING_LENGTH];

    int lines_counter = 0;
    while (lines_counter < MAX_NUMBER_STRINGS) {
        if (my_fgets(line_buf[lines_counter], MAX_STRING_LENGTH, input_file_pointer) != NULL) {
            lines_counter++;
        }
    }

    fclose(input_file_pointer);

    return 0;
}


