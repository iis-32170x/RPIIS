#include <windows.h>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Cube CubickRubick;
	srand(time(0));
	CubickRubick.Game();
}