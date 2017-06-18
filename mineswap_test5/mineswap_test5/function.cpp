#include<stdio.h>                 
#include<time.h> 
#include<stdlib.h> 
#include <windows.h>
#pragma comment(lib, "winmm.lib")
#define col_1 10	
#define row_1 10
#define col_2 20	
#define row_2 20
#define MINE_NUM_1 10
#define MINE_NUM_2 50




void fillblank_1();
int  open_1(int x, char y);
void open_neighbors_1(int x, char y);
void fix_helpless_1();
void flag_1(int x, char y);
int  flag_count_1();
bool is_win_1();
void neighbors_count_1();
void init_1(int num);
void print_1();
void fillblank_2();
int  open_2(int x, char y);
void open_neighbors_2(int x, char y);
void fix_helpless_2();
void flag_2(int x, char y);
int  flag_count_2();
bool is_win_2();
void neighbors_count_2();
void init_2(int num);
void print_2();
void init_crazymode(int num);
void init_tipholemode(int num);
void init_naughtyholemode(int num);
void init_crazyholemode(int num);




struct mine
{
	bool is_mine;
	bool is_crazymine;
	bool is_hole;
	int status;
	int neighbors;
};
mine map_1[row_1 + 2][col_1 + 2];
mine map_2[row_2 + 2][col_2 + 2];


void fillblank_1()
{
	int i, j;
	for (i = 0; i < row_1 + 1; i++)
		for (j = 0; j < col_1 + 1; j++)
			if (i<1 || i > col_1 || j <1 || j >row_1)
				map_1[i][j].status = 1;
}

int open_1(int x, char y)
{
	y -= 96;
	if (x<1 || x>row_1 || y<1 || y>col_1)
		return 0;
	if (map_1[x][y].status != 0)
		return 0;
	else if (map_1[x][y].is_mine == true)
		return -1;
	else if (map_1[x][y].neighbors == 0)
	{
		map_1[x][y].status = 1;
		open_neighbors_1(x, y + 96);
	}
	else
		map_1[x][y].status = 1;
	return 1;
}

void fix_helpless_1()
{
	int i, j;
	for (i = 1; i < row_1; i++)
		for (j = 1; j < col_1; j++)
			if (map_1[i][j].neighbors == 0 && map_1[i][j].status == 1)
			{
				map_1[i - 1][j - 1].status = 1;
				map_1[i - 1][j].status = 1;
				map_1[i - 1][j + 1].status = 1;
				map_1[i][j - 1].status = 1;
				map_1[i][j + 1].status = 1;
				map_1[i + 1][j - 1].status = 1;
				map_1[i + 1][j].status = 1;
				map_1[i + 1][j + 1].status = 1;
			}
}

void open_neighbors_1(int x, char y)
{
	y -= 96;
	if (y + 1 < col_1 + 1)
		open_1(x, y + 1 + 96);
	if (x - 1 > 0)
		open_1(x - 1, y + 96);
	if (y - 1 > 0)
		open_1(x, y - 1 + 96);
	if (x + 1 < row_1 + 1)
		open_1(x + 1, y + 96);
}

void flag_1(int x, char y)
{
	y -= 64;
	if (map_1[x][y].status == 2)
		map_1[x][y].status = 0;
	else if (map_1[x][y].status == 0)
		map_1[x][y].status = 2;
}

int flag_count_1()
{
	int num = 0;
	int i, j;
	for (i = 1; i < row_1 + 1; i++)
		for (j = 1; j < col_1 + 1; j++)
			if (map_1[i][j].status == 2)
				num++;
	return MINE_NUM_1 - num;
}

bool is_win_1()
{
	int i, j;
	for (i = 1; i < row_1 + 1; i++)
		for (j = 1; j < col_1 + 1; j++)
			if (map_1[i][j].status == 0 && map_1[i][j].is_mine == false || map_1[i][j].status == 0 && map_1[i][j].is_crazymine == false || map_1[i][j].status == 2 && map_1[i][j].is_mine == false|| map_1[i][j].status == 2 && map_1[i][j].is_crazymine == false)
				return false;
	return true;
}

void neighbors_count_1()
{
	int i, j;
	for (i = 1; i < row_1 + 1; i++)
		for (j = 1; j < col_1 + 1; j++)
		{
			map_1[i][j].neighbors = map_1[i - 1][j - 1].is_mine + map_1[i - 1][j].is_mine + map_1[i - 1][j + 1].is_mine +
				map_1[i][j - 1].is_mine + map_1[i][j + 1].is_mine + map_1[i + 1][j - 1].is_mine + map_1[i + 1][j].is_mine +
				map_1[i + 1][j + 1].is_mine + 2 * (map_1[i - 1][j - 1].is_crazymine + map_1[i - 1][j].is_crazymine + map_1[i - 1][j + 1].is_crazymine +
					map_1[i][j - 1].is_crazymine + map_1[i][j + 1].is_crazymine + map_1[i + 1][j - 1].is_crazymine + map_1[i + 1][j].is_crazymine +
					map_1[i + 1][j + 1].is_crazymine);
		}
}

void init_1(int num)
{
	int i, j;
	for (i = 1; i < row_1; i++)
		for (j = 1; j < col_1; j++)
		{
			map_2[i][j].is_mine = 0;
			map_2[i][j].status = 0;
			map_2[i][j].neighbors = 0;
			map_2[i][j].is_hole = 0;
			map_2[i][j].is_crazymine = 0;
		}

	srand((unsigned)time(NULL));
	i = num;
	int temp;

	while (i > 0)
	{
		temp = rand() % (row_1*col_1);
		if (map_1[temp / row_1 + 1][temp % col_1 + 1].is_mine == false)
		{
			map_1[temp / row_1 + 1][temp % col_1 + 1].is_mine = true;
			i--;
		}
	}
	neighbors_count_1();
}



void print_1()
{
	fix_helpless_1();
	int i, j;
	printf("¡°@¡±Indicates that it is not open£¬¡°F¡±Indicates that the flag has been inserted and the number indicates the total number of mines in the surrounding 8 blocks.\n");
	printf("Current residual mine:%d\n", flag_count_1());
	printf("   ");
	for (i = 0; i < col_1; i++)
		printf(" %c ", i + 97);
	printf("\n");
	for (i = 1; i < col_1 + 1; i++)
	{
		printf("%2d ", i);
		for (j = 1; j < row_1 + 1; j++)
		{ 
			if (map_1[i][j].status == 1 && map_1[i][j].neighbors != 0)
				printf(" %d ", map_1[i][j].neighbors);
			else if (map_1[i][j].status == 1 && map_1[i][j].neighbors == 0)
				printf("   ");
			else if (map_1[i][j].status == 2)
				printf(" F ");
			else
				printf(" @ ");
		}
		printf("\n");
	}
}





void fillblank_2()
{
	int i, j;
	for (i = 0; i < row_2 + 1; i++)
		for (j = 0; j < col_2 + 1; j++)
			if (i<1 || i > col_2 || j <1 || j >row_2)
				map_2[i][j].status = 1;
}

int open_2(int x, char y)
{
	y -= 96;
	if (x<1 || x>row_2 || y<1 || y>col_2)
		return 0;
	if (map_2[x][y].status != 0)
		return 0;
	else if (map_2[x][y].is_mine == true)
		return -1;
	else if (map_2[x][y].neighbors == 0)
	{
		map_2[x][y].status = 1;
		open_neighbors_2(x, y + 96);
	}
	else
		map_2[x][y].status = 1;
	return 1;
}

void fix_helpless_2()
{
	int i, j;
	for (i = 1; i < row_2; i++)
		for (j = 1; j < col_2; j++)
			if (map_2[i][j].neighbors == 0 && map_2[i][j].status == 1)
			{
				map_2[i - 1][j - 1].status = 1;
				map_2[i - 1][j].status = 1;
				map_2[i - 1][j + 1].status = 1;
				map_2[i][j - 1].status = 1;
				map_2[i][j + 1].status = 1;
				map_2[i + 1][j - 1].status = 1;
				map_2[i + 1][j].status = 1;
				map_2[i + 1][j + 1].status = 1;
			}
}

void open_neighbors_2(int x, char y)
{
	y -= 96;
	if (y + 1 < col_1 + 1)
		open_2(x, y + 1 + 96);
	if (x - 1 > 0)
		open_2(x - 1, y + 96);
	if (y - 1 > 0)
		open_2(x, y - 1 + 96);
	if (x + 1 < row_1 + 1)
		open_2(x + 1, y + 96);
}

void flag_2(int x, char y)
{
	y -= 64;
	if (map_2[x][y].status == 2)
		map_2[x][y].status = 0;
	else if (map_2[x][y].status == 0)
		map_2[x][y].status = 2;
}

int flag_count_2()
{
	int num = 0;
	int i, j;
	for (i = 1; i < row_2 + 1; i++)
		for (j = 1; j < col_2 + 1; j++)
			if (map_2[i][j].status == 2)
				num++;
	return MINE_NUM_2 - num;
}

bool is_win_2()
{
	int num = row_2 + col_2;
	int i, j;
	for (i = 1; i < row_2 + 1; i++)
		for (j = 1; j < col_2 + 1; j++)
			if (map_2[i][j].status == 0 && map_2[i][j].is_mine == false || map_2[i][j].status == 0 && map_2[i][j].is_crazymine == false|| map_2[i][j].status == 2 && map_2[i][j].is_mine == false|| map_2[i][j].status == 2 && map_2[i][j].is_crazymine == false)
				return false;
	return true;
}

void neighbors_count_2()
{
	int i, j;
	for (i = 1; i < row_2 + 1; i++)
		for (j = 1; j < col_2 + 1; j++)
		{
			map_2[i][j].neighbors = map_2[i - 1][j - 1].is_mine + map_2[i - 1][j].is_mine + map_2[i - 1][j + 1].is_mine +
				map_2[i][j - 1].is_mine + map_2[i][j + 1].is_mine + map_2[i + 1][j - 1].is_mine + map_2[i + 1][j].is_mine +
				map_2[i + 1][j + 1].is_mine + 2 * (map_2[i - 1][j - 1].is_crazymine + map_2[i - 1][j].is_crazymine + map_2[i - 1][j + 1].is_crazymine +
					map_2[i][j - 1].is_crazymine + map_2[i][j + 1].is_crazymine + map_2[i + 1][j - 1].is_crazymine + map_2[i + 1][j].is_crazymine +
					map_2[i + 1][j + 1].is_crazymine);
		}
}

void init_2(int num)
{
	int i, j;
	for (i = 1; i < row_1; i++)
		for (j = 1; j < col_1; j++)
		{
			map_2[i][j].is_mine = 0;
			map_2[i][j].status = 0;
			map_2[i][j].neighbors = 0;
			map_2[i][j].is_hole = 0;
			map_2[i][j].is_crazymine = 0;
		}

	srand((unsigned)time(NULL));
	i = num;
	int temp;

	while (i > 0)
	{
		temp = rand() % (row_2*col_2);
		if (map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine == false)
		{
			map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine = true;
			i--;
		}
	}
	neighbors_count_2();
}



void print_2()
{
	fix_helpless_2();
	int i, j;
	printf("¡°@¡±Indicates that it is not open£¬¡°F¡±Indicates that the flag has been inserted and the number indicates the total number of mines in the surrounding 8 blocks.\n");
	printf("Current residual mine:%d\n", flag_count_2());
	printf("   ");
	for (i = 0; i < col_2; i++)
		printf(" %c ", i + 97);
	printf("\n");
	for (i = 1; i < col_2 + 1; i++)
	{
		printf("%2d ", i);
		for (j = 1; j < row_2 + 1; j++)
		{
			if (map_2[i][j].status == 1 && map_2[i][j].neighbors != 0)
				printf(" %d ", map_2[i][j].neighbors);
			else if (map_2[i][j].status == 1 && map_2[i][j].neighbors == 0|| map_2[i][j].is_hole)
				printf("   ");
			else if (map_2[i][j].status == 2)
				printf(" F ");
			else
				printf(" @ ");
		}
		printf("\n");
	}
}

void init_crazymode(int num)
{
	int i, j;
	for (i = 1; i < row_1; i++)
		for (j = 1; j < col_1; j++)
		{
			map_2[i][j].is_mine = 0;
			map_2[i][j].status = 0;
			map_2[i][j].neighbors = 0;
		}

	srand((unsigned)time(NULL));
	i = num-1;
	j = num / 10;
	int temp;

	while (j > 0)
	{
		temp = rand() % (row_1*col_1);
		if (map_1[temp / row_1 + 1][temp % col_1 + 1].is_mine == false || map_1[temp / row_1 + 1][temp % col_1 + 1].is_crazymine == false)
		{

			map_1[temp / row_1 + 1][temp % col_1 + 1].is_crazymine = true;
			j--;

		}
	}

	while (i > 0)
	{
		temp = rand() % (row_1*col_1);
		if (map_1[temp / row_1 + 1][temp % col_1 + 1].is_mine == false || map_1[temp / row_1 + 1][temp % col_1 + 1].is_crazymine == false)
		{
			map_1[temp / row_1 + 1][temp % col_1 + 1].is_mine = true;
			i--;

		}
	}
	neighbors_count_1();
}

void init_tipholemode(int num)
{
	int i, j;
	for (i = 1; i < row_2; i++)
		for (j = 1; j < col_2; j++)
		{
			map_2[i][j].is_mine = 0;
			map_2[i][j].status = 0;
			map_2[i][j].neighbors = 0;
			map_2[i][j].is_hole = 0;
			map_2[i][j].is_crazymine = 0;
		}

	srand((unsigned)time(NULL));
	i = num;
	int temp;
	j = num/5 ;

	while (i > 0)
	{
		temp = rand() % (row_2*col_2);
		if (map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine == false || map_2[temp / row_2 + 1][temp % col_2 + 1].is_hole == false)
		{
			map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine = true;
			i--;
		}
	}

	while (j > 0)
	{
		temp = rand() % (row_2*col_2);
		if (map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine == false || map_2[temp / row_2 + 1][temp % col_2 + 1].is_hole==false)
		{

			map_2[temp / row_2 + 1][temp % col_2 + 1].is_hole = true;
			j--;

		}
	}

	neighbors_count_2();
}

void init_naughtyholemode(int num)
{
	int i, j;
	for (i = 1; i < row_2; i++)
		for (j = 1; j < col_2; j++)
		{
			map_2[i][j].is_mine = 0;
			map_2[i][j].status = 0;
			map_2[i][j].neighbors = 0;
			map_2[i][j].is_hole = 0;
			map_2[i][j].is_crazymine = 0;
		}

	srand((unsigned)time(NULL));
	i = num;
	int temp;
	j = num;

	while (i > 0)
	{
		temp = rand() % (row_2*col_2);
		if (map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine == false || map_2[temp / row_2 + 1][temp % col_2 + 1].is_hole == false)
		{
			map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine = true;
			i--;
		}
	}

	while (j > 0)
	{
		temp = rand() % (row_2*col_2);
		if (map_2[temp / row_2 + 1][temp % col_2 + 1].is_hole == false)
		{

			map_2[temp / row_2 + 1][temp % col_2 + 1].is_hole = true;
			j--;

		}
	}

	neighbors_count_2();
}

void init_crazyholemode(int num)
{
	int i, j, k;
	for (i = 1; i < row_2; i++)
		for (j = 1; j < col_2; j++)
		{
			map_2[i][j].is_mine = 0;
			map_2[i][j].status = 0;
			map_2[i][j].neighbors = 0;
			map_2[i][j].is_hole = 0;
			map_2[i][j].is_crazymine = 0;
		}

	srand((unsigned)time(NULL));
	i = 4 * num / 5;
	int temp;
	j = num / 2;
	k = num / 5;

	while (i > 0)
	{
		temp = rand() % (row_2*col_2);
		if (map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine == false || map_2[temp / row_2 + 1][temp % col_2 + 1].is_hole == false || map_2[temp / row_2 + 1][temp % col_2 + 1].is_crazymine == false)
		{
			map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine = true;
			i--;
		}
	}
	

	while (j > 0)
	{
		temp = rand() % (row_2*col_2);
		if (map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine == false || map_2[temp / row_2 + 1][temp % col_2 + 1].is_hole == false || map_2[temp / row_2 + 1][temp % col_2 + 1].is_crazymine == false)
		{
			map_2[temp / row_2 + 1][temp % col_2 + 1].is_hole = true;
			j--;

		}
	}

	while (k > 0)
	{
		temp = rand() % (row_2*col_2);
		if (map_2[temp / row_2 + 1][temp % col_2 + 1].is_mine == false || map_2[temp / row_2 + 1][temp % col_2 + 1].is_hole == false || map_2[temp / row_2 + 1][temp % col_2 + 1].is_crazymine == false)
		{
			map_2[temp / row_2 + 1][temp % col_2 + 1].is_crazymine= true;
			k--;

		}
	}

	neighbors_count_2();
}