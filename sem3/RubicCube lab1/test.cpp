#include "pch.h"
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\RubicCubeGraphic.h"
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\RubicCube.h"
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\RubicCube.cpp"
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\RubicCubeGraphic.cpp"
#include "gtest/gtest.h"

using namespace std;

TEST(CheckCubeChoiceMenuGraphic, RubicCubeGameVisuals) {
	RubicCubeGameVisuals::CubeChoiceMenuGraphic();
	ASSERT_TRUE(1 == 1);
}

TEST(CheckMenuGraphic, RubicCubeGameVisuals) {
	RubicCubeGameVisuals::MenuGraphic();
	ASSERT_TRUE(1 == 1);
}

TEST(CheckBanner, RubicCubeGameVisuals) {
	RubicCubeGameVisuals::Banner();
	ASSERT_TRUE(1 == 1);
}

TEST(CheckColoringMessageWrong, CheckColoring) {
	RubicCube Cube("wrong_colors.txt");
	Cube.ColoringCheckMessage();
	ASSERT_TRUE(1 == 1);
}

TEST(CheckColoringMessageRightFile, CheckColoring) {
	RubicCube Cube("right_colors.txt");
	Cube.ColoringCheckMessage();
	ASSERT_TRUE(1 == 1);
}

TEST(CheckColoringMessageRight, CheckColoring) {
	RubicCube Cube(0);
	Cube.ColoringCheckMessage();
	ASSERT_TRUE(1 == 1);
}

TEST(CheckBasicCubeColoring, CheckColoring) {
	RubicCube Cube(0);
	ASSERT_TRUE(Cube.CheckColoring() == 1);
}

TEST(CheckRandomRotationCubeColoring, CheckColoring) {
	RubicCube Cube(3);
	ASSERT_TRUE(Cube.CheckColoring() == 1);
}

TEST(CheckWrongCubeColoringFromFile, CheckColoring) {
	RubicCube Cube("wrong_colors.txt");
	ASSERT_TRUE(Cube.CheckColoring() == 0);
}

TEST(CheckWrongCubeColoringCorners, CheckColoring) {
	RubicCube Cube("wrong_corners.txt");
	ASSERT_TRUE(Cube.CheckColoring() == 0);
}

TEST(CheckWrongCubeColoringEdges, CheckColoring) {
	RubicCube Cube("wrong_edges.txt");
	ASSERT_TRUE(Cube.CheckColoring() == 0);
}

TEST(CheckWrongCubeColoringNearCorners, CheckColoring) {
	RubicCube Cube("wrong_near_corners.txt");
	ASSERT_TRUE(Cube.CheckColoring() == 0);
}

TEST(CheckWrongCubeColoringNearEdges, CheckColoring) {
	RubicCube Cube("wrong_near_edges.txt");
	ASSERT_TRUE(Cube.CheckColoring() == 0);
}

TEST(CheckRightCubeColoringFromFile, CheckColoring) {
	RubicCube Cube("right_colors.txt");
	ASSERT_TRUE(Cube.CheckColoring() == 1);
}

TEST(CheckExitYes, ExitOption) {
	RubicCube Cube(0);
	cout << "Введите: Y\n";
	ASSERT_TRUE(Cube.ExitGame() == 0);
}

TEST(CheckExitNo, ExitOption) {
	RubicCube Cube(0);
	cout << "Введите: N\n";
	ASSERT_TRUE(Cube.ExitGame());
}

TEST(Equality, Operators) {
	RubicCube Cube1(0);
	RubicCube Cube2(0);
	ASSERT_TRUE(Cube1 == Cube2);
}

TEST(Inequality, Operators) {
	RubicCube Cube1(0);
	RubicCube Cube2(2);
	ASSERT_TRUE(Cube1 != Cube2);
}

TEST(Assignment, Operators) {
	RubicCube Cube1(2);
	RubicCube Cube2(0);
	Cube1 = Cube2;
	ASSERT_TRUE(Cube1 == Cube2);
}

TEST(SeeCube, SeeGraphic) {
	RubicCube Cube(0);
	Cube.SeeCube();
	ASSERT_TRUE(1 == 1);
}

TEST(CubeChoiceMenu, MenuLogic) {
	RubicCube Cube1("right_colors.txt");
	RubicCube Cube2(0);
	cout << "Выберите 2\n";
	cout << "Введите файл: right_colors.txt\n";
	Cube2.CubeChoiceMenu(Cube2);
	ASSERT_TRUE(Cube1 == Cube2);
}



int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}