#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fp;
	char str[10];
	fp = fopen("raj.txt","r");
	printf("Value of file pointer: %p\n",fp);
	if(fp==0)
	{
		printf("File couldn't be opened!!\n");
		exit(-1);
	}
	fgets(str,10,fp);
	printf("Text is: %s\n",str);
	fclose(fp);
	return 0;
}
