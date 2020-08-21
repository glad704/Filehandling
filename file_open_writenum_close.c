#include<stdio.h>

int main()
{
	FILE* fp;
	int var;
	fp = fopen("raman.txt","w");
	printf("Value of file pointer is: %p\n",fp);
	printf("Enter the value you want to enter in file: \n");
	scanf("%d",&var);
	putw(var,fp);
	fclose(fp);
	return 0;
}

