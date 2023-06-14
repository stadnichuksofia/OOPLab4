#include <iostream>
#include <conio.h>
#include "Lab4Exmaple.h"

using namespace std;

//Перевантаження операцій та асоціативні класи.
int MainMenu() {
    int mainchoice;
    cout << "Main Menu: \n";
    cout << "1. Task 1: \n";
    cout << "2. Task 2: \n";
    cout << "3. Task 3: \n";
    cout << "4. Exit \n";
    cout << "Enter your choice: " << endl;
    cin >> mainchoice;
    system("cls");
    return mainchoice;
}
int main()
{
    std::cout << " Lab #4 \n";

    int mainchoice = MainMenu();
    if (mainchoice > 3 || mainchoice < 1) {
        cout << "Please choose task";
    }
    switch (mainchoice) {
		case 1: {
			mainExample1();
			break;
		}
		case 2: {
			mainExample2(); 
			break;
		}
		case 3: {
			mainExample3();
			break;
		}
        default: break;
    }
}