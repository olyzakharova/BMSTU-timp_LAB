#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
int main(int argc, char* argv[]) /** \func int main(int argc,char* argv[] */
{
FILE *pf;
int a = 0;
char c;
int i = 0;
char _FileName[100];


if (argc != 1)
{
	printf("\n Error :) \n");
	return 1;
}
if (sscanf_s(argv[1], "%s", &_FileName) < 1)
{
	printf("\n Error :( \n");
	return 1;
}

	fopen_s(&pf,_FileName, "r"); 
	if (pf == 0) { printf_s("error file\n"); }
	else printf_s("file was successfully opened\n");

	while (!feof(pf)) 
	{
		if (fgetc(pf) == '/')
		{
			if (fgetc(pf) == '*')
			{
				if (fgetc(pf) == '*')
				{
					while (fgetc(pf) != '\\')
					{
						;
					}
			      
						if (fgetc(pf) == 'f')
						{
							if (fgetc(pf) == 'u')
							{
								if (fgetc(pf) == 'n')
								{
									if (fgetc(pf) == 'c')
									{
										while ((c = fgetc(pf)) != '/')
										{
											if (c == '*')
											{
												char a;
												if ((a=fgetc(pf)) == '/')
												{
													break;
												}
												else 
												{ 
													printf_s("%c", c);
													printf_s("%c", a);
													continue;
												}
											}
											printf_s("%c", c);
											
										}
										printf_s("\n");
									}
								}
							}
					
					}
				}

			}
		}
	}
	fclose(pf);
    return 0;
}
//Функция и для проверки правильности работы программы
/**
\func int sum(int a, int b) 
*/
int sum(int a, int b) {
	return a + b;
}
