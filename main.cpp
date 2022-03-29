#include<iostream>
#include"LQueue.h"
using namespace std;

int main()
{
	void menu(LQueue * Q);
	LQueue *Q;
	Q = new Lqueue;
	Q->front = new Node;
	Q->tail = new Node;
	InitLQueue(Q);
	menu(Q);
	return 0;
}


void menu(LQueue* Q) {
	int i = 0;
	cout << "                         链栈的实现" << endl;
	cout << "-----------" << " " << "1.初始化队列" << endl;
	cout << "-----------" << " " << "2.得到队列长度" << endl;
	cout << "-----------" << " " << "3.入队" << endl;
	cout << "-----------" << " " << "4.出队" << endl;
	cout << "-----------" << " " << "5.判断队列是否为空" << endl;
	cout << "-----------" << " " << "6.查看队头元素" << endl;
	cout << "-----------" << " " << "7.清空队列" << endl;
	cout << "-----------" << " " << "8.销毁队列" << endl;
	cout << "-----------" << " " << "9.输出栈数据" << endl;
	cout << "-----------  请输入命令序号:";
	cin >> i;
	switch (i) {
	case 1: {
		InitLQueue(Q); menu(Q); break;
	}
	case 2: {
		LengthLQueue(Q); menu(Q); break;
	}
	case 3: {
		int data;
		cout << "请输入入队元素" << endl;
		cin >>data;
		EnLQueue(Q, data); menu(Q); break;
	}
	case 4: {
		DeLQueue(Q); menu(Q); break;
	}
	case 5: {
		if (IsEmptyLQueue(Q) == FALSE) { cout << "不为空" << endl; }
		if (IsEmptyLQueue(Q) == TRUE) { cout << "为空" << endl; }
		menu(Q); break;
	}
	case 6: {
		GetHeadLQueue(Q); menu(Q); break;
	}
	case 7: {
		ClearLQueue(Q); menu(Q); break;
	}
	case 8: {
		DestoryLQueue(Q); menu(Q); break;
	}
	case 9: {
		TraverseLQueue(Q); menu(Q); break;
	}
	}
	return;

}




