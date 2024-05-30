#pragma once
namespace Y {
	struct Deck {
	public:
		 Deck* addfront(Deck*& begin);
		 Deck* addback(Deck*& end);
		 void output();
		 Deck* delfront(Deck*& begin);
		 Deck* delback(Deck*& end,Deck*& begin);
		 Deck* crtdeck();
		 bool check();
		 Deck* file();
		 Deck* end();
		 int val=0;
		 Deck* next = nullptr;
		 Deck* prev = nullptr;
	};
}