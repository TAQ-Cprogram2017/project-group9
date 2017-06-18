#pragma once
#ifndef _MF_
#define _MF_

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

#endif
