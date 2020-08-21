#include<stdio.h>

int main()
{
	FILE* fp;
	int var;
	fp = fopen("raman.txt","r");
	printf("Value of file pointer is: %p\n",fp);
	var = getw(fp);
	printf("Integer value in File is: %d\n",var);
	fclose(fp);
	return 0;
}
