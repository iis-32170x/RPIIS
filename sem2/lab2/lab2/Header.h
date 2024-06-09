#pragma once
#include <string>

using namespace std;

namespace Y {
	struct element {
		element* next = nullptr;
		element* prev = nullptr;
		element* side = nullptr;
		element* prevside = nullptr;
		string field ;
		int mult = 1;
	};
	class set {
	private:
		element* Insert(element* el, string a);
		bool subset(element* A, element* B);
		void Insert(string a);
		void output(element* mnvo);
		string check(string mnvo);
	public:
		void input();
		void output(set* mnvo);
		set** Obed(set** mnvo, int n);
		element* multiplicity(element* mnvo);
		set** file(set**& mnvo,int& countr);
		element* root = nullptr;
	};
}