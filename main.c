#include "onegin.h"

int main() {

    FILE *input_file_pointer = fopen(DEFAULT_INPUT_FILENAME, "r");

    fseek(input_file_pointer, 0L, SEEK_END);

    long file_size = ftell(input_file_pointer);
    char *text = (char *) calloc(file_size, sizeof(char));

    fseek(input_file_pointer, 0, SEEK_SET);

    fread(text, sizeof(char), file_size, input_file_pointer);

    int lines_counter = 0;
    for (char *str_pointer = text; str_pointer!=NULL && *str_pointer!='\0'; str_pointer=strchr(str_pointer+1, '\n') ){
        lines_counter++;
    }

    char **strings_pointers = (char **) calloc(lines_counter + 1, sizeof(char *));

    for (char *str_pointer = text, flag = 0; str_pointer!=NULL && *str_pointer!='\0'; str_pointer=strchr(str_pointer+1, '\n')){
        if (flag) {
            *strings_pointers = str_pointer + 1;
            *(*strings_pointers - 1) = '\0';
            strings_pointers++;
        }
        else {
            *strings_pointers = str_pointer;
            strings_pointers++;
            flag = 1;
        }
    }

    strings_pointers -= lines_counter;

    qsort(strings_pointers, lines_counter, sizeof(char*), cmpfunc);

    puts(*strings_pointers);

    FILE *output_file_pointer = fopen(DEFAULT_OUTPUT_FILENAME, "w");
    for(int i = 0; i < lines_counter; i++) {

        fprintf(output_file_pointer, "%s\n", *(strings_pointers + i));
    }


    return 0;
}
