#pragma once

namespace SetLib
{
   //ћетод, осуществл€ющий операцию декартова произведени€ дл€ произвольного числа множеств
    std::vector<std::vector<int>> cartesianProduct(const std::vector<std::vector<int>>& sets);

    // ‘ункци€ дл€ вывода множества в консоль
    void printSet(const std::vector<int>& set);

    // ћетод дл€ создани€ и инициализации произвольного числа множеств
    std::vector<std::vector<int>> CreateSets(int num);
}