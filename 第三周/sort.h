#pragma once
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#include<fstream>
using namespace std;


void color(int a[], int n);

int* read(int k);

void fin(int a[], int left,int right ,int k);

void menu(int arr[],int n);

void InsertSort(int a[],int k);

void MergeSort(int a[], int k);

void msort(int a[],int temarr[], int left, int right);

void merge(int a[], int temarr[], int  left, int mid, int right);

void CountSort(int a[], int len);

void QuickSort(int a[],int left,int right);

void RadixSort(int a[], int len);

