#pragma once
namespace Y {
	class Deck {
	public:
		 Deck* addfront();
		 Deck* addback();
		 void output();
		 Deck* delfront();
		 Deck* delback();
		 Deck* crtdeck();
		 bool check();
		 Deck* file();
	private:
		int val;
		Deck* next;
		Deck* prev;
	};
}
