# Расчетная работа
## Условие (Вариант 4.16)
Найти граф конденсации для орграфа.
___
##  *Алгорит выполнения*

Для выполнения поставленной задачи используем алгоритм Касараю

### Алгоритм Косарайю

Алгоритм Косарайю предназначен для поиска компонент сильной связности в ориентированном графе и состоит из трёх шагов:

1.Выполнить поиск в глубину (DFS), пока не будут «помечены» все вершины. Вершина считается «помеченной», когда она входит в вектор "order"..

2.Инвертировать исходный граф.

3.Выполнить DFS в порядке убывания вершин вектора "order".

Полученные деревья каждого такта DFS последнего шага являются компонентами сильной связности
___

##  *Реализация на C++*
```
#include<iostream>
#include<vector>

using namespace std;
vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;

void dfs1(int v) {
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i)
		if (!used[g[v][i]])
			dfs1(g[v][i]);
	order.push_back(v);
}

void dfs2(int v) {
	used[v] = true;
	component.push_back(v);
	for (size_t i = 0; i < gr[v].size(); ++i)
		if (!used[gr[v][i]])
			dfs2(gr[v][i]);
}

int main() {
	setlocale(LC_ALL, "rus");
	int n = 3;
	int m;
	g.resize(n);
	gr.resize(n);

	cout << "Введите количество ребер" << endl;
	cin >> m;
	cout << "Введите ребра" << endl;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}


	

	used.assign(n, false);
	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs1(i);
	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2(v);
			for (int u : component) {
				cout << u << " ";
			}
			cout << endl;
				component.clear();
		}
	}
}
```
___
[Для вопросов и претензий](https://www.youtube.com/watch?v=HEXWRTEbj1I)
