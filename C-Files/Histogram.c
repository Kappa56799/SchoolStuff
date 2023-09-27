#include <stdio.h>
#define SIZE 10

//Function Signatures
void Histogram(int arr[]);

int main() {
  int array[10] = {0}; //Our number Array

  //Gets user input
  for(int i = 0; i < SIZE; i++) {
    printf("Enter the number of stars you want to display on the histogram:\n");
    scanf("%d", &array[i]);
  }
  
  //Function call
  Histogram(array);
  return 0;
}

//Function to print Histogram,titles and values
void Histogram(int array[]) {
  //Prints titles
  printf("%-10s %-10s", "Value", "Histogram");
  
  //Prints values
  for(int i = 0; i < SIZE; i++) {
    printf("\n%-10d", array[i]);
    
    //Prints Histogram
    for(int j = 0; j < array[i]; j++) {
      printf("*");
    }
  }
}
