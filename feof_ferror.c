#include<stdio.h>

int main()
{
	FILE* fp;
	char str[10];
	fp = fopen("raj.txt","r");
	printf("Value of file pointer is: %p\n",fp);
	fgets(str,10,fp);
	printf("Text is: %s\n",str);
	if(feof(fp)!=0)
	{
		printf("End of file!!\n");
	}
	if(ferror(fp)==0)
	{
		printf("Reading........!!\n");
	}
	fclose(fp);
	return 0;
}
