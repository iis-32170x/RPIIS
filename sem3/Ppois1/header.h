#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <conio.h>

using namespace std;

extern const unsigned short SIZE;

extern vector<int> in_game_map;
extern vector<vector<int>> game_map;

extern vector<int> in_right_map;
extern vector<vector<int>> right_map;

struct coordinate
{
    unsigned x;
    unsigned y;
};

extern coordinate zero;

void create_right_map();
void create_game_map();
bool check_map();
void up_move();
void down_move();
void right_move();
void left_move();
void end_game();
void get_direction();
void screen();

#endif // HEADER_H