#include<stdio.h>

int main()
{
	FILE* fp;
	char ch;
	fp = fopen("raman.txt","a");
	printf("File pointer value is: %p\n",fp);
	printf("Enter the character you want to enter in File: \n");
	scanf("%c",&ch);
	putc(ch,fp);
	fclose(fp);
	return 0;
}
