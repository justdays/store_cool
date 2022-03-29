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
	cout << "                         ��ջ��ʵ��" << endl;
	cout << "-----------" << " " << "1.��ʼ������" << endl;
	cout << "-----------" << " " << "2.�õ����г���" << endl;
	cout << "-----------" << " " << "3.���" << endl;
	cout << "-----------" << " " << "4.����" << endl;
	cout << "-----------" << " " << "5.�ж϶����Ƿ�Ϊ��" << endl;
	cout << "-----------" << " " << "6.�鿴��ͷԪ��" << endl;
	cout << "-----------" << " " << "7.��ն���" << endl;
	cout << "-----------" << " " << "8.���ٶ���" << endl;
	cout << "-----------" << " " << "9.���ջ����" << endl;
	cout << "-----------  �������������:";
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
		cout << "���������Ԫ��" << endl;
		cin >>data;
		EnLQueue(Q, data); menu(Q); break;
	}
	case 4: {
		DeLQueue(Q); menu(Q); break;
	}
	case 5: {
		if (IsEmptyLQueue(Q) == FALSE) { cout << "��Ϊ��" << endl; }
		if (IsEmptyLQueue(Q) == TRUE) { cout << "Ϊ��" << endl; }
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




