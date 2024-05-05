#include "intersection.h"


int main() {
	int num;
	string set1, set2;
	cout << "Enter test number(1-4): ";
	cin >> num;
	switch (num)
	{
	case 1:
		set1 = fromFile("set1.txt");
		set2 = fromFile("set2.txt");
		break;
	case 2:
		set1 = fromFile("set3.txt");
		set2 = fromFile("set4.txt");
		break;
	case 3:
		set1 = fromFile("set5.txt");
		set2 = fromFile("set6.txt");
		break;
	case 4:
		set1 = fromFile("set7.txt");
		set2 = fromFile("set8.txt");
		break;
	default:
		cout << "There is no such test number";
		exit(0);

	}
	setÑhecking(set1, set2);
	spacetest(set1, set2);
	
	string res = intersection(set1, set2);
	cout << "Initial set 1: " << set1 << endl;
	cout << "Initial set 2: " << set2 << endl;
	cout << "Intersection set: " << res;
}