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

	head = new D;                           //ָ��ĳ�ʼ��
	p = new D;
	head->next = p;
	head->data = 0;
	q = p;

	cout << "������������" << endl;         

	cin >> k;

	cout << endl;

	for( i = 0; i < k; i++ )               //��ѭ�����������ȣ�headָ������Ϊ�գ����������ڣ�
	{
		cout << "����������" << endl;        //��������

		cin >> p->data;

		cout << endl;

		p = new D;

		q->next = p;

		q = p;
	}

	q->next = NULL;

	p = head->next;

	for (i = 0; i < k; i++)                    //���
	{
		cout << p->data<< endl;

		p = p->next;

	}
	return 0;
}
