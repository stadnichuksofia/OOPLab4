#pragma once
#include <iostream>
#include <math.h>
#include<complex>
using namespace std;

typedef complex<double> ComplexDouble;
#define _RE 0
#define _IM 1
ComplexDouble RandComplexDouble();
class ComplexMatrix;
class ComplexVector
{
	ComplexDouble* v;
	int num = 2;
	int state = 0;
	static ComplexDouble badIndexRef;
	static int numVec;
public:
	ComplexVector() : num(0), v(nullptr) {}
	ComplexVector(int n);
	ComplexVector(int n, ComplexDouble&);
	ComplexVector(int n, ComplexDouble*);
	ComplexVector(const ComplexVector& s);  // crot copy
	ComplexVector& operator=(const ComplexVector& s);
	ComplexVector& operator=(ComplexVector&& s) noexcept;
	void Init(int n);   //
	void Init(int n, ComplexDouble);   //
	~ComplexVector() {
		//	std::cout << " del vec";
		if (v) delete[] v;
	}
	void Input();
	void Output();
	friend istream& operator>>(istream& is, ComplexVector& s);
	friend ostream& operator<<(ostream& os, ComplexVector& s);
	friend class ComplexMatrix;
	// reload operators
	bool operator!() const;   // true : v[i] != 0
	bool operator~() const;   // true : all v[i] != 0

	ComplexDouble& operator[](int index);
	ComplexVector& operator++();
	ComplexVector& operator++(int);
	friend  ComplexVector& operator--(ComplexVector&);
	friend  ComplexVector& operator--(ComplexVector& ,int);

	ComplexVector& operator+=(const ComplexVector& s);
	ComplexVector& operator+=(const ComplexDouble& b);
	ComplexVector& operator+=(const double& b);
	ComplexVector& operator+=(const long& b);
	ComplexVector operator+(const ComplexVector& b);
	ComplexVector operator+(const ComplexDouble& b);
	ComplexVector operator+(const double& b);
	ComplexVector operator+(const long& b);

	ComplexVector& operator-=(const ComplexVector& s);
	ComplexVector& operator-=(const ComplexDouble& b);
	ComplexVector& operator-=(const double& b);
	ComplexVector& operator-=(const long& b);
	ComplexVector operator-(const ComplexVector& b);
	ComplexVector operator-(const ComplexDouble& b);
	ComplexVector operator-(const double& b);
	ComplexVector operator-(const long& b);

	ComplexDouble operator*=(const ComplexVector& b);  //  r= a0*b0+a1*b1+...+an-1*bn-1
	ComplexVector& operator%=(const ComplexVector& b);  // (a0*b0, a1*b1,...,an-1*bn-1)
	ComplexVector& operator*=(const ComplexDouble& b);
	ComplexVector& operator*=(const double& b);
	ComplexVector& operator*=(const long& b);
	ComplexDouble operator*(const ComplexVector& b);  //  r= a0*b0+a1*b1+...+an-1*bn-1
	ComplexVector operator%(const ComplexVector& b);  // (a0*b0, a1*b1,...,an-1*bn-1)
	ComplexVector operator*(const ComplexDouble& b);
	ComplexVector operator*(const double& b);
	ComplexVector operator*(const long& b);

	ComplexVector& operator/=(const ComplexVector& b);  // (a0/b0, a1/b1,...,an-1/bn-1)
	ComplexVector& operator/=(const ComplexDouble& b);
	ComplexVector& operator/=(const double& b);
	ComplexVector& operator/=(const long& b);
	ComplexVector operator/(const ComplexVector& b);  // (a0/b0, a1/b1,...,an-1/bn-1)
	ComplexVector operator/(const ComplexDouble& b);
	ComplexVector operator/(const double& b);
	ComplexVector operator/(const long& b);
	//

	bool operator||(const ComplexVector& b);
	friend bool operator&&(const ComplexVector& a,const ComplexVector& b);
	bool operator==(const ComplexVector& a);
	bool operator!=(const ComplexVector& a);
	void RandComplexVector();
};
