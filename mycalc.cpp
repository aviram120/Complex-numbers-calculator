
Complex numbers calculator.
The program calculates addition, subtraction, multiplication and division of complex numbers.
(Calculato r supports all right arithmetic)
In addition, it is possible to calculate an absolute value, real value and a simulated value of a complex number.
It is possible to activate sound (hearing the result).

Calculator supports the sounding result!


++++++++++++++++Important++++++++++++
To activate the sound,
Copy the files to the teacher voice raised.
Folder should be with the name:"soundfiles"

With audio files!!!!!!!
+++++++++++++++++++++++++++++++++++++


================================
Template complex number: (a+b*i)
================================

*
*/

#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <vector>
#include <sstream> // for ostringstream
#include "Complex .h"
#include "soundPP.h"
#include <playsoundapi.h>
#include <MMsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

void printOnTheScreen();
void gotoXY(int x, int y);
void convertStinrgToTwoInt(string s, double * x, double * y);
void clearLineOneOne();
void explanatoryScreen();
 
int main(){

	std::vector<Complex> vectorOfComplex;

	string s;
	char ch;
	double x = 0, y = 0;
	boolean flagOfMulti = false;//*If you need to perform multiplication operation
	boolean flagOfDiv = false;//* If it is necessary to do division
	boolean flagOfPrintARM = false;//*Responsible absolute value, real and imeag
	boolean flagOfSound = false;//*Responsible of the sound
	int flagOfARM = 0;//*Responsible of the type absolute value, real and imeag

	Complex com1(x, y);
	Complex com3(x, y);
	printOnTheScreen();
	
	ch = getch();
	while (ch != 'q')
	{
		gotoXY(1, 1);

		if (ch == 'e')//* to Insert a complex number 
		{		
			clearLineOneOne();
			cin >> s;
			convertStinrgToTwoInt(s, &x, &y);//*Converter the stirng to complex number (a+b*i)
			com1.setCompA(x);
			com1.setCompB(y);
			vectorOfComplex.push_back(com1);//* push the complex to the vector
			clearLineOneOne();
		}
		if (flagOfMulti)//*To calculate the multiplication
		{
			/*pop out the last two organs*/
			com1.copyComplex(vectorOfComplex.back());
			vectorOfComplex.pop_back();
			com3.copyComplex(vectorOfComplex.back());
			vectorOfComplex.pop_back();

			/*Performs the action and put the result in to vector*/
			com1 = com1*com3;
			vectorOfComplex.push_back(com1);//* push the complex to the vector
			flagOfMulti = false;//*Indicates that the operation of multiplication was done
		}
		if (flagOfDiv)//*To calculate the division
		{
			/*pop out the last two organs*/
			com1.copyComplex(vectorOfComplex.back());
			vectorOfComplex.pop_back();
			com3.copyComplex(vectorOfComplex.back());
			vectorOfComplex.pop_back();

			/*Performs the action and put the result vector*/
			com1 = com3 / com1;
			vectorOfComplex.push_back(com1);//* push the complex to the vector
			flagOfDiv = false;//*Indicates that the operation of division was done
		}
		if (ch == '-')//*subtraction
			vectorOfComplex.back().setCompOperator(2);

		if (ch == '*')//*Multiplication
			flagOfMulti = true;

		if (ch == '/')//*Divide
			flagOfDiv = true;

		if (ch == 'a')//*abs (1)
			flagOfARM = 1;

		if (ch == 'r')//*real ( return a) (2)
			flagOfARM = 2;

		if (ch == 'm')//*imeag ( return b) (3)
			flagOfARM = 3;

		clearLineOneOne();

		if (ch == '=')//*To get the result
		{
			clearLineOneOne();

			Complex compCul1;
			Complex compCul2;

			if (!vectorOfComplex.empty())//*pop out the last organ from the vector
			{
				compCul1.copyComplex(vectorOfComplex.back());
				vectorOfComplex.pop_back();
			}

			if (flagOfARM != 0)//* abs/real/imaginary for complex number
			{
				if (flagOfARM == 1)//*abs
					cout << compCul1.calcAbs();
				if (flagOfARM == 2)//*real (return a)
					cout << compCul1.getCompA();
				if (flagOfARM == 3)//*imaginary (return b)
					cout << compCul1.getCompB();

				if (flagOfSound)//* for the sound
				{
					if (flagOfARM == 1)//*abs
						playSoundAvi(compCul1.calcAbs());
					if (flagOfARM == 2)//*real (return a)
						playSoundAvi(compCul1.getCompA());
					if (flagOfARM == 3)//*imaginary (return b)
						playSoundAvi(compCul1.getCompB());
				}
				/*Indicates that the actions was done*/
				flagOfARM = 0;
				flagOfPrintARM = true;

			}
			if (vectorOfComplex.empty() && (!flagOfPrintARM))//*If no action has occurred(ARM or only press ==)
			{
				cout << compCul1;
				if (flagOfSound)//*play sound
				{
					playSoundAvi(compCul1.getCompA());//*real
					if (compCul1.getCompB()>=0)//* if the comB=<0
						PlaySound(TEXT("soundfiles\\plus.wav"), NULL, SND_SYNC);//*plus
					playSoundAvi(compCul1.getCompB());//*imaginary
					PlaySound(TEXT("soundfiles\\multiplied_by.wav"), NULL, SND_SYNC);//*imultiplied_by
					PlaySound(TEXT("soundfiles\\i.wav"), NULL, SND_SYNC);//*i
				}
			}

			flagOfPrintARM = false;

			while (!vectorOfComplex.empty())//*Calculates the other organs in vector
			{
				compCul2.copyComplex(vectorOfComplex.back());//*pop out the last organ
				vectorOfComplex.pop_back();

				if (compCul2.getCompOperator() != 2)//*Checks to perform arithmetic operations (addition or subtraction)
					compCul1 = compCul1 + compCul2;//* addition operation
				else
					compCul1 = compCul2 - compCul1;//*Subtraction operation

				if (vectorOfComplex.empty())//*print the Result
					cout << compCul1;
				if (flagOfSound)//*play sound
				{
					playSoundAvi(compCul1.getCompA());//*real
					if (compCul1.getCompB()>=0)
						PlaySound(TEXT("soundfiles\\plus.wav"), NULL, SND_SYNC);//*plus
					playSoundAvi(compCul1.getCompB());//*imaginary
					PlaySound(TEXT("soundfiles\\multiplied_by.wav"), NULL, SND_SYNC);//*imultiplied_by
					PlaySound(TEXT("soundfiles\\i.wav"), NULL, SND_SYNC);//*i
				}
			}
			vectorOfComplex.push_back(compCul1);//*Put the organ in vector

		}
		if (ch == 'c')//*clear the vector
		{
			clearLineOneOne();
			while (!vectorOfComplex.empty())//*Delete all the organ in the vector
				vectorOfComplex.pop_back();
		}
		if (ch == 'h')//*Help Menu
		{
			explanatoryScreen();//* print on the Screen the Help Menu
			system("CLS");
			printOnTheScreen();
		}
		if (ch == 's')//*Turn on / turn off the sound
		{
			if (!flagOfSound)
				flagOfSound = true;
			else
				flagOfSound = false;
		}

		gotoXY(1, 1);
		ch = getch();
		clearLineOneOne();

	}
	clearLineOneOne();
	return 0;
}
//*******************************************
//***************Methods*********************
//*******************************************
void clearLineOneOne()
//*The method performs Delete the line and moves the cursor where you want
{
	gotoXY(1, 1);
	cout << "                  ";
	gotoXY(1, 1);
}
void explanatoryScreen()
//*The system prints on the screen the Help Menu
{
	system("CLS");
	cout << "-------------------------------------------------------" << endl;
	cout << "|                     Help Menu                       |" << endl;
	cout << "|Digits 0 - 9                                         |" << endl;
	cout << "|Press E to insert a number of complex (pattern:a+b*i)|" << endl;
	cout << "|Press = to see the result                            |" << endl;
	cout << "|Press + to make an addition                          |" << endl;
	cout << "|Press - to perform a subtraction                     |" << endl;
	cout << "|Press * to perform multiplication                    |" << endl;
	cout << "|Press / to perform a division operation              |" << endl;
	cout << "|                                                     |" << endl;
	cout << "|Press R for the real component                       |" << endl;
	cout << "|Press M for the imaginary component                  |" << endl;
	cout << "|Press A for absolute value                           |" << endl;
	cout << "|Press S to hear the result                           |" << endl;
	cout << "|Press P to exit from this menu                       |" << endl;
	cout << "|Press Q to exit from the calculator                  |" << endl;
	cout << "-------------------------------------------------------" << endl;

	char ch = getch();
	if (ch == 'p')//* exit from the help menu
	{
		return;
	}
}
void convertStinrgToTwoInt(string s, double * x, double * y)
/*The method takes a string of several complex and two address.
The method sets the values ​​of the numbers in the values ​​of the complex number
*/
{
	string s1, s2;

	double thePlus;
	double theC;

	for (int i = 0; i < s.length(); i++)//* run on the string
	{
		if (s[i] == '+')
			thePlus = i;
		if (s[i] == '-')
			thePlus = i;
		if (s[i] == '*')
			theC = i;
	}
	s1 = s.substr(0, thePlus);//* a
	s2 = s.substr(thePlus, theC);//* b

	stringstream convert1(s1);//* convert string to double
	convert1 >> *x;
	stringstream convert2(s2);//* convert string to double
	convert2 >> *y;
}
void gotoXY(int x, int y)
//*The method moves the cursor where you want the screen
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}
void printOnTheScreen()
//*The method prints on the screen the calculator
{

	int x;
	int const LENGTH = 38;

	for (int i = 0; i < LENGTH; i++)
		cout << "-";

	cout << "" << endl;
	cout << "|";

	cout << "                                    |" << endl;
	for (int i = 0; i < LENGTH; i++)
		cout << "-";
	cout << "" << endl;

	cout << "|1| |2| |3|         |+|  |-|  |/|  |*| " << endl;
	cout << "|4| |5| |6|         |Real(z)|   |M(z)|" << endl;
	cout << "|7| |8| |9|         |Abs(z)|       |H|" << endl;
	cout << "|0| |C| |=|         |  toggle Speak  |" << endl;
	cout << "|                   |Enter number z: |" << endl;
	cout << "|                   |     exit Q     |" << endl;

	for (int i = 0; i < LENGTH; i++)
		cout << "-";
	cout << "" << endl;

	gotoXY(1, 1);

};
