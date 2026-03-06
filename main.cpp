#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

//카드를 3장씩 받음
//총합이 21이 넘으면 짐
//21보다 작을 경우 서로 수를 비교해서 큰쪽이 이김.
//같을 경우 플레이어가 승리.
//1~9 까지는 숫자
//J, Q, K는 10으로 판정.

enum {
	Win,
	Lose
};

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	int Player[3] = { 0, }; //플레이어 카드
	int Com[3] = { 0, };    //컴퓨터 카드
	int Decision = 0;

	for (;;)
	{
		
		int TotalCountP = 0; //플레이어 카드 토탈 합계
		int TotalCountC = 0; //컴퓨터 카드 토탈 합계
		int RandomJQK = rand() % 3;

		for (int i = 0; i < 3; ++i)
		{
			Player[i] = rand() % 10 + 1;
			Com[i] = rand() % 10 + 1;

			TotalCountP += Player[i];
			TotalCountC += Com[i];
		}

		cout << "플레이어가 받은 카드 : ";
		for (int i = 0; i < 3; ++i)
		{
			if (Player[i] != 10)
			{
				cout << Player[i] << ' ';
			}
			else
			{
				switch (RandomJQK)
				{
				case 0:
					cout << 'j' << ' ';
					break;
				case 1:
					cout << 'Q' << ' ';
					break;
				case 2:
					cout << 'K' << ' ';
					break;
				}
			}
		}
		cout << '\n';
		cout << "합계 : " << TotalCountP << '\n';

		cout << "컴퓨터가 받은 카드 : ";
		for (int i = 0; i < 3; ++i)
		{
			if (Com[i] != 10)
			{
				cout << Com[i] << ' ';
			}
			else
			{
				switch (RandomJQK)
				{
				case 0:
					cout << 'J' << ' ';
					break;
				case 1:
					cout << 'Q' << ' ';
					break;
				case 2:
					cout << 'K' << ' ';
					break;
				}
			}
		}

		cout << '\n';
		cout << "합계 : " << TotalCountC << '\n';

		if (TotalCountP > 21 || TotalCountC > 21) //둘 중 하나가 21을 넘겼을 경우
		{
			if (TotalCountP > 21 && TotalCountC <= 21) //플레이어만 넘겼을 떄
			{
				Decision = Lose;
			}

			if (TotalCountC > 21) //컴퓨터가 넘겼을 때 (무조건 플레이어 승리)
			{
				Decision = Win;
			}
		}
		else //둘 다 21을 안 넘겼을 경우
		{
			if (TotalCountP >= TotalCountC)
			{
				Decision = Win;
			}
			else
			{
				Decision = Lose;
			}
		}

		switch (Decision)
		{
		case Win:
			cout << "플레이어 승리!!" << endl;
			break;
		case Lose:
			cout << "플레이어 패배!!" << endl;
			break;
		}

		cout << "다시 플레이할려면 아무키나 눌러주세요.";
		int Temp;
		Temp = _getch();

		system("cls");
	}
}