#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50

void CompareWords(char[], char[]);
const char *AppendWord(char[]);
int CalculateLength(const char*);

int main() {
    char word1[SIZE], word2[SIZE];

    printf("Enter a word: \n");
    scanf("%s", &word1);

    printf("Enter another word: \n");
    scanf("%s", &word2);

    CompareWords(word1,word2);

    const char *newsentence = AppendWord(word1);
    printf("%s\n ", newsentence);

    int result = CalculateLength(newsentence); 
    printf("%d", result);
}

void CompareWords(char word3[], char word4[]) {
    if(strcmp(word3,word4) == 0) {
        printf("The word is the same!\n");
    }
    else {
        printf("The words are not the same.\n");
    }
}

const char *AppendWord(char word1[]) {
    char *sentence = (char*)calloc(30, sizeof(char));
    strcat(sentence, "First Word entered is: ");
    strcat(sentence, word1);

    return sentence;
}

int CalculateLength(const char *newsentence) {
    int result = 0;
    result = strlen(newsentence);

    return result;

}


