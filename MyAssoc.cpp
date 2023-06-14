#include "MyAssoc.h"
ostream& operator<<(ostream& os, MyTime& t) {
	os << t.hour << ":";
	if (t.minute <= 9) os << "0" << t.minute; else os << t.minute;
	os << " ";
	return os;
}
istream& operator>>(istream& iso, MyTime& t) {
	iso >> t.hour >> t.minute;
	t.hour %= 24;
	t.minute %= 60;
	return iso;
}

void MyAssoc::TableFlight()
{
		cout << " TableFlight \n";
		for (int i = 0; i < numRec; i++) {
			cout << " Flight " << MasFlightNumber[i] << " time " 
				 << MasTime[i] << endl;
		}
}
	

