struct vetka
{
	int data; 

	vetka* left; 

	vetka* right;

	vetka(int val) : data(val), left(nullptr), right(nullptr) {}


};
void Add(vetka*& current, int value);
void add1(vetka*& current, vetka*& mnozhC);
void proverka(int value, vetka* node, vetka*& mnozhC);
void removeNode(vetka*& current, int value);
void Peresechenie(vetka* mnozhA, vetka* mnozhB, vetka*& mnozhC);
void Objedinenie(vetka* mnozhA, vetka* mnozhB, vetka*& mnozhC);
void print(vetka* node);
vetka* FindElem(vetka* node, int value);
vetka* findMinNode(vetka* node);