#include "Task3.h"
#define _USE_MATH_DEFINES 
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
using namespace std;

//ДОДАТКОВО
//Задача 3.3.Створити клас MatrixDouble(матриця цілих чисел), використовуючи
//клас VectorDouble.Розробити такі елементи класу :
//• Поля(захищені) :
//	− VectorDouble* DoubleArray; // масив
//− int n, size; // розміри матриці
//− int codeError; // код помилки
//− static int num_matrix; // кількість матриць (загально доступних)
//− У змінну стану встановлювати код помилки, коли не вистачає пам'яті,
//виходить за межі матриці.У класі визначити :
//• конструктори :
//− конструктор без параметрів(DoubleArray = nullptr, n = m =
//	codeError = 0);
//− конструктор з одним параметрів типу int size(створює одиничну
//	матрицю n = size на size);
//− конструктор із двома параметрами - розміри матриці(виділяє місце та
//	ініціалізує значенням нуль);
//− конструктор із трьома параметрами - розміри вектора та значення
//ініціалізації;
//− копіювання;
//• функції доступу до полів : n, sizeта codeError.
//• деструктор(деструктор звільняє пам'ять);
//• перевантаження операцій(операції перевантажувати через функції класу або
//	дружні функції, якщо не вказано яким чином це робити) :
//− унарних префіксних та постфіксних ++ та-- : одночасно збільшує (зменшує) значення елементів масиву на 1;
//− унарної логічної !(заперечення) : повертає значення true, якщо
//елементи якщо n та size не дорівнюють – нулю, інакше false;
//− унарний арифметичний - (мінус) : повертає всі елементи масиву класу
//матриця з протилежним знаком;
//− присвоєння = : копіює матрицю(перевантажити через функцію класу);
//− арифметичних бінарні :
//a. + додавання :
//	i.для двох матриць;
//ii.для матриці та скаляра типу int;
//iii.для матриці та скаляра типу double;
//iv.для матриці та скаляра типу float;
//b. - (віднімання) :
//i.для двох матриць
//ii.для матриці та скаляра типу int;
//iii.для матриці та скаляра типу double;
//iv.для матриці та скаляра типу float;
//c.* (множення)
//i.для двох матриць,
//ii.для матриці та вектора VectorDouble,
//iii.для матриці та скаляра типу double;
//iv.для матриці та скаляра типу float;
//d. / (ділення)
//i.для матриці та скаляра типу int;
//ii.для матриці та скаляра типу float;
//e. % (остача від ділення)
//i.для матриці та скаляра типу int;
//ii.для матриці та скаляра типу double;
//iii.для матриці та скаляра типу float;
//f. += присвоєння з додаванням :
//i.для двох матриць
//ii.для матриці та скаляра типу double;
//iii.для матриці та скаляра типу float;
//g. -= присвоєння з відніманням :
//i.для двох матриць;
//ii.для матриці та скаляра типу double;
//iii.для матриці та скаляра типу float;
//h. *= присвоєння з множенням
//i.для двох матриць,
//ii.для матриці та вектора VectorDouble;
//iii.для матриці та скаляра типу double;
//iv.для матриці та скаляра типу float;
//i. /= присвоєння з діленням
//i.для матриці та скаляра типу int;
//ii.для матриці та скаляра типу double;
//iii.для матриці та скаляра типу float;
//j. %= присвоєння з остачею від ділення
//i.для матриці та скаляра типу int;
//
//− операцій == (рівності)та != (нерівності), функція - операція виконує
//певні дії над кожною парою елементів матриці за індексом;
//− порівняння(функція - операція виконує певні дії над кожною парою
//	елементів матриць за індексом)
//	a. > (більше)для двох матриць;
//b. >= (більше рівне) для двох матриць;
//c. < (менше)для двох матриць;
//d. <= (менше рівне) для двох матриць.
//− операцію індексації[] – функцію, яка звертається до елементу
//VectorDouble, якщо індекс невірний вказує на останній елемент
//масиву та встановлює код помилки у змінну CodeError.
//− розподілу пам’яті new та delete;
//− виклику функції();
//− побітові операції зсувів, як дружні операції введення та виведення
//вектора у потік(перевантажувати через дружні функції)
//a.введення >> (побітовий зсув право);
//b.введення << (побітовий зсув ліво);
//
//• Передбачити можливість підрахунку числа об'єктів даного типу. Перевірити
//роботу цього класу.

enum STATE {
	OK, BAD_INIT, BAD_DIV, BAD_MULTIPLY
};
class VectorDouble
{
	double* vec;
	int num = 2;
	int state = 0;
	static double bad_index;
public:
	VectorDouble() :VectorDouble(1) {}
	VectorDouble(int n);
	VectorDouble(int n, double);
	VectorDouble(const VectorDouble& s);
	VectorDouble& operator=(const VectorDouble& s);
	VectorDouble& operator=(VectorDouble&& s) noexcept;
	void Init(int n);
	void Init(int n, double);
	~VectorDouble() {
		if (vec) delete[] vec;
	}
	friend istream& operator>>(istream& is, VectorDouble& s);
	friend ostream& operator<<(ostream& os, VectorDouble& s);
	double& operator[](int index);

	VectorDouble& operator++();
	VectorDouble& operator+=(const VectorDouble& s);
	VectorDouble& operator+=(const double& b);
	VectorDouble& operator+=(const float& b);
	VectorDouble  operator+(const VectorDouble& b);
	VectorDouble  operator+(const double& b);
	VectorDouble  operator+(const float& b);

	VectorDouble& operator--();
	VectorDouble& operator-=(const VectorDouble& s);
	VectorDouble& operator-=(const double& b);
	VectorDouble& operator-=(const float& b);
	VectorDouble  operator-(const VectorDouble& b);
	VectorDouble  operator-(const double& b);
	VectorDouble  operator-(const float& b);

	VectorDouble& operator*=(const VectorDouble& b);
	VectorDouble& operator*=(const double& b);
	VectorDouble& operator*=(const float& b);
	VectorDouble operator*(const VectorDouble& b);
	VectorDouble operator*(const double& b);
	VectorDouble operator*(const float& b);

	VectorDouble& operator/=(const VectorDouble& b);
	VectorDouble& operator/=(const double& b);
	VectorDouble& operator/=(const float& b);

	VectorDouble& operator/(const VectorDouble& b);
	VectorDouble operator/(const double& b);
	VectorDouble operator/(const float& b);

	bool operator>(const VectorDouble& s);
	bool operator>=(const VectorDouble& s);
	bool operator<(const VectorDouble& s);
	bool operator<=(const VectorDouble& s);
};

double VectorDouble::bad_index = 0;
VectorDouble::VectorDouble(int n) {
	if (n <= 0)    n = 1;
	num = n;
	vec = new double[n];
	for (int i = 0; i < n; i++) {
		vec[i] = 0.0;
	}
}
VectorDouble::VectorDouble(int n, double b) : VectorDouble(n) {
	for (int i = 0; i < num; i++) {
		vec[i] = b;
	}
}
VectorDouble::VectorDouble(const VectorDouble& s) {
	num = s.num;
	vec = new double[num];
	state = 1;
	for (int i = 0; i < num; i++)   vec[i] = s.vec[i];
}
VectorDouble& VectorDouble::operator=(const VectorDouble& s) {
	if (this == &s) return *this;
	if (num != s.num)
	{
		if (vec) delete[] vec;
		num = s.num;
		vec = new double[num];
		state = 1;
	}
	for (int i = 0; i < num; i++)   vec[i] = s.vec[i];
	return *this;
}
VectorDouble& VectorDouble::operator=(VectorDouble&& s) noexcept
{
	if (this == &s) return *this;
	num = s.num; state = s.state;
	if (this->vec != nullptr) delete[] vec;
	vec = s.vec;
	s.num = 0; s.vec = nullptr; s.state = -1;
	return *this;
}
void VectorDouble::Init(int n) {
	if (num != n) {
		if (vec != nullptr) delete[] vec;
		num = n;
		vec = new double[n];
	}
	for (int i = 0; i < num; i++) 	vec[i] = 0;
}
void VectorDouble::Init(int n, double b) {
	if (num != n) {
		if (vec != nullptr) delete[] vec;
		num = n;
		vec = new double[n];
	}
	for (int i = 0; i < num; i++) 	vec[i] = b;
}
istream& operator>>(istream& is, VectorDouble& s) {
	for (int i = 0; i < s.num; i++)
	{
		is >> s.vec[i];
	}
	return is;
};
ostream& operator<<(ostream& os, VectorDouble& s) {
	for (int i = 0; i < s.num; i++)
		os << s.vec[i] << '\t';
	os << endl;
	return os;
}
double& VectorDouble::operator[](int index)
{
	if (index >= 0 && index < num) return vec[index];
	cout << " Error : operator[] - index out of range \n";
	return bad_index;
}
VectorDouble& VectorDouble::operator-=(const VectorDouble& b) /*присвоєння з відніманням*/
{
	int i;
	if (num == b.num) for (i = 0; i < num; i++) vec[i] -= b.vec[i];
	else {
		cout << " Warning: vectors of different sizes are used in operation -= \n";
		if (num < b.num) {
			double* tmp;
			tmp = new double[b.num];
			for (i = 0; i < num; i++) tmp[i] = vec[i] - b.vec[i];
			for (; i < b.num; i++) tmp[i] = -b.vec[i];
			num = b.num;
			if (vec != nullptr) delete[] vec;
			vec = tmp;
		}
		else 	for (i = 0; i < b.num; i++) vec[i] -= b.vec[i];
	}
	return *this;
}
VectorDouble& VectorDouble::operator-=(const double& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++) vec[i] -= b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator-=(const float& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++) vec[i] -= b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator--()
{
	for (int i = 0; i < num; i++) vec[i] -= 1;
	return *this;
}
VectorDouble VectorDouble::operator-(const VectorDouble& b)
{
	VectorDouble tmp(*this);
	tmp -= b;
	return tmp;
}
VectorDouble VectorDouble::operator-(const double& b)
{
	VectorDouble tmp(*this);
	tmp -= b;
	return tmp;
}
VectorDouble VectorDouble::operator-(const float& b)
{
	VectorDouble tmp(*this);
	tmp -= b;
	return tmp;
}
VectorDouble& VectorDouble::operator++()
{
	for (int i = 0; i < num; i++) vec[i] += 1;
	return *this;
}
VectorDouble& VectorDouble::operator+=(const VectorDouble& b)
{
	int i;
	if (num == b.num) for (i = 0; i < num; i++) vec[i] += b.vec[i];
	else
	{
		cout << " Warning: vectors of different sizes are used in operation += \n";
		if (num < b.num) {
			double* tmp;
			tmp = new double[b.num];
			for (i = 0; i < num; i++) tmp[i] = vec[i] + b.vec[i];
			for (; i < b.num; i++) tmp[i] = b.vec[i];
			num = b.num;
			if (vec != nullptr) delete[] vec;
			vec = tmp;
		}
		else for (i = 0; i < b.num; i++) vec[i] += b.vec[i];
	}
	return *this;
}
VectorDouble& VectorDouble::operator+=(const double& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++) vec[i] += b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator+=(const float& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++) vec[i] += b;
	}
	return *this;
}
VectorDouble VectorDouble::operator+(const VectorDouble& b)
{
	VectorDouble tmp(*this);
	tmp += b;
	return tmp;
}
VectorDouble VectorDouble::operator+(const double& b)
{
	VectorDouble tmp(*this);
	tmp += b;
	return tmp;
}
VectorDouble VectorDouble::operator+(const float& b)
{
	VectorDouble tmp(*this);
	tmp += b;
	return tmp;
}
VectorDouble& VectorDouble::operator*=(const  VectorDouble& b)
{
	if (num != b.num) { std::cout << " Error : vectors of different sizes are used in operation %= \n"; return *this; }
	for (int i = 0; i < num; i++) vec[i] *= b.vec[i];
	return *this;
}
VectorDouble& VectorDouble::operator*=(const double& b) {
	VectorDouble tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	for (int i = 0; i < num; i++) vec[i] *= b;
	return *this;
	return tmp;
}
VectorDouble& VectorDouble::operator*=(const float& b) {
	VectorDouble tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	for (int i = 0; i < num; i++) vec[i] *= b;
	return *this;
	return tmp;
}
VectorDouble VectorDouble::operator*(const  VectorDouble& b)
{
	if (num != b.num) { std::cout << " Error : vectors of different sizes are used in operation %= \n"; return *this; }
	for (int i = 0; i < num; i++) vec[i] *= b.vec[i];
	return *this;
}
VectorDouble VectorDouble::operator*(const double& b) {
	VectorDouble rez(*this);
	VectorDouble tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return rez;
	}
	rez *= b;
	return rez;
	return tmp;
}
VectorDouble VectorDouble::operator*(const float& b) {
	VectorDouble rez(*this);
	VectorDouble tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return rez;
	}
	rez *= b;
	return rez;
	return tmp;
}
VectorDouble& VectorDouble::operator/=(const  VectorDouble& b)
{
	if (num != b.num) { std::cout << " Error : vectors of different sizes are used in operation %= \n"; return *this; }
	for (int i = 0; i < num; i++) vec[i] /= b.vec[i];
	return *this;
}
VectorDouble& VectorDouble::operator/=(const double& b) {
	VectorDouble tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	else for (int i = 0; i < num; i++) vec[i] /= b;
	return *this;
	return tmp;
}
VectorDouble& VectorDouble::operator/=(const float& b) {
	VectorDouble tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	else for (int i = 0; i < num; i++) vec[i] /= b;
	return *this;
	return tmp;
}
VectorDouble& VectorDouble::operator/(const  VectorDouble& b)
{
	if (num != b.num) { std::cout << " Error : vectors of different sizes are used in operation %= \n"; return *this; }
	for (int i = 0; i < num; i++) vec[i] /= b.vec[i];
	return *this;
}
VectorDouble VectorDouble::operator/(const double& b) {
	VectorDouble rez(*this);
	VectorDouble tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return rez;
	}
	rez /= b;
	return rez;
	return tmp;
}
VectorDouble VectorDouble::operator/(const float& b) {
	VectorDouble rez(*this);
	VectorDouble tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return rez;
	}
	rez /= b;
	return rez;
	return tmp;
}
bool VectorDouble::operator>(const VectorDouble& s) {
	for (int i = 0; i < num; i++) {
		if (vec[i] > s.vec[i])
			return true;
	}
	return false;
}
bool VectorDouble::operator>=(const VectorDouble& s) {
	for (int i = 0; i < num; i++) {
		if (vec[i] >= s.vec[i])
			return true;
	}
	return false;
}
bool VectorDouble::operator<(const VectorDouble& s) {
	for (int i = 0; i < num; i++) {
		if (vec[i] < s.vec[i])
			return true;
	}
	return false;
}
bool VectorDouble::operator<=(const VectorDouble& s) {
	for (int i = 0; i < num; i++) {
		if (vec[i] <= s.vec[i])
			return true;
	}
	return false;
}

class MatrixDouble {
private:
	VectorDouble* arr = nullptr;
	int n = 1;
	int m = 1;
	int state = 0;
public:
	MatrixDouble() :arr(nullptr), n(0), m(0), state(0) {}
	MatrixDouble(int n) :MatrixDouble(n, n) {};
	MatrixDouble(int n, int m) :MatrixDouble(n, m, 0) {};
	MatrixDouble(int n, int m, float);
	MatrixDouble(const MatrixDouble& s);
	MatrixDouble& operator=(const MatrixDouble& s);
	MatrixDouble& operator=(MatrixDouble&& s) noexcept;
	~MatrixDouble() {
		if (arr) delete[] arr;
	}
	friend istream& operator>>(istream& is, MatrixDouble& s);
	friend ostream& operator<<(ostream& os, MatrixDouble& s);
	VectorDouble& operator[](int index);
	MatrixDouble& operator++();
	MatrixDouble& operator--();

	MatrixDouble& operator+=(const MatrixDouble& s);
	MatrixDouble& operator+=(const float& b);
	MatrixDouble  operator+(const MatrixDouble& b);
	MatrixDouble  operator+(const double& b);
	MatrixDouble  operator+(const float& b);

	MatrixDouble& operator-=(const MatrixDouble& s);
	MatrixDouble& operator-=(const double& b);
	MatrixDouble& operator-=(const float& b);
	MatrixDouble  operator-(const MatrixDouble& b);
	MatrixDouble  operator-(const double& b);
	MatrixDouble  operator-(const float& b);


	MatrixDouble& operator*=(const double& b);
	MatrixDouble& operator*=(const float& b);
	MatrixDouble operator*(const MatrixDouble& b);
	MatrixDouble operator*(const float& b);


	MatrixDouble& operator/=(const double& b);
	MatrixDouble& operator/=(const float& b);
	MatrixDouble operator/(const double& b);
	MatrixDouble operator/(const float& b);

	bool operator>(const  MatrixDouble& s);
	bool operator>=(const MatrixDouble& s);
	bool operator<(const  MatrixDouble& s);
	bool operator<=(const MatrixDouble& s);

	int getState() {
		return state;
	}
};
MatrixDouble::MatrixDouble(int ni, int mi, float b)
{
	if (ni <= 0) n = 1; else n = ni;
	if (mi <= 0) m = 1; else m = mi;
	arr = new VectorDouble[n];
	for (int i = 0; i < n; i++) arr[i].Init(m, b);
}
MatrixDouble::MatrixDouble(const MatrixDouble& s)
{
	n = s.n;
	m = s.m;
	int i;
	arr = new VectorDouble[n];
	for (i = 0; i < n; i++) arr[i].Init(m, 0);
	for (i = 0; i < n; i++)
		for (int j = 0; j < m; j++)  arr[i][j] = s.arr[i][j];

}
MatrixDouble& MatrixDouble::operator=(const MatrixDouble& s)
{
	if (this != &s) {
		int i;
		if (n != s.n || m != s.m) {
			n = s.n; m = s.m;
			if (arr != nullptr) {
				delete[] arr;
			}
			arr = new VectorDouble[n];
			for (i = 0; i < n; i++) arr[i].Init(m, 0);
		}
		for (i = 0; i < n; i++)
			for (int j = 0; j < m; j++)  arr[i][j] = s.arr[i][j];

	}
	return *this;
}
VectorDouble& MatrixDouble::operator[](int index)
{
	if (index >= 0 && index < n) return arr[index];
	cout << " Error : operator[] - index index out of range \n";
	return arr[0];
}
MatrixDouble& MatrixDouble::operator=(MatrixDouble&& s) noexcept
{
	n = s.n; m = s.m;
	arr = s.arr;
	s.arr = nullptr;
	s.n = 0; s.m = 0;
	return *this;
}
istream& operator>>(istream& is, MatrixDouble& s)
{
	for (int i = 0; i < s.n; i++) is >> s.arr[i];
	return is;
}
ostream& operator<<(ostream& os, MatrixDouble& s)
{
	for (int i = 0; i < s.n; i++) os << s.arr[i];  // << endl;
	return os;
}
MatrixDouble& MatrixDouble::operator++() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] += 1;
		}
	}
	return *this;
}
MatrixDouble& MatrixDouble::operator--() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] -= 1;
		}
	}
	return *this;
}
MatrixDouble& MatrixDouble::operator+=(const MatrixDouble& s) {
	if (s.n == n) for (int i = 0; i < n; i++) arr[i] += s.arr[i];
	else {
		cout << "Error: matrices of different dimensions \n";
		cout << "The += operation was not performed. \n";
	}
	return *this;
}
MatrixDouble& MatrixDouble::operator+=(const float& b) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] += b;
		}
	}
	return *this;
}
MatrixDouble  MatrixDouble::operator+(const MatrixDouble& b) {
	MatrixDouble mat(*this);
	if (b.n == n) {
		mat += b;
	}
	else
	{
		cout << "Error: matrices of different dimensions \n";
		cout << "The += operation was not performed. \n";
	}
	return mat;
}
MatrixDouble  MatrixDouble::operator+(const double& b) {
	MatrixDouble mat(*this);
	mat += b;
	return mat;
}
MatrixDouble  MatrixDouble::operator+(const float& b) {
	MatrixDouble mat(*this);
	mat += b;
	return mat;
}
MatrixDouble& MatrixDouble::operator-=(const MatrixDouble& s) {
	if (s.n == n) for (int i = 0; i < n; i++) arr[i] -= s.arr[i];
	else {
		cout << "Error: matrices of different dimensions \n";
		cout << "The -= operation was not performed. \n";
	}
	return *this;
}
MatrixDouble& MatrixDouble::operator-=(const double& b) {
	for (int i = 0; i < n; i++) arr[i] -= b;
	return *this;
}
MatrixDouble& MatrixDouble::operator-=(const float& b) {
	for (int i = 0; i < n; i++) arr[i] -= b;
	return *this;
}
MatrixDouble  MatrixDouble::operator-(const MatrixDouble& b) {
	MatrixDouble mat(*this);
	mat -= b;
	return mat;
}
MatrixDouble  MatrixDouble::operator-(const double& b) {
	MatrixDouble mat(*this);
	mat -= b;
	return mat;
}
MatrixDouble  MatrixDouble::operator-(const float& b) {
	MatrixDouble mat(*this);
	mat -= b;
	return mat;
}
MatrixDouble& MatrixDouble::operator*=(const double& b) {
	MatrixDouble tmp;
	if (b == 0) {
		tmp.state = BAD_MULTIPLY;
		cout << "Error Multiply" << endl;
		return *this;
	}
	else for (int i = 0; i < n; i++) arr[i] *= b;
	return *this;
	return tmp;
}
MatrixDouble& MatrixDouble::operator*=(const float& b) {
	MatrixDouble tmp;
	if (b == 0) {
		tmp.state = BAD_MULTIPLY;
		cout << "Error Multiply" << endl;
		return *this;
	}
	else for (int i = 0; i < n; i++) arr[i] *= b;
	return *this;
	return tmp;
}
MatrixDouble  MatrixDouble::operator*(const MatrixDouble& b) {
	if (n == b.m && m == b.m) {
		MatrixDouble ret(m, n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				ret[i][j] = 0;
				for (int l = 0; l < m; l++) ret[i][j] += arr[i][l] * b.arr[l][j];
			}
		return ret;
	}
	else {
		cout << "Error: matrices of different dimensions \n";
		cout << "The *  operation was not performed. \n";
		return *this;
	}
}
MatrixDouble  MatrixDouble::operator*(const float& b) {
	MatrixDouble mat(*this);
	MatrixDouble tmp;
	if (b == 0) {
		tmp.state = BAD_MULTIPLY;
		cout << "Error Multiply" << endl;
		return mat;
	}
	else mat *= b;
	return mat;
	return tmp;
}
MatrixDouble& MatrixDouble::operator/=(const double& b) {
	MatrixDouble tmp;
	if (b == 0)
	{
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	else for (int i = 0; i < n; i++) arr[i] /= b;
	return *this;
	return tmp;
}
MatrixDouble& MatrixDouble::operator/=(const float& b) {
	MatrixDouble tmp;
	if (b == 0)
	{
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	else for (int i = 0; i < n; i++) arr[i] /= b;
	return *this;
	return tmp;
}
MatrixDouble  MatrixDouble::operator/(const double& b) {
	MatrixDouble mat(*this);
	MatrixDouble tmp;
	if (b == 0)
	{
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return mat;
	}
	else for (int i = 0; i < n; i++) arr[i] /= b;
	return mat;
	return tmp;
}
MatrixDouble  MatrixDouble::operator/(const float& b) {
	MatrixDouble mat(*this);
	MatrixDouble tmp;
	if (b == 0)
	{
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return mat;
	}
	else for (int i = 0; i < n; i++) arr[i] /= b;
	return mat;
	return tmp;
}
bool MatrixDouble::operator>(const  MatrixDouble& s) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > s.arr[i][j])
				return true;
		}
	}
	return false;
}
bool MatrixDouble::operator>=(const MatrixDouble& s) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] >= s.arr[i][j])
				return true;
		}
	}
	return false;
}
bool MatrixDouble::operator<(const  MatrixDouble& s) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] < s.arr[i][j])
				return true;
		}
	}
	return false;
}
bool MatrixDouble::operator<=(const MatrixDouble& s) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] >= s.arr[i][j])
				return true;
		}
	}
	return false;
}

int task3() {
	//cout << "\n Hello Task3: \n";
	//system("chcp 1251");
	MatrixDouble A(3);
	MatrixDouble B(3, 3);
	MatrixDouble C(3, 3, 9);
	MatrixDouble D(3, 3, 1.9);
	MatrixDouble E(3, 3, 9);
	MatrixDouble matrixcopy(C);
	VectorDouble vector1(3, 7);
	VectorDouble vector2(3);
	double value = 1.7;
	cout << "Task2 MatrixDouble : " << endl;
	cout << "A" << endl << A << endl;
	cout << "B" << endl << B << endl;
	cout << "C" << endl << C << endl;
	cout << "D" << endl << D << endl;
	cout << "Vector" << endl << vector1 << endl;
	cout << "Operations:" << endl;
	cout << "Overload ++::" << endl;
	cout << (++C);
	cout << "Overload -- :" << endl;
	cout << (--C);
	cout << "Overload matrix + matrix :" << endl;
	C += D;
	cout << C;
	cout << "Overload matrix + double :" << endl;
	C += value;
	cout << C;
	cout << "Overload matrix - double :" << endl;
	C -= value;
	cout << C;
	cout << "Overload matrix - matrix :" << endl;
	C -= D;
	cout << C;
	cout << "Overload matix * matrix :" << endl;
	C = C * D;
	cout << C;
	cout << "Overload matrix * double :" << endl;
	C *= value;
	cout << C;
	cout << "Overload matrix * 0:" << endl;
	C *= 0.0;
	cout << C;
	cout << "Overload matrix / double :" << endl;
	C /= value;
	cout << C;
	cout << "Overload matrix / 0 :" << endl;
	C /= 0.0;
	cout << C;
	cout << "Exercise 1" << endl;
	cout << "C = C + D  - B  + C / 7 : " << endl;
	C = (C + D - B + C) / 7.0;
	cout << C;
	return 0;
}
