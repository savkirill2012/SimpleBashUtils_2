#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int flag_b;
    int flag_e;
    int flag_n;
    int flag_s;
    int flag_t;
    int flag_v;
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
                error_flag = add_gnu_flags_to_struct(flags, consol_input[i]);
            } else {
                error_flag = add_flags_to_file_struct(flags, consol_input[i]);
            }
        } else {
            //add file
        }

        if (error_flag == -1) {
            break;
        } 
    }

    return error_flag;
}

int add_flags_to_file_struct(Flags_cat *flags, const char *row) {
    int error_flag = 0;
    int len = strlen(row); 

    for (int i = 1; i < len; i++) {
        switch (row[i]) {
            case 'e': 
                flags->flag_e = 1;
                flags->flag_v = 1; 
                break;
            case 'E': flags->flag_e = 1; 
                break;
            case 'b': flags->flag_b = 1;
                break;
            case 'n': flags->flag_n = 1; 
                break;
            case 's': flags->flag_s = 1;
                break;
            case 't': flags->flag_t = 1;
                break;
            case 'v': flags->flag_v = 1;
                break;
            default: error_flag = -1;
        }

        if (error_flag == -1) {
            printf("Error can't search the flag %c\n", row[i]);
            break;
        }
    }

    return error_flag;
}

int add_gnu_flags_to_struct(Flags_cat *flags, const char *row) {
    int error_flag = -1;
    char *gnu_flags[] = {"--number-nonblank", "--number", "--squeeze-blank"};

    for (int i = 0; i < 3; i++) {
        if (strcmp(row, gnu_flags[i]) == 0) {
            switch (i){
                case 0: flags->flag_b = 1;
                    break;
                case 1: flags->flag_n = 1;
                    break;
                case 2: flags->flag_s = 1;
                    break;
            }
            
            error_flag = 0;
            break;
        }
    }

    if (error_flag == -1) {
        printf("Can't find this flag: %s\n", row);
    }

    return error_flag;
}