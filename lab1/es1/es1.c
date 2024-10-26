#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cercaRegexp(char *src, char *regexp);

int main(void) {
    char *src = (char *) malloc(10 * sizeof(char));
    char *regexp = (char *) malloc(10 * sizeof(char));
    
    strcpy(src, "ciao");
    strcpy(regexp, "c.ao");

    char *result = cercaRegexp(src, regexp);
    if (result) {
        printf("Match found: %s\n", result);
    } else {
        printf("No match found.\n");
    }

    free(src);
    free(regexp);
    return 0;
}

char *cercaRegexp(char *src, char *regexp) {
    int i, j, src_len = strlen(src), regexp_len = strlen(regexp);
    
    for (i = 0; i <= src_len - regexp_len; i++) {
        int found = 1;
        for (j = 0; j < regexp_len; j++) {
            if (regexp[j] == '.') {
                // Any character matches
                continue;
            } else if (regexp[j] == '[') {
                // Match character class
                int class_found = 0;
                j++; // Move past '['
                while (regexp[j] != ']' && regexp[j] != '\0') {
                    if (src[i + j - (regexp_len - 1)] == regexp[j]) {
                        class_found = 1;
                    }
                    j++;
                }
                if (!class_found) {
                    found = 0;
                    break;
                }
            } else if (regexp[j] != src[i + j]) {
                found = 0;
                break;
            }
        }
        
        if (found) {
            return &src[i]; // Return the starting address of the match
        }
    }
    
    return NULL; // No match found
}
