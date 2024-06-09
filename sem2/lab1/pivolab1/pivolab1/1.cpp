#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;

struct Stack {
	int info;
	Stack* next;
}*begind;

Stack* InStack(Stack* p, int in) {
	Stack* t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}//begind = InStack (begind, in);

void View(Stack* p)
{
	Stack* t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->next;
	}
}//View (begind);

Stack* OutStack(Stack* p, int* out) {
	Stack* t = p;
	*out = p->info;
	p = p->next;
	delete t;
	return p;
}//begin = OutStack ( begin, &out ); 

int main()
{
	system("chcp 1251<n");
	setlocale(LC_ALL, "russian");
	int in, n,m, kol, out;
	cout << "Input kolvo el = "; cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "push an element:";
		cin >> in;
		begind = InStack(begind, in);
	}
	View(begind);
	cout << endl;

	/*int value = GetStack(begind);
	cout << value << endl;*/

	cout << endl;
	cout << "¬ведите кол-во элементов которые хотите удалить" << endl; cin >> m;
	for (int i = 0; i < m; i++) {
		begind = OutStack(begind, &out);
	}

	cout << endl;
	View(begind);
	return 0;
}