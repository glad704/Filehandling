#include<stdio.h>

int main()
{
	FILE* fp;
	int n;
	char str[40];
	fp = fopen("raman.txt","r+");
	printf("Value of file pointer is: %p\n",fp);
	fgets(str,10,fp);
	printf("Text is: %s\n",str);
	fseek(fp,2,SEEK_SET);
	fputs("Testing",fp);
	rewind(fp);
	fgets(str,15,fp);
	printf("Text is: %s\n",str);
	n = ftell(fp);
	printf("Position of fp pointer is: %d\n",n);
	fclose(fp);
	return 0;
}
