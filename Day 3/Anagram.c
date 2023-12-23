#include <stdio.h>
#include <string.h>

int isAnagram(const char *s, const char *t) {
    if (strlen(s) != strlen(t)) {
        return 0; // False
    }
    int i,freq_s[256] = {0};
    for (i = 0; s[i] != '\0'; i++) {
        freq_s[(int)s[i]]++;
    }
    for (i = 0; t[i] != '\0'; i++) {
        freq_s[(int)t[i]]--;
        if (freq_s[(int)t[i]] < 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    char s[100], t[100];
    printf("Enter the first string: ");
    scanf("%s", s);
    printf("Enter the second string: ");
    scanf("%s", t);
    if (isAnagram(s, t)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }
    return 0;
}

