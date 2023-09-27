#include <stdio.h>
#define SIZE 2 
int main()
{
  int m=SIZE, n=SIZE, p=SIZE, q=SIZE, c, d;
  int first[SIZE][SIZE], second[SIZE][SIZE], addition[SIZE][SIZE];
  
  printf("the number of rows of matrix 1 must be the same as the number of columns of matrix 2\n");
 
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
 
    printf("addition of entered matrices:-\n");
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", addition[c][d]);
 
      printf("\n");
    }
 
    printf("the address of the additon 2_D matrix: \n"); 
    printf("%p\n",addition);
    printf("the address of the 1-d arry of pointers of 2_d matrix:-\n");
     for(c=0; c<m;c++)
	    printf("%p\t",(addition+c));
	   
    printf("\n");
    printf("the addresses of the elements of the addition matrix: \n");
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%p\t", (*(addition+c)+d));
 
      printf("\n");
    }
 
  return 0;
}

 