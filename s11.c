/**
 * C program to remove empty lines from a file
 */

#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 1000

/* Function declarations */
int isempty(const char* str);
void removeemptylines(FILE* srcfile,FILE* tempfile);
void printfile(FILE* fptr);

int main()
{
	FILE* srcfile;
	FILE* tempfile;
	char path[100];

	/* Input file path */
	printf("Enter file path: ");
	scanf("%s",path);

	/* Try to open file */
	srcfile = fopen(path,"r");
	tempfile = fopen("remove-blanks.tmp","w");

	/* Exit if file not opened successfully */
	if(srcfile == NULL || tempfile == NULL)
	{
		printf("Unable to open file.\n");
		printf("Please check you have read/write priviledge.\n");
		exit(EXIT_FAILURE);
	}

	printf("\nFile contents before removing all empty lines.\n\n");
	printfile(srcfile);

	/* Move src file pointer to beginning */
	rewind(srcfile);

	/* Remove empty lines from files. */
	removeemptylines(srcfile,tempfile);

	/* Close all open files */
	fclose(srcfile);
	fclose(tempfile);

	/* Delete src file and rename temp file as src */
	remove(path);
	rename("remove-blanks.tmp",path);

	printf("\n\n\nFile contents after removing all empty line.\n\n");

	/* Open source file and print its contents */
	srcfile = fopen(path,"r");
	printfile(srcfile);
	fclose(srcfile);

	return 0;
}

/**
 * Print contents of a file
 */
void printfile(FILE* fptr)
{
	char ch;
	while((ch = fgetc(fptr))!=EOF)
	{
		putchar(ch);
	}
}

/**
 * Checks, whether a given string is empty or not.
 * A string is empty if it only contains white space
 * characters.
 *
 * Returns 1 if given string is empty otherwise 0.
 */
int isempty(const char* str)
{
	char ch;
	do
	{
		ch = *(str++);

		/* Check non whitespace character */
		if(ch!=' '&&ch!='\t'&&ch!='\r'&&ch!='\0')
		{
			return 0;
		}
	}while(ch!='\0');

	return 1;
}

/**
 * Function to remove empty lines from a file
 */
void removeemptylines(FILE* srcfile,FILE* tempfile)
{
	char buffer[BUFFER_SIZE];

	while((fgets(buffer,BUFFER_SIZE,srcfile))!=NULL)
	{
		/* If current line is not empty then write to temporary file */
		if(!isempty(buffer))
		{
			fputs(buffer,tempfile);
		}
	}
}
