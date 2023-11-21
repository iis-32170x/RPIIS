#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

void cicle(vector<vector<int>>& graph, int v, vector<vector<int>>& novigraph) {
	
	vector<vector<int>> pyts(1);
	int pyti{ 1 };
	pyts[0].push_back(0);

	for (int i{ 0 }; i < v; i++) {
		int obchiecopy{ 0 };

		for (int k{ 0 }; k < pyti; k++) {
			int copy{ -1 };
			bool vozvrat{ false };

			if (pyts[k][i] != -1) {
				for (int j : graph[pyts[k][i]]) {
					bool mojno_li_idti{ true };

					if (j == 0) {
						vozvrat = true;
					}

					for (int x : pyts[k]) {
						if (j == x) {
							mojno_li_idti = false;
						}
					}

					if (mojno_li_idti == true) {
						copy++;
						if (copy == 0) {
							pyts[k].push_back(j);
						}
						else {
							pyts.push_back(pyts[k]);
							pyts[pyti - 1 + copy + obchiecopy].erase(pyts[pyti - 1 + copy + obchiecopy].end() - 1);
							pyts[pyti - 1 + copy + obchiecopy].push_back(j);
						}
					}
					if (i == (v - 1) && vozvrat == true && copy == -1) {
						copy++;
						pyts[k].push_back(0);
					}
				}
			}
			else {
				pyts[k].push_back(-1);
			}

			if (copy == -1 && i != (v - 1)) {
				pyts[k].push_back(-1);
			}

			if (i == (v - 1) && vozvrat == true) {
				
				for (int z{ 1 }; z <= v; z++) {
					bool mojno_li_idti2{ true };
					for (int c : novigraph[pyts[k][z - 1]]) {
						if (c == pyts[k][z]) {
							mojno_li_idti2 = false;
						}
					}
					if (mojno_li_idti2 == true) {
						novigraph[pyts[k][z-1]].push_back(pyts[k][z]);
					}
				}
			}
			if (copy > 0) {
				obchiecopy += copy;
			}
		}
		pyti += obchiecopy;
	}
}


int main() {

	setlocale(LC_ALL, "RU");
	string stroka;

	cout << "Введите файл: ";
	cin >> stroka;

	ifstream inputFile(stroka);
	ofstream outputFile("novigraph.txt");

	int versh, svaz;
	inputFile >> versh >> svaz;

	vector<vector<int>> graph(versh);
	vector<vector<int>> novigraph(versh);

	for (int i{ 0 }; i < svaz; i++) {
		int a, b;
		inputFile >> a >> b;
		graph[a].push_back(b);
	}
	inputFile.close();

	cout << endl;
	cicle(graph, versh, novigraph);

	int g{ 0 };
	for (int i{ 0 }; i < versh; i++) {
		for (int k : novigraph[i]) {
			outputFile << i << " " << k << endl;
			g++;
		}
	}
	if (g == 0) {
		outputFile << "PYSTOE MNOJESTVO";
	}
	outputFile.close();
}
