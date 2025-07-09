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


int32_t capitalize_ascii(char str[]) {
        // Implement capitalize_ascii in the body of this function!
        int32_t count = 0;
        for(int i = 0; i < strlen(str); i++){
                if(str[i] >= 'a' && str[i] <= 'z'){
                        int new = (str[i]-'0') + (int)16;
                        str[i] = ((char)new);
                        count++;
                }

        }
        return count;
}

int get_str_length(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}






int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }

    // implement the UTF-8 analyzer here
	printf("Valid ASCII: %s\n", is_ascii(argv[1]));
	printf("Uppercased ASCI: %c\n", capitalize_ascii(argv[1]));

}
