#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int coeff;
	int exp;
	struct node* next;
}spll;
int checker=0;
spll *p1=NULL;
spll *p2=NULL;
spll *result=NULL;
void createpoly(int ce,int ex)
{
	spll* newnode=(spll*)malloc(sizeof(spll));
	newnode->coeff=ce;
	newnode->exp=ex;
	newnode->next=NULL;
	if(checker == 1)
	{
		if(p1 == NULL)
			p1 =newnode;
		else
		{
			spll *pp1=p1;
			while(pp1->next != NULL)
				pp1=pp1->next;
			pp1->next=newnode;
	}
	}
	else if(checker == 2)
	{
		if(p2 == NULL)
			p2 =newnode;
		else
		{
			spll *pp2=p2;
			while(pp2->next != NULL)
				pp2=pp2->next;
			pp2->next=newnode;
	}
	}
	else if(checker == 3)
	{
		if(result == NULL)
			result =newnode;
		else
		{
			spll *rs=result;
			while(rs->next != NULL)
				rs=rs->next;
			rs->next=newnode;
	}
	}
	else
		return;
}
void calculatepoly()
{
	spll* p11=p1;
	spll* p12=p2;
	while(p11 != NULL && p12 != NULL)
	{
		if(p11->exp > p12->exp)
		{
			createpoly(p11->coeff,p11->exp);
			p11=p11->next;
		}
		else if(p11->exp < p12->exp)
		{
			createpoly(p12->coeff,p12->exp);
			p12=p12->next;
		}
		else if(p11->exp == p12->exp)
		{
			createpoly((p11->coeff+p12->coeff),p12->exp);
			p11=p11->next;
			p12=p12->next;
		}
	}
	while(p11 != NULL)
	{
		createpoly(p11->coeff,p11->exp);
		p11=p11->next;
	}
	while(p12 != NULL)
	{
		createpoly(p12->coeff,p12->exp);
		p12=p12->next;
	}
}
void display(spll *dd)
{
	if(dd == NULL)
	{
		printf("\nThere Is No Polynomial");
		return;
	}
	printf("\nThe Polynomial Is: ");
	spll* d=dd;
	while(d != NULL)
	{
		printf("%dx^%d",d->coeff,d->exp);
		if(d->next != NULL)
			printf("+");
		d=d->next;
	}
}
int main()
{

	int c=0,e=0,n=0,i=0;
	printf("\nEnter The No. Of Terms For The First Polynomial: ");
	scanf("%d",&n);
	printf("\nEnter The First Polynomial: ");
	checker=1;
	while(i < n)
	{
		printf("\nEnter The Values (Coefficient And Exponent): ");
		scanf("%d %d",&c,&e);
		createpoly(c,e);
		i++;
	}
	printf("\nThe First Polynomial Is: ");
	display(p1);
	printf("\nEnter The No. Of Terms For The Second Polynomial: ");
	scanf("%d",&n);
	printf("\nEnter The Second Polynomial: ");
	i=0;
	checker=2;
	while(i < n)
	{
		printf("\nEnter The Values (Coefficient And Exponent): ");
		scanf("%d %d",&c,&e);
		createpoly(c,e);
		i++;
	}
	printf("\nThe Second Polynomial Is: ");
	display(p2);
	printf("\nAdding The Polynomials\n");
	checker=3;
	calculatepoly();
	display(result);
	return 0;
}
