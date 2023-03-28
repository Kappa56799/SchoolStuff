#include <stdio.h>
#include <stdlib.h>

int main() {
    //declaring variables to prove stuff
    int *ptr;
    int num = 0;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    // Dynamically allocate memory 
    ptr = (int*)calloc(num, sizeof(int)); //float* is for floating-point 
  
    // Check if the memory has been successfully allocated
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return 0;
    }

    else {
        // Memory has been successfully allocated
        printf("Memory successfully allocated \n");
  
        // Get the elements of the array
        printf("Enter The values you want to input into the array: \n");
        for (int i = 0; i < num; ++i) {
            scanf("%d", &*(ptr + i)); //pointer notation same thing as ptr[i]
        }
  
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (int i = 0; i < num; ++i) {
            printf("%d, ", ptr[i]); //array notation same thing as *(ptr+i)
        }
    }
        // Get the new size for the array
        printf("Enter number of new elements: ");
        scanf("%d", &num);
    
        // Dynamically re-allocate memory using realloc()
        ptr = realloc(ptr, num * sizeof(int));
  
        // Memory has been successfully allocated
        printf("Memory successfully re-allocated using realloc.\n");

        // Get the elements of the array
        printf("Enter The values you want to input into the array: \n");
        for (int i = 0; i < num; ++i) {
            scanf("%d", &*(ptr + i)); //pointer notation same thing as ptr[i]
        }
  
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (int i = 0; i < num; ++i) {
            printf("%d, ", ptr[i]);
        }
  
        free(ptr); //frees call memory allocated
  
    return 0;
}

