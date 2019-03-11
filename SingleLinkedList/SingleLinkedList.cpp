
#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;



struct SingleLinkedList
{
	int number;
	SingleLinkedList *next;

};

SingleLinkedList *firstElement;
SingleLinkedList *lastElement;


void AddElemenToList(int num)
{	
	SingleLinkedList *Element = new SingleLinkedList;
	Element->number = num;

	if (firstElement == NULL && firstElement == lastElement) {
		firstElement = Element;
		lastElement = Element;
		lastElement->next = NULL;
	}
	else {
		lastElement->next = Element;
		lastElement = Element;
		lastElement->next = NULL;
	}

	
}

void AddElementToListByNumber(int num, int numberOfElement) {
	SingleLinkedList *Element = new SingleLinkedList;
	SingleLinkedList *temp = new SingleLinkedList;
	SingleLinkedList *temp1 = new SingleLinkedList; 
	SingleLinkedList *temp2 = new SingleLinkedList;

	Element->number = num;
	temp = firstElement;

	for (int i = 1; i <= numberOfElement; i++) {
		
		if (i == numberOfElement-1) {
			temp1 = temp;
		}
		else if (i == numberOfElement) {
			temp2 = temp;
		}

		temp = temp->next;
	}

	temp1->next = Element;
	Element->next = temp2;
}

void AddFirstElement(int num) {

	SingleLinkedList *Element = new SingleLinkedList;
	Element->number = num;
	Element->next = firstElement;
	firstElement = Element;

}

void DeleteElementToListByNumber(int numberOfElement) {

	SingleLinkedList *temp = new SingleLinkedList;
	SingleLinkedList *temp1 = new SingleLinkedList;
	SingleLinkedList *temp2 = new SingleLinkedList;
	SingleLinkedList *temp3 = new SingleLinkedList;


	temp = firstElement;

	for (int i = 1; i <= numberOfElement + 1; i++) {

		if (i == numberOfElement - 1) {
			temp1 = temp;
		}
		else if (i == numberOfElement) {
			temp2 = temp;
		}
		else if (i == numberOfElement + 1) {
			temp3 = temp;
			break;
		}

		temp = temp->next;
	}

	
	if (temp2->next == NULL) {
		lastElement = temp1;
		temp1->next = NULL;
	}
	else {
		temp1->next = temp3;
	}
	delete temp2;


}

void DeleteFirstElement() {
	SingleLinkedList *temp1 = new SingleLinkedList;
	SingleLinkedList *temp2 = new SingleLinkedList;

	temp1 = firstElement;
	temp2 = temp1->next;
	delete temp1;
	firstElement = temp2;
}


void DeleteAllSingleLinkedList() {
	SingleLinkedList *temp1 = new SingleLinkedList;
	SingleLinkedList *temp2 = new SingleLinkedList;
	temp1 = firstElement;
	while (temp1) {
		temp2 = temp1;
		temp1 = temp1->next;
		delete temp2;
	}
	firstElement = NULL;
	lastElement = NULL;
}

void ShowSingleLinkedList() {
	SingleLinkedList *temp = new SingleLinkedList;
	temp = firstElement;
	while (temp) {
		cout << temp->number << endl;
		temp = temp->next;
	}
}

int menu() {
	int k = 1, num = 1;

	string A = "1 CREATE A LIST        ", 
		   B = "2 ADD TO END OF LIST   ",
		   C = "3 ADD BY ITEM NUMBER   ",
		   D = "4 DELETE BY ITEM NUMBER",
		   E = "5 DELETE LIST          ";

	cout << A << "<---\n";
	cout << B << "\n";
	cout << C << "\n";
	cout << D << "\n";
	cout << E << "\n";


	while (true) {

		int l = _getch(), c = _getch();
		system("cls");

		if (c == 80) {
			k++;
		}

		else if (c == 72) {
			k--;
		}


		if (k == 5) {
			k = 1;
		}

		else if (k == 0) {
			k = 4;
		}

		if (l == 13) {
			return k;
		}


		if (l == 49) {
			return 1;
		}
		else if (l == 50) {
			return 2;
		}
		else if (l == 51) {
			return 3;
		}
		else if (l == 52) {
			return 4;
		}



		if (k == 1) {
			cout << A << "<---\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
		}
		else if (k == 2) {
			cout << A << "\n";
			cout << B << "<---\n";
			cout << C << "\n";
			cout << D << "\n";
		}
		else if (k == 3) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "<---\n";
			cout << D << "\n";
		}
		else if (k == 4) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "<---\n";
		}



	}

}

int main()
{
	
	

	AddElemenToList(5);
	AddElemenToList(10);
	AddElemenToList(11);
	AddElemenToList(12);
	AddElemenToList(13);
	AddElementToListByNumber(14, 2);
	AddElemenToList(15);
	AddFirstElement(1);
	AddElemenToList(16);
	AddElementToListByNumber(18, 2);
	DeleteElementToListByNumber(10);
	DeleteElementToListByNumber(9);
	DeleteFirstElement();
	DeleteElementToListByNumber(7);
	DeleteAllSingleLinkedList();
	AddElemenToList(3);
	AddElemenToList(5);
	AddElemenToList(10);
	AddElemenToList(11);
	AddElemenToList(12);
	AddElemenToList(13);
	AddElementToListByNumber(14, 2);
	AddElemenToList(15);
	AddFirstElement(1);
	AddElemenToList(16);
	AddElementToListByNumber(18, 2);
	DeleteAllSingleLinkedList();
	AddElemenToList(6);
	ShowSingleLinkedList();

	


}

