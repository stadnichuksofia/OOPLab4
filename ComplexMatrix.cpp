#include "ComplexMatrix.h"
const double EpsCalculations = 1.e-5;
ComplexMatrix::ComplexMatrix(int ni, int mi, ComplexDouble b)
{
	if (ni <= 0) n = 2; else n = ni;
	if (mi <= 0) m = 2; else m = mi;
	 vec = new ComplexVector[n];
	 for (int i = 0; i < n; i++) vec[i].Init(m, b);
	// vec = new ComplexVector[n]{ ComplexVector(m,b) };
	

}

ComplexMatrix::ComplexMatrix(const ComplexMatrix& s)
{
	n = s.n;
	m = s.m;
	int i;
//	vec = new ComplexVector[n]{ ComplexVector(m) };
	vec = new ComplexVector[n];    
	for (i = 0; i < n; i++) vec[i].Init(m,0);
	for (i = 0; i < n; i++)
		for (int j = 0; j < m; j++)  vec[i][j] = s.vec[i][j];

}

ComplexMatrix& ComplexMatrix::operator=(const ComplexMatrix& s)
{
	if (this != &s) {
		int i;
		if (n != s.n || m != s.m) {
			n = s.n; m = s.m;
			if (vec != nullptr) {
					delete[] vec;
			}
				vec = new ComplexVector [n];
				for (i = 0; i < n; i++) vec[i].Init(m,0);
		}
		for (i = 0; i < n; i++)
			for (int j = 0; j < m; j++)  vec[i][j] = s.vec[i][j];
		
	}
	return *this;
}

ComplexMatrix& ComplexMatrix::operator=(ComplexMatrix&& s) noexcept
{
	n = s.n; m = s.m;
	vec = s.vec;
	s.vec = nullptr;
	s.n = 0; s.m = 0;
	return *this;
}

void ComplexMatrix::Input()
{
}

void ComplexMatrix::Output()
{
}

bool ComplexMatrix::operator!() const
{
	return false;
}

bool ComplexMatrix::operator~() const
{
	return false;
}

ComplexVector& ComplexMatrix::operator[](int index)
{
	if (index >= 0 && index < n) return vec[index];
	cout << " Error : operator[] - index index out of range \n";
	return vec[0];
}

ComplexMatrix& ComplexMatrix::operator+=(const ComplexMatrix& s)
{
	if (s.n == n) for (int i = 0; i < n; i++) vec[i] += s.vec[i];
	else {
		cout << "Error: matrices of different dimensions \n";
		cout << "The += operation was not performed. \n";
	}
	return *this;
}

ComplexMatrix& ComplexMatrix::operator+=(const ComplexDouble& b)
{
	for (int i = 0; i < n; i++) vec[i] += b;
	return *this;
}

ComplexMatrix& ComplexMatrix::operator+=(const double& b)
{
	for (int i = 0; i < n; i++) vec[i] += b;
	return *this;
}

ComplexMatrix ComplexMatrix::operator+(const ComplexMatrix& b)
{
	 ComplexMatrix mat(*this);
	 mat += b;
	 return mat;
}

ComplexMatrix ComplexMatrix::operator+(const ComplexDouble& b)
{
	ComplexMatrix mat(*this);
	mat += b;
	return mat;
}

ComplexMatrix ComplexMatrix::operator+(const double& b)
{
	ComplexMatrix mat(*this);
	mat += b;
	return mat;
}

ComplexMatrix& ComplexMatrix::operator-=(const ComplexMatrix& s)
{
	if (s.n == n) for (int i = 0; i < n; i++) vec[i] -= s.vec[i];
	else {
		cout << "Error: matrices of different dimensions \n";
		cout << "The += operation was not performed. \n";
	}
	return *this;
}

ComplexMatrix& ComplexMatrix::operator-=(const ComplexDouble& b)
{
	for (int i = 0; i < n; i++) vec[i] -= b;
	return *this;
}

ComplexMatrix& ComplexMatrix::operator-=(const double& b)
{
	for (int i = 0; i < n; i++) vec[i] -= b;
	return *this;
}

ComplexMatrix ComplexMatrix::operator-(const ComplexMatrix& b)
{
	ComplexMatrix mat(*this);
	mat -= b;
	return mat;
}

ComplexMatrix ComplexMatrix::operator-(const ComplexDouble& b)
{
	ComplexMatrix mat(*this);
	mat -= b;
	return mat;
}

ComplexMatrix ComplexMatrix::operator-(const double& b)
{
	ComplexMatrix mat(*this);
	mat -= b;
	return mat;
}


ComplexMatrix& ComplexMatrix::operator*=(const ComplexDouble& b)
{
	for (int i = 0; i < n; i++) vec[i] *= b;
	return *this;
}

ComplexMatrix& ComplexMatrix::operator*=(const double& b)
{
	for (int i = 0; i < n; i++) vec[i] *= b;
	return *this;
}

ComplexMatrix ComplexMatrix::operator*(const ComplexMatrix& b)
{
	if (n == b.m && m == b.m) {
		ComplexMatrix ret(m,n);
		for(int i=0; i<n; i++)
			for (int j = 0; j < m; j++)
			{
				ret[i][j] = 0;
				for (int l = 0; l < m; l++) ret[i][j] += vec[i][l] * b.vec[l][j];
			}
		return ret;
	}
	else {
		cout << "Error: matrices of different dimensions \n";
		cout << "The *  operation was not performed. \n";
		return *this;
	}
}

ComplexVector ComplexMatrix::operator*(const ComplexVector& b)
{
	ComplexVector ret(n);
	if (n == b.num) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{				
				 ret[i] += vec[i][j] * b.v[j];
			}
	}
	else {
		cout << "Error: matrix and vector different dimensions \n";
		cout << "The *  operation was not performed. \n";
	}
	return ret;
}

ComplexMatrix ComplexMatrix::operator*(const ComplexDouble& b)
{
	ComplexMatrix mat(*this);
	mat *= b;
	return mat;
}

ComplexMatrix ComplexMatrix::operator*(const double& b)
{
	ComplexMatrix mat(*this);
	mat *= b;
	return mat;
}


ComplexMatrix& ComplexMatrix::operator/=(const ComplexDouble& b)
{
	if (fabs(b.real()) < EpsCalculations && fabs(b.imag()) < EpsCalculations)
	{
		std::cout << " Error Matrix opreation /= b \n";
	}
	else for (int i = 0; i < n; i++) vec[i] /= b;
	return *this;
}

ComplexMatrix& ComplexMatrix::operator/=(const double& b)
{
	if (fabs(b) < EpsCalculations)
	{
		std::cout << " Error Matrix opreation /= b \n";
	}
	else for (int i = 0; i < n; i++) vec[i] /= b;
	return *this;
}



ComplexMatrix ComplexMatrix::operator/(const ComplexDouble& b)
{
	ComplexMatrix mat(*this);
	mat *= b;
	return mat;
}


ComplexMatrix ComplexMatrix::operator/(const double& b)
{
	ComplexMatrix mat(*this);
	mat *= b;
	return mat;
}

void ComplexMatrix::RandComplexMatrix()
{
	for (int i = 0; i < n; i++) vec[i].RandComplexVector();
}

istream& operator>>(istream& is, ComplexMatrix& s)
{
	for (int i = 0; i < s.n; i++) is >> s.vec[i];
	return is;
}

ostream& operator<<(ostream& os, ComplexMatrix& s)
{
	for (int i = 0; i < s.n; i++) os << s.vec[i];  // << endl;
	return os;
}
