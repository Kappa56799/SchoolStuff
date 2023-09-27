#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50

//Function prototype
const char *AppendWord(char word[]);

//Main function
int main() {
   //User String 
    char word[SIZE];

    //User Input
    printf("Enter a word: \n");
    fgets(word,SIZE, stdin);
    word[strcspn(word, "\n")] = '\0';

    //Function Call
    const char *newsentence = AppendWord(word);
    puts(newsentence);
}

//Function to return a String in C
const char *AppendWord(char word[]) {
    int length = strlen(word);
    char *sentence = (char*)malloc(sizeof(char) * length);
    strcat(sentence, "First Word entered is: ");
    strcat(sentence, word);

    return sentence;
}

