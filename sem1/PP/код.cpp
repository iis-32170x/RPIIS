#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

void cicle(vector<vector<int>>& graph, int v, vector<vector<int>>& novigraph) {
	
	vector<vector<int>> pyts(1);
	int pyti{ 1 };
	pyts[0].push_back(0);

	for (int shagi{ 0 }; shagi < v; shagi++) {
		int obchiecopy{ 0 };

		for (int pytik{ 0 }; pytik < pyti; pytik++) {
			int copy{ -1 };
			bool vozvrat{ false };

			if (pyts[pytik][shagi] != -1) {
				for (int vozmoj : graph[pyts[pytik][shagi]]) {
					bool mojno_li_idti{ true };

					if (vozmoj == 0) {
						vozvrat = true;
					}

					for (int nashx : pyts[pytik]) {
						if (vozmoj == nashx) {
							mojno_li_idti = false;
						}
					}

					if (mojno_li_idti == true) {
						copy++;
						if (copy == 0) {
							pyts[pytik].push_back(vozmoj);
						}
						else {
							pyts.push_back(pyts[pytik]);
							pyts[pyti - 1 + copy + obchiecopy].erase(pyts[pyti - 1 + copy + obchiecopy].end() - 1);
							pyts[pyti - 1 + copy + obchiecopy].push_back(vozmoj);
						}
					}
					if (shagi == (v - 1) && vozvrat == true && copy == -1) {
						copy++;
						pyts[pytik].push_back(0);
					}
				}
			}
			else {
				pyts[pytik].push_back(-1);
			}

			if (copy == -1 && shagi != (v - 1)) {
				pyts[pytik].push_back(-1);
			}

			if (shagi == (v - 1) && vozvrat == true) {
				
				for (int shagz{ 1 }; shagz <= v; shagz++) {
					bool mojno_li_idti2{ true };
					for (int novic : novigraph[pyts[pytik][shagz - 1]]) {
						if (novic == pyts[pytik][shagz]) {
							mojno_li_idti2 = false;
						}
					}
					if (mojno_li_idti2 == true) {
						novigraph[pyts[pytik][shagz-1]].push_back(pyts[pytik][shagz]);
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

	for (int svazi{ 0 }; svazi < svaz; svazi++) {
		int a, b;
		inputFile >> a >> b;
		graph[a].push_back(b);
	}
	inputFile.close();

	cout << endl;
	cicle(graph, versh, novigraph);

	int proverca_na_pystotu{ 0 };
	for (int vershi{ 0 }; vershi < versh; vershi++) {
		for (int k : novigraph[vershi]) {
			outputFile << vershi << " " << k << endl;
			proverca_na_pystotu++;
		}
	}
	if (proverca_na_pystotu == 0) {
		outputFile << "PYSTOE MNOJESTVO";
	}
	outputFile.close();
}
