/**
 * C program to print source code of itself as output
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fptr;
	char ch;

	/**
	 * __FILE__ is a macro that contains path of current file.
	 * Open current program in read mode.
	 */
	fptr = fopen(__FILE__,"r");

	/* fopen() return NULL if unable to open file in given mode */
	if(fptr==NULL)
	{
		/* Unable to open file hence exit */
		printf("\nUnable to open file.\n");
		printf("Please check whether file exists and you have read prviledge.\n");
		exit(EXIT_FAILURE);
	}

	/* Read file character by character */
	while((ch = fgetc(fptr))!=EOF)
	{
		printf("%c",ch);
	}

	/* Close files to release resources */
	fclose(fptr);

	return 0;
}
