#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"poly.h"
//section a
List* Create_List()
{
	List*lst = (List*)malloc(sizeof(List*));
	lst->head = NULL;
	lst->tail = NULL;
	return lst;
}

//assistance
Polynomial*CreatePoly(double coef, unsigned int pow)
{
	Polynomial*p = (Polynomial*)malloc(sizeof(Polynomial));
	p->coef = coef;
	p->power = pow;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

//section b
void InsertPoly(List*p, double coef, unsigned int pow)
{
	Polynomial*be = p->head, *en = p->tail, *inserted = CreatePoly(coef, pow), *help, *fr;
	if (!be && !en)//insert to an empty list
	{
		p->head = inserted;
		p->tail = inserted;
		return;
	}
	if (be->power > pow)//insert first
	{
		inserted->next = be;
		be->prev = inserted;
		p->head = inserted;
		return;
	}
	if (en->power < pow)//insert last 
	{
		en->next = inserted;
		inserted->prev = en;
		p->tail = inserted;
		return;
	}
	while (be->next != NULL && be->power < inserted->power)
		be = be->next;//otherwise find the wright space
	if (be->next == NULL && be->power == inserted->power)
	{
		if (be->coef == (-1)*inserted->coef)
		{
			if (be->prev == NULL)
			{
				help = be;
				be = NULL;
				free(help);
				p->head = NULL;
				p->tail = NULL;
			}
			else
			{
				help = be;
				be = be->prev;
				p->tail = be;
				be->next = NULL;
				free(help);
			}
			return;
		}
		be->coef = (be->coef) + inserted->coef;
		return;
	}
	if (!be->next)
	{
		be->next = inserted;
		inserted->prev = be;
		p->tail = inserted;
		return;
	}
	if (be->power == inserted->power)
	{
		if (be->coef == (-1)*inserted->coef)
		{
			if (be->prev == NULL)
			{
				fr = be;
				be = be->next;
				be->prev = NULL;
				free(fr);
				p->head = be;
				return;
			}
			fr = be;
			be = be->next;
			be->prev = fr->prev;
			be = be->prev;
			be->next = fr->next;
			free(fr);
			return;
		}
		be->coef = (be->coef) + inserted->coef;
		return;
	}
	be->prev = inserted;
	inserted->next = be;
	be = be->prev;
	be->next = inserted;
	inserted->prev = be;
}

//section c
List* SumPolynomials(List*p1, List*p2)
{
	List*sumPoly = Create_List();
	Polynomial *temp1 = p1->head, *temp2 = p2->head;
	while (temp1 != NULL)
	{
		InsertPoly(sumPoly, temp1->coef, temp1->power);
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		InsertPoly(sumPoly, temp2->coef, temp2->power);
		temp2 = temp2->next;
	}
	return sumPoly;
}

//section d
List* DifferencePolynomials(List*p1, List*p2)
{
	List*sumPoly = Create_List();
	Polynomial*temp1 = p1->head, *temp2 = p2->head;
	while (temp1 != NULL)
	{
		InsertPoly(sumPoly, temp1->coef, temp1->power);
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		InsertPoly(sumPoly, -1 * (temp2->coef), temp2->power);
		temp2 = temp2->next;
	}
	return sumPoly;
}

//section e
List*MultiInConst(List*p, double c)
{
	List*multipoly = Create_List();
	Polynomial*temp1 = p->head;
	double in;
	unsigned int powin;
	if (c == 0)
		return multipoly;
	while (temp1 != NULL)
	{
		in = c * (temp1->coef);
		powin = temp1->power;
		InsertPoly(multipoly, in, powin);
		temp1 = temp1->next;
	}
	return multipoly;
}

//sectiom f
int SizePoly(List*p)
{
	if (p->tail == NULL)
	{
		printf("EMPTY POLYNOMIAL\n");
		return -1;
	}
	return p->tail->power;
}

//section g-succeced
void ResetPoly(List*p)
{
	Polynomial* temp1 = p->head, *temp2;
	while (temp1 != p->tail)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		free(temp2);
	}
	p->head = NULL;
	p->tail = NULL;
}

//section h-succeced
void PrintPoly(List*p1)
{
	if (p1->tail == NULL && p1->head == NULL)
	{
		printf("ZERO(empty polynomial\n");
		return;
	}
	Polynomial *tail = p1->tail;
	if (tail->coef == -1)
	{
		if (tail->power == 0)
			printf("-1");
		else if (tail->power == 1)
			printf("-x");
		else
			printf("-x^%u", tail->power);
	}

	else if (tail->coef == 1)
	{
		if (tail->power == 0)
			printf("1");
		else if (tail->power == 1)
			printf("x");
		else
			printf("x^%u", tail->power);
	}
	else
	{
		if (tail->power == 0)
			printf("%lf", tail->coef);
		else if (tail->power == 1)
			printf("%lfx", tail->coef);
		else
			printf("%lfx^%u", tail->coef, tail->power);
	}
	tail = tail->prev;
	while (tail&&tail->coef != 0)
	{
		if (tail->coef == -1)
		{
			if (tail->power == 0)
				printf("-1");
			else if (tail->power == 1)
				printf("-x");
			else
				printf("-x^%u", tail->power);
		}
		else if (tail->coef == 1)
		{
			if (tail->power == 0)
				printf("+1");
			else if (tail->power == 1)
				printf("+x");
			else
				printf("+x^%u", tail->power);
		}
		else if (tail->coef < 0)
		{
			if (tail->power == 0)
				printf("%lf", tail->coef);
			else if (tail->power == 1)
				printf("%lf", tail->coef);
			else
				printf("%lfx^%u", tail->coef, tail->power);
		}
		else
		{
			if (tail->power == 0)
				printf("+%lf", tail->coef);
			else if (tail->power == 1)
				printf("+%lfx", tail->coef);
			else
				printf("+%lfx^%u", tail->coef, tail->power);
		}
		tail = tail->prev;
	}
	printf("\n");
	printf("\n");
}

//section i-BONUS(10 pts)
List*MulticlipatePolynomilas(List*p1, List*p2)
{
	List*lst = Create_List();
	Polynomial*temp1 = p1->head, *temp2 = p2->head;
	unsigned int pow1;
	double coef1;
	while (temp1)
	{
		temp2 = p2->head;
		while (temp2)
		{
			coef1 = (temp1->coef)*(temp2->coef);
			pow1 = (temp2->power) + (temp1->power);
			InsertPoly(lst, coef1, pow1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return lst;
}

//assistant function
List*InputPoly()
{
	int power;
	double coef;
	List*p = Create_List();
	printf("Insert coefficient(Insert ZERO to exit)- ");
	scanf_s("%lf", &coef);
	if (coef == 0)
		return p;
	printf("Insert natural Power- ");
	scanf_s("%u", &power);
	while (power < 0)
	{
		printf("Insert natural Power- ");
		scanf_s("%u", &power);
	}
	while (1)
	{
		InsertPoly(p, coef, power);
		printf("Insert coefficient(Insert ZERO to exit)- ");
		scanf_s("%lf", &coef);
		if (coef == 0)
			break;
		printf("Insert natural Power- ");
		scanf_s("%u", &power);
		while (power < 0)
		{
			printf("Insert natural Power- ");
			scanf_s("%u", &power);
		}
	}
	return p;
}