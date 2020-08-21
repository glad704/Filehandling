#include<stdio.h>

int main()
{
	FILE* fp;
	char str[10];
	fp = fopen("raman.txt","r");
	printf("File pointer value is: %p\n",fp);
	fgets(str,10,fp);
	printf("Character in files are: %s\n",str);
	fclose(fp);
	return 0;
}
