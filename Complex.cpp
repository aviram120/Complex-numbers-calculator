
The department represents a complex number.
The department performs an addition, subtraction, multiplication, and division between the complex numbers.

*
*/
#include "Complex .h"
#include <cmath>
#include <iostream>

using namespace std;

//*******************************************
//***************Constructors****************
//*******************************************
Complex::Complex()
// empty Constructor 
{
	this->a = 0;
	this->b = 0;
	this->op = 0;
}
Complex::Complex(double num1, double num2)
// empty Constructor Get two number and initializes the attributes
{
	this->a = num1;
	this->b = num2;
	this->op = NULL;
}
Complex::Complex(const Complex & other)
//copy Constructor
{
	this->a = other.a;
	this->b = other.b;
	this->op = other.op;
}
Complex::Complex(double num1, double num2, int i)
//The constructor accepts two numbers,operator and place them features
{
	this->a = num1;
	this->b = num2;
	this->op = i;
}
//*******************************************
//***************Set/Get*********************
//*******************************************
void Complex ::setCompA(double num)
{
	this->a = num;
}
void Complex ::setCompB(double num){
	this->b = num;
}
double Complex ::getCompA() const
{
	return a;
}
double Complex ::getCompB() const
{
	return b;
}
int Complex::getCompOperator() const
{
	return op;
}
void Complex::setCompOperator(int i){
	this->op = i;
}
//*******************************************
//***************Methods*********************
//*******************************************
void Complex::copyComplex(const Complex & other)
//*The method receives two copies of objects including
{
	this->a = other.a;
	this->b = other.b;
	this->op = other.op;
}
Complex   Complex::operator+(const Complex  &other)
//The method accepts two Complex objects and performs an addition operation between
{
	Complex  newComplex ;
	newComplex .a = this->a + other.a;
	newComplex .b = this->b + other.b;
	return newComplex ;
}
Complex Complex::operator+(const double &num)
//The method accepts Complex objects and double and performs an addition operation between them
{
	Complex  newComplex;
	newComplex.a = this->a + num;
	newComplex.b = this->b;
	return newComplex;
}
Complex   Complex ::operator-(const Complex  &other)
//The method accepts two Complex objects and performs a subtraction operation between them
{
	Complex  newComplex ;
	newComplex .a = this->a - other.a;
	newComplex .b = this->b - other.b;
	return newComplex ;
}
Complex   Complex ::operator-(const double &num)
//The method accepts  Complex objects and double performs a subtraction operation between them
{
	Complex  newComplex;
	newComplex.a = this->a - num;
	newComplex.b = this->b;
	return newComplex;
}
Complex   Complex ::operator*(const Complex  &other)
//The method accepts two Complex objects and performs multiplication between them
{
	Complex  newComplex ;

	newComplex .a = (this->a * other.a) - (this->b * other.b);
	newComplex .b = (this->a * other.b) + (this->b * other.a);
	return newComplex ;
}
Complex   Complex ::operator*(const double &num)
//The method accepts two Complex objects and performs multiplication between them
{
	Complex  newComplex;

	newComplex.a = this->a * num;
	newComplex.b = this->b  *num;
	return newComplex;
}
Complex   Complex ::operator/(const Complex  &other)
//The method accepts two Complex objects and performs a division operation between them
{ 
	Complex  newComplex ;
	
	double a, b, c, d;

	a = this->a;
	b = this->b;
	c = other.a;
	d = other.b;

	newComplex .a = ((a*c + b*d)/(c*c + d*d));
	newComplex .b = ((-a*d + b*c)/(c*c + d*d));
	return newComplex ;
}
Complex   Complex ::operator/(const double &num)
//The method accepts two Complex objects and performs a division operation between them
{
	Complex  newComplex;
	
	newComplex.a = this->a/num;
	newComplex.b = this->b/num;
	return newComplex;
}
double Complex ::calcAbs()
//The method accepts a Complex object and returns the absolute value
{	
	double x=this -> a;
	double y=this->b;
	return sqrt(x*x + y*y);
}
ostream& operator <<(ostream& os, const Complex & other)
//*Format for cout
{
	if (other.getCompB()>=0)
		os << other.getCompA() << "+" << other.getCompB() << "*i" << endl;
	else
		os << other.getCompA() << other.getCompB() << "*i" << endl;

	return os;
}
Complex operator+(double n, const Complex & other)
{
	Complex newComplex;

	newComplex.setCompA(other.getCompA() + n);
	newComplex.setCompB(other.getCompB());

	return newComplex;
}
Complex operator-(double n, const Complex & other)
{
	Complex newComplex;

	newComplex.setCompA(other.getCompA() - n);
	newComplex.setCompB(other.getCompB());

	return newComplex;
}
Complex operator*(double n, const Complex & other)
{
	Complex newComplex;

	newComplex.setCompA(other.getCompA()* n);
	newComplex.setCompB(other.getCompB()* n);

	return newComplex;
}
Complex operator/(double n, const Complex & other)
{
	Complex newComplex;

	newComplex.setCompA(other.getCompA()/ n);
	newComplex.setCompB(other.getCompB()/ n);

	return newComplex;
}
