#include"AnalizePharse.h"
void PresentingAnArithmeticPharse(char*str)
{
	int leng, index = 3;
	if (RemoveSpaces_CheackInput(str) == 0)
	{
		printf("UNVALID INPUT\n");
		return;
	}
	leng = strlen(str);
	if (leng % 2 == 0 || leng < 3)
	{
		printf("UNVALID PHARSE\n");
		return;
	}
	stack operands, operators;
	char result = 'Z', tempOper, curOper, first, second, third;
	create_stack(&operands);
	create_stack(&operators);
	push(str[0], &operands);
	push(str[1], &operators);
	push(str[2], &operands);
	while (!stack_is_empty(&operands))
	{
		stack_top(&operators,&curOper);
		if (index < leng)
		{
			tempOper = str[index++];
			if (stronger(curOper,tempOper ))//return 1 if tempOper is stronger then curOper
			{
				push(tempOper, &operators);
				push(str[index++], &operands);
			}
			else
			{
				while (!stack_is_empty(&operators))
				{
					pop(&operands, &first);
					pop(&operators, &second);
					pop(&operands, &third);
					printf("%4c     | %5c  |%5c   |%2c\n", second, third, first, result);
					push(result, &operands);
					result--;
				}
				push(str[index++], &operands);
				push(tempOper, &operators);
			}
		}
		else
		{
			while (!stack_is_empty(&operators))
			{
				pop(&operands, &first);
				pop(&operators, &second);
				pop(&operands, &third);
				printf("%4c     | %5c  |%5c   |%2c\n", second, third, first, result);
				push(result, &operands);
				result--;
			}
			break;
		}
	}
}
int RemoveSpaces_CheackInput(char*str)
{
	int count = 0, i;
	for (i = 0; str[i]; i++)
		if (str[i] != ' ')
			str[count++] = str[i];
	str[count] = '\0';
	for (i = 0; str[i]; i++)
	{
		if (i % 2 == 0)
			if (!((str[i] >= '0'&&str[i] <= '9') || (str[i] >= 'A'&&str[i] <= 'H')))
				return 0;
		if (i % 2 == 1)
			if (!(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'))
				return 0;
	}
	return 1;
}

int stronger(char c1, char c2)
{
	if (c1 == '+' || c1 == '-')
	{
		if (c2 == '+' || c2 == '-')
			return 0;
		return 1;
	}
	if (c1 == '*' || c1 == '/')
	{
		if (c2 == '^')
			return 1;
		return 0;
	}
	if (c1 == '^')
	{
		if (c2 == '^')
			return 1;
		return 0;
	}
}