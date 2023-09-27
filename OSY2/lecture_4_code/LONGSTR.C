/* A program to read in 5 strings and display the longest */

#include <stdio.h>
#include <string.h>

void main()
{
  char strings[5][81];								/* Array to hold strings */
  int index, index_of_longest;
  int longest_len = 0;

  /* Input the strings from the keyboard */
  printf("enter 5 strings \n");
  for (index = 0; index < 5; index++)
  {
	printf("\n Enter string%d: ", index+1);
	gets(strings[index]);
  }

  /* Now find the longest string */
  for (index = 0; index < 5; index++)
  {
	if (strlen(strings[index]) > longest_len)
	{
		longest_len = strlen(strings[index]);
		index_of_longest = index;
	}
  }

  printf("\nThe longest is %s\n", strings[index_of_longest]);
  printf("It contains %d characters", strlen(strings[index_of_longest]));
}
