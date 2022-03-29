#pragma once
#include "LinkStack.h" 
#include<iostream>
using namespace std;
//链栈

void menu(LinkStack* s)
{
	void read(LinkStack * s);//输出全部元素函数
	int i = 0;
	cout << "                         链栈的实现" << endl;
	cout << "-----------" << " " << "1.初始化栈" << endl;
	cout << "-----------" << " " << "2.检测栈长度" << endl;
	cout << "-----------" << " " << "3.入栈" << endl;
	cout << "-----------" << " " << "4.出栈" << endl;
	cout << "-----------" << " " << "5.得到栈顶元素" << endl;
	cout << "-----------" << " " << "6.判断栈是否为空" << endl;
	cout << "-----------" << " " << "7.清空栈" << endl;
	cout << "-----------" << " " << "8.销毁栈" << endl;
	cout << "-----------" << " " << "9.输出栈数据" << endl;
	cout << "-----------  请输入命令序号:" ;
	cin >> i;
	switch (i)
	{
	case 1: {
		initLStack(s); menu(s); break;
	}
	case 2: {
		int j = 0;
		cout << "请输入你认为的栈长度" << endl;
		cin >> j;
		LStackLength( s, j); menu(s); break;
	}
	case 3: {
		int a = 0;
		while (true)
		{
			cout << "请输入入栈的数据(小于2147483647)" << endl;

			cin >> a;

			if (cin.fail())
			{
				cin.clear();

				cin.ignore(2000, '\n');
			}

			else if (a<2147483647 && a>-2147483648) { break; }

			cout << "输入错误，请重新输入" << endl;
		}
		pushLStack(s, a); menu(s); break;
	}
	case 4: {
		int a = 0;
		cout << "请输入出栈的数据" << endl;
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
	default: {cout << "输入错误" << endl; menu(s); break; }
	}


}

//初始化栈

Status initLStack(LinkStack* s) {

	int i,k;
	
	s->top = new StackNode;
	
	s->count = 1;

	(s->top)->next = nullptr;

	StackNode* p,*q;

	q = s->top;

	while (true)
	{
		cout << "请输入栈的初始大小(小于10)" << endl;

		cin >> k;

		if (cin.fail())
		{
			cin.clear();

			cin.ignore(2000, '\n');
		}

		else if (k >= 1 && k <= 10) { break; }

		cout << "输入错误，请重新输入" << endl;
	}
	
	cout << "请输入数据" << endl;

	cin >> (s->top)->data;

	for (i = 0; i < k-1; i++)

	{
		p = new StackNode;

		s->count = s->count + 1;

		p->next=s->top;

		s->top = p;

		cout << "请输入数据" << endl;

		cin >> (s->top)->data;
	}
	cout << "初始化完成" << endl;

	return SUCCESS;
}


//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	if (s->count == -1) { cout << "栈不存在" << endl; menu(s); return ERROR;}

	if (s->top == NULL) { s->count = -1; cout << "栈为空" << endl; menu(s); return ERROR; }

	else if (s->top != NULL) { cout << "栈不为空" << endl;  }

	return SUCCESS;
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType e) {
	if(s->count == -1){ cout << "栈不存在" << endl; menu(s); return ERROR;}

	if (s->top == nullptr) { cout << "栈为空" << endl; menu(s); return ERROR; }

	cout << "栈顶元素为：" << (s->top)->data << endl;

	menu(s);

	return SUCCESS;

}

//清空栈
Status clearLStack(LinkStack* s) {
	if (s->count == -1) { cout << "栈不存在" << endl; menu(s); return ERROR; }

	if (s->top == nullptr) { cout << "栈为空" << endl; menu(s); return ERROR;}

	StackNode* p;

	p = s->top;

	for (; p->next != nullptr;)
	{
		p = p->next;
	}
	
	s->top = nullptr;

	s->count = 0;

	cout << "清空完成" << endl;

	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack* s) {
	if (s->count==-1 ) { cout << "栈不存在" << endl; menu(s); return ERROR; }

	if (s->top == nullptr) { cout << "栈为空" << endl; menu(s); return ERROR;}

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

	cout << "销毁完成" << endl;

	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack* s, int length) {
	if (s->count == -1) { cout << "栈不存在" << endl; menu(s); return ERROR; }

	if (s->top == nullptr) { cout << "栈为空,长度为0" << endl; menu(s); return ERROR;}

	int c = 1;

	StackNode* p=s->top;

	if ((s->top)->next == nullptr) { cout << c << endl; return SUCCESS; }

	for (; (s->top)->next != nullptr;)
	{
		s->top = (s->top)->next;
		
		c++;
	}
	s->top = p;

	if (c == length) { cout << "长度正确" << c << endl; menu(s); return SUCCESS; }
	else if (c != length) { cout << "长度不正确，以下是正确长度：";cout<< c << endl; menu(s); return ERROR; }
}

//入栈
Status pushLStack(LinkStack* s, ElemType data) {
	if (s->count == -1) { cout << "栈不存在" << endl; menu(s); return ERROR; }

	if (s->top == nullptr) { cout << "栈为空" << endl; menu(s); return ERROR;}

	StackNode* p;

	p = new StackNode;

	p->data = data;

	p->next = s->top;

	s->top = p;
	
	cout << "入栈成功" << endl;

	return SUCCESS;

}

//出栈
Status popLStack(LinkStack* s, ElemType  data) {
	if (s->count == -1) { cout << "栈不存在" << endl; menu(s); return ERROR; }

	if (s->top == nullptr) { cout << "栈为空" << endl; menu(s); return ERROR; }

	cout << "出栈元素为：" ;

	cout << (s->top)->data << endl;

	StackNode* p= s->top;

	s->top = (s->top)->next;

	delete p;

	cout << "出栈成功" << endl;

	return SUCCESS;
}

//输出栈中的数据
void read(LinkStack* s){
	StackNode* p=s->top;

	if(s->count == -1){ cout << "栈不存在" << endl; menu(s);  }

	if (p == nullptr) { cout << "栈为空" << endl; menu(s); }

	for (; p!= nullptr;)
	{
		cout << p->data << endl;

		p = p->next;
	}
	cout << "全部输出完成" << endl;
}



