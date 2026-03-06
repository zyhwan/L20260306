#include <iostream>
#include <conio.h>
#include <string>

#define CARDSIZE		52

using namespace std;

string DrawShape(int CardNumber)
{
	int Shape = CardNumber % 13 + 1;

	if (Shape == 11)
	{
		return "j";
	}
	else if (Shape == 12)
	{
		return "Q";
	}
	else if (Shape == 13)
	{
		return "K";
	}
	else if (Shape == 1)
	{
		return "A";
	}
	else
	{
		return to_string(Shape);
	}
}


int main()
{
	//Init
	int Cards[52] = { 0, };

	for (int i = 0; i < 52; ++i)
	{
		Cards[i] = i + 1;
	}


	srand((unsigned int)time(nullptr)); //시드 초기값 설정
	//Shuffle
	//Random(난수) 두개를 선택해서 교환

	for (int i = 0; i < CARDSIZE * 10; i++)
	{
		int FirstIndex = rand() % 52;
		int FirstSecond = rand() % 52;

		int Temp = Cards[FirstIndex];

		Cards[FirstIndex] = Cards[FirstSecond];
		Cards[FirstSecond] = Temp;
	}

	//Deal
	int ComputerCard[3];
	int PlayerCard[3];
	//0, 1
	//2, 3
	//4, 5
	for (int i = 0; i < 3; ++i)
	{
		ComputerCard[i] = Cards[i * 2];
		PlayerCard[i] = Cards[(i * 2) + 1];
	}

	int ComputerScore = 0;
	int PlayerScore = 0;

	for (int i = 0; i < 3; ++i)
	{
		ComputerScore += ComputerCard[i] % 13 + 1;
		PlayerScore += PlayerCard[i] % 13 + 1; 
	}
	//Draw

	if (ComputerScore > 21)
	{
		cout << "Win";
	}
	else if (PlayerScore > 21)
	{
		cout << "Lose";
	}
	else if (ComputerScore > PlayerScore)
	{
		cout << "Lose";
	}
	else
	{
		cout << "Win";
	}


	return 0;
}
