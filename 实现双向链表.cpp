#include<iostream>
#include<stdio.h>
using namespace std;
class D
{
public:
	D* prior;                              //ǰָ��
	int data;
	D* next;                               //��ָ��

};

int main()
{
	D* head, * p, * q, * tail;      //tailָ��ָ�����һ�����

	int k, i;

	head = new D;                   //ָ��ĳ�ʼ��
	
	p = new D;

	head->prior = NULL;

    head->data = 0;

	head->next = p;

	p->prior = head;

	q = p;

	cout << "������������" << endl;

	cin >> k;

	cout << endl;

	for (i = 0; i < k; i++)               //��ѭ�����������ȣ�headָ������Ϊ�գ����������ڣ�
	{
		cout << "����������" << endl;        //��������

		cin >> p->data;

		cout << endl;

		p = new D;

		q->next = p;

		p->prior = q;                             
		/*priorָ��ָ��ǰһ����㣬nextָ���һ�����*/
		q = p;
	}

	q->next = NULL;

	tail = q->prior;

	p = head->next;

	for (i = 0; i < k; i++)                    //��ǰ�������
	{
		cout << p->data << endl;

		p = p->next;

	}

	p = tail;

	for(i=0;i<k;i++)                           //�Ӻ���ǰ���
	{
		cout << p->data << endl;

		p = p->prior;
	}

	return 0;

}
