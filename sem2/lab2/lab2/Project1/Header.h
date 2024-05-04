#pragma once
#include <string>
namespace Y {
	struct stack {
		char znak;
		stack* next;
	};
	struct element {
		element* next = nullptr;
		element* prev = nullptr;
		element* side = nullptr;
		element* prevside = nullptr;
		std::string field ;
		int mult = 1;
	};
	class set {
	private:
		element* Insert(element* el, std::string a);
		bool subset(element* A, element* B);
		void Insert(std::string a);
		void output(element* mnvo);
		std::string check(std::string mnvo);
	public:
		void input();
		void output(set* mnvo);
		set** Obed(set** mnvo, int n);
		element* multiplicity(element* mnvo);
		set** file(set**& mnvo,int& countr);
		element* root = nullptr;

	};
}