#include "LQueue.h" 
#include<iostream>
using namespace std;
#pragma

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	int i, k;

	Q->length = 1;

	Q->front= Q->tail;

	(Q->front)->next = nullptr;

	Node* p;

	while (true)
	{
		cout << "��������еĳ�ʼ��С(С��10)" << endl;

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

	cin >> (Q->front)->data;
	

	for (i = 0; i < k - 1; i++)

	{
		p = new Node;

		Q->length = Q->length + 1;

		p->next = nullptr;

		Q->tail->next = p;

		cout << "����������" << endl;

		cin >> p->data;

		Q->tail = p;
	}
	cout << "��ʼ�����" << endl;

	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	if (Q->front == Q->tail)return ;
	delete Q->front;
	delete Q->tail;
	Q->length = 0;
	cout << "�ݻ����" << endl;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(LQueue *Q){
	if (Q->front == nullptr)return FALSE;
	else return TRUE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q){
	if (IsEmptyLQueue(Q)==0)return FALSE;
	cout << "��ͷԪ��Ϊ��" << Q->front->data << endl;
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	int l;
	Node *p=Q->front;
	for(l=1;p->next!=nullptr;l++)
	{
		p = p->next;
	}
	cout << "���г���Ϊ��" <<Q->length<< endl;

	return l;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, int data){
	if (IsEmptyLQueue(Q) == 0)return FALSE;
	Node* p=new Node;
	p->data = data;
	p->next = nullptr;
	Q->tail->next = p;
	Q->tail = p;
	Q->length++;
	cout << "������" << endl;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if (IsEmptyLQueue(Q) == 0)return FALSE;
	Node* p;
	p = Q->front;
	Q->front = p->next;
	cout << p->data << endl;
	Q->length--;
	delete p;
	cout<<"�������" << endl;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if (IsEmptyLQueue(Q) == 0)return;
	Q->front = Q->tail;
	Q->front = nullptr;
	Q->length = 0;
	cout << "������" << endl;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q){
	Node* p = Q->front;
	for(;p->next!=nullptr;)
	{
		cout << p->data<<endl;
		p = p->next;

	}
	cout << p->data << endl;
	cout << "�������" << endl;
	return TRUE;

}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
	
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
 // LQUEUE_H_INCLUDED


