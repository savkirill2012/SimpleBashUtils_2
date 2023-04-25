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
} FLAGS_CAT;

typedef struct {
    char ***file_names;
    int len;
} FILES_CAT;


int get_flags_and_files_from_consol_input(FLAGS_CAT *flags, FILES_CAT *files, const int num_elem, char **consol_input);
int add_flags_to_file_struct(FLAGS_CAT *flags, const char *row);
int add_gnu_flags_to_struct(FLAGS_CAT *flags, const char *row);
void add_file_to_struct(FILES_CAT *files, const char *row);


int main(int argc, char **argv) {

    //init
    FILES_CAT input_files;
    FLAGS_CAT input_flags;
 
    input_files.file_names = malloc(sizeof(char **) * 1);

    //main logic
    get_flags_and_files_from_consol_input(&input_flags, &input_files, argc, argv);

    //print flags
    if (input_files.len > 0) {
        printf("files: ");
        for (int i = 0; i < input_files.len; i++) {
           // printf("%s, ", (*(input_files.file_names) + i));
        }
        printf("\n");
    }
    // print files
    printf("flags: ");
    if (input_flags.flag_b == 1) {
        printf("b, ");
    } 
    if (input_flags.flag_e == 1) {
        printf("e, ");
    }
    if (input_flags.flag_n == 1) {
        printf("n, ");
    }
    if (input_flags.flag_s == 1) {
        printf("s, ");
    }
    if (input_flags.flag_t == 1) {
        printf("t, ");
    }
    if (input_flags.flag_v == 1) {
        printf("v, ");
    }

    return 0;
}

int get_flags_and_files_from_consol_input(FLAGS_CAT *flags, FILES_CAT *files, const int num_elem, char **consol_input) {
    int error_flag = 0;

    for (int i = 1; i < num_elem; i++) {
        if (consol_input[i][0] == '-') {
            if (consol_input[i][1] == '-') {
                error_flag = add_gnu_flags_to_struct(flags, consol_input[i]);
            } else {
                error_flag = add_flags_to_file_struct(flags, consol_input[i]);
            }
        } else {
            add_file_to_struct(files, consol_input[i]);
        }

        if (error_flag == -1) {
            break;
        } 
    }

    return error_flag;
}

int add_flags_to_file_struct(FLAGS_CAT *flags, const char *row) {
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

int add_gnu_flags_to_struct(FLAGS_CAT *flags, const char *row) {
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

/*void add_file_to_struct(FILES_CAT *files, const char *row) {
    size_t len_row = strlen(row);

    *(files->file_names) = realloc(files->file_names, sizeof(char *) * (files->len + 1));
    
    char *pointer_to_new_filename = *(*(files->file_names)) + files->len; 
    pointer_to_new_filename = realloc(pointer_to_new_filename, sizeof(char) * (len_row + 1)); 
    
    for (size_t i = 0; i < len_row; i++) {
        pointer_to_new_filename[i] = row[i];
    }
    pointer_to_new_filename[len_row] = '\0';

    files->len += 1;
}*/