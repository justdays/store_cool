#pragma once
class S
{
public:
	S* prior;
	int data;
	S* next;
};

S* delet(S* p);

S* creat();

S* insert(S* p);

void menu(S* p);

S* del(S* p);

int read_lenth(S* p);

void print_one(S* p);

void print_all(S* p);

S* add_ht(S* p);

S* correct(S* p);

void menu(S* p);