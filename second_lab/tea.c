#include <stdio.h>
#include <string.h>

#define GENERETE_KEY_ARGUMENT "generate_key"
#define ENCRYPT_FILE_ARGUMENT "encrypt"
#define DECRYPT_FILE_ARGUMENT "decrypt"



long long encrypt_part(long part[2], long key[4]) {

}

long long decrypt_part(long part[2], long key[4]) {

}

void encrypt(long key[4], FILE* input, FILE* output) {
    printf("popa");
}

void decrypt(long key[4], FILE* input, FILE* output) {
    printf("pisya");
}

int main(int argc, const char *argv[]) {
    if (argc == 2 && !strcmp(argv[1], GENERETE_KEY_ARGUMENT)) {
        printf(GENERETE_KEY_ARGUMENT);
    }

    else if (3 <= argc && argc <= 5) {
        const char *key = argv[2];
        FILE *input = stdin, *output = stdout;

        if (argc >= 4) {
            input = fopen(argv[3], "r");
            if (!input) {
                printf("Error while opening input file \"%s\"", argv[4]);
                return 0;
            }
        }

        if (argc >= 5) {
            output = fopen(argv[4], "w+");
            if (!output) {
                printf("Error while opening output file \"%s\"", argv[5]);
                return 0;
            }
        }

        if (!strcmp(argv[1], ENCRYPT_FILE_ARGUMENT)) {
            encrypt((long*)key, input, output);
        }
        else if (!strcmp(argv[1], DECRYPT_FILE_ARGUMENT)) {
            decrypt((long*)key, input, output);
        }
        else {
            printf("Unknown argument \"%s\"", argv[1]);
        }
    }
    else {
        printf("Arguments:\n");
        printf("\t%s\n", GENERETE_KEY_ARGUMENT);
        printf("\t%s key [input_file] [output_file]\n", ENCRYPT_FILE_ARGUMENT);
        printf("\t%s key [input_file] [output_file]\n", DECRYPT_FILE_ARGUMENT);
    }
}
