/*
 * 
 * 10_3.c
 * В файле .txt записан полный адрес файла (возможно без расширения).
 * Необходимо изменить его расширение на ".html"
 * и записать результат в файл .txt.
 * 
 */

#include <stdio.h>
#include <string.h>

void input(char *str)
{
	FILE *fi = fopen("in.txt", "r");
	while(fscanf(fi, "%[^\n]", str) == 1);
	fclose(fi);
}

void extension(char *strExt, char *buffer)
{
	for(int i = strlen(strExt) - 1; i >= 0; i--)
		{
			if(strExt[i] == '/')
				{
					strcpy(buffer, strExt);
					strcat(buffer, ".html");
					break;
				}
			else if(strExt[i] == '.')
			{
				memcpy(buffer, strExt, i);
				strcat(buffer, ".html");
				break;
			}
		}
}

void output(char *strOut)
{
	FILE *fo = fopen("out.txt", "w");
	fprintf(fo, "%s", strOut);
	fclose(fo);
}

int main(int argc, char **argv)
{
	char str[1024], strFinish[1024];
	input(str);
	extension(str, strFinish);
	output(strFinish);
	return 0;
}
