/*
 * 
 * 10_1.c
 * В файле .txt записаны символы. Необходимо разработать функцию, которая
 * меняет местам пары соседних символов не обращая внимания на символы
 * пробел. Если количество символов нечетно (пробелы не считаем), то 
 * последний символ не меняем. Результат записать в файл .txt.
 * 
 */

#include <stdio.h>
#include <string.h>

void change(int size, char *line)
{
	int i = 0, j;
	char temp;
	while (i < size)
	{
		while (line[i] == ' ') i++;
		j = i + 1;
		while (line[j] == ' ') j++;
		if (j >= size) break;
		temp = line[i];
		line[i] = line [j];
		line[j] = temp;
		i = j + 1;
	}
}

int main()
{
	char in_file[] = "in.txt", out_file[] = "out.txt";
	char in_str[1024];
	FILE *f;
	f = fopen(in_file, "r");
	fscanf(f, "%[^\n]", in_str);
	fclose(f);
	change(strlen(in_str), in_str);
	f = fopen(out_file, "w");
	fprintf(f, "%s", in_str);
	fclose(f);
	return 0;
}
