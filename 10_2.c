/*
 * 
 * 10_2.c
 * � 䠩�� .txt ����室��� 㤠���� �� ��譨� �஡���
 * (� ��砫� �।������� � ᤢ����� �஡���).
 * ��� �襭�� ����� ࠧࠡ���� �㭪��.
 * ������� ������� � 䠩� .txt.
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
