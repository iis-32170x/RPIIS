#include <iostream>
#include <vector>
#include <fstream>
#include <cstddef>
using namespace std;

bool isPlanar(size_t v, size_t e)
{
    return e + 6 <= 3 * v;
}

std::vector<std::vector<bool>> DelV(std::vector<std::vector<bool>> g, int n)
{
    for (auto i = 0; i < n; ++i)
    {
        g[i].erase(g[i].begin() + n - 1);
    }
    g.erase(g.begin() + n - 1);
    return g;
}

int SkolkoEdjey(std::vector<std::vector<bool>>& g)
{
    int cnt = 0;
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g.size(); j++)
        {
            if (g[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt / 2;
}

void Printg(std::vector<std::vector<bool>> g)
{
    std::cout << std::noboolalpha << "GRAPH\n";

    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g.size(); j++)
        {
            std::cout << g[i][j];
        }
        std::cout << '\n';
    }
}

int Find(std::vector<std::vector<bool>> g)
{
    if (isPlanar(g.size(), SkolkoEdjey(g)) || g.size() < 3)
    {
        return 0;
    }
    int k = 1 + Find(DelV(g, 1));//удаляем первую вершину 
    
    for (int i = 2; i <= g.size(); i++)
    {
        int tmp = 1 + Find(DelV(g, i));
        if (tmp < k)
        {
            k = tmp;
        }
    }
    return k;
}

int main()
{
    std::vector<std::vector<bool>> g;
    std::ifstream ifs("graph.txt");
    int v, e;
    ifs >> v >> e;
    g.resize(v);
    for (int i = 0; i < v; i++)
    {
        g[i].resize(v);
        for (int j = 0; j < v; j++)
        {
            bool tmp;
            ifs >> tmp;
            g[i][j] = tmp;
        }
    }
    if (isPlanar(g.size(), SkolkoEdjey(g)))
    {
        std::cout << "PLANAR!";
    }
    else
    {
        std::cout << "You need to delete " << Find(g) << " vertexs";
    }
    return 0;
}




