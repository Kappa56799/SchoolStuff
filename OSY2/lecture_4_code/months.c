/* A program to illustrate using an array of strings.

	The program stores the months of the year in an array and the
	displays them to the user */


#include <stdio.h>
void main()
{
	/* Define an array of strings */
	char *months[12] = {"January", "February", "March", "April", "May", "June",
							  "July", "August", "September", "October", "November",
							  "December" };

	int i;

	/* Display the months of the year using subscripts */
	printf("The months of the year are:\n\n");
	for(i = 0; i< 12; i++)
	  printf("%s\n", months[i]);
    
    
    /* Display the months of the year using pointer arithmetic */
	printf("The months of the year are:\n\n");
	for(i = 0; i< 12; i++)
	  printf("%s\n", *(months +i));
    
    

    
    
    // hold exe window open
        getchar();
}