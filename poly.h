#include<stdio.h>
#include<stdlib.h>

typedef struct Polynomial {
	unsigned int power;
	double coef;
	struct Polynomial*next;
	struct Polynomial*prev;
}Polynomial;

typedef struct List {
	Polynomial*head;
	Polynomial*tail;
}List;
List* Create_List();
void InsertPoly(List*p, double coef, unsigned int pow);
Polynomial*CreatePoly(double coef, unsigned int pow);
List* SumPolynomials(List*p1, List*p2);
List* DifferencePolynomials(List*p1, List*p2);
List*MultiInConst(List*p, double c);
int SizePoly(List*p);
void ResetPoly(List*p);
void PrintPoly(List*p1);
List*MulticlipatePolynomilas(List*p1, List*p2);
List*InputPoly();