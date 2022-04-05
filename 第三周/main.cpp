#include<iostream>
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include"sort.h"
using namespace std;
int main()
{
	int arr[8] = { 8,7,6,5,4,3,2,1 };
	menu(arr, 8);
	//clock_t start = clock();
	//int arr[8] = {1,2,1,0,2,0,0,1};
	//int n = 8;
	//int i;
	//for (i = 0; i < n; i++)
	//{
	//	cout << " " << arr[i];

	//}
	//cout << endl;
	//color(arr,n);
	//for (int i = 0; i < n; i++)
	//{
	//	cout << " " << arr[i];

	//}
	//cout << endl;
	//clock_t end = clock();
	//cout << "排序的时间为："<<double (end-start)/CLOCKS_PER_SEC<<"s" << endl;
	return 0;
}