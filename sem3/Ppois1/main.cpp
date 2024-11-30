#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <conio.h>
#include "header.h"

using namespace std;

const unsigned short SIZE = 4;

vector<int> in_game_map(SIZE);
vector<vector<int>> game_map(SIZE, in_game_map);

vector<int> in_right_map(SIZE);
vector<vector<int>> right_map(SIZE, in_right_map);

coordinate zero;

int main()
{
    srand(static_cast<int>(time(NULL)));

    create_right_map();
    do
    {
        create_game_map();
    } while (check_map());

    do
    {
        screen();
        get_direction();
    } while (!check_map());

    cout << "\nYou win!\nGame over!\n";
    _getch();

    return 0;
}