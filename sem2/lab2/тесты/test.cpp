#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;


void Preobraz(Mnozh Ex, vector<string>& Elem, vector<int>& Kratn) {
    for (int j = 0; j < Ex.MoshMn; j++) {
        Elem.push_back(Ex.El[j].el);
        Kratn.push_back(Ex.El[j].kratn);
    }
}

//Тест сим разности множеств, элементами которого являются неориентированные и и ориентированные множества  
TEST(SimRazn_Mnozh_s_Elem_neorent_mnozh, Mnozs) {
    Mnozh A;
    A.El[0].el = "rrr";
    A.El[1].el = "{2,1}";
    A.El[2].el = "<1,2>";
    A.El[1].kratn = 3;
    A.El[2].kratn = 3;
    A.MoshMn = 3; 
    Mnozh MultMn[10];
    string path = "myfile.txt";
    Mnozh C = ReadFile(MultMn, path);
    vector<string> C_el;
    vector<string> A_el;
    vector<int> C_kr;
    vector<int> A_kr;
    Preobraz(C, C_el, C_kr);
    Preobraz(A, A_el, A_kr);
    EXPECT_EQ( C_el, A_el );
    EXPECT_EQ(C_kr, A_kr);
}

//Тест сим разности множеств 
TEST(SimRazn_Nesk_Mnozh, Mnozs) {
    Mnozh A;
    A.El[0].el = "E";
    A.El[1].el = "D";
    A.El[2].el = "F";
    A.El[3].el = "A";
    A.El[0].kratn = 3;
    A.El[2].kratn = 5;
    A.MoshMn = 4;
    Mnozh MultMn[10];
    string path = "myfile2.txt";
    Mnozh C = ReadFile(MultMn, path);
    vector<string> C_el;
    vector<string> A_el;
    vector<int> C_kr;
    vector<int> A_kr;
    Preobraz(C, C_el, C_kr);
    Preobraz(A, A_el, A_kr);
    EXPECT_EQ(C_el, A_el);
    EXPECT_EQ(C_kr, A_kr);
}

TEST(Proverka_na_korretni_vvod, Mnozs) {
    Mnozh MultMn[10];
    string path = "myfile3.txt";
    string path1 = "myfile4.txt";
    EXPECT_TRUE(ReadFile1(MultMn, path));
    EXPECT_FALSE(ReadFile1(MultMn, path1));
}

int main(int argc, char* argv[]) {

    

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}