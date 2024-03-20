#include <iostream>

using namespace std;

struct cell {
	char name = '@'; // primary key
	int multiplicity = 0; //zero by default
};

bool reps(cell* array, int N) {
	for (int i = 0; i < N; ++i) {
		if (array[i].name == array[N].name) {
			return true;
		}
	}
	return false;
}

cell* fillCells(cell* array, int N) {
	for (int i = 0; i < N; ++i) {
		cout << "Enter the name of a cell" << endl;
		char name;
		bool ok = false;
		while (!ok) {
			cin >> name;
			if (cin.fail() || reps(array, i)) {
				cin.clear();
				cin.ignore(12999, '\n');
				cout << "Nuh-uh" << endl;
			}
			else {
				ok = true;
				array[i].name = name;
			}
		}

		cout << "Enter the multiplicity of the cell" << endl;
		int multiplicity;
		bool ok_ = false;
		while (!ok_) {
			cin >> multiplicity;
			if (cin.fail() || multiplicity == 0) {
				cin.clear();
				cin.ignore(12999, '\n');
				cout << "Nuh-uh" << endl;
			}
			else {
				ok_ = true;
				array[i].multiplicity = multiplicity;
			}
		}
	}
	return array;
}

void showArray(cell* array, int N) {
	cout << "The array is:\n{";
	for (int i = 0; i < N; ++i) {
		if (i != N - 1) {
			cout << array[i].multiplicity << array[i].name << ", ";
		}
		else {
			cout << array[i].multiplicity << array[i].name << " ";
		}
	}
	cout << "}" << endl;
}

int min_(int first, int second) {
	return first >= second ? second : first;
}

cell* intersection(cell* first, cell* second, int N, int n) {
	int commonCount = 0;
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < n; ++k) {
			if (first[i].name == second[k].name) {
				++commonCount;
			}
		}
	}
	
	cell* temp = new cell[commonCount];
	int count = 0;
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < n; ++k) {
			if (first[i].name == second[k].name) {
				temp[count].name = first[i].name;
				temp[count].multiplicity = min_(first[i].multiplicity, second[k].multiplicity);
				++count;
			}
		}
	}

	return temp;
}

int common_count(cell* first, cell* second, int N, int n) {
	int commonCount = 0;
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < n; ++k) {
			if (first[i].name == second[k].name) {
				++commonCount;
			}
		}
	}
	return commonCount;
}

int main() {
	cout << "Enter the size of array" << endl;
	int N;
	bool ok = false;
	while (!ok) {
		cin >> N;
		if (cin.fail() || N <= 0) {
			cin.clear();
			cin.ignore(12999, '\n');
			cout << "Nuh-uh" << endl;
		}
		else {
			ok = true;
		}
	}
	cell* mainArray = new cell[N];

	fillCells(mainArray, N);
	showArray(mainArray, N);
	bool ok_;
	bool isOn = true;
	while (isOn) {
		cout << "Enter 1, if you want to continue intersection, otherwise, enter 0." << endl;
		int option;
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(12999, '\n');
			cout << "Nuh-uh" << endl;
		}
		switch (option)
		{
		case 1:
			cell* temp;
			cout << "Enter the size of array" << endl;
			ok_ = false;
			int n;
			while (!ok_) {
				cin >> n;
				if (cin.fail() || n <= 0) {
					cin.clear();
					cin.ignore(12999, '\n');
					cout << "Nuh-uh" << endl;
				}
				else {
					ok_ = true;
				}
			}
			temp = new cell[n];
			fillCells(temp, n);
			showArray(temp, n);
			mainArray = intersection(mainArray, temp, N, n);
			cout << "The array is:\n{";
			for (int i = 0; i < common_count(mainArray, temp, N, n); ++i) {
				if (i != N - 1) {
					cout << mainArray[i].multiplicity << mainArray[i].name << ", ";
				}
				else {
					cout << mainArray[i].multiplicity << mainArray[i].name << " ";
				}
			}
			cout << "}" << endl;
			delete[] temp;
			break;
		case 0:
			isOn = false;
			cout << "Bye." << endl;
			break;
		default:
			cout << "Nuh-uh" << endl;
			break;
		}
	}
	delete[] mainArray;
	return 0;
}