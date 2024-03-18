#include "Sort.h"
#include <iostream>
using namespace std;
void newelementtest(MassiveLibrary::Massive& a)
{
	cout << "Operation of adding a new element\n";
	a.New_element();
	a.Output();
	a.New_element();
	a.Output();
}
void Associationtest(MassiveLibrary::Massive& a, MassiveLibrary::Massive& b)
{
	cout << "Association operation\n";
	a.Association(b);
	a.Output();
}
void Searchtest(MassiveLibrary::Massive& a)
{
	cout << "Search operation\n";
	a.Search();
	a.Output();
}
void Intersectiontest(MassiveLibrary::Massive& a, MassiveLibrary::Massive& b)
{
	cout << "Intersection operation\n";
	a.Intersection(b);
	a.Output();
}
int main()
{
	int illusion_of_choice;
	int size;
	cout << "Press 1 to test the program with empty arrays.\nPress 2 to test the program with non-empty arrays";
	while (!(std::cin >> illusion_of_choice) || (std::cin.peek() != '\n') || (illusion_of_choice != 1 && illusion_of_choice != 2))
	{
		std::cin.clear();
		std::cin.ignore(99999, '\n');
		std::cout << "Incorrect data type" << std::endl;
	}
	if (illusion_of_choice == 1)
	{
		size = 0;
	}
	else
	{
		size = 3;
	}
	MassiveLibrary::Massive testmass(size);
	MassiveLibrary::Massive testmass2(size);
	testmass.Output();
	testmass2.Output();
	newelementtest(testmass);
	Associationtest(testmass, testmass2);
	Searchtest(testmass);
	Intersectiontest(testmass, testmass2);
	return 0;
}