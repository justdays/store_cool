#pragma once


class n {
public:
	double t;
	n* next;
};



typedef  struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	n;
}LinkStack;


class c {
public:
	char a;
	c* next;
};

int emptstack(LinkStack* s);
int Comput(char a[]);
int com(int a, int b, char c);
int pri(char a, c* cha);
void push(LinkStack* s, int data);
LinkStack* create();
int getTop(LinkStack* s);
void expression(LinkStack* sn, LinkStack* sc, char c);