#include <stdio.h>
#include <string.h>

#define min(a, b)  (a < b) ? a : b

#define GENERETE_KEY_ARGUMENT "generate_key"
#define ENCRYPT_FILE_ARGUMENT "encrypt"
#define DECRYPT_FILE_ARGUMENT "decrypt"

#define BLOCK_LENGTH 8
#define KEY_LENGTH 16
#define CYCLES_COUNT 32
#define SCHCEDULE_CONST 0x9e3779b9
#define DELTA_CONST 0xC6EF3720


void encrypt_block(int block[2], const int key[4]) {
    for (int i = 0; i < CYCLES_COUNT; i++) {
        int delta = (i + 1) * SCHCEDULE_CONST;
        block[0] += ((block[1] << 4) + key[0]) ^ (block[1] + delta) ^ ((block[1] >> 5) + key[1]);
        block[1] += ((block[0] << 4) + key[2]) ^ (block[0] + delta) ^ ((block[0] >> 5) + key[3]);
    }
}


void decrypt_block(int block[2], const int key[4]) {
    for (int i = 0; i < CYCLES_COUNT; i++) {
        int delta = DELTA_CONST - i * SCHCEDULE_CONST;
        block[1] -= ((block[0] << 4) + key[2]) ^ (block[0] + delta) ^ ((block[0] >> 5) + key[3]);
        block[0] -= ((block[1] << 4) + key[0]) ^ (block[1] + delta) ^ ((block[1] >> 5) + key[1]);
    }
}


void encrypt(const int key[4], FILE* input, FILE* output) {
    char block[BLOCK_LENGTH];
    while (fread(block, sizeof(char), BLOCK_LENGTH, input)) {
        encrypt_block((int*)block, key);
        fwrite(block, sizeof(char), BLOCK_LENGTH, output);
        memset(block, 0x01, BLOCK_LENGTH);
    }
}


void decrypt(const int key[4], FILE* input, FILE* output) {
    char block[BLOCK_LENGTH];
    while (fread(block, sizeof(char), BLOCK_LENGTH, input)) {
        decrypt_block((int*)block, key);
        fwrite(block, sizeof(char), BLOCK_LENGTH, output);
        memset(block, 0x01, BLOCK_LENGTH);
    }
}


FILE* open_file(int argn, int argc, const char *argv[], const char* mode) {
    FILE* file = fopen(argv[argn], mode);
    if (!file) {
        printf("Error while opening file \"%s\"\n", argv[4]);
        return NULL;
    }
    return file;
}


int main(int argc, const char *argv[]) {
    if (argc == 2 && !strcmp(argv[1], GENERETE_KEY_ARGUMENT)) {
    }
    else if (argc == 5) {
        int key[4];
        memset(key, 0, KEY_LENGTH);
        memcpy(key, argv[2], min(KEY_LENGTH, strlen(argv[2])));

        FILE *input = open_file(3, argc, argv, "rb");
        FILE *output = open_file(4, argc, argv, "wb+");
        if (!input || !output)
            return 0;

        if (!strcmp(argv[1], ENCRYPT_FILE_ARGUMENT)) {
            encrypt((int*)key, input, output);
        }
        else if (!strcmp(argv[1], DECRYPT_FILE_ARGUMENT)) {
            decrypt((int*)key, input, output);
        }
        else {
            printf("Unknown argument \"%s\"\n", argv[1]);
        }

        fclose(input);
        fclose(output);
    }
    else {
        printf("Arguments:\n");
        printf("\t%s\n", GENERETE_KEY_ARGUMENT);
        printf("\t%s [key] [input_file] [output_file]\n", ENCRYPT_FILE_ARGUMENT);
        printf("\t%s [key] [input_file] [output_file]\n", DECRYPT_FILE_ARGUMENT);
    }
}
