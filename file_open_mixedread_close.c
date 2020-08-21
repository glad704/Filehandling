#include<stdio.h>

int main()
{
	FILE* fp;
	char ch='A';
	int num=10;
	fp = fopen("raman.txt","w");
	printf("Value of file pointer is: %p\n",fp);
	fprintf(fp,"%c %d",ch,num);
	fclose(fp);
	return 0;
}
