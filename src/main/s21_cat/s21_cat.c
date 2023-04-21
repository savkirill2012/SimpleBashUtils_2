#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int flag_b;
    int flag_e;
    int flag_n;
    int flag_s;
    int flag_t;
    char **file_names;
} Flags_cat;



int main(int argc, char **argv) {


    return 0;
}

int get_flags_from_consol_input(Flags_cat *flags, const int num_elem, const char **consol_input) {
    int error_flag = 0;

    for (int i = 1; i < num_elem; i++) {
        if (consol_input[i][0] == '-') {
            if (consol_input[i][1] == '-') {
                //check for flag
            } else {
                //check for flag
            }
        } else {
            //add file
        } 
    }

    return error_flag;
}

int add_flags_to_file_struct(Flags_cat *flags, const char *row) {
    int error_flag = 0;
    int len = strlen(row); 

    for (int i = 1; i < len; i++) {
        switch (row[i]) {
            case 'e': /* add flag*/ break;
            case 'b': /* add flag*/ break;
            case 'n': /* add flag*/ break;
            case 's': /* add flag*/ break;
            case 't': /* add flag*/ break;
            case 'v': /* add flag*/ break;
            default: error_flag = -1;
        }

        if (error_flag == -1) {
            printf("Error can't search the flag %c\n", row[i]);
            break;
        }
    }

    return error_flag;
}
