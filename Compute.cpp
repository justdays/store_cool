#include<iostream>
#include<string>
#include"Compute.h"
using namespace std;


int pri(char a) {
	int n=0;
	switch(a)
	{
	case '(': {n = 1; break; }

	case '+':
	case '-': {n = 2; break; }

	case '*':
	case '/': {n = 3; break; }
	}
	return n;
}

void push(LinkStack* s, int data)
{
	StackNode* temp = new StackNode;

	temp->data = data;
	temp->next = s->top->next;
	s->top->next = temp;

	s->n++;
}

LinkStack* create()
{
	LinkStack* s = new LinkStack;

	s->top = new StackNode;
	s->top->next = NULL;
	s->n = 0;

	return s;
}

int pop(LinkStack* s) {
	StackNode* t;
	t = new StackNode;
	t = s->top;
	s->top = (s->top)->next;
	delete t;
	return s->top->data;
}

int getTop(LinkStack* s) {
	return (s->top)->data;
}

int emptstack(LinkStack* s) {
	if (s->top->next == nullptr)return 1;
	else return 0;
}

int com(int a, int b, char c)
{
	int n=0;

	switch (c)
	{
	case '+':
		n = a + b;
		break;
	case '-':
		n = a - b;
		break;
	case '*':
		n = a * b;
		break;
	case '/':
		n = a / b;
		break;
	}

	return n;


}

int Comput(char a[]) {
	LinkStack* sn = create();
	LinkStack* sc = create();
	int sum;
	int temp = 0;
	char* e = a;
	while (*e != '\0')
	{
		if (*e >= '0' && *e <= '9')
		{
			sum = 0;
			while (*e >= '0' && *e <= '9')
			{
				sum = sum * 10 + *e++ - '0';
			}
			push(sn, sum);
			continue;
		}

		if (*e == '(')
		{
			push(sc, *e++);
			continue;
		}
		if (*e == ')')
		{
			while (getTop(sc) != '(')
			{
				temp = com(pop(sn), pop(sn), pop(sc));
				push(sn,temp );
			}
			pop(sc);      //此时字符栈的栈顶元素是左括号'('，所以应该将其出栈
			e++;
			continue;
		}

		expression(sn, sc, *e++);
	}

	while (emptstack(sc) == 0)
	{
		push(sn, com(pop(sn), pop(sn), pop(sc)));
	}

	return pop(sn);

}


void expression(LinkStack * sn, LinkStack * sc, char c){
		while (emptstack(sc) == 0 && (pri(getTop(sc)) >= pri(c)))
		{
			push(sn, com(pop(sn), pop(sn), pop(sc)));
		}
		push(sc, c);
	}

