#pragma once
#include "ComplexVector.h"
/// <summary>
/// Matrix
/// </summary>
/// <returns></returns>
class ComplexMatrix
{
	ComplexVector* vec=nullptr;
	int n = 2, m = 2;
	int state = 0;
public:
	ComplexMatrix() : ComplexMatrix(2) {}
	ComplexMatrix(int n) : ComplexMatrix(n, n) {};
	ComplexMatrix(int n, int m) : ComplexMatrix(n, n, 0) {};
	ComplexMatrix(int n, int m, ComplexDouble);
	ComplexMatrix(const ComplexMatrix& s);
	ComplexMatrix& operator=(const ComplexMatrix& s);
	ComplexMatrix& operator=(ComplexMatrix&& s) noexcept;
	~ComplexMatrix() {
	//	std::cout << " del mat";
		if (vec) delete[] vec;
	}
	void Input();
	void Output();
	friend istream& operator>>(istream& is, ComplexMatrix& s);
	friend ostream& operator<<(ostream& os, ComplexMatrix& s);
	// reload operators
	bool operator!() const;   // true : v[i] != 0
	bool operator~() const;   // true : all v[i] != 0
	ComplexVector& operator[](int index);

	ComplexMatrix& operator+=(const ComplexMatrix& s);
	ComplexMatrix& operator+=(const ComplexDouble& b);
	ComplexMatrix& operator+=(const double& b);

	ComplexMatrix operator+(const ComplexMatrix& b);
	ComplexMatrix operator+(const ComplexDouble& b);
	ComplexMatrix operator+(const double& b);

	ComplexMatrix& operator-=(const ComplexMatrix& s);
	ComplexMatrix& operator-=(const ComplexDouble& b);
	ComplexMatrix& operator-=(const double& b);

	ComplexMatrix operator-(const ComplexMatrix& b);
	ComplexMatrix operator-(const ComplexDouble& b);
	ComplexMatrix operator-(const double& b);
	
	ComplexMatrix& operator*=(const ComplexDouble& b);
	ComplexMatrix& operator*=(const double& b);

	ComplexMatrix operator*(const ComplexMatrix& b);
	ComplexVector operator*(const ComplexVector& b);
	ComplexMatrix operator*(const ComplexDouble& b);
	ComplexMatrix operator*(const double& b);


	ComplexMatrix& operator/=(const ComplexDouble& b);
	ComplexMatrix& operator/=(const double& b);

	ComplexMatrix operator/(const ComplexDouble& b);
	ComplexMatrix operator/(const double& b);

	void RandComplexMatrix();
};
