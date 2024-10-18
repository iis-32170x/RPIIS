#include "pch.h"
#include <gtest/gtest.h>
#include "../Laba1PPOIS/Header.h"
#include "../Laba1PPOIS/Header.cpp"


TEST(RubiksCubeTest, InitialState) {
    Cube cube;
    vector<Face> initialFaces = cube.GetDisplayedFace();
    EXPECT_EQ(cube.Examination(initialFaces), 1);
}

TEST(RubiksCubeTest, RandomizeCube) {
    Cube cube;
    vector<Face> initialFaces = cube.GetDisplayedFace();
    cube.Randomize(initialFaces);
    initialFaces = cube.GetDisplayedFace();
    EXPECT_EQ(cube.Examination(initialFaces), 0);
}
TEST(RubiksCubeTest, FileCube) {
    Cube cube;
    vector<Face> initialFaces = cube.GetDisplayedFace();
    cube.CubeReading(initialFaces);
    initialFaces = cube.GetDisplayedFace();
    EXPECT_EQ(cube.Examination(initialFaces), 0);
}
TEST(RubiksCubeTest, RotateFace) {
    Cube cube;
    vector<Face> initialFaces = cube.GetDisplayedFace();
    cube.FaceTurn(initialFaces, false);
    initialFaces = cube.GetDisplayedFace();
    EXPECT_EQ(cube.Examination(initialFaces), 0);
}
TEST(RubiksCubeTest, RotateAndBackFaces) {
    Cube cube;
    vector<Face> initialFaces = cube.GetDisplayedFace();
    cube.FaceTurn(initialFaces, false);
    initialFaces = cube.GetDisplayedFace();
    cube.FaceTurn(initialFaces, true);
    initialFaces = cube.GetDisplayedFace();
    EXPECT_EQ(cube.Examination(initialFaces), 1);
}
TEST(RubiksCubeTest, ManyRotatesFaces) {
    Cube cube;
    vector<Face> initialFaces = cube.GetDisplayedFace();
    cube.VerticalFaceTurn(initialFaces, 2, true);
    initialFaces = cube.GetDisplayedFace();
    cube.VerticalFaceTurn(initialFaces, 2, false);
    initialFaces = cube.GetDisplayedFace();
    cube.HorisontalFaceTurn(initialFaces, 2, false);
    initialFaces = cube.GetDisplayedFace();
    cube.HorisontalFaceTurn(initialFaces, 2, true);
    initialFaces = cube.GetDisplayedFace();
    EXPECT_EQ(cube.Examination(initialFaces), 1);
}