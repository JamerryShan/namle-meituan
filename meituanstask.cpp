#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <time.h> 
#include <conio.h>
using namespace std;

int compare(char sum1, char sum2)
{
	if (sum1 >= sum2)
		return 1;
	else
		return 0;
}
int bust(int sum)
{
	if (sum > 21)
		return 0;
	else
		return 1;
}
enum suits { hearts, spades, clubs, diamonds };
struct card
{
	suits suit;
	char value[3];
	int score;
};
void random(card a[], int n)
{
	int index, i;
	card tmp;
	srand(time(NULL));
	for (i = n - 1; i>0; i--)
	{
		index = rand() % i;
		tmp = a[i];
		a[i] = a[index];
		a[index] = tmp;
	}

}
void game()
{
	char suit[][10] = { "hearts", "spades", "clubs", "diamonds" };
	struct card cards[52];
	char values[][3] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cards[i * 13 + j].value[k] = values[j][k];
			}
			cards[i * 13 + j].suit = suits(i);
			switch (cards[i * 13 + j].value[0])
			{
			case 'A':
				cards[i * 13 + j].score = 1;
				break;
			case 'J':
				cards[i * 13 + j].score = 10;
				break;
			case 'Q':
				cards[i * 13 + j].score = 10;
				break;
			case 'K':
				cards[i * 13 + j].score = 10;
				break;
			case '2':
				cards[i * 13 + j].score = 2;
				break;
			case '3':
				cards[i * 13 + j].score = 3;
				break;
			case '4':
				cards[i * 13 + j].score = 4;
				break;
			case '5':
				cards[i * 13 + j].score = 5;
				break;
			case '6':
				cards[i * 13 + j].score = 6;
				break;
			case '7':
				cards[i * 13 + j].score = 7;
				break;
			case '8':
				cards[i * 13 + j].score = 8;
				break;
			case '9':
				cards[i * 13 + j].score = 9;
				break;
			case '1':
				cards[i * 13 + j].score = 10;
				break;
			}

		}
	}
	card host[15];
	card player[15];
	int host_sum = 0, player_sum = 0;
	random(cards, 52);
	char choice;
	host[0] = cards[0];
	host[1] = cards[1];
	host_sum = host[0].score + host[1].score;

	player[0] = cards[2];
	player[1] = cards[3];
	player_sum = player[0].score + player[1].score;
	cout << "Your cards: " << endl;
	cout << suit[player[0].suit] << "-" << player[0].value << endl;
	cout << suit[player[1].suit] << "-" << player[1].value << endl;
	int i;
	if (host_sum <= 18)
	{
		int k = 3;
		for (i = 4; i <= 16 && host_sum <= 18; i++)
		{
			host[k] = cards[i];
			k++;
			host_sum += cards[i].score;
		}
	}
	if (!bust(host_sum))
	{
		cout << "Host busted!You win!" << endl;
	}
	else
	{
		int h = 2;
		cout << "您是否要进行抽牌（y/n）" << endl;
		while (1)
		{
			cin >> choice;
			switch (choice)
			{
			case 'y':
				cout << "Done" << endl;
				player[h] = cards[i];
				player_sum += player[h].score;
				cout << suit[player[h].suit] << "-" << player[h].value << endl;
				h++;
				i++;
				break;
			case'n':
				if (bust(host_sum) && bust(player_sum))
				{
					if (compare(host_sum, player_sum))
					{
						cout << "Host wins!" << endl;
						cout << "Press any key to exit" << endl;
						cin.get();
						cin.get();
						exit(0);
					}
					else
					{
						cout << "You win!" << endl;
						cout << "Press any key to exit" << endl;
						cin.get();
						cin.get();
						exit(0);
					}
				}
				end:break;
			default:
				if (choice != 'y' || choice != 'n')
				{
					cout << "Error" << endl;
				}
				break;
			}
			if (!bust(host_sum))
			{
				cout << "Host busted!You win!" << endl;
				break;
			}
			if (!bust(player_sum))
			{
				cout << "You busted!Host wins!" << endl;
				break;
			}
			
		}
	}
}
int main()
{
	int n;
	cout << "                  欢迎进入游戏！" << endl;
	cout << "                   1.开始游戏" << endl;
	cout << "                   2.退出游戏" << endl;
	if (scanf_s("%d", &n) && n == 1)
		game();
	else if (n == 2)
	{
		return 0;
	}
	cout << "Press any key to exit" << endl;
	cin.get();
	cin.get();
    return 0;
}