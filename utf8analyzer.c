#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

char* is_ascii(char string[]) {
        // Implement is_ascii in the body of this function!
        int result = 0;
        for(int i = 0; i < strlen(string); i++){
                if((string[i] & 0b10000000) == 0){
                        result += 1;
                }

        }
        if(result == strlen(string)){
        return "true";
        }
        return "false";
}


char* capitalize_ascii(char str[]) {
        // Implement capitalize_ascii in the body of this function!
        char* result = str;
        for(int i = 0; i < strlen(str); i++){
                if(str[i] >= 'a' && str[i] <= 'z'){
                        int new = (str[i]-'0') + (int)16;
                        result[i] = ((char)new);   
                }

       }
        return result;
}


int get_str_length(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}


int32_t utf8_num_codepoints(char str[]) {
int32_t count = 0;

for(int i = 0; i < strlen(str); i++){

if(((unsigned char)str[i] & 0b11100000) == 0b11000000 |
                ((unsigned char)str[i] & 0b10000000) == 0 |
                ((unsigned char)str[i] & 0b11110000) == 0b11100000 |
                ((unsigned char)str[i] & 0b11111000) == 0b11110000){
count++;
}


}
return count;
}


uint32_t get_codepoint(const unsigned char *str, int *index) {
    uint32_t codepoint = 0;
    unsigned char c = str[*index];
    int len = 0;

    if ((c & 0x80) == 0x00) { // 1-byte
        codepoint = c;
        len = 1;
    } else if ((c & 0xE0) == 0xC0) { // 2-byte
        codepoint = ((c & 0x1F) << 6) |
                    (str[*index + 1] & 0x3F);
        len = 2;
    } else if ((c & 0xF0) == 0xE0) { // 3-byte
        codepoint = ((c & 0x0F) << 12) |
                    ((str[*index + 1] & 0x3F) << 6) |
                    (str[*index + 2] & 0x3F);
        len = 3;
    } else if ((c & 0xF8) == 0xF0) { // 4-byte
        codepoint = ((c & 0x07) << 18) |
                    ((str[*index + 1] & 0x3F) << 12) |
                    ((str[*index + 2] & 0x3F) << 6) |
                    (str[*index + 3] & 0x3F);
        len = 4;
    } else {
        codepoint = c;
        len = 1;
    }

    *index += len;
    return codepoint;
}    
   


void print_utf8_codepoints(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        uint32_t cp = get_codepoint((const unsigned char *)str, &i);
        printf("%u\n", cp); 
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }

    // implement the UTF-8 analyzer here
	printf("Valid ASCII: %s\n", is_ascii(argv[1]));
	printf("Uppercased ASCII: %s\n", capitalize_ascii(argv[1]));
	printf("Length in bytes: %d\n", get_str_length(argv[1]));
	printf("Number of codepoints: %d\n", utf8_num_codepoints(argv[1]));

	print_utf8_codepoints(argv[1]);
}
