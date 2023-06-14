#pragma once
#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned int uint;
const int DefaultAssocSize = 20;
struct MyTime
{
	unsigned short hour;  // 0-23
	unsigned short minute; // 0-59
	bool operator==(MyTime& s)
	{
		return hour == s.hour && minute == s.minute ? true : false;
	}
	bool operator>(MyTime& s)
	{
		if (hour > s.hour) return true;
		if (hour < s.hour) return false;
		return minute > s.minute ? true : false;
	}
};
ostream& operator<<(ostream& os, MyTime& t);
istream& operator>>(istream& iso, MyTime& t);
class  MyAssoc
{
	uint* MasFlightNumber;
	MyTime* MasTime;
	int MaxRec;
	int numRec;
	int State=0;
public:
	MyAssoc() : numRec(0), MaxRec(DefaultAssocSize) {
		MasFlightNumber = new  uint[DefaultAssocSize];   MasTime = new MyTime[DefaultAssocSize];
	}
	~MyAssoc() {
		if (MasFlightNumber != nullptr) delete[] MasFlightNumber;
		if (MasTime != nullptr) delete[] MasTime;
	}
	MyAssoc(int size, uint* mf, MyTime* tm) : numRec(size), MaxRec(size + 5) {
		MasFlightNumber = new  uint[MaxRec];   MasTime = new MyTime[MaxRec];
		for (int i = 0; i < size; i++) {
			MasFlightNumber[i] = mf[i];
			MasTime[i] = tm[i];
		}
	}

	void TableFlight();
	
	uint operator[](MyTime& s) {
		uint flight = 0;
		for (int i = 0; i < numRec; i++)
			if (MasTime[i] == s) return MasFlightNumber[i];
		cout << " Error: item not found ";
		State = -1;
		return flight;
	}

	MyTime operator[](uint& s) {
		MyTime ctime{ 0 };
		for (int i = 0; i < numRec; i++)
			if (MasFlightNumber[i] == s) return MasTime[i];
		cout << " Error: item not found ";
		State = -1;
		return ctime;
	}

	void operator()(uint a, uint b) {
		bool t = false;
		for (int i = 0; i < numRec; i++)
			if (MasTime[i].hour >= a && MasTime[i].hour <= b) {
				cout << MasFlightNumber[i] << "\t";
				t = true;
			}
		if (t == false) cout << " Item not found \n";
		cout << endl;
		return;
	}


};
