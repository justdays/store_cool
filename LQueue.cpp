#include "LQueue.h" 
#include<iostream>
using namespace std;
#pragma

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
		cout << "请输入队列的初始大小(小于10)" << endl;

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

	cin >> (Q->front)->data;
	

	for (i = 0; i < k - 1; i++)

	{
		p = new Node;

		Q->length = Q->length + 1;

		p->next = nullptr;

		Q->tail->next = p;

		cout << "请输入数据" << endl;

		cin >> p->data;

		Q->tail = p;
	}
	cout << "初始化完成" << endl;

	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	if (Q->front == Q->tail)return ;
	delete Q->front;
	delete Q->tail;
	Q->length = 0;
	cout << "摧毁完成" << endl;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(LQueue *Q){
	if (Q->front == nullptr)return FALSE;
	else return TRUE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q){
	if (IsEmptyLQueue(Q)==0)return FALSE;
	cout << "队头元素为：" << Q->front->data << endl;
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	int l;
	Node *p=Q->front;
	for(l=1;p->next!=nullptr;l++)
	{
		p = p->next;
	}
	cout << "队列长度为：" <<Q->length<< endl;

	return l;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, int data){
	if (IsEmptyLQueue(Q) == 0)return FALSE;
	Node* p=new Node;
	p->data = data;
	p->next = nullptr;
	Q->tail->next = p;
	Q->tail = p;
	Q->length++;
	cout << "入队完成" << endl;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
	cout<<"出队完成" << endl;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if (IsEmptyLQueue(Q) == 0)return;
	Q->front = Q->tail;
	Q->front = nullptr;
	Q->length = 0;
	cout << "清空完成" << endl;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
	cout << "遍历完成" << endl;
	return TRUE;

}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
	
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
 // LQUEUE_H_INCLUDED


