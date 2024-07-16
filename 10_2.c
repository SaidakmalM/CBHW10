/*
 * 
 * 10_2.c
 * В файле .txt необходимо удалить все лишние пробелы
 * (в начале предложения и сдвоенные пробелы).
 * Для решения задачи разработать функцию.
 * Результат записать в файл .txt.
 * 
 */

#include <stdio.h>

enum states { Start, In, Out };
int main()
{
	FILE *fi = fopen("in.txt", "r");
	FILE *fo = fopen("out.txt", "w");
	int c, state = Start;
	while ((c = fgetc(fi)) != EOF)
		{
			switch (state)
				{
					case Start:
						if (c != ' ')
							{
								state = In;
								fputc(c, fo);
							}
						break;
					case In:
						if (c == ' ') state = Out;
						else fputc(c, fo);
						break;
					case Out:
						if (c != ' ')
							{
								state = In;
								fputc(' ', fo);
								fputc(c, fo);
							}
						break;
				}
		}
	fclose(fi);
	fclose(fo);
	return 0;
}
