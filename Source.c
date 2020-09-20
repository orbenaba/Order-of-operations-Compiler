#include<stdio.h>
#include<stdlib.h>
#include"poly.h"
#include"AnalizePharse.h"

void Ex1();
void Ex2();

void main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 2; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-2: ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 5));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			}
		} while (all_Ex_in_loop && select);
		system("PAUSE");
}

void Ex1()
{
	char tempstr[100];
	printf("Insert an arithmetic pharse(MAXIMUM size pharse is 100 characters)\n");
	printf("Dear Examiner, take into account that section BONUS is included at this function\n");
	gets(tempstr);
	gets(tempstr);
	printf("operation|operand1|operand2|result\n");
	PresentingAnArithmeticPharse(tempstr);
}

void Ex2()
{
	List*p1 = Create_List(), *p2 = Create_List(), *p3 = Create_List();
	printf("you are situated in EXCERCISE 2 menu\n\n");
	printf("Pay attenation, when you input a Polynomial to some section,it will be reset so that you have to initialize your polynomial again\n\n");
	int select = 0, i, all_Ex_in_loop = 0, c;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			printf("create new Polynomial-->1\n");
			printf("Addition-two Polynomials-->2\n");
			printf("subtraction-two polynomials-->3\n");
			printf("multiclipation-polynomial in const-->4\n");
			printf("degree of polynomial-->5\n");
			printf("reset polynomial-->6\n");
			printf("print polynomial-->7\n");
			printf("BONUS-multiclipating Polynomials-->8\n");
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-8: ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 8));
			switch (select)
			{
			case 1:
				p3 = InputPoly();
				printf("your Polynomial is:\n ");
				PrintPoly(p3);
				ResetPoly(p3);
				break;
			case 2:
				printf("First Polynomial:\n");
				p1 = InputPoly();
				printf("Second Polynomial:\n");
				p2 = InputPoly();
				p3 = SumPolynomials(p1, p2);
				printf("The first Polinom is: ");
				PrintPoly(p1);
				printf("\nThe second Polinom is: ");
				PrintPoly(p2);
				printf("\nThe result is: ");
				PrintPoly(p3);
				ResetPoly(p1);
				ResetPoly(p2);
				ResetPoly(p3);
				break;
			case 3:
				printf("First Polynomial:\n");
				p1 = InputPoly();
				printf("Second Polynomial:\n");
				p2 = InputPoly();
				p3 = DifferencePolynomials(p1, p2);
				printf("The first Polinom is: ");
				PrintPoly(p1);
				printf("\nThe second Polinom is: ");
				PrintPoly(p2);
				printf("\nThe result is: ");
				PrintPoly(p3);
				ResetPoly(p1);
				ResetPoly(p2);
				ResetPoly(p3);
				break;
			case 4:
				printf("Please insert a multiclipator const(double): ");
				scanf_s("%d", &c);
				printf("\nMake a polynomial:\n");
				p1 = InputPoly();
				p2 = MultiInConst(p1, c);
				printf("your Polynomial is: ");
				PrintPoly(p1);
				printf("AND Your result: ");
				PrintPoly(p2);
				ResetPoly(p1);
				ResetPoly(p2);
				break;
			case 5:
				printf("Insert a polynomial:\n ");
				p1 = InputPoly();
				printf("Your polynomial degree is:\n %d\n", SizePoly(p1));
				ResetPoly(p1);
				break;
			case 6:
				printf("Insert a polynomial in order to reset it:\n");
				p1 = InputPoly();
				printf("Your original polynomial is:\n");
				PrintPoly(p1);
				printf("After reset:\n ");
				ResetPoly(p1);
				PrintPoly(p1);
				break;
			case 7:
				printf("Insert simply Polynomial: ");
				p1 = InputPoly();
				printf("Your simply polynomial is: ");
				PrintPoly(p1);
				ResetPoly(p1);
				break;
			case 8:
				printf("Welcome to my special Bonus\n");
				printf("Feel comfortable to insert some polynomials as you wish:\nPolynoimal 1:\n ");
				p1 = InputPoly();
				printf("Polynomial 2:\n");
				p2 = InputPoly();
				p3 = MulticlipatePolynomilas(p1, p2);
				printf("Polynomial 1: ");
				PrintPoly(p1);
				printf("\nPolynomial 2: ");
				PrintPoly(p2);
				printf("\nresult is:\n");
				PrintPoly(p3);
				ResetPoly(p1);
				ResetPoly(p2);
				ResetPoly(p3);
				break;
			}
		} while (all_Ex_in_loop && select);
}
