#pragma once
#define _USE_CRT_NO_SECURE_WARNINGS
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include "Header.h"
#include "List.h"

using namespace std;

void Adder(NodeList& nodelist, Rational current);

void ListCreator_alt(int n, NodeList*& Kantor)
{
	int str = 1;
	int tmp_str = str;
	int stlb = 0;
	int tmp_stlb = stlb;
	int stlbincr = 1, tmp_stlbincr = 1;
	bool d = 0, s = 0, tmp_s = 0;
	Rational current;
	int current_element = 1;
	for (current_element; current_element <= n;) {
		current.numerator = stlb;
		current.number = current_element;
		current.denominator = str;
		current.s = s;
		Kantor->addLast(current);
		current_element++;
		if (current_element > n)break;
		if (d == 0) {
			str++;
			tmp_str = str;
			switch (s) {
			case 0: {
				stlb -= stlbincr;
				s = 1;
				stlbincr++;
			}
			case 1: {
				stlb += stlbincr;
				s = 0;
				stlbincr++;
			}
			}
			current.number = current_element;
			current.denominator = tmp_str;
			current.numerator = tmp_stlb;
			current.stlbincr = stlbincr;
			current.s = s;
			Kantor->addLast(current);
			current_element++;
			if (current_element > n)break;
			while (tmp_stlb != stlb) {
				tmp_stlb--;
				current.number = current_element;
				current.denominator = tmp_str;
				current.numerator = tmp_stlb;
				current.stlbincr = stlbincr;
				current.s = s;
				switch (tmp_s) {
				case 0: {
					tmp_stlb -= tmp_stlbincr;
					tmp_s = 1;
					tmp_stlbincr++;
				}
				case 1: {
					tmp_stlb += tmp_stlbincr;
					tmp_s = 0;
					tmp_stlbincr++;
				}
				}
				Kantor->addLast(current);
				current_element++;
				if (current_element > n)break;
			}
			while (tmp_str != 1) {
				tmp_str--;
				current.number = current_element;
				current.denominator = tmp_str;
				current.numerator = tmp_stlb;
				current.stlbincr = stlbincr;
				current.s = s;
				Kantor->addLast(current);
				current_element++;
				if (current_element > n)break;
			}
			d = 1;
		}
		else {

			d = 0;
		}
	}
}

void ListCreator(int n, NodeList*& Kantor)
{
	int str = 1;
	int stlb = 0, stlbincr = 1;
	bool s = 0;
	int tmp_str = 1;
	Rational current;
	int current_element = 1;
	for (current_element; current_element <= n;) {
		current.number = current_element;
		current.numerator = stlb;
		current.denominator = str;
		tmp_str = str;
		current.s = s;
		current.stlb = stlb;
		current.str = str;
		current.tmp_str = tmp_str;
		current.stlbincr = stlbincr;

		Kantor->addLast(current);
		while (tmp_str != 1 && current_element < n)
		{
			current_element++;
			tmp_str--;
			switch (s) {
			case 0: {
				stlb = stlb - stlbincr;
				stlbincr++;
				s = 1;
				break;
			}
			case 1: {
				stlb = stlb + stlbincr;
				stlbincr++;
				s = 0;
				break;
			}
			}
			current.s = s;
			current.stlb = stlb;
			current.str = str;
			current.tmp_str = tmp_str;
			current.stlbincr = stlbincr;
			current.number = current_element;
			current.numerator = stlb;
			current.denominator = tmp_str;
			Kantor->addLast(current);
		}
		str++;
		current_element++;
		stlb = 0;
		s = 0;
		stlbincr = 1;
	}
	Kantor->Print();
	system("pause");
	return;
}

void Add(NodeList& nodelist)
{
	if (nodelist.head != NULL) {
		int nmb = nodelist.tail->info.number + 1;
		bool tmp_s = 0;
		int stolbik = 0, tmp_tmp_str = 1;
		int tmp_stlbincr = 1;
		Rational current;
		if (nodelist.tail->info.tmp_str != 1)
		{
			tmp_tmp_str = nodelist.tail->info.tmp_str - 1;
			switch (nodelist.tail->info.s) {
			case 0: {
				stolbik = nodelist.tail->info.stlb - nodelist.tail->info.stlbincr;
				tmp_stlbincr = nodelist.tail->info.stlbincr + 1;
				tmp_s = 1;
				break;
			}
			case 1: {
				stolbik = nodelist.tail->info.stlb + nodelist.tail->info.stlbincr;
				tmp_stlbincr = nodelist.tail->info.stlbincr + 1;
				tmp_s = 0;
				break;
			}
			}
			current.s = tmp_s;
			current.stlb = stolbik;
			current.str = nodelist.tail->info.str;
			current.tmp_str = tmp_tmp_str;
			current.stlbincr = tmp_stlbincr;
			current.number = nmb;
			current.numerator = stolbik;
			current.denominator = tmp_tmp_str;
		}
		else if (nodelist.tail->info.tmp_str == 1) {
			current.str = nodelist.tail->info.str + 1;
			current.tmp_str = current.str;
			current.stlb = 0;
			current.stlbincr = 1;
			current.number = nmb;
			current.numerator = stolbik;
			current.denominator = current.str;
			current.s = 0;
		}
		Adder(nodelist, current);
		nodelist.Print();
		system("pause");
	}
	else {
		Rational current;
		current.denominator = 1;
		current.numerator = 0;
		current.number = 1;
		current.s = 0;
		current.stlb = 0;
		current.stlbincr = 1;
		current.str = 1;
		current.tmp_str = 0;
		nodelist.addLast(current);
		system("pause");
	}
}

void Adder(NodeList& nodelist, Rational current) {
	nodelist.addLast(current);
}

void Delete(NodeList& nodelist, int key) {
	nodelist.remove(key);
	system("cls");
	cout << "Updated List:\n";
	nodelist.Print();
	system("pause");
}

Node* Find(NodeList nodelist, int key) {
	return nodelist.find(key);
}

int Min(int a, int b) {
	bool ok = abs(a) < abs(b);
	if (ok)return a;
	else return b;
}

void Summ(NodeList nodelist, int& sumnum, int& sumden) {
	if (nodelist.head != NULL) {
		Node* cur = nodelist.head;
		sumnum = cur->info.numerator;
		sumden = cur->info.denominator;
		cur = cur->next;
		while (cur) {
			sumnum = sumnum * cur->info.denominator + cur->info.numerator * sumden;
			sumden = sumden * cur->info.denominator;
			int c = Min(sumnum, sumden);
			for (int i = 1; i < c; ++i) {
				if (sumnum % i == 0 && sumden % i == 0) {
					sumnum = sumnum / i;
					sumden = sumden / i;
				}
			}

			cur = cur->next;
		}
		system("cls");
		cout << "Summ of elements of the List: " << sumnum << " / " << sumden << endl;
		system("pause");
		delete cur;
		return;
	}
	else {
		cout << "Empty List!" << endl;
		return;
	}
}



void ShowFun(NodeList nodelist)
{
	int tmpstr = 1;
	Node* cur = nodelist.head;
	for (int i = 1; i < nodelist.tail->info.str; ++i) {
		while (cur) {
			if (cur->info.tmp_str == tmpstr)cout << "   " << setw(3) << cur->info.numerator << "/" << setw(3) << cur->info.denominator;
			cur = cur->next;
		}
		cout << endl;
		tmpstr++;
		cur = nodelist.head;
	}
	system("pause");
	cur = NULL;
	delete[] cur;
	return;
}