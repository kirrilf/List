
#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h> 
#include <cmath>

using namespace std;


void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}



struct SingleLinkedList
{
	int number;
	SingleLinkedList *next;
	SingleLinkedList *previous;

};

SingleLinkedList *firstElement;
SingleLinkedList *lastElement;

int getValue()
{
	while (true) // Цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		int a;
		cin >> a;

		// Проверка на предыдущее извлечение
		if (cin.fail()) // если предыдущее извлечение оказалось провальным
		{
			cin.clear(); // возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "ERROR.  Please try again.\n";
		}
		else
		{
			cin.ignore(2147483647, '\n'); // удаляем лишние значения

			return a;
		}
	}
}


void AddElemenToList(int num)
{	
	SingleLinkedList *Element = new SingleLinkedList;
	SingleLinkedList *temp = new SingleLinkedList;
	Element->number = num;

	if (firstElement == NULL && firstElement == lastElement) {
		firstElement = Element;
		firstElement->previous = NULL;
		lastElement = Element;
		lastElement->next = NULL;
	}
	else {
		lastElement->next = Element;
		temp = lastElement;
		lastElement = Element;
		lastElement->previous = temp;
		lastElement->next = NULL;
	}

	
}

void AddElementToListByNumber(int num, int numberOfElement) {
	SingleLinkedList *Element = new SingleLinkedList;
	SingleLinkedList *temp = new SingleLinkedList;
	SingleLinkedList *temp1 = new SingleLinkedList; 
	SingleLinkedList *temp2 = new SingleLinkedList;
	SingleLinkedList *temp3 = new SingleLinkedList;

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
	Element->previous = temp1;
	Element->next = temp2;
	temp2->previous = Element;
}

void AddFirstElement(int num) {

	SingleLinkedList *Element = new SingleLinkedList;
	SingleLinkedList *temp = new SingleLinkedList;
	temp = firstElement;
	Element->number = num;
	Element->next = firstElement;
	firstElement = Element;
	firstElement->previous = NULL;
	temp->previous = Element;

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
		temp3->previous = temp1;
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
	firstElement->previous = NULL;
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

void DeletePlotSingleLinkedList(int start, int finish) {
	
	SingleLinkedList *temp = new SingleLinkedList;
	SingleLinkedList *temp1 = new SingleLinkedList;
	SingleLinkedList *temp2 = new SingleLinkedList;


	temp = firstElement;
	if (start != 1) {
		for (int i = 1; i <= finish; i++) {
			if (i == start - 1) {
				temp1 = temp;
				temp = temp->next;
			}
			else if (i >= start && i < finish) {
				if (start == 1) {}
				temp2 = temp;
				temp = temp->next;
				delete temp2;
			}
			else if (i == finish) {
				if (temp->next == NULL) {
					temp1->next = NULL;
					delete temp;
					lastElement = temp1;
				}
				else {
					temp2 = temp;
					temp = temp->next;
					temp1->next = temp;
					temp->previous = temp1;
					delete temp2;
				}
			}
			else {
				temp = temp->next;
			}
		}
	}
	else {
		for (int i = 1; i <= finish; i++) {
			if (i == finish) {
				if (temp->next == NULL) {
					lastElement = NULL;
					firstElement = NULL;
				}
				else {
					temp2 = temp;
					temp = temp->next;
					temp->previous = NULL;
					firstElement = temp;
					delete temp2;
				}
			
			}
			else {
				temp2 = temp;
				temp = temp->next;
				delete temp2;
			}
		
		
		}
	
	
	}



}



void ShowSingleLinkedList() {
	SingleLinkedList *temp = new SingleLinkedList;
	temp = firstElement;
	int i = 1;
	while (temp) {
		cout << i << ")" <<temp->number << " ";
		temp = temp->next;
		i++;
	}
}

void ShowSingleLinkedListReverse(int count) {
	SingleLinkedList *temp = new SingleLinkedList;
	temp = lastElement;
	int i = count;
	while (temp) {
		cout << i << ")" << temp->number << " ";
		temp = temp->previous;
		i--;
	}
}

void ShowSingleLinkedListInMenu(int count) {
	if (count != 0) {
		gotoxy(0, 6);
		cout << "List: ";
		ShowSingleLinkedList();
		gotoxy(0, 7);
		cout << "Count: " << count;
		gotoxy(0, 8);
		cout << "List Reverse: ";
		ShowSingleLinkedListReverse(count);
		gotoxy(0, 0);
	}

}



int menu(int count) {
	int k = 1, num = 1;

	string	A = "1 CREATE A LIST          ",
			B = "2 ADD TO END OF LIST     ",
			C = "3 ADD BY ITEM NUMBER     ",
			D = "4 DELETE BY ITEM NUMBER  ",
			E = "5 DELETE LIST            ",
			F = "6 DELETE PART OF THE LIST";	

	system("cls");
	cout << A << "<---\n";
	cout << B << "\n";
	cout << C << "\n";
	cout << D << "\n";
	cout << E << "\n";
	cout << F << "\n";
	ShowSingleLinkedListInMenu(count);



	while (true) {

		int l = _getch(), c = 0;
		if (l == 224) {
			c = _getch();
		}
		system("cls");

		if (c == 80) {
			k++;
		}

		else if (c == 72) {
			k--;
		}


		if (k == 7) {
			k = 1;
		}

		else if (k == 0) {
			k = 6;
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
		else if (l == 53) {
			return 5;
		}
		else if (l == 54) {
			return 6;
		}



		if (k == 1) {
			cout << A << "<---\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
			cout << E << "\n";
			cout << F << "\n";
			ShowSingleLinkedListInMenu(count);
		}
		else if (k == 2) {
			cout << A << "\n";
			cout << B << "<---\n";
			cout << C << "\n";
			cout << D << "\n";
			cout << E << "\n";
			cout << F << "\n";
			ShowSingleLinkedListInMenu(count);
		}
		else if (k == 3) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "<---\n";
			cout << D << "\n";
			cout << E << "\n";
			cout << F << "\n";
			ShowSingleLinkedListInMenu(count);
		}
		else if (k == 4) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "<---\n";
			cout << E << "\n";
			cout << F << "\n";
			ShowSingleLinkedListInMenu(count);
		}
		else if (k == 5) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
			cout << E << "<---\n";
			cout << F << "\n";
			ShowSingleLinkedListInMenu(count);
		}
		else if (k == 6) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
			cout << E << "\n";
			cout << F << "<---\n";
			ShowSingleLinkedListInMenu(count);
			
		}



	}

}

void StartMenu() {
	int count = 0;

	while (true) {
		int g = menu(count);
		if (g == 1 && count == 0) {
			int num;
			system("cls");
			cout << "Enter item: ";
			num = getValue();
			AddElemenToList(num);
			count++;
		}
		else if (g == 1 && count != 0) {
			system("cls");
			cout << "List already created ";
			system("pause");
		}
		else if (g == 2 && count != 0) {
			int num;
			system("cls");
			cout << "Enter item: ";
			num = getValue();;
			AddElemenToList(num);
			count++;
		}
		else if (g == 2 && count == 0) {
			system("cls");
			cout << "No List ";
			system("pause");
		}
		else if (g == 3 && count != 0) {
			int num, numberOfElement;
			system("cls");
			cout << "Enter item: ";
			num = getValue();;
			cout << "Number of item: ";
			numberOfElement = getValue();;
			if (numberOfElement > 0) {

				if (numberOfElement == 1) {
					AddFirstElement(num);
					count++;
				}
				else if (numberOfElement == count) {
					AddElemenToList(num);
					count++;
				}
				else {
					if (numberOfElement > count) {
						system("cls");
						cout << "Number more than the number of items in the list ";
						system("pause");
					}
					else {
						AddElementToListByNumber(num, numberOfElement);
						count++;
					}
				}
			}
			else {
				system("cls");
				cout << "Number negative";
				system("pause");
			}
		}
		else if (g == 3 && count == 0) {
			system("cls");
			cout << "No List ";
			system("pause");
		}
		else if (g == 4 && count != 0) {
			int numberOfElement;
			cout << "Eneter number of element: ";
			numberOfElement = getValue();;
			if (numberOfElement <= count && numberOfElement > 0) {
				if (numberOfElement == 1) {
					DeleteFirstElement();
					count--;
				}
				else {
					DeleteElementToListByNumber(numberOfElement);
					count--;
				}
			}
			else {
				system("cls");
				cout << "Item number is less than zero or greater than the number of items in the list ";
				system("pause");
			}
		}
		else if (g == 4 && count == 0) {
			system("cls");
			cout << "No List ";
			system("pause");
		}
		else if (g == 5 && count != 0) {
			DeleteAllSingleLinkedList();
			count = 0;
		}
		else if (g == 5 && count == 0) {
			system("cls");
			cout << "No List ";
			system("pause");
		}
		else if (g == 6 && count != 0) {
			system("cls");
			int start, finish;
			cout << "Enter first number: ";
			start = getValue();;
			cout << "Enter last number: ";
			finish = getValue();;
			if (start <= 0 || finish <= 0 || start > count || finish > count) {
				cout << "Input Error";
				system("pause");
			}
			else {
				if (start > finish) {
					int temp;
					temp = start;
					start = finish;
					finish = temp;
				}
				DeletePlotSingleLinkedList(start, finish);
				count = count - (finish - start) - 1;
			}
			

		}
		else if (g == 6 && count == 0) {
			system("cls");
			cout << "No List ";
			system("pause");
		}
			
	}



}











int main()
{	
	StartMenu();
	



}

