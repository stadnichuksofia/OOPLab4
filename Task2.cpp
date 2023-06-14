#include "Task2.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <fstream>
using namespace std;
typedef unsigned int uint;

//Побудувати асоційований клас збереження
//двох сутностей.В завданні створити клас, який представляє собою
//асоціативний масив між двома сутностями.Написати функцію створення
//набору асоціативних сутностей.Перевантажити операцію індексації[] –
//функцію, яка звертається до об’єкта класу, за однією сутністю, якщо індекс,
//повертає асоціативну сутність, якщо відповідної сутності немає в встановлює
//код помилки у змінну CodeError, альтернативні звернення через
//перевантаження операції виклику функції(); перевантажити дружні операції
//введення та виведення.

//Задача 2.10.Інвентарний номер книги в бібліотеці та назва.

// створюємо структурну змінну з ім'ям Books та присвоюємо значення відровідним членам Books
struct Book
{
	string NameOfBook;

	bool operator==(Book& s)
	{
		return NameOfBook.compare(s.NameOfBook);
	}

};

//Об'єкт типу ostream отримує значення різних типів,
//перетворює їх у послідовність символів і передає їх через буфер у певне місце для виведення (консоль, файл, мережеві інтерфейси тощо)
ostream& operator<<(ostream& os, Book& n) {
	cout << n.NameOfBook;
	return os;
}

//отримання введеного значення
istream& operator>>(istream& iso, Book& n) {
	cin >> n.NameOfBook;
	return iso;
}

class Library
{
	uint* InventNumber;
	Book* Literature;
	int MaxRec;
	int numRec;
	int State;

public:
	Library() :
		numRec(0), MaxRec(20) {
		InventNumber = new uint[20];
		Literature = new Book[20];
	}

	~Library() {
		if (InventNumber != nullptr) delete[] InventNumber;
		if (Literature != nullptr) delete[] Literature;
	}

	Library(int size, uint* iN, Book* tm) : numRec(size), MaxRec(size + 5) {
		InventNumber = new uint[MaxRec]; Literature = new Book[MaxRec];
		for (int i = 0; i < size; i++) {
			InventNumber[i] = iN[i];
			Literature[i] = tm[i];
		}
	}

	void TableInvNum()
	{
		cout << " TableInvNum \n";
		for (int i = 0; i < numRec; i++) {
			cout << " InvNumber: " << InventNumber[i] << ";" << " Name of book: " << Literature[i] << endl;
		}
	}

	uint operator[](Book& s) {
		uint InvN = 0;
		for (int i = 0; i < numRec; i++)
			if (Literature[i] == s) return InventNumber[i];
		cout << "Error: item not found!";
		State = -1;
		return InvN;
	}

	Book operator[](uint& s) {
		Book Nname = Book();
		for (int i = 0; i < numRec; i++)
			if (InventNumber[i] == s) return Literature[i];
		cout << "Error: item not found! ";
		State = -1;
		return Nname;
	}

	void operator()(string Str) {
		bool t = false;
		for (int i = 0; i < numRec; i++)
			if (Literature[i].NameOfBook.find(Str) != std::string::npos){
				cout << InventNumber[i] << "\t";
				t = true;
			}
		if (t == false) cout << "Book not found! \n";
		cout << endl;
		return;
	}
};


int task2()
{
	cout << " End begin \n";
	uint InvNumber[10] = { 1818, 1823, 1847, 711, 1871, 1922, 1949, 1965, 1925, 1942};
	Book NameOfBook[10] = {
		"Persuasion",
		"Frankenstein",
		"Jane Eyre ",
		"The Iliad",
		"Perfume",
		"Fight Club",
		"Nineteen Eighty-Four",
		"Lolita",
		"Great Expectations",
		"The Stranger"
	};
	Library dbase(10, InvNumber, NameOfBook);
	dbase.TableInvNum();
	string Name;
	cout << "Enter name of book: " << endl;
	cin.ignore(20, ' ');
	cin >> Name;
	cout << "Inventory number of this book is: " << endl;
	dbase(Name);
	uint Num;
	cout << "Enter inventory number: " << endl;
	cin >> Num;
	cout << "" << endl;
	Book BookTitles;
	BookTitles = dbase[Num];
	cout << "\nInventory number: " << Num << "\n" << "Name of book: " << BookTitles << endl;
	return 0;
}
