#include <stdio.h>
#include <string.h>

//function signature
int countWord(char string[], char word[]);

int main() {
    char string[] = "Hello World, Hello";
    char word[] = "Hello";
    int count = countWord(string, word);

    printf("'%s' appears %d times in '%s'\n", word, count, string);

    return 0;
}

int countWord(char string[], char word[]) {
    int count = 0;
    char *StringSplit;

    // Splits the string 
    StringSplit = strtok(string, " ");

    // Loop through the string, checking each split string for the word
    while (StringSplit != NULL) {
        if (strcmp(StringSplit, word) == 0) {
            count++;
        }
        // Get the next part of the string
        StringSplit = strtok(NULL, " ");
    }

    return count;
}
