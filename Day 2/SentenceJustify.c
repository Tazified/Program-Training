#include <stdio.h>
#include <string.h>
void justifySentence(char sentence[], int screenLength) {
 int length = strlen(sentence);
 int spaceCount = 0;
for (int i = 0; i < length; i++) {
 if (sentence[i] == ' ') {
 spaceCount++;
 }
 }
 int totalSpaces = screenLength - length + spaceCount;
 int spacesToAdd = totalSpaces / spaceCount;
 int extraSpaces = totalSpaces % spaceCount;
 for (int i = 0; i < length; i++) {
 if (sentence[i] == ' ') {
 for (int j = 0; j < spacesToAdd; j++) {
 printf("*");
 }
 if (extraSpaces > 0) {
 printf("*");
 extraSpaces--;
 }
 } else {
 printf("%c", sentence[i]);
 }
 }
 printf("\n");
}
int main() {
 char sentence[1000];
 int screenLength;
 printf("Enter the sentence: ");
 fgets(sentence, sizeof(sentence), stdin);
 printf("Enter the screen length: ");
 scanf("%d", &screenLength);
 printf("Justified Sentence:\n");
 justifySentence(sentence, screenLength);
 return 0;
}
