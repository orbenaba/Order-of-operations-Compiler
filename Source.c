#include<stdio.h>
#include<stdlib.h>
#include "AnalizePharse.h"

void Ex1();

void main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-1: ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 1));
			if(select == 1)
				Ex1();
		} while (all_Ex_in_loop && select);
		system("PAUSE");
}

void Ex1()
{
	char tempstr[100];
	printf("Insert an arithmetic pharse(MAXIMUM size pharse is 100 characters)\n");
	gets(tempstr);
	gets(tempstr);
	printf("operation|operand1|operand2|result\n");
	presentingAnArithmeticPharse(tempstr);
}
