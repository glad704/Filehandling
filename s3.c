/**
 * C program to input numbers from file and write even,
 * odd and prime numbers to separate file.
 */

#include<stdio.h>
#include<stdlib.h>

/* Function decalaration */
int isEven(const int NUM);
int isPrime(const int NUM);

int main()
{
	/* File pointer to hold reference to different files */
	FILE *fptrIn,
	     *fptrEven,
	     *fptrOdd,
	     *fptrPrime;

	int num;

	/*
	 * Open all files to perform read/write.
	 */
	fptrIn = fopen("numbers.txt","r");
	fptrEven = fopen("even-numbers.txt","w");
	fptrOdd = fopen("odd-numbers.txt","w");
	fptrPrime = fopen("prime-numbers.txt","w");

	/* fopen() return NULL if unable to open file in given mode */
	if(fptrIn == NULL || fptrEven == NULL || fptrOdd == NULL || fptrPrime == NULL)
	{
		/* Unable to open file hence exit */
		printf("Unable to open file.\n");
		printf("Please check whether file exists and you have read/write priviledge.\n");
		exit(EXIT_FAILURE);
	}

	/* File open success message */
	printf("File opened successfully. Reading integers from file. \n\n");

	// Read an integer and store read status in success.
	while(fscanf(fptrIn,"%d",&num)!=-1)
	{
		/*
		 * Write prime, even and odd numbers to different files.
		 */
		if(isPrime(num))
		{
			fprintf(fptrPrime,"%d",num);
		}
		else if(isEven(num))
		{
			fprintf(fptrEven,"%d",num);
		}
		else
		{
			fprintf(fptrOdd,"%d",num);
		}
	}

	/* Done with all files, hence close all. */
	fclose(fptrIn);
	fclose(fptrEven);
	fclose(fptrOdd);
	fclose(fptrPrime);

	printf("Data written to files successfully.\n");

	return 0;
}

/**
 * Check whether a given number is even or not. The function
 * return 1 if given number is odd, otherwise return 0.
 */
int isEven(const int NUM)
{
	return!(NUM&1);
}

/**
 * Check whether a number is prime or not.
 * REturns 1 if the number is prime otherwise 0.
 */
int isPrime(const int NUM)
{
	int i;

	// Only positive integers are prime
	if(NUM<0)
	{
		return 0;
	}

	for(i=2;i<=NUM/2;i++)
	{
		/*
		 * If the number is divisible by any number
		 * other than 1 and self then it is not prime
		 */
		if(NUM%i==0)
		{
			return 0;
		}
	}
	return 1;
}
