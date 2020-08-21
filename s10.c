/**
 * C program to delete specific line from a file
 */

#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 1000

/* Function decalarations */
void deleteline(FILE* srcfile,FILE* tempfile,const int line);
void printfile(FILE* fptr);

int main()
{
	FILE* srcfile;
	FILE* tempfile;
	char path[100];
	int line;

	/* Input file path and line number */
	printf("Enter file path: ");
	scanf("%s",path);
	printf("Enter line number to remove: ");
	scanf("%d",&line);

	/* Try to open file */
	srcfile = fopen(path,"r");
	tempfile = fopen("delete-line.tmp","w");

	/* Exit if file not opened successfully */
	if(srcfile == NULL || tempfile == NULL)
	{
		printf("Unable to open file.\n");
		printf("Please check you have read/write priviledge.\n");
		exit(EXIT_FAILURE);
	}

	printf("\nFile contents before removing line.\n\n");
	printfile(srcfile);

	/* Move src file pointer to beginning */
	rewind(srcfile);

	/* Delete given line from file */
	deleteline(srcfile,tempfile,line);

	/* Close all open files */
	fclose(srcfile);
	fclose(tempfile);

	/* Delete src file and rename temp file as src */
	remove(path);
	rename("delete-line.tmp",path);

	printf("\n\nFile contents after removing %d line.\n\n",line);

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
 * function to delete a given line from file
 */
void deleteline(FILE* srcfile,FILE* tempfile,const int line)
{
	char buffer[BUFFER_SIZE];
	int count = 1;

	while((fgets(buffer,BUFFER_SIZE,srcfile))!=NULL)
	{
		/* If current line is not the line user wanted to remove */
		if(line!=count)
		{
			fputs(buffer,tempfile);
		}
		count++;
	}
}
