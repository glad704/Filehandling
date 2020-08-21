/**
 * C program to read a file and display file contents character by character
 * using fgetc()
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
	/* File pointer to hold reference to our file */
	FILE* fptr;
	char ch;

	/*
	 * OPen file in r(read) mode.
	 * file1.txt is complete file path to read
	 */
	fptr = fopen("file1.txt","r");

	/* fopen() return NULL If last operation was unsuccessful */
	if(fptr == NULL)
	{
		/* Unable to open file hence exit */
		printf("Unable to open file.\n");
		printf("Please check whether file exists and you have read privilage.\n");
		exit(EXIT_FAILURE);
	}

	/* File open success message */
	printf("File opened successfully. Reading file contents character by character.\n\n");

	do
	{
		/* Read single character from file */
		ch = fgetc(fptr);

		/* Print character read on console */
		putchar(ch);
	}while(ch!=EOF);	/* Repeat this if last read character is not EOF */

	/* Done with this file, close file to release resource */
	fclose(fptr);

	return 0;
}
	
