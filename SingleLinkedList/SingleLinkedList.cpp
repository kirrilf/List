
#include "pch.h"
#include <iostream>

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

	temp1->next = temp3;
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
}

void ShowSingleLinkedList() {
	SingleLinkedList *temp = new SingleLinkedList;
	temp = firstElement;
	while (temp) {
		cout << temp->number << endl;
		temp = temp->next;
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
	ShowSingleLinkedList();

	


}

