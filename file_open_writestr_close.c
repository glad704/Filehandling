#include<stdio.h>
#include<string.h>

int main()
{
	FILE* fp;
	char str[16];
	fp = fopen("raman.txt","w");
	printf("File pointer value is: %p\n",fp);
	strcpy(str,"This is next");
	fputs(str,fp);
	fclose(fp);
	return 0;
}
