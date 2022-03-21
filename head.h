#pragma once
#include<iostream>
#include<stdio.h>

using namespace std;

class D
{
public:
	int data;
	D* next;
};

D* delet(D* p);

D* creat();

D* insert(D* p);

void menu(D* p);

D* del(D* p);

int read_lenth(D* p);

void print_one(D* p);

void print_all(D* p);

D* add_ht(D* p);

D* correct(D* p);
