#include<iostream>
#include<stdio.h>
using namespace std;
class D                              
{public:
	int data;                      
	D* next;                     
};

int main_1()
{
	D *head, *p, *q;

	int k,i;

	head = new D;                           //指针的初始化
	p = new D;
	head->next = p;
	head->data = 0;
	q = p;

	cout << "请输入链表长度" << endl;         

	cin >> k;

	cout << endl;

	for( i = 0; i < k; i++ )               //用循环控制链表长度（head指针数据为空，不包括在内）
	{
		cout << "请输入数据" << endl;        //输入数据

		cin >> p->data;

		cout << endl;

		p = new D;

		q->next = p;

		q = p;
	}

	q->next = NULL;

	p = head->next;

	for (i = 0; i < k; i++)                    //输出
	{
		cout << p->data<< endl;

		p = p->next;

	}
	return 0;
}
