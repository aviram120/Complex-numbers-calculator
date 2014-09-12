
The Department operates a complex calculator sound support.
The Department supports voice activation to 7 digits.
*/
#include "soundPP.h"
#include <windows.h>
#pragma comment( lib, "Winmm.lib" ) //Library for sound
#include <playsoundapi.h>

void playSoundAvi(const double &num)
{
	int a = (double)num;
	int i = 0;
	bool flagOf10 = false;
	int ar[7] = { 0, 0, 0, 0, 0, 0, 0 };//*for 7 number
	if (num<0)//*Negative
	{
		PlaySound(TEXT("soundfiles\\minus.wav"), NULL, SND_SYNC);//*minus(-)
		a = a*(-1);
	}
	if (a == 0)//*zero
		PlaySound(TEXT("soundfiles\\0.wav"), NULL, SND_SYNC);
	while (a != 0)
	{
		ar[i] = a % 10; // the smallest number;
		a = a / 10;
		i++;
	}


	int size = sizeof ar / sizeof(int);

	for (int i = size - 1; i >= 0; i--)
	{
		if (ar[i] != 0)
		{
			if (i == 6)
				playMillion(ar[i]);//*Million
			if (i == 5)
				play100k(ar[i]);//*Hundred thousand
			if (i == 4)
				play10k(ar[i]);//*Ten thousand
			if (i == 3)
				playK(ar[i]);//*Thousand
			if (i == 2)
				numberOfTheSoundHundred(ar[i]);//*Hundred
			
			if (i == 1)//*Ten
			{
				if (ar[i] == 1 && ar[i-1] != 0)//* 11-19
				{
					numberbetween19To11(ar[i - 1]);
					flagOf10 = true;
				}
				if (!flagOf10)//*10, 20-80
					numberOfTheSoundTen(ar[i]);
			}
				
			if (i == 0 && (!flagOf10))//*1-9
				numberOfTheSoundOne(ar[i]);
		}
	}
}
void playMillion(int x)
//*Million
{
	numberOfTheSoundOne(x);//*1-9
	PlaySound(TEXT("soundfiles\\million.wav"), NULL, SND_SYNC);//*Million
}
void play100k(int x)
//*Hundred thousand
{
	numberOfTheSoundHundred(x);//*900-100
	PlaySound(TEXT("soundfiles\\thousand.wav"), NULL, SND_SYNC);//*thousand	
}
void play10k(int x)
//*Ten thousand
{
	numberOfTheSoundTen(x);//*90-10
	PlaySound(TEXT("soundfiles\\thousand.wav"), NULL, SND_SYNC);//*thousand
}
void playK(int x)
//*Thousand
{
	numberOfTheSoundOne(x);//*1-9
	PlaySound(TEXT("soundfiles\\thousand.wav"), NULL, SND_SYNC);//*thousand
}
void numberOfTheSoundHundred(int x)
//*Hundred
{
	if (x == 9)//*900
		PlaySound(TEXT("soundfiles\\900.wav"), NULL, SND_SYNC);
	if (x == 8)//*800
		PlaySound(TEXT("soundfiles\\800.wav"), NULL, SND_SYNC);
	if (x == 7)//*700
		PlaySound(TEXT("soundfiles\\700.wav"), NULL, SND_SYNC);
	if (x == 6)//*600
		PlaySound(TEXT("soundfiles\\600.wav"), NULL, SND_SYNC);
	if (x == 5)//*500
		PlaySound(TEXT("soundfiles\\500.wav"), NULL, SND_SYNC);
	if (x == 4)//*400
		PlaySound(TEXT("soundfiles\\400.wav"), NULL, SND_SYNC);
	if (x == 3)//*300
		PlaySound(TEXT("soundfiles\\300.wav"), NULL, SND_SYNC);
	if (x == 2)//*200
		PlaySound(TEXT("soundfiles\\200.wav"), NULL, SND_SYNC);
	if (x == 1)//*100
		PlaySound(TEXT("soundfiles\\100.wav"), NULL, SND_SYNC);
}
void numberOfTheSoundTen(int x)
//*ten
{
	if (x == 9)//*90
		PlaySound(TEXT("soundfiles\\90.wav"), NULL, SND_SYNC);
	if (x == 8)//*80
		PlaySound(TEXT("soundfiles\\80.wav"), NULL, SND_SYNC);
	if (x == 7)//*70
		PlaySound(TEXT("soundfiles\\70.wav"), NULL, SND_SYNC);
	if (x == 6)//*60
		PlaySound(TEXT("soundfiles\\60.wav"), NULL, SND_SYNC);
	if (x == 5)//*50
		PlaySound(TEXT("soundfiles\\50.wav"), NULL, SND_SYNC);
	if (x == 4)//*40
		PlaySound(TEXT("soundfiles\\40.wav"), NULL, SND_SYNC);
	if (x == 3)//*30
		PlaySound(TEXT("soundfiles\\30.wav"), NULL, SND_SYNC);
	if (x == 2)//*20
		PlaySound(TEXT("soundfiles\\20.wav"), NULL, SND_SYNC);
	if (x == 1)//*10
		PlaySound(TEXT("soundfiles\\10.wav"), NULL, SND_SYNC);
}
void numberOfTheSoundOne(int x)
//*1-9
{
	if (x == 9)//*9
		PlaySound(TEXT("soundfiles\\9.wav"), NULL, SND_SYNC);
	if (x == 8)//*8
		PlaySound(TEXT("soundfiles\\8.wav"), NULL, SND_SYNC);
	if (x == 7)//*7
		PlaySound(TEXT("soundfiles\\7.wav"), NULL, SND_SYNC);
	if (x == 6)//*6
		PlaySound(TEXT("soundfiles\\6.wav"), NULL, SND_SYNC);
	if (x == 5)//*5
		PlaySound(TEXT("soundfiles\\5.wav"), NULL, SND_SYNC);
	if (x == 4)//*4
		PlaySound(TEXT("soundfiles\\4.wav"), NULL, SND_SYNC);
	if (x == 3)//*3
		PlaySound(TEXT("soundfiles\\3.wav"), NULL, SND_SYNC);
	if (x == 2)//*2
		PlaySound(TEXT("soundfiles\\2.wav"), NULL, SND_SYNC);
	if (x == 1)//*1
		PlaySound(TEXT("soundfiles\\1.wav"), NULL, SND_SYNC);

}
void numberbetween19To11(int x)
//*11-19
{
	if (x == 9)//*19
		PlaySound(TEXT("soundfiles\\19.wav"), NULL, SND_SYNC);
	if (x == 8)//*18
		PlaySound(TEXT("soundfiles\\18.wav"), NULL, SND_SYNC);
	if (x == 7)//*17
		PlaySound(TEXT("soundfiles\\17.wav"), NULL, SND_SYNC);
	if (x ==6)//*16
		PlaySound(TEXT("soundfiles\\16.wav"), NULL, SND_SYNC);
	if (x == 5)//*15
		PlaySound(TEXT("soundfiles\\15.wav"), NULL, SND_SYNC);
	if (x == 4)//*14
		PlaySound(TEXT("soundfiles\\14.wav"), NULL, SND_SYNC);
	if (x == 3)//*13
		PlaySound(TEXT("soundfiles\\13.wav"), NULL, SND_SYNC);
	if (x == 2)//*12
		PlaySound(TEXT("soundfiles\\12.wav"), NULL, SND_SYNC);
	if (x == 1)//*11
		PlaySound(TEXT("soundfiles\\11.wav"), NULL, SND_SYNC);
};
