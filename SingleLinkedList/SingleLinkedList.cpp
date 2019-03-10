
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

void AddElementToListByNumber(int num, int numberOfElemet) {
	SingleLinkedList *Element = new SingleLinkedList;
	SingleLinkedList *temp = new SingleLinkedList;
	SingleLinkedList *temp1 = new SingleLinkedList; 
	SingleLinkedList *temp2 = new SingleLinkedList;

	Element->number = num;
	temp = firstElement;

	for (int i = 1; i <= numberOfElemet; i++) {
		
		if (i == numberOfElemet-1) {
			temp1 = temp;
		}
		else if (i == numberOfElemet) {
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

void ShowSingleLinkedList() {
	SingleLinkedList *temp = new SingleLinkedList;
	temp = firstElement;
	while (temp) {
		cout << temp->number << endl;
		temp = temp->next;
	}
}

void DeleteElementToListByN


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
	ShowSingleLinkedList();

	


}

