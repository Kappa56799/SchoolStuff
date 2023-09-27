#include <stdio.h>

#define ROWS 3
#define COLS 3
int main() {
  int matrix[ROWS][COLS] = {{1,2,3},{4,5,6},{7,8,9}};
  int *pointer = matrix[0];
  
  //Prints Entire Matrix
  for(int i=0; i<ROWS*COLS; i++) {
    printf("%p ", (pointer+i));
  }
  
  printf("\n");

  //Also Prints the Entire Matrix
  for(int i=0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
  }
  
  printf("\n");
  
  //Same thing as before
  for(int i = 0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      printf("%d ", *(*(matrix+i)+j));
    }
  }

  printf("\n");
  
  //Displaying the array as a matrix
  for(int i=0; i<ROWS*COLS; i++) {
    if (i % ROWS == 0) {
      printf("\n");
    }
    printf("%p ", (pointer+i));
  }
  return 0;
}
