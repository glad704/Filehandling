#include<stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("raj.txt","r");
	printf("File pointer value = %p\n",fp);
	fclose(fp);
	return 0;
}
