

#include <stdio.h>

#define SIZE 3
 
int main()
{
  int m=SIZE, n=SIZE, p=SIZE, q=SIZE, c, d;
  int first[SIZE][SIZE], second[SIZE][SIZE], addition[SIZE][SIZE];
  
 
  printf("Enter the elements of first matrix\n");
 
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      {
      printf("enter the vlaue for row %d and col %d: ",c,d);	
      scanf("%d", &first[c][d]);
      }
 
 
    printf("Enter the elements of second matrix\n");
 
    for (c = 0; c < p; c++)
      for (d = 0; d < q; d++)
        {
	printf("enter the value for row %d and col %d: ",c,d);
        scanf("%d", &second[c][d]);
        }
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        
        addition[c][d] = first[c][d] + second[c][d];
      }
    }
	
	printf("the values of first matric:-\n");
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", first[c][d]);
 
      printf("\n");
    }
	
	printf("the values of the second matrix:-\n");
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", addition[c][d]);
 
      printf("\n");
    }
 
    printf("values of the addition matrices:-\n");
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", addition[c][d]);
 
      printf("\n");
    }
  
 
  return 0;
}
