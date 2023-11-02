#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


void findCombs(std::vector<int>& lst, std::vector<std::vector<int>>& result, int start = 0) {
    int length = lst.size();

    if (start == length - 1) {
        result.push_back(lst);
    } else {
        for (int i = start; i < length; ++i) {
            std::swap(lst[start], lst[i]);
            findCombs(lst, result, start + 1);
            std::swap(lst[start], lst[i]);
        }
    }
}

bool isEqual(std::vector<std::vector<bool>> graph, std::vector<std::vector<bool>> pat, int k) {
    for (int i = 0; i < pat.size(); i += 1) {
        for (int j = 0; j < pat.size(); j += 1) {
            if (pat[i][j] == 1 and graph[i + k][j + k] != pat[i][j]) {
                return false;

            }
        }
    }
    return true;
}

std::vector<std::vector<std::vector<bool>>> findIsom(auto graph, auto combs) {
    std::vector<std::vector<std::vector<bool>>> kombGraphs;
    std::vector<std::vector<bool>> a;
    std::vector<bool> sub;

    for (auto k : combs) {
        a.clear();

        for (auto i : k) {
            sub.clear();
            for (auto j : k) {
                sub.push_back(graph[i][j]);
            }
            a.push_back(sub);
        }

        kombGraphs.push_back(a);
    }

    return kombGraphs;
}

int main() {
    std::ifstream f1;
    std::string line;
    std::cout << "Enter file name: ";
//     line = "";
    std::cin >> line;
    f1.open(line);

    int n, t;
    bool i;
    f1 >> n;
    t = 0;
    std::vector<std::vector<bool>> graph(n, std::vector<bool>(n));
    while (t < n * n) {
        f1 >> i;
        graph[t / n][t % n] = i;
        t += 1;
    }

    std::vector<int> l;

    for (int i = 0; i < n; i += 1) {
        l.push_back(i);
    }

    std::vector<std::vector<int>> combs;
    findCombs(l, combs);

    auto combsGr = findIsom(graph, combs);

    f1 >> n;
    t = 0;
    std::vector<std::vector<bool>> pat(n, std::vector<bool>(n));
    while (t < n * n) {
        f1 >> i;
        pat[t / n][t % n] = i;
        t += 1;
    }

    f1.close();

    std::vector<std::vector<int>> res;

    for (int k = 0; k < combsGr.size(); k += 1) {
        for (int i = 0; i < graph.size() - pat.size() + 1; i += 1) {
            if (isEqual(combsGr[k], pat, i)) {
                std::vector<int> n;

                for (int j = 0; j < pat.size(); j += 1) {
                    n.push_back(combs[k][j + i] + 1);
                }


                if (not std::count(res.begin(), res.end(), n)) {
                    res.push_back(n);
                }
            }
        }
    }

    std::ofstream f2;
    f2.open(line + "_exit");

    for (auto i : res) {
        for (int j = 0; j < i.size(); j += 1) {
            f2 << j + 1 << " -> " << i[j] << '\n';
        }
        f2 << '\n';
    }

    f2.close();

    return 0;
}
