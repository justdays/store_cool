#pragma once
#include "LinkStack.h" 
#include<iostream>
using namespace std;
//��ջ

void menu(LinkStack* s)
{
	void read(LinkStack * s);//���ȫ��Ԫ�غ���
	int i = 0;
	cout << "                         ��ջ��ʵ��" << endl;
	cout << "-----------" << " " << "1.��ʼ��ջ" << endl;
	cout << "-----------" << " " << "2.���ջ����" << endl;
	cout << "-----------" << " " << "3.��ջ" << endl;
	cout << "-----------" << " " << "4.��ջ" << endl;
	cout << "-----------" << " " << "5.�õ�ջ��Ԫ��" << endl;
	cout << "-----------" << " " << "6.�ж�ջ�Ƿ�Ϊ��" << endl;
	cout << "-----------" << " " << "7.���ջ" << endl;
	cout << "-----------" << " " << "8.����ջ" << endl;
	cout << "-----------" << " " << "9.���ջ����" << endl;
	cout << "-----------  �������������:" ;
	cin >> i;
	switch (i)
	{
	case 1: {
		initLStack(s); menu(s); break;
	}
	case 2: {
		int j = 0;
		cout << "����������Ϊ��ջ����" << endl;
		cin >> j;
		LStackLength( s, j); menu(s); break;
	}
	case 3: {
		int a = 0;
		while (true)
		{
			cout << "��������ջ������(С��2147483647)" << endl;

			cin >> a;

			if (cin.fail())
			{
				cin.clear();

				cin.ignore(2000, '\n');
			}

			else if (a<2147483647 && a>-2147483648) { break; }

			cout << "�����������������" << endl;
		}
		pushLStack(s, a); menu(s); break;
	}
	case 4: {
		int a = 0;
		cout << "�������ջ������" << endl;
		cin >> a;
		popLStack(s,a); menu(s); break;
	}
	case 5: {
		ElemType e=0;
		getTopLStack(s,e); menu(s); break;
	}
	case 6: {
		isEmptyLStack( s); menu(s); break;
	}
	case 7: {
		clearLStack(s); menu(s); break;
	}
	case 8: {
		destroyLStack(s); menu(s); break;
	}
	case 9: {
		read(s); menu(s); break;
	}
	default: {cout << "�������" << endl; menu(s); break; }
	}


}

//��ʼ��ջ

Status initLStack(LinkStack* s) {

	int i,k;
	
	s->top = new StackNode;
	
	s->count = 1;

	(s->top)->next = nullptr;

	StackNode* p,*q;

	q = s->top;

	while (true)
	{
		cout << "������ջ�ĳ�ʼ��С(С��10)" << endl;

		cin >> k;

		if (cin.fail())
		{
			cin.clear();

			cin.ignore(2000, '\n');
		}

		else if (k >= 1 && k <= 10) { break; }

		cout << "�����������������" << endl;
	}
	
	cout << "����������" << endl;

	cin >> (s->top)->data;

	for (i = 0; i < k-1; i++)

	{
		p = new StackNode;

		s->count = s->count + 1;

		p->next=s->top;

		s->top = p;

		cout << "����������" << endl;

		cin >> (s->top)->data;
	}
	cout << "��ʼ�����" << endl;

	return SUCCESS;
}


//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	if (s->count == -1) { cout << "ջ������" << endl; menu(s); return ERROR;}

	if (s->top == NULL) { s->count = -1; cout << "ջΪ��" << endl; menu(s); return ERROR; }

	else if (s->top != NULL) { cout << "ջ��Ϊ��" << endl;  }

	return SUCCESS;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType e) {
	if(s->count == -1){ cout << "ջ������" << endl; menu(s); return ERROR;}

	if (s->top == nullptr) { cout << "ջΪ��" << endl; menu(s); return ERROR; }

	cout << "ջ��Ԫ��Ϊ��" << (s->top)->data << endl;

	menu(s);

	return SUCCESS;

}

//���ջ
Status clearLStack(LinkStack* s) {
	if (s->count == -1) { cout << "ջ������" << endl; menu(s); return ERROR; }

	if (s->top == nullptr) { cout << "ջΪ��" << endl; menu(s); return ERROR;}

	StackNode* p;

	p = s->top;

	for (; p->next != nullptr;)
	{
		p = p->next;
	}
	
	s->top = nullptr;

	s->count = 0;

	cout << "������" << endl;

	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack* s) {
	if (s->count==-1 ) { cout << "ջ������" << endl; menu(s); return ERROR; }

	if (s->top == nullptr) { cout << "ջΪ��" << endl; menu(s); return ERROR;}

	StackNode* p;

	p = s->top;

	s->top = (s->top)->next;

	for (; p->next != nullptr;)
	{
		delete p;

		p = s->top;

		s->top = (s->top)->next;		
	}
	s->count = -1;

	delete s->top;

	s = nullptr;

	cout << "�������" << endl;

	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int length) {
	if (s->count == -1) { cout << "ջ������" << endl; menu(s); return ERROR; }

	if (s->top == nullptr) { cout << "ջΪ��,����Ϊ0" << endl; menu(s); return ERROR;}

	int c = 1;

	StackNode* p=s->top;

	if ((s->top)->next == nullptr) { cout << c << endl; return SUCCESS; }

	for (; (s->top)->next != nullptr;)
	{
		s->top = (s->top)->next;
		
		c++;
	}
	s->top = p;

	if (c == length) { cout << "������ȷ" << c << endl; menu(s); return SUCCESS; }
	else if (c != length) { cout << "���Ȳ���ȷ����������ȷ���ȣ�";cout<< c << endl; menu(s); return ERROR; }
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	if (s->count == -1) { cout << "ջ������" << endl; menu(s); return ERROR; }

	if (s->top == nullptr) { cout << "ջΪ��" << endl; menu(s); return ERROR;}

	StackNode* p;

	p = new StackNode;

	p->data = data;

	p->next = s->top;

	s->top = p;
	
	cout << "��ջ�ɹ�" << endl;

	return SUCCESS;

}

//��ջ
Status popLStack(LinkStack* s, ElemType  data) {
	if (s->count == -1) { cout << "ջ������" << endl; menu(s); return ERROR; }

	if (s->top == nullptr) { cout << "ջΪ��" << endl; menu(s); return ERROR; }

	cout << "��ջԪ��Ϊ��" ;

	cout << (s->top)->data << endl;

	StackNode* p= s->top;

	s->top = (s->top)->next;

	delete p;

	cout << "��ջ�ɹ�" << endl;

	return SUCCESS;
}

//���ջ�е�����
void read(LinkStack* s){
	StackNode* p=s->top;

	if(s->count == -1){ cout << "ջ������" << endl; menu(s);  }

	if (p == nullptr) { cout << "ջΪ��" << endl; menu(s); }

	for (; p!= nullptr;)
	{
		cout << p->data << endl;

		p = p->next;
	}
	cout << "ȫ��������" << endl;
}



