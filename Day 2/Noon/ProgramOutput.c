#include <stdio.h>
#include <ctype.h>

int main() {

    char input[100], character;
    int count;

    printf("Enter input string: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; ++i) {
        character = input[i];

        if (isdigit(input[i + 1])) {

            sscanf(&input[i + 1], "%d", &count);

            for (int j = 0; j < count; ++j) {
                printf("%c", character);
            }

            int digitLength = 0;
            while (isdigit(input[i + 1 + digitLength])) {
                digitLength++;
            }

            i += digitLength;
        } else {

            printf("%c", character);
        }
    }

    printf("\n");

    return 0;
}
