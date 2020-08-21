#include<stdio.h>

int main()
{
	FILE* fp;
	char ch[] = "Testing";
	char str[20];
	fp = fopen("Ramesh.txt","wb+");
	printf("Value of file pointer is: %p\n",fp);
	fwrite(ch,sizeof(ch),1,fp);
	fseek(fp,0,SEEK_SET);
	fread(str,sizeof(ch),1,fp);
	printf("Text is: %s\n",str);
	fclose(fp);
	return 0;
}
