#include<stdio.h>

int main()
{
	FILE* fp;
	int num;
	char ch[10];
	fp = fopen("raman.txt","r");
	printf("Value in file pointer is: %p\n",fp);
	fscanf(fp,"%s %d",ch,&num);
	printf("Character value in file is: %s\n",ch);
	printf("Integer value in file is: %d\n",num);
	fclose(fp);
	return 0;
}
