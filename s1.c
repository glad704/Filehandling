/**
 * C program to create a file and write data into file.
 */

#include<stdio.h>
#include<stdlib.h>

#define DATA_SIZE 1000

int main()
{
	/* Variable ti store user content */
	char data[DATA_SIZE];

	/* file pointer to hold reference to our file */
	FILE* ptr;

	/*
	 * Open file in w (write) mode.
	 * "data/file1.txt" is complete path to create file
	 */
	ptr = fopen("file1.txt","w");

	/* fopen() return NULL if last operation was unsuccessful */
	if(ptr == NULL)
	{
		/* File not created hence exit */
		printf("Unable to create file.\n");
		exit(EXIT_FAILURE);
	}

	/* Input contents from user to store in file */
	printf("Enter contents to store in file : \n");
	fgets(data,DATA_SIZE,stdin);

	/* Write data to file */
	fputs(data,ptr);

	/* Close file to save file data */
	fclose(ptr);

	/* Success message */
	printf("File created and saved successfully. :) \n");

	return 0;
}
