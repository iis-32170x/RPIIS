#include <gtest/gtest.h>
#include "pch.h"
#include <sstream>
#include <string>
#include "sdiff.h" 


TEST(Get_Sets_Test, Sets_Success) {
    Set Multi_A;
    Multi_A.elem_count = 4;
    Multi_A.Elem[0].element = "a";
    Multi_A.Elem[0].multiplicity = 1;
    Multi_A.Elem[1].element = "b";
    Multi_A.Elem[1].multiplicity = 2;
    Multi_A.Elem[2].element = "c";
    Multi_A.Elem[2].multiplicity = 3;
    Multi_A.Elem[3].element = "d";
    Multi_A.Elem[3].multiplicity = 8;

    vector<string> Multi_A_elem;
    vector<int> Multi_A_mcy;

    for (int i = 0; i < Multi_A.elem_count; i++) {
        Multi_A_elem.push_back(Multi_A.Elem[i].element);
        Multi_A_mcy.push_back(Multi_A.Elem[i].multiplicity);
    }


    Set Multi_B;
    string path = "test_input.txt";
    GetSets(&Multi_B, path);
    vector<string> Multi_B_elem;
    vector<int> Multi_B_mcy;

    for (int i = 0; i < Multi_B.elem_count; i++) {
        Multi_B_elem.push_back(Multi_B.Elem[i].element);
        Multi_B_mcy.push_back(Multi_B.Elem[i].multiplicity);
    }
    EXPECT_EQ(Multi_A_elem, Multi_B_elem);
    EXPECT_EQ(Multi_A_mcy, Multi_B_mcy);
}



TEST(File_Is_There, Successful_openinh) {
    Set MultMn[10];
    string path = "test_input.txt";
    string path1 = "tets_ipunt.txt";
    EXPECT_TRUE(GetSets1(MultMn, path));
    EXPECT_FALSE(GetSets1(MultMn, path1));
}


TEST(GetSetsTest, CorrectFile) {
    Set MultiSet[123];
    string path = "correct_input.txt";

    ASSERT_NO_THROW({
        GetSets(MultiSet, path);
        });

    ASSERT_EQ(MultiSet->set_count, 2);
    ASSERT_EQ(MultiSet[0].elem_count, 3);
    ASSERT_EQ(MultiSet[1].elem_count, 4);
}


TEST(DoSymmDiffTest, BasicTest) {
    Set MultiSet[123];  
    string path = "test_input.txt"; 
    string path1 = "test_abobik.txt";

    ASSERT_NO_THROW({
        Do_Symm_Diff(MultiSet, path);
        });

    ASSERT_THROW({
         Do_Symm_Diff(MultiSet, path1);
        }, runtime_error);
  
}
  

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    testing::InitGoogleTest(&argc, argv);
    int result= RUN_ALL_TESTS();
    if (result == 0) {
        cout << "\n\nВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО! :)" << endl;
    }
    else {
        cout << "\n\nТЕСТЫ НЕ ПРОЙДЕНЫ :(" << endl;
    }

    return result;
}






