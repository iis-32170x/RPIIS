#ifndef SET_H
#define SET_H
#include <vector>
using namespace std;

class Set
{
public:
	Set() {}
	Set(vector<int> elements) : elements(elements) {}
	bool contains(int value) { return find(elements.begin(), elements.end(), value) != elements.end(); }
	void add(int value) { elements.push_back(value); }
	vector<int> getElements() { return elements; }


	friend ostream& operator<<(ostream& os, const Set& set)
	{
		for (const int& elem : set.elements)
		{
			os << elem << " ";
		}
		return os;
	}
private:
	vector<int> elements;
};
#endif