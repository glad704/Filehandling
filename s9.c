/**
 * C program to delete a word from file
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1000

void removeAll(char* str,const char* toRemove);

int main()
{
	FILE* fptr;
	FILE* ftemp;
	char path[100];
	char toRemove[100];
	char buffer[1000];

	/* Input source file path */
	printf("Enter path of source file: ");
	scanf("%s",path);
	printf("Enter word to remove: ");
	scanf("%s",toRemove);

	/* Open files */
	fptr = fopen(path,"r");
	ftemp = fopen("delete.tmp","w");

	/* fopen() return NULL if unable to open file in given mode */
	if(fptr == NULL || ftemp == NULL)
	{
		/* Unable to open file hence exit */
		printf("\nUnable to open file.\n");
		printf("Please check whether file exists and you have read/write priviledge.\n");
		exit(EXIT_FAILURE);
	}

	/*
	 * Read line from source file and write to destination
	 * file after removing given word.
	 */
	while((fgets(buffer,BUFFER_SIZE,fptr))!=NULL)
	{
		// Remove all occurrence of word from current line
		removeAll(buffer,toRemove);

		// Write to temp file
		fputs(buffer,ftemp);
	}

	/* Close all files to release resources */
	fclose(fptr);
	fclose(ftemp);

	/* Delete original source file */
	remove(path);

	/* Rename temp file as original file */
	rename("delete.tmp",path);

	printf("\nAll occurrence of '%s' removed successfully.",toRemove);

	return 0;
}

/**
 * Remove all occurrence of a given word in string.
 */
void removeAll(char* str,const char* toRemove)
{
	int i,j,stringlen,toRemovelen;
	int found;

	stringlen = strlen(str);	// length of string
	toRemovelen = strlen(toRemove);	// length of word to remove

	for(i=0;i<=stringlen-toRemovelen;i++)
	{
		/* Match word with string */
		found = 1;
		for(j=0;j<toRemovelen;j++)
		{
			if(str[i+j]!=toRemove[j])
			{
				found=0;
				break;
			}
		}

		/* If it is not a word */
		if(str[i+j]!=' ' && str[i+j]!='\t' && str[i+j]!='\n' && str[i+j]!='\0')
		{
			found = 0;
		}

		/*
		 * If word is found then shift all characters to left
		 * and decrement the string length
		 */
		if(found==1)
		{
			for(j=i;j<=stringlen-toRemovelen;j++)
			{
				str[j] = str[j + toRemovelen];
			}

			stringlen = stringlen - toRemovelen;

			// We will match next occurrence of word from current index.
			i--;
		}
	}
}
