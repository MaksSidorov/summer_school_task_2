#include "onegin.h"

int main() {

    FILE *input_file_pointer = fopen(DEFAULT_INPUT_FILENAME, "r");

    if (!input_file_pointer) {
        printf("Error opening file %s", DEFAULT_INPUT_FILENAME);
        return READ_FILE_ERROR;
    }
    
    char line_buffer[MAX_NUMBER_STRINGS][MAX_STRING_LENGTH];

    int lines_counter = 0;
    while (lines_counter < MAX_NUMBER_STRINGS) {
        if (my_fgets(line_buffer[lines_counter], MAX_STRING_LENGTH, input_file_pointer) != NULL) {
            lines_counter++;
        }
    }
    fclose(input_file_pointer);

    qsort(line_buffer, MAX_NUMBER_STRINGS, sizeof(char) * MAX_STRING_LENGTH, cmpfunc);

    FILE *output_file_pointer = fopen(DEFAULT_OUTPUT_FILENAME, "w");
    for(int i = 0; i < MAX_NUMBER_STRINGS; i++) {
        fprintf(output_file_pointer, "%s", line_buffer[i]);
    }

    return 0;
}
