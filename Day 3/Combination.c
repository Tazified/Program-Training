#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void generateCombinations(char* digits, int index, char* current, char** result, int* count) {
    if (index == strlen(digits)) {
        result[*count] = strdup(current);
        (*count)++;
        return;
    }
    int i;
	char* letters = mapping[digits[index] - '0'];
    for (i = 0; i < strlen(letters); i++) {
        current[index] = letters[i];
        generateCombinations(digits, index + 1, current, result, count);
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }
    int i,totalCombinations = 1;
    for (i = 0; i < strlen(digits); i++) {
        int digit = digits[i] - '0';
        totalCombinations *= strlen(mapping[digit]);
    }
    char** result = (char**)malloc(totalCombinations * sizeof(char*));
    char* current = (char*)malloc(strlen(digits) + 1);
    current[strlen(digits)] = '\0';
    int count = 0;
    generateCombinations(digits, 0, current, result, &count);
    *returnSize = count;
    free(current);
    return result;
}

int main() {
    int i;
	char digits[100];
    printf("Enter the string of digits: ");
    scanf("%s", digits);
    int size;
    char** result = letterCombinations(digits, &size);
    printf("Output:\n");
    for (i = 0; i < size; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}

