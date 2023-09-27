#include <stdio.h>
#include <string.h>

void is(char* str) {
    int count = 0;
    char* ptr = str;

    while (*ptr != '\0') {
        if (strstr(ptr, "is") == ptr) {
            count++;
        }
        ptr++;
    }
    printf("The String %s has \"is\" %d times", str, count);
}

int main() {
    char* str = "Hello is is Hello";

    is(str);
    return 0;
}







