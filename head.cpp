#include<iostream>
#include<stdio.h>
#include"head.h"
using namespace std;

int main()
{
	D* p ;
	p = creat();
	menu(p);
	return 0;
}

void menu(D *p)
{
	cout << "                        请输入指令" << endl;
	cout << endl;
	cout << "--------  -1.结束程序" << endl;
	cout << "--------  0.创建链表" << endl;
	cout << "--------  1.打印链表长度" << endl;
	cout << "--------  2.打印第i个元素" << endl;
	cout << "--------  3.全部打印" << endl;
	cout << "--------  4.在尾部或头部添加一个元素" << endl;
	cout << "--------  5.在第i+1位插入元素" << endl;
	cout << "--------  6.修改第i个元素" << endl;
	cout << "--------  7.删除第i+1个元素(非头尾元素)" << endl;
	cout << "--------  8.删除头或尾元素" << endl;
	int a = 0;
	cout << "                        请输入指令:";
	cin >> a;
	cout << endl;
	switch (a)
	{
	case -1:exit(0); break;                    //结束程序
	case 0:{                         
		p=creat(); menu(p); break; }
		                                       //创建链表
	case 1:{
		int k = 0;
		if (p == NULL) { cout << "不存在链表,请先创造链表" << endl; menu(p); }
		else { k = read_lenth(p); cout << k << endl; menu(p); }
		break;
	 }
		                                       //打印链表长度
	case 2:{
		if (p == NULL) { cout << "不存在链表,请先创造链表" << endl; menu(p); }
		else { print_one(p); menu(p);  }
		break;
	}
		                                       //打印第i个元素
	case 3:{
		if(p==NULL) { cout << "不存在链表,请先创造链表" << endl; menu(p); }
		else { print_all(p); menu(p); }
		break;
	}
		                                       //全部打印
	case 4:{
		if (p == NULL) { cout << "不存在链表,请先创造链表" << endl; menu(p); }
		else { p=add_ht(p); menu(p); }
		break;
	}
		                                       //在尾部或头部添加一个元素
	case 5:{if (p == NULL) { cout << "不存在链表,请先创造链表" << endl; menu(p); }
		  else { p = insert(p); menu(p); }
		  break;
	}
		                                       //在第i+1前插入元素
	case 6:{
		if (p == NULL) { cout << "不存在链表,请先创造链表" << endl; menu(p); }
		else { p = correct(p); menu(p); }
		break;
	}
		                                       //修改第i个元素
	case 7:{
		if (p == NULL) { cout << "不存在链表,请先创造链表" << endl; menu(p); }
		else { p = del(p); menu(p); }
		break;
	}

	case 8: {
		if (p == NULL) { cout << "不存在链表,请先创造链表" << endl; menu(p); }
		else{
			p = delet(p); menu(p); break;
		}
	}
		                                       //删除第i+1个元素元素
	default:cout << "输入出错!!!" << endl; menu(p);
		break;
	}



}

D* delet(D* p) {
	int m = 0;
	D* head = p;
	cout << "若删除头则输入1，从删除末尾则输入0" << endl;
	cout << "请输入i的值" << endl;
	cin >> m;
	if (m == 1) { head = head->next; cout << "已删除" << endl; return head; }
	else if (m == 0) {
		for (; (p->next)->next != NULL;) { p = p->next; }
		p->next = NULL;
		cout << "已删除" << endl;
		return head;
	}
	else { cout << "输入出错" << endl; menu(p); }
}

D* creat()
{
	D* head, * p, * q;

	int k, i;

	head = new D;                           //指针的初始化

	p = head;

	q = p;

	cout << "请输入链表长度" << endl;

	cin >> k;

	cout << endl;

	cout << "请输入数据" << endl;        //输入数据

	cin >> p->data;

	cout << endl;

	for (i = 0; i < k-1; i++)               //用循环控制链表长度（head指针数据为空，不包括在内）
	{
		p = new class D;

		q->next = p;

		cout << "请输入数据" << endl;        //输入数据

		cin >> p->data;

		cout << endl;

		q = p;
	}

	q->next = NULL;

	p = head->next;

	cout << "单链表已创建完成。" << endl;

	return head;

}

D* insert(D* p){
	D* head = p;
	D* q = NULL;
	int j = 0;
	cout<< "请输入i的值" << endl;
	cin >> j;
	for (int i = 1; i < j; i++)
	{
		p = p->next;                      //p为第i个元素
	}
	q = new D;
	q->next = p->next;
	p->next = q;
	cout << "请输入添加的值" << endl;
	cin >> q->data;
	cout << "已插入" << endl;
	return head;
}

D* del(D* p) {
	D* head = p;
	D* q=NULL;
	int j = 0;
	cout << "请输入i的值" << endl;
	cin >> j;
	for (int i = 1; i < j; i++)
	{
		p = p->next;                      //p为第i个元素
	}
	cout << "第i个数据为：" << p->data << endl;
	q = p->next;                                //即p为第i个元素，删除了q,q是第i+1个
	p->next=q->next;
	cout << endl;
	cout << "已删除"<<endl;
	return head;
}

D* correct(D* p)
{
	D* head = p;
	int j = 0;
	cout << "请输入i的值" << endl;
	cin >> j;
	/*当i=1时，指针指向第二个数据，故要输出第i个，i就<j*/
	for (int i = 1; i < j; i++)
	{
		p = p->next;
	}
	cout << "第i个数据为：" << p->data << endl<<"请输入修改数值：";
	cin >> p->data;
	cout << endl;
	cout << "修改后第i个数据为：" << p->data << endl;
	return head;
}

int read_lenth(D* p)
{
	int c = 0;
	/*每经过一个结点，c加一，故c的大小就是链表的长度*/
	for (; p!= NULL;)
	{
		c++;

		p = p->next;
	}
	return c;
}

void print_one(D* p)
{
	int j = 0;
	cout << "请输入i的值" << endl;
	cin >> j;
	/*当i=1时，指针指向第二个数据，故要输出第i个，i就<j*/
	for (int i = 1; i < j; i++)
	{
		p = p->next;
	}
	cout << "第i个数据为：" << p->data << endl;

}

void print_all(D* p)
{
	for (; p != NULL;)
	{
		cout << p->data << endl;
		p = p->next;

	}
	cout << "输出完成" << endl;
}

D* add_ht(D* p)
{
	int i=0;
	D* head=p;
	cout << "若从头添加则输入1，从末尾添加则输入0" << endl;
	cin >> i;
	switch (i)
	{
	case 0:
	{
		for (; p->next != NULL;)
		{
			p = p-> next;
			/*先用循环达到最后一个结点*/
		}
		p->next = new D;
		p = p->next;
		p->next = NULL;
		cout<< "请输入添加的值" << endl;
		cin >> p->data;
		cout << "末尾添加成功" << endl;
		/*此时指针指向最后一个结点，故要将其指向第一个*/
		return head;
		menu(p);
		break;
	}
	case 1:
	{
		D* head_2=p;
		p = p->next;
		D* q = new D;
		q->next = head->next;
		head->next = q;
		q->data = head->data;
		cout<< "请输入添加的值" << endl;
		cin >> head->data;
		cout << "开头添加成功" << endl;
		return head_2;
		break;
	}
	default:cout << "输入出错!!!" << endl; menu(p);
		break;

	}
}