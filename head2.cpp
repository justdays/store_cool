#include<iostream>
#include<stdio.h>
#include"head2.h"
using namespace std;

int main()
{
	S* p;
	p = creat();
	menu(p);
	return 0;
}

void menu(S* p)
{
	cout << "                        ������ָ��" << endl;
	cout << endl;
	cout << "--------  -1.��������" << endl;
	cout << "--------  0.��������" << endl;
	cout << "--------  1.��ӡ������" << endl;
	cout << "--------  2.��ӡ��i��Ԫ��" << endl;
	cout << "--------  3.ȫ����ӡ" << endl;
	cout << "--------  4.��β����ͷ�����һ��Ԫ��" << endl;
	cout << "--------  5.�ڵ�i+1λ����Ԫ��" << endl;
	cout << "--------  6.�޸ĵ�i��Ԫ��" << endl;
	cout << "--------  7.ɾ����i+1��Ԫ��(��ͷβԪ��)" << endl;
	cout << "--------  8.ɾ��ͷ��βԪ��" << endl;
	int a = 0;
	cout << "                        ������ָ��:";
	cin >> a;
	cout << endl;
	switch (a)
	{
	case -1:exit(0); break;                    //��������
	case 0: {
		p = creat(); menu(p); break; }
		  //��������
	case 1: {
		int k = 0;
		if (p == NULL) { cout << "����������,���ȴ�������" << endl; menu(p); }
		else { k = read_lenth(p); cout << k << endl; menu(p); }
		break;
	}
		  //��ӡ������
	case 2: {
		if (p == NULL) { cout << "����������,���ȴ�������" << endl; menu(p); }
		else { print_one(p); menu(p); }
		break;
	}
		  //��ӡ��i��Ԫ��
	case 3: {
		if (p == NULL) { cout << "����������,���ȴ�������" << endl; menu(p); }
		else { print_all(p); menu(p); }
		break;
	}
		  //ȫ����ӡ
	case 4: {
		if (p == NULL) { cout << "����������,���ȴ�������" << endl; menu(p); }
		else { p = add_ht(p); menu(p); }
		break;
	}
		  //��β����ͷ�����һ��Ԫ��
	case 5: {if (p == NULL) { cout << "����������,���ȴ�������" << endl; menu(p); }
		  else { p = insert(p); menu(p); }
		  break;
	}
		  //�ڵ�i+1ǰ����Ԫ��
	case 6: {
		if (p == NULL) { cout << "����������,���ȴ�������" << endl; menu(p); }
		else { p = correct(p); menu(p); }
		break;
	}
		  //�޸ĵ�i��Ԫ��
	case 7: {
		if (p == NULL) { cout << "����������,���ȴ�������" << endl; menu(p); }
		else { p = del(p); menu(p); }
		break;
	}

	case 8: {
		if (p == NULL) { cout << "����������,���ȴ�������" << endl; menu(p); }
		else {
			p = delet(p); menu(p); break;
		}
	}
		  //ɾ����i+1��Ԫ��Ԫ��
	default:cout << "�������!!!" << endl; menu(p);
		break;
	}



}

S* creat()
{
	S* head, * p, * q;

	int k, i;

	head = new S;                           //ָ��ĳ�ʼ��

	head->prior = NULL;

	p = head;

	q = p;

	cout << "������������" << endl;

	cin >> k;

	cout << endl;

	cout << "����������" << endl;        //��������

	cin >> p->data;

	cout << endl;

	for (i = 0; i < k - 1; i++)               //��ѭ�����������ȣ�headָ������Ϊ�գ����������ڣ�
	{
		p = new class S;

		p->prior = q;

		q->next = p;

		cout << "����������" << endl;        //��������

		cin >> p->data;

		cout << endl;

		q = p;
	}

	q->next = NULL;

	p = head->next;

	cout << "˫�������Ѵ�����ɡ�" << endl;

	return head;

}

S* insert(S* p) {
	S* head = p;
	S* q = NULL;
	int j = 0;
	cout << "������i��ֵ" << endl;
	cin >> j;
	for (int i = 1; i < j; i++)
	{
		p = p->next;                      //pΪ��i��Ԫ��
	}
	q = new S;
	q->next = p->next;
	p->next = q;
	cout << "��������ӵ�ֵ" << endl;
	cin >> q->data;
	cout << "�Ѳ���" << endl;
	return head;
}

S* del(S* p) {
	S* head = p;
	S* q = NULL;
	int j = 0;
	cout << "������i��ֵ" << endl;
	cin >> j;
	for (int i = 1; i < j; i++)
	{
		p = p->next;                      //pΪ��i��Ԫ��
	}
	cout << "��i������Ϊ��" << p->data << endl;
	q = p->next;                                //��pΪ��i��Ԫ�أ�ɾ����q,q�ǵ�i+1��
	p->next = q->next;
	cout << endl;
	cout << "��ɾ��" << endl;
	return head;
}

S* correct(S* p) {
	S* head = p;
	int j = 0;
	cout << "������i��ֵ" << endl;
	cin >> j;
	/*��i=1ʱ��ָ��ָ��ڶ������ݣ���Ҫ�����i����i��<j*/
	for (int i = 1; i < j; i++)
	{
		p = p->next;
	}
	cout << "��i������Ϊ��" << p->data << endl << "�������޸���ֵ��";
	cin >> p->data;
	cout << endl;
	cout << "�޸ĺ��i������Ϊ��" << p->data << endl;
	return head;
}

int read_lenth(S* p) {
	int c = 0;
	/*ÿ����һ����㣬c��һ����c�Ĵ�С��������ĳ���*/
	for (; p != NULL;)
	{
		c++;

		p = p->next;
	}
	return c;
}

void print_one(S* p)
{
	int j = 0;
	cout << "������i��ֵ" << endl;
	cin >> j;
	/*��i=1ʱ��ָ��ָ��ڶ������ݣ���Ҫ�����i����i��<j*/
	for (int i = 1; i < j; i++)
	{
		p = p->next;
	}
	cout << "��i������Ϊ��" << p->data << endl;

}

void print_all(S* p)
{
	for (; p != NULL;)
	{
		cout << p->data << endl;
		p = p->next;

	}
	cout << "������" << endl;
}

S* add_ht(S* p) {
	int i = 0;
	S* head = p;
	cout << "����ͷ���������1����ĩβ���������0" << endl;
	cin >> i;
	switch (i)
	{
	case 0:
	{
		for (; p->next != NULL;)
		{
			p = p->next;
			/*����ѭ���ﵽ���һ�����*/
		}
		p->next = new S;
		p = p->next;
		p->next = NULL;
		cout << "��������ӵ�ֵ" << endl;
		cin >> p->data;
		cout << "ĩβ��ӳɹ�" << endl;
		/*��ʱָ��ָ�����һ����㣬��Ҫ����ָ���һ��*/
		return head;
		menu(p);
		break;
	}
	case 1:
	{
		S* head_2 = p;
		p = p->next;
		S* q = new S;
		q->next = head->next;
		head->next = q;
		q->data = head->data;
		cout << "��������ӵ�ֵ" << endl;
		cin >> head->data;
		cout << "��ͷ��ӳɹ�" << endl;
		return head_2;
		break;
	}
	default:cout << "�������!!!" << endl; menu(p);
		break;

	}
}

S* delet(S* p) {
	int m = 0;
	S* head = p;
	cout << "��ɾ��ͷ������1����ɾ��ĩβ������0" << endl;
	cout << "������i��ֵ" << endl;
	cin >> m;
	if (m == 1) { head = head->next; cout << "��ɾ��" << endl; return head; }
	else if (m == 0) {
		for (; (p->next)->next != NULL;) { p = p->next; }
		p->next = NULL;
		cout << "��ɾ��" << endl;
		return head;
	}
	else { cout << "�������" << endl; menu(p); }
}