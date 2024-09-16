#include <iostream>
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\RubicCubeGraphic.h"
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\RubicCube.h"

using namespace std;

ostream& operator << (ostream& stream, const RubicCube& cube) {
	for (int face = 0; face < 6; face++) {
		stream << "\t\t\t Грань " << face + 1 << endl;
		for (int row = 0; row < 3; row++) {
			stream << "\t\t\t";
			for (int col = 0; col < 3; col++) {
				stream << cube.Cube[face][row][col] << "  ";
			}
			stream << endl;
		}
		stream << endl << endl;
	}
	return stream;
}

int main() {
	setlocale(LC_ALL, "ru");
	RubicCube Cube1(0);
	RubicCube Cube2(5);
	cout << Cube1 << endl;
	cout << Cube2 << endl;
	


	cout << (Cube1 == Cube2);
	



	return 0;
}