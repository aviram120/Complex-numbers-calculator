
#include <iostream>
using namespace std;
#pragma once

class Complex 
{

private:
	double a;
	double b;
	int op;//* Contains the operator (2="-")

public:
	Complex::Complex();
	Complex(double num1, double num2);
	Complex(const Complex & other);
	Complex(double num1, double num2, int i);
	void setCompA(double num);
	void setCompB(double num);
	double getCompA() const;
	double getCompB() const;
	int getCompOperator() const;
	void setCompOperator(int i);
	void Complex::copyComplex(const Complex & other);
	Complex  operator+(const Complex  &other);
	Complex operator+(const double &num);
	
	Complex  operator-(const Complex  &other);
	Complex  operator-(const double &num);

	Complex  operator/(const Complex  &other);
	Complex  operator/(const double &num);

	Complex  operator*(const Complex  &other);
	Complex  operator*(const double &num);

	double calcAbs();

};
ostream& operator <<(std::ostream& os, const Complex & other);
Complex operator+(double n, const Complex & other);
Complex operator-(double n, const Complex & other);
Complex operator*(double n, const Complex & other);
Complex operator/(double n, const Complex & other);
