#include <stdio.h>                 
#include <time.h> 
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <time.h>
#include "mf.h"
#pragma comment(lib, "winmm.lib")
#define col_1 10	
#define row_1 10
#define col_2 20	
#define row_2 20
#define MINE_NUM_1 10
#define MINE_NUM_2 50

using namespace std;

void main()
{
	PlaySound(TEXT("ForTheWin.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	printf("Welcome to experience the ninth group produced c language demining game \nPlease choose the difficulty please enter 1 or 2 or 3\nlevel 1£ºeasy 2£ºhard 3£ºcrazy mode 4:tiphole mode 5:naughtyhole mode 6:supercrazy plus supertiphole mode\n");
	int m;
	scanf_s("%d", &m);
	system("cls");
	switch (m)
	{
	case 1:
	{
		PlaySound(TEXT("Remember me.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		clock_t start = clock();
		init_1(MINE_NUM_1);
		int  x;
		char y;
		void fillblank_1();
		print_1();
		while (1)
		{
			printf("\nPlease enter coordinates, for example:a1\nIf you want to set the flag, change the column number to uppercase:\n");
			scanf_s("%c", &y);
			scanf_s("%d", &x);
			system("cls");

			if (x <= 0 || x > col_1)
			{
				print_1();
				printf("Coordinates wrong, please enter:\n");
				continue;
			}
			if (y >= 65 && y <= 64 + row_1)
				flag_1(x, y);
			else if (y >= 97 && y <= 96 + row_1)
				open_1(x, y);
			else
			{
				print_1();
				printf("Coordinates wrong, please enter£º\n");
				continue;
			}
			print_1();
			if (open_1(x, y) == -1)
			{
				PlaySound(TEXT("Fail.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("boom-shakalaka......game over\n");
				break;
			}
			if (is_win_1())
			{
				PlaySound(TEXT("Victory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("hahaha(: congratulations you win!\n");
				break;
			}
		}
		clock_t end = (clock() - start) / CLOCKS_PER_SEC;
		cout << "time comsumption is " << end << endl;
	}
	Sleep(3000);
	break;
	case 2:
	{
		PlaySound(TEXT("Charlie Trains Atom.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		clock_t start = clock();
		init_2(MINE_NUM_2);
		int  x;
		char y;
		void fillblank_2();
		print_2();
		while (1)
		{
			printf("\nPlease enter coordinates, for example:a1\nIf you want to set the flag, change the column number to uppercase:\n");
			scanf_s("%c", &y);
			scanf_s("%d", &x);
			system("cls");

			if (x <= 0 || x > col_2)
			{
				print_2();
				printf("Coordinates wrong, please enter:\n");
				continue;
			}
			if (y >= 65 && y <= 64 + row_2)
				flag_2(x, y);
			else if (y >= 97 && y <= 96 + row_2)
				open_2(x, y);
			else
			{
				print_2();
				printf("Coordinates wrong, please enter£º\n");
				continue;
			}
			print_2();
			if (open_2(x, y) == -1)
			{
				PlaySound(TEXT("Fail.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("boom-shakalaka......game over\n");
				break;
			}
			if (is_win_2())
			{
				PlaySound(TEXT("Victory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("hahaha(: congratulations you win!\n");
				break;
			}
		}
		clock_t end = (clock() - start) / CLOCKS_PER_SEC;
		cout << "time comsumption is " << end << endl;
	}
	Sleep(3000);
	break;
	case 3:
	{
		PlaySound(TEXT("Love Story.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		clock_t start = clock();
		init_crazymode(MINE_NUM_1);
		int  x;
		char y;
		void fillblank_1();
		print_1();
		while (1)
		{
			printf("\nPlease enter coordinates, for example:a1\nIf you want to set the flag, change the column number to uppercase;\n");
			scanf_s("%c", &y);
			scanf_s("%d", &x);
			system("cls");

			if (x <= 0 || x > col_1)
			{
				print_1();
				printf("Coordinates wrong, please enter:\n");
				continue;
			}
			if (y >= 65 && y <= 64 + row_1)
				flag_1(x, y);
			else if (y >= 97 && y <= 96 + row_1)
				open_1(x, y);
			else
			{
				print_1();
				printf("Coordinates wrong, please enter:\n");
				continue;
			}
			print_1();
			if (open_1(x, y) == -1)
			{
				PlaySound(TEXT("Fail.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("boom-shakalaka......game over\n");
				break;
			}
			if (is_win_1())
			{
				PlaySound(TEXT("Victory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("hahaha(: congratulations you win!\n");
				break;
			}
		}
		clock_t end = (clock() - start) / CLOCKS_PER_SEC;
		cout << "time comsumption is " << end << endl;
	}
	Sleep(3000);
	break;
	case 4:
	{
		PlaySound(TEXT("Empire of Angels.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		clock_t start = clock();
		init_tipholemode(MINE_NUM_2);
		int  x;
		char y;
		void fillblank_2();
		print_2();
		while (1)
		{
			printf("\nPlease enter coordinates, for example:a1\nIf you want to set the flag, change the column number to uppercase:\n");
			scanf_s("%c", &y);
			scanf_s("%d", &x);
			system("cls");

			if (x <= 0 || x > col_2)
			{
				print_2();
				printf("Coordinates wrong, please enter:\n");
				continue;
			}
			if (y >= 65 && y <= 64 + row_2)
				flag_2(x, y);
			else if (y >= 97 && y <= 96 + row_2)
				open_2(x, y);
			else
			{
				print_2();
				printf("Coordinates wrong, please enter:\n");
				continue;
			}
			print_2();
			if (open_2(x, y) == -1)
			{
				PlaySound(TEXT("Fail.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("boom-shakalaka......game over\n");
				break;
			}
			if (is_win_2())
			{
				PlaySound(TEXT("Victory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("hahaha(: congratulations you win!\n");
				break;
			}
		}
		clock_t end = (clock() - start) / CLOCKS_PER_SEC;
		cout << "time comsumption is " << end << endl;
	}
	Sleep(3000);
	break;
	case 5:
	{
		PlaySound(TEXT("Cherry Bomb.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		clock_t start = clock();
		init_naughtyholemode(MINE_NUM_2);
		int  x;
		char y;
		void fillblank_2();
		print_2();
		while (1)
		{
			printf("\nPlease enter coordinates, for example:a1\nIf you want to set the flag, change the column number to uppercase: \n");
			scanf_s("%c", &y);
			scanf_s("%d", &x);
			system("cls");

			if (x <= 0 || x > col_2)
			{
				print_2();
				printf("Coordinates wrong, please enter:\n");
				continue;
			}
			if (y >= 65 && y <= 64 + row_2)
				flag_2(x, y);
			else if (y >= 97 && y <= 96 + row_2)
				open_2(x, y);
			else
			{
				print_2();
				printf("Coordinates wrong, please enter:\n");
				continue;
			}
			print_2();
			if (open_2(x, y) == -1)
			{
				PlaySound(TEXT("Fail.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("boom-shakalaka......game over\n");
				break;
			}
			if (is_win_2())
			{
				PlaySound(TEXT("Victory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("hahaha(: congratulations you win!\n");
				break;
			}
		}
		clock_t end = (clock() - start) / CLOCKS_PER_SEC;
		cout << "time comsumption is " << end << endl;
	}
	Sleep(3000);
	break;
	case 6:
	{
		PlaySound(TEXT("Titanium.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		clock_t start = clock();
		init_crazyholemode(MINE_NUM_2);
		int  x;
		char y;
		void fillblank_2();
		print_2();
		while (1)
		{
			printf("\nPlease enter coordinates, for example:a1\nIf you want to set the flag, change the column number to uppercase: \n");
			scanf_s("%c", &y);
			scanf_s("%d", &x);
			system("cls");

			if (x <= 0 || x > col_2)
			{
				print_2();
				printf("Coordinates wrong, please enter:\n");
				continue;
			}
			if (y >= 65 && y <= 64 + row_2)
				flag_2(x, y);
			else if (y >= 97 && y <= 96 + row_2)
				open_2(x, y);
			else
			{
				print_2();
				printf("Coordinates wrong, please enter:\n");
				continue;
			}
			print_2();
			if (open_2(x, y) == -1)
			{
				PlaySound(TEXT("Fail.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("boom-shakalaka......game over\n");
				break;
			}
			if (is_win_2())
			{
				PlaySound(TEXT("Victory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				printf("hahaha(: congratulations you win!\n");
				break;
			}
		}
		clock_t end = (clock() - start) / CLOCKS_PER_SEC;
		cout << "time comsumption is " << end << endl;
	}
	Sleep(3000);
	}
}