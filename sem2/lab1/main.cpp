#include "HaffmanTree.h"
#include "fstream"
using namespace std;
int main() {
	int num;
	string filename;
	cout << "Enter test number: ";
	cin >> num;
	cout << endl;
	switch (num)
	{
	case 1:
		filename = "test1.txt";
		break;
	case 2:
		filename = "test2.txt";
		break;
	case 3:
		filename = "test3.txt";
		break;
	case 4:
		filename = "test4.txt";
		break;
	default:
		cout << "There is no such test number";
		exit;

	}
	ifstream file(filename);
	string text;
	while (file) {
		getline(file,text);
	}
	unordered_map<char, string> BTable;
	Node* root = BuildTree(text, BTable);
	cout << "Encoded text: ";
	string encodedText = EncodeText(text, BTable);
	cout << EncodeText(text, BTable) << endl;
	cout << "Decoded text: ";
	string Decode =DecodeText(encodedText, root);
	cout << Decode << endl;
	if (text == Decode) {
		cout << "Test passed";
	}
	else {
		cout << "Test failed";
	}

}	