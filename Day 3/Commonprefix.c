#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* result = "";
        return result;
    }
 int i,j;
    for (i = 0; strs[0][i] != '\0'; i++) {
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i] || strs[j][i] == '\0') {
                char* result = malloc(i + 1);
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }

}

int main() {
    char* strs1[] = {"flower", "flow", "flight"};
    printf("Output 1: %s\n", longestCommonPrefix(strs1, 3)); 

    char* strs2[] = {"dog", "racecar", "car"};
    printf("Output 2: %s\n", longestCommonPrefix(strs2, 3)); 

    return 0;
}

