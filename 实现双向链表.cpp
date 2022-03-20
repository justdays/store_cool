#include<iostream>
#include<stdio.h>
using namespace std;
class D
{
public:
	D* prior;                              //前指针
	int data;
	D* next;                               //后指针

};

int main()
{
	D* head, * p, * q, * tail;      //tail指针指向最后一个结点

	int k, i;

	head = new D;                   //指针的初始化
	
	p = new D;

	head->prior = NULL;

    head->data = 0;

	head->next = p;

	p->prior = head;

	q = p;

	cout << "请输入链表长度" << endl;

	cin >> k;

	cout << endl;

	for (i = 0; i < k; i++)               //用循环控制链表长度（head指针数据为空，不包括在内）
	{
		cout << "请输入数据" << endl;        //输入数据

		cin >> p->data;

		cout << endl;

		p = new D;

		q->next = p;

		p->prior = q;                             
		/*prior指针指向前一个结点，next指向后一个结点*/
		q = p;
	}

	q->next = NULL;

	tail = q->prior;

	p = head->next;

	for (i = 0; i < k; i++)                    //从前往后输出
	{
		cout << p->data << endl;

		p = p->next;

	}

	p = tail;

	for(i=0;i<k;i++)                           //从后往前输出
	{
		cout << p->data << endl;

		p = p->prior;
	}

	return 0;

}
