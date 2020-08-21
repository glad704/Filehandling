#include<stdio.h>

int main()
{
	FILE* fp;
	char str;
	fp = fopen("raj.txt","r");
	printf("File pointer value is: %p\n",fp);
	str = getc(fp);
	printf("First character of FILE is: %c\n",str);
	fclose(fp);
	return 0;
}
