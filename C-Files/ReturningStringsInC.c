/*
//question 1  (9)
#include <stdio.h>
#include <string.h>
#define SIZE 6

//** means pointer to pointer since we make our array a pointer to save on memory and we need pointers to allow the function to read them.
int NameSearch(char *, char **);

int main() {
    char *names[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank"};
    char searchName[20];
    int Namefound = 0;

    printf("Enter a name to search for: ");
    scanf("%s", &searchName);

    Namefound = NameSearch(searchName,names);

    if (Namefound) {
        printf("Hello %s!\n", searchName);
    } 
    else {
        printf("%s not found in the list.\n", searchName);
    }

    return 0;
}

//The function that reads the array until the name is found or not. 1 is returned if the 2 strings are the same meaning the name is found else 0 is returned
int  NameSearch(char *searchName, char **names) {
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(names[i], searchName) == 0) {
            return 1;
        }
    }
    return 0;
}
*/

/*
//question 1 (10)
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#define SIZE 4

int main() {
    char yourString[SIZE];
    int counter = 0;
    int converted = 0;
    int sum =0;

    printf("Enter a string with numbers and characters: ");
    scanf("%s", &yourString);

    for(int i = 0; i < SIZE; ++i) {
        if(!isdigit(yourString[i])) {
            printf("A character has been input");
            return 1;
        }
    }

    converted =  atoi(yourString);
    sum = converted + 1;
    printf("The converted + 1 is: %d\n", sum);

    return 0;
}
*/

/*
//question 1 (11)
#include <stdio.h>
#include <string.h>
#define SIZE 10

struct Country {
    char name[50];
    char capital[50];
};

int main() {
    char country[50];
    char *capital = 0;
    struct Country countries[SIZE] = {
        {"Australia, Canberra"},
        {"Belgium", "Brussels"},
        {"China","Beijing"},
        {"Denmark","Copenhagen"},
        {"England", "London"},
        {"France", "Paris"},
        {"Greece", "Athens"},
        {"Ireland", "Dublin"},
        {"Scotland", "Edinburgh"},
        {"Wales", "Cardiff"}
    };

    printf("Enter a country: \n");
    scanf("%s", &country);

    for(int i = 0; i < SIZE; ++i) {
        if(strcmp(country, countries[i].name) == 0) {
            capital = countries[i].capital;
            break;
        }
    }

    if(capital == 0) {
        printf("Error country not found in the list.\n");
        return 1;
    }

    printf("The capital of %s is %s. \n", country,capital);
    return 0;
}
/*

/*
//question 2
#include <stdio.h>
#include <string.h>
#define SIZE 60

int CountCharacters(char[]);
void AppendSentence(char[]);

int main() {
    char mySentence[SIZE];
    printf("Input a Sentence: ");
    fgets(mySentence,SIZE, stdin);
    mySentence[strcspn(mySentence, "\n")] = '\0';

    int counter = CountCharacters(mySentence);

    printf("The sentence has %d characters. \n", counter);

    AppendSentence(mySentence);
}

int CountCharacters(char sentence[]) {
    int counter = 0;
    for(int i = 0; i <strlen(sentence); ++i) {
        if (sentence[i] != ' ') {
            counter++;
        }
    }
    return counter;
}

char AppendSentence(char sentence[]) {
    char sentence2[35] = "My sentence is: ";
    char *newsentence;
    newsentence = strcat(sentence2,sentence);

    printf("%s", newsentence);
}
*/

//question 3
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


