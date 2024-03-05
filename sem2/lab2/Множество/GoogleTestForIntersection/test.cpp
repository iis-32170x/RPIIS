#include "pch.h"
#include "..\SetLib\Header.h"

TEST(TestSetLib, TestCreateSets) {
	using namespace SetLib;
	setlocale(LC_ALL, "ru");
	std::vector<std::vector<int>> set = CreateSets(3);
	EXPECT_EQ(set.size(), 3);
}

// Для 2-ёх множеств по 3 элемента
TEST(TestSetLib, TestCartesianProduct) {
	using namespace SetLib;
	setlocale(LC_ALL, "ru");
	std::vector<std::vector<int>> set1 = CreateSets(3);
	std::vector<std::vector<int>> set2 = cartesianProduct(set1);

	EXPECT_EQ(set2.size(), 27);
}