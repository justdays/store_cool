#include "sort.h"
#include"creat.h"

int b[10000] = { 0 };
int c[50000] = { 0 };
int d[200000] = { 0 };

void color(int a[], int n)
{
	int* p, * q, * o;
	int i,temp=0;
	p = &a[0];
	q = &a[n - 1];
	o = p;
	for (i = 0; i < n; i++)
	{
		if (o > q) { break; }
		if (*o == 0) { 
			temp = *p; *p = *o; *o = temp; p++; 
		    if (*o == 0) { temp = *p; *p = *o; *o = temp; p++; }
			if(*o == 2) { temp = *q; *q = *o; *o = temp; q--; }
		}
		if (*o == 2) {
			temp = *q; *q = *o; *o = temp; q--;
			if (*o == 0) { temp = *p; *p = *o; *o = temp; p++; }
			if (*o == 2) { temp = *q; *q = *o; *o = temp; q--; }
		}
		o++;
	}
	cout << "排序完成" << endl;
}

int* read(int k)
{
	ifstream infile("random number.txt", ios::in);
	if (!infile) { cout << "出错啦！文件出错了！！" << endl; }
	
	int i = 0;
	switch (k)
	{
	case 0: {int arr[100];
		for (i = 0; i < 100; i++)
		{
			infile >> arr[i];
		}
		return arr;
		break;
	}
	case 1: {

		for (i = 0; i < 10000; i++)
		{
			infile >> b[i];
		}
		return b;
		break;
	}
	case 2: {

		for (i = 0; i < 50000; i++)
		{
			infile >> c[i];
		}
		return c;
		break;
	}
	case 3: {

		for (i = 0; i < 200000; i++)
		{
			infile >> d[i];
		}
		return d;
		break;
	}
	default:cout << "出错了，输入出错，自动退出" << endl; exit(0);
	}
}

void fin(int a[], int left, int right, int k)
{
	int temp = 0;
	int x = a[0];
	int l = left;
	int r = right;
	while (l < r)
	{
		while (a[r] >= x && l < r) { r--; }
		if (l < r) { temp = a[r]; a[r] = a[l]; a[l] = temp; }
		while (a[l] < x && l < r) { l++; }
		if (l < r) { temp = a[r]; a[r] = a[l]; a[l] = temp; }
	}
	a[l] = x;
	if (l == k){cout << "第k小的数为：" << x << endl;
}
	else {
		fin(a, left, l - 1, k);
		fin(a, l + 1, right, k);
	}

}

void menu(int arr[],int n)
{
	int k = 0;
	cout << "-------- 1." << "插入排序" << endl;
	cout << "-------- 2." << "快速排序" << endl;
	cout << "-------- 3." << "归并排序" << endl;
	cout << "-------- 4." << "计数排序" << endl;
	cout << "-------- 5." << "基数排序" << endl;
	cout << "-------- 6." << "颜色排序" << endl;
	cout << "-------- 7." << "找到第k大的数" << endl;
	cout << "-------- 8." << "生成测试数据并保存到文件" << endl;
	cout << "-------- 9." << "读取数据到数组内并进行测试" << endl;
	cout << "-------- 10." << "100个数据10k次排序" << endl;
	cout << "--------------请输入指令：" << endl;
	cin >> k;
	switch (k)
	{
	case 1: {
		int i; clock_t start = clock();
		for (i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		InsertSort(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		clock_t end = clock();
		cout << "排序的时间为：" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
	case 2 :{int i; clock_t start = clock();
		for (i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		QuickSort(arr,0 ,n-1);
		for (int i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		clock_t end = clock();
		cout << "排序的时间为：" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
	case 3: {int i; clock_t start = clock();
		for (i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		MergeSort(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		clock_t end = clock();
		cout << "排序的时间为：" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
	case 4: {int i; clock_t start = clock();
		for (i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		CountSort(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		clock_t end = clock();
		cout << "排序的时间为：" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
	case 5: {int i; clock_t start = clock();
		for (i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		RadixSort(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		clock_t end = clock();
		cout << "排序的时间为：" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
	case 6:{clock_t start = clock();
		int arr[8] = { 1,2,1,0,2,0,0,1 };
		int n = 8;
		int i;
		for (i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		color(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << " " << arr[i];

		}
		cout << endl;
		clock_t end = clock();
		cout << "排序的时间为：" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
	case 7: {
		int a[7] = { 5,2,8,4,3,7,6 };
		int k = 3;
		fin(a, 0, 6, k); break;
	}
	case 8: {creat(); menu(arr, n); break; }
	case 9: {
		k = 0;
		int c = 0;
		cout << "0.100" << endl;
		cout << "1.10000" << endl;
		cout << "2.50000" << endl;
		cout << "3.200000" << endl;
		cout << "请输入读取数据的长度" << endl;
		cin >> k;
		switch (k)
		{
		case 0: {c = 100; break; }
		case 1: {c = 10000; break; }
		case 2: {c = 50000; break; }
		case 3: {c = 200000; break; }
		default:cout << "输入出错!!自动退出" << endl; exit(0); break;
		}
		arr = read(k); menu(arr, c); break;
	}
	case 10: {
		int i = 0;
		ifstream infile("random number.txt", ios::in);
		if (!infile) { cout << "出错啦！文件出错了！！" << endl; }
		int arr[100];
		int k = 0;
		cout << "-------- 1." << "插入排序" << endl;
		cout << "-------- 2." << "快速排序" << endl;
		cout << "-------- 3." << "归并排序" << endl;
		cout << "-------- 4." << "计数排序" << endl;
		cout << "-------- 5." << "基数排序" << endl;
		cout << "------------请输入排序方法" << endl;
		cin >> k;
		int i = 0;
		switch (k) {
		case 1: {
			clock_t start;
			for (i = 0; i < 100000; i++) {
				for (i = 0; i < 100; i++)
				{
					infile >> arr[i];
				}
				InsertSort(arr, 100);
			}
			cout << "排序的时间为：" << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl; break;
		}
		case 2: {
			clock_t start;
			for (i = 0; i < 100000; i++) {
				for (i = 0; i < 100; i++)
				{
					infile >> arr[i];
				}
				QuickSort(arr,0, 99);
			}
			cout << "排序的时间为：" << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl; break;
		}
		case 3: {
			clock_t start;
			for (i = 0; i < 100000; i++) {
				for (i = 0; i < 100; i++)
				{
					infile >> arr[i];
				}
				MergeSort(arr, 100);
			}
			cout << "排序的时间为：" << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl; break;
		}
		case 4: {
			clock_t start;
			for (i = 0; i < 100000; i++) {
				for (i = 0; i < 100; i++)
				{
					infile >> arr[i];
				}
				CountSort(arr, 100);
			}
			cout << "排序的时间为：" << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl; break;
		}
		case 5: {
			clock_t start;
			for (i = 0; i < 100000; i++) {
				for (i = 0; i < 100; i++)
				{
					infile >> arr[i];
				}
				RadixSort(arr, 100);
			}
			cout << "排序的时间为：" << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl; break;
		}
		default:cout << "输入出错，自动退出" << endl; exit(0);
		}
		
	}
	default:cout << "输入出错!!" << endl; break;
	}
}

void InsertSort(int a[],int k)
{
	int *p, *q,*o;
	int temp;
	p = a;
	q = a;
	for (int i = 1; i < k; i++)
	{
		p++;
		temp = *p;
		o = p;
		if (*p < *q) { while (temp < *q) { *o = *q; *q = temp; o--; q--; } }
		q = p;
	}
	cout << "排序成功" << endl;

}

void MergeSort(int a[], int k)//归并排序入口
{
	//分配一个辅助数组
	int* temarr = new int [k];
	if(temarr)
    {
		msort(a, temarr, 0, k - 1);
		
	}//分配成功
	else {
		cout << "错误：临时数组分配错误" << endl;
	}//分配失败

}

void merge(int a[], int temarr[], int left, int mid, int right)  //合并
{
	//标记左右半区第一个未排序的变量
	int l_pos = left;
	int r_pos = mid + 1;
	//临时数组第一个元素下标
	int pos = left;
	//合并
	while (l_pos <= mid && r_pos <= right)
	{
		if(a[l_pos]<a[r_pos])//左半区第一个更小
		{
			temarr[pos++] = a[l_pos++];
		}
		else { temarr[pos++] = a[r_pos++]; }//右半区第一个更小

	}
	//合并左半区剩余元素
	while (l_pos <= mid) { temarr[pos++] = a[l_pos++]; }
	//合并右半区剩余元素
	while (r_pos <= right) { temarr[pos++] = a[r_pos++]; }
	//把临时数组中合并后的元素复制回原来的数组,从左往右复制
	while (left <= right) { a[left] = temarr[left]; left++; }
}

void CountSort(int a[], int len)
{
	int i;
	if (len < 2)return;
	int max = a[0];//找出最大值，确定范围
	for(i=0;i<len;i++)
	{
		if (a[i] > max)max = a[i];
	}
	int* count = new int[max + 1];
	//创建统计数组，分配大小为max+1,全部赋值0
	memset(count, 0, sizeof(int) * (max + 1));
	//计数
	for (i = 0; i < len; i++)
	{
		count[a[i]]++;
	}
	//统计数组的累计值
	for (i = 1; i < max + 1; i++) 
	{
		count[i] = count[i - 1] + count[i];
	}
	int* output = new int[len];
	for (i = 0; i < len; i++) {
		output[count[a[i]] - 1] = a[i];//count[a[i]]是累计值
		count[a[i]]--;
	}
	for (i = 0; i < len; i++)
	{
		a[i] = output[i];
	}

}

void QuickSort(int a[], int left, int right)
{
	if (left >= right)return;
	//如果只有一个数，则不用划分
	int i, j, base, temp;
	i = left, j = right;
	base = a[left];
	while (i < j)
	{
		while (a[j] >= base && i < j)j--;
		while (a[i] <= base && i < j)i++;
		if (i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[left] = a[i];
	a[i] = base;
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, right);
	//以下是错误代码
		/*int l = left;
		int r = right;
		while (l < r) {
			//从右开始找到第一个小于基准数的数
			while (l<r&&a[r] >= x) { r--; }
			//并将它赋给左边的left
			if (l <= r) { a[l++] = a[r]; }
			//再从左开始找到第一个大于基准数的数，将他赋给右边的right，循环直到左右相遇
			while (l<r&&a[l] < x) { l++; }
			if (l <= r) { a[r--] = a[l]; }
		}
		//此时基准数应赋给l和r相遇的空间
		a[left] = x;
		//再递归划分，此时left为左端，right为右端，l和r为基准数不应被包含
		QuickSort(a, left, l - 1);
		QuickSort(a, l + 1, right);*/
	
}

void RadixSort(int a[], int len)
{
	int base = 1;//位数
	int max=a[0], i;
	//创建一个临时数组来存放一次计数排序后的数组
	int* t = new int[len];

	//先求出最大值
	for (i = 1; i < len; i++)
	{
		if (a[i] > max) { max = a[i]; }
	}
	//求出最大值的位数,用循环进行计数排序，分别对个位百位等排序
	while (max/base>0)
	{
		int bucket[10] = { 0 };
		//计算每个桶内有多少个数字
		for (i = 0; i < len; i++)
		{
			bucket[a[i] / base % 10]++;
		}
		for (i = 1; i < 10; i++)
		{
			bucket[i] = bucket[i - 1] + bucket[i];//bucket存放累计数
		}
		//存放第一次排序数据
		for (i = len-1; i >= 0; i--)
		{
			t[bucket[a[i] / base % 10] - 1] = a[i];
			bucket[a[i] / base % 10]--;
		}
		for (i = 0; i < len; i++)
		{
			a[i] = t[i];
		}
		base = base * 10;
	}

}

void msort(int a[], int temarr[], int left, int right)
{
  //如果只有一个元素，并不需要被划分
	if (left < right) {
		int mid = (left + right) / 2;//找到中间点
		msort(a, temarr, left, mid);//划分左半区
		msort(a, temarr, mid + 1, right);//划分右半区
		merge(a, temarr, left, mid, right);//合并函数
	}

}




