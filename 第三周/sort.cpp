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
	cout << "�������" << endl;
}

int* read(int k)
{
	ifstream infile("random number.txt", ios::in);
	if (!infile) { cout << "���������ļ������ˣ���" << endl; }
	
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
	default:cout << "�����ˣ���������Զ��˳�" << endl; exit(0);
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
	if (l == k){cout << "��kС����Ϊ��" << x << endl;
}
	else {
		fin(a, left, l - 1, k);
		fin(a, l + 1, right, k);
	}

}

void menu(int arr[],int n)
{
	int k = 0;
	cout << "-------- 1." << "��������" << endl;
	cout << "-------- 2." << "��������" << endl;
	cout << "-------- 3." << "�鲢����" << endl;
	cout << "-------- 4." << "��������" << endl;
	cout << "-------- 5." << "��������" << endl;
	cout << "-------- 6." << "��ɫ����" << endl;
	cout << "-------- 7." << "�ҵ���k�����" << endl;
	cout << "-------- 8." << "���ɲ������ݲ����浽�ļ�" << endl;
	cout << "-------- 9." << "��ȡ���ݵ������ڲ����в���" << endl;
	cout << "-------- 10." << "100������10k������" << endl;
	cout << "--------------������ָ�" << endl;
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
		cout << "�����ʱ��Ϊ��" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
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
		cout << "�����ʱ��Ϊ��" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
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
		cout << "�����ʱ��Ϊ��" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
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
		cout << "�����ʱ��Ϊ��" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
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
		cout << "�����ʱ��Ϊ��" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
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
		cout << "�����ʱ��Ϊ��" << double(end - start) / CLOCKS_PER_SEC << "s" << endl; break; }
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
		cout << "�������ȡ���ݵĳ���" << endl;
		cin >> k;
		switch (k)
		{
		case 0: {c = 100; break; }
		case 1: {c = 10000; break; }
		case 2: {c = 50000; break; }
		case 3: {c = 200000; break; }
		default:cout << "�������!!�Զ��˳�" << endl; exit(0); break;
		}
		arr = read(k); menu(arr, c); break;
	}
	case 10: {
		int i = 0;
		ifstream infile("random number.txt", ios::in);
		if (!infile) { cout << "���������ļ������ˣ���" << endl; }
		int arr[100];
		int k = 0;
		cout << "-------- 1." << "��������" << endl;
		cout << "-------- 2." << "��������" << endl;
		cout << "-------- 3." << "�鲢����" << endl;
		cout << "-------- 4." << "��������" << endl;
		cout << "-------- 5." << "��������" << endl;
		cout << "------------���������򷽷�" << endl;
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
			cout << "�����ʱ��Ϊ��" << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl; break;
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
			cout << "�����ʱ��Ϊ��" << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl; break;
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
			cout << "�����ʱ��Ϊ��" << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl; break;
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
			cout << "�����ʱ��Ϊ��" << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl; break;
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
			cout << "�����ʱ��Ϊ��" << double(clock() - start) / CLOCKS_PER_SEC << "s" << endl; break;
		}
		default:cout << "��������Զ��˳�" << endl; exit(0);
		}
		
	}
	default:cout << "�������!!" << endl; break;
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
	cout << "����ɹ�" << endl;

}

void MergeSort(int a[], int k)//�鲢�������
{
	//����һ����������
	int* temarr = new int [k];
	if(temarr)
    {
		msort(a, temarr, 0, k - 1);
		
	}//����ɹ�
	else {
		cout << "������ʱ����������" << endl;
	}//����ʧ��

}

void merge(int a[], int temarr[], int left, int mid, int right)  //�ϲ�
{
	//������Ұ�����һ��δ����ı���
	int l_pos = left;
	int r_pos = mid + 1;
	//��ʱ�����һ��Ԫ���±�
	int pos = left;
	//�ϲ�
	while (l_pos <= mid && r_pos <= right)
	{
		if(a[l_pos]<a[r_pos])//�������һ����С
		{
			temarr[pos++] = a[l_pos++];
		}
		else { temarr[pos++] = a[r_pos++]; }//�Ұ�����һ����С

	}
	//�ϲ������ʣ��Ԫ��
	while (l_pos <= mid) { temarr[pos++] = a[l_pos++]; }
	//�ϲ��Ұ���ʣ��Ԫ��
	while (r_pos <= right) { temarr[pos++] = a[r_pos++]; }
	//����ʱ�����кϲ����Ԫ�ظ��ƻ�ԭ��������,�������Ҹ���
	while (left <= right) { a[left] = temarr[left]; left++; }
}

void CountSort(int a[], int len)
{
	int i;
	if (len < 2)return;
	int max = a[0];//�ҳ����ֵ��ȷ����Χ
	for(i=0;i<len;i++)
	{
		if (a[i] > max)max = a[i];
	}
	int* count = new int[max + 1];
	//����ͳ�����飬�����СΪmax+1,ȫ����ֵ0
	memset(count, 0, sizeof(int) * (max + 1));
	//����
	for (i = 0; i < len; i++)
	{
		count[a[i]]++;
	}
	//ͳ��������ۼ�ֵ
	for (i = 1; i < max + 1; i++) 
	{
		count[i] = count[i - 1] + count[i];
	}
	int* output = new int[len];
	for (i = 0; i < len; i++) {
		output[count[a[i]] - 1] = a[i];//count[a[i]]���ۼ�ֵ
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
	//���ֻ��һ���������û���
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
	//�����Ǵ������
		/*int l = left;
		int r = right;
		while (l < r) {
			//���ҿ�ʼ�ҵ���һ��С�ڻ�׼������
			while (l<r&&a[r] >= x) { r--; }
			//������������ߵ�left
			if (l <= r) { a[l++] = a[r]; }
			//�ٴ���ʼ�ҵ���һ�����ڻ�׼�����������������ұߵ�right��ѭ��ֱ����������
			while (l<r&&a[l] < x) { l++; }
			if (l <= r) { a[r--] = a[l]; }
		}
		//��ʱ��׼��Ӧ����l��r�����Ŀռ�
		a[left] = x;
		//�ٵݹ黮�֣���ʱleftΪ��ˣ�rightΪ�Ҷˣ�l��rΪ��׼����Ӧ������
		QuickSort(a, left, l - 1);
		QuickSort(a, l + 1, right);*/
	
}

void RadixSort(int a[], int len)
{
	int base = 1;//λ��
	int max=a[0], i;
	//����һ����ʱ���������һ�μ�������������
	int* t = new int[len];

	//��������ֵ
	for (i = 1; i < len; i++)
	{
		if (a[i] > max) { max = a[i]; }
	}
	//������ֵ��λ��,��ѭ�����м������򣬷ֱ�Ը�λ��λ������
	while (max/base>0)
	{
		int bucket[10] = { 0 };
		//����ÿ��Ͱ���ж��ٸ�����
		for (i = 0; i < len; i++)
		{
			bucket[a[i] / base % 10]++;
		}
		for (i = 1; i < 10; i++)
		{
			bucket[i] = bucket[i - 1] + bucket[i];//bucket����ۼ���
		}
		//��ŵ�һ����������
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
  //���ֻ��һ��Ԫ�أ�������Ҫ������
	if (left < right) {
		int mid = (left + right) / 2;//�ҵ��м��
		msort(a, temarr, left, mid);//���������
		msort(a, temarr, mid + 1, right);//�����Ұ���
		merge(a, temarr, left, mid, right);//�ϲ�����
	}

}




