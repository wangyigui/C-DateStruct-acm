#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Polynomial                 
{
	float    coef;   
	int      expn;   
	struct   Polynomial *next;
}Polynomial,*Polyn;

Polyn CreatePoly()                        
{
	Polynomial *head,*rear,*s;
	int c,e,n,i;

	head=(Polynomial *)malloc(sizeof(Polynomial));
	rear = head;

	scanf("%d\n",&n);

	for(i=1;i<=n;i++)
	{
		scanf("\n(%d,%d)",&c,&e);

		s = (Polynomial *)malloc(sizeof(Polynomial));
		s -> coef = c;
		s -> expn = e;
		rear -> next = s ;
		rear = s;
	}
	rear -> next = NULL;
	return(head);

}

void PrintPolyn(Polyn P)                    
{
	Polyn q = P -> next;
	int flag = 1;
	if(!q)
	{
		putchar('0');
		printf("\n");
		return ;
	}

	while(q)
	{
		if(q->expn < 0)
		{
			q = q->next;
			continue;
		}
		if(q -> coef > 0 && flag != 1)  putchar('+');
		if(q -> coef != 1 && q -> coef != -1)
		{
			printf("%g",q -> coef);
			if(q -> expn == 1)  putchar('X');
			else if(q -> expn)  printf("X^%d",q -> expn);
		}
		else
		{
			if(q -> coef == 1)
			{
				if(! q -> expn) putchar('1');
				else if(q -> expn == 1)  putchar('X');
				else printf("X^%d",q -> expn);
			}
		}
		q = q -> next;
		flag++;
	}
	printf("\n");
}
Polyn DerivationPolyn(Polyn head)
{
	Polynomial *p;
	p = head -> next;
	while (p)
	{
		p -> coef = p -> coef * p -> expn;
		p -> expn = --p -> expn;
		p = p -> next;
	}
	return head;
}
int main()
{
	Polynomial *head;                  
	head = CreatePoly(); 
	DerivationPolyn(head);                                              	
	PrintPolyn(head);                                
}