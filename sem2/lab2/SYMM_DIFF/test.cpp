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






//
//TEST(SeeSetsTest, BasicTest) {
//    Set MultiSet[123];  // Создание массива MultiSet
//    // Заполнение MultiSet данными (по вашему тестовому сценарию)
//    // Например:
//    MultiSet[0].elem_count = 3;
//    MultiSet[0].Elem[0].element = "a";
//    MultiSet[0].Elem[0].multiplicity = 3;
//    MultiSet[0].Elem[1].element = "b";
//    MultiSet[0].Elem[1].multiplicity = 2;
//    MultiSet[0].Elem[2].element = "c";
//    MultiSet[0].Elem[2].multiplicity = 1;
//    // Захват вывода
//    testing::internal::CaptureStdout();
//    // Вызов функции SeeSets
//    SeeSets(MultiSet);
//    // Получение захваченного вывода
//    string output = testing::internal::GetCapturedStdout();
//
//    string expected_output = "МНОЖЕСТВО № 1: \n\n\t{ 3a, 2b, c } \n\n\n";
//
//    // Проверка корректности вывода с помощью утверждения (assertion)
//    EXPECT_EQ(output, expected_output);
//}

//
//TEST(Symm_Diff_Test, Correct_Diff) {
//    Set Multi[2];
//
//    Multi[0].elem_count = 3;
//    Multi[0].Elem[0].element = "a";
//    Multi[0].Elem[0].multiplicity = 3;
//    Multi[0].Elem[1].element = "b";
//    Multi[0].Elem[1].multiplicity = 2;
//    Multi[0].Elem[2].element = "f";
//    Multi[0].Elem[2].multiplicity = 4;
//
//    Multi[1].elem_count = 3;
//    Multi[1].Elem[0].element = "c";
//    Multi[1].Elem[0].multiplicity = 3;
//    Multi[1].Elem[1].element = "b";
//    Multi[1].Elem[1].multiplicity = 2;
//    Multi[1].Elem[2].element = "f";
//    Multi[1].Elem[2].multiplicity = 3;
//    Multi[0].brackets_count = 0;
//    Multi[1].brackets_count = 0;
//
//    Set A;
//    A = SymmDiff(Multi);
//
//    vector<string> result_elem;
//    vector<int> result_mcy;
//
//    for (int i = 0; i < A.elem_count; i++) {
//        result_elem.push_back(A.Elem[i].element);
//        result_mcy.push_back(A.Elem[i].multiplicity);
//    }
//
//    vector<string> expected_elem = { "c", "a", "f" };
//    vector<int> expected_mcy = { 3, 3, 1 };
//
//    EXPECT_EQ(result_elem, expected_elem);
//    EXPECT_EQ(result_mcy, expected_mcy);
//}

//TEST(One_Type_Test, Correct_Type) {
//    Set Multi;
//
//    Multi.elem_count = 6;
//    Multi.Elem[0].element = "a";
//    Multi.Elem[1].element = "b";
//    Multi.Elem[1].multiplicity = 2;
//    Multi.Elem[2].element = "{1,2,3}";
//    Multi.Elem[2].multiplicity = 3;
//    Multi.Elem[3].element = "f";
//    Multi.Elem[4].element = "f";
//    Multi.Elem[4].multiplicity = 3;
//    Multi.Elem[5].element = "a";
//    Multi.Elem[5].multiplicity = 2;
//
// /*   MultiSet[1].elem_count = 4;
//    MultiSet[1].Elem[0].element = "c";
//    MultiSet[1].Elem[0].multiplicity = 3;
//    MultiSet[1].Elem[1].element = "{1,3,2}";
//    MultiSet[1].Elem[1].multiplicity = 4;
//    MultiSet[1].Elem[2].element = "b";
//    MultiSet[1].Elem[2].multiplicity = 5;
//    MultiSet[1].Elem[3].element = "f";
//    MultiSet[1].Elem[3].multiplicity = 3;*/
//
//    // Вызываем функцию OneType для обработки множеств
//    OneType(&Multi);
//
//    //// Вызываем функцию SymmDiff для вычисления симметрической разности
//    //SymmDiff(MultiSet);
//
//    vector<string> Multi_elem;
//    vector<int> Multi_mcy;
//
//    for (int i = 0; i < Multi.elem_count; i++) {
//        Multi_elem.push_back(Multi.Elem[i].element);
//        Multi_mcy.push_back(Multi.Elem[i].multiplicity);
//    }
//
//    // Ожидаемый результат симметрической разности
//    Set Multi_exp;
//    string path = "test_type.txt";
//    GetSets(&Multi_exp, path);
//    vector<string> Multi_exp_elem;
//    vector<int> Multi_exp_mcy;
//
//    for (int i = 0; i < Multi_exp.elem_count; i++) {
//        Multi_exp_elem.push_back(Multi_exp.Elem[i].element);
//        Multi_exp_mcy.push_back(Multi_exp.Elem[i].multiplicity);
//    }
//    EXPECT_EQ(Multi_elem, Multi_exp_elem);
//    EXPECT_EQ(Multi_mcy, Multi_exp_mcy);
//}
