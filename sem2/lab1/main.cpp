#include <iostream>
#include <vector>
import trie;
using namespace std;




int main() {
	setlocale(LC_ALL, "ru");
	trie t;

	t.insert("artem");
	cout << t.search("art");
	t.remove_by_prefix("artem");
	cout << t.search("art");
}
