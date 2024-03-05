#include "mnojestvo.hpp"
#include <gtest/gtest.h>

#define CORRECT_FALSE(NAME)                                         \
    mnojestva.clear();                                              \
    all_file = "";                                                  \
    ASSERT_FALSE(format(NAME, mnojestva, all_file));                \

#define CORRECT_TRUE(NAME)                                          \
    mnojestva.clear();                                              \
    all_file = "";                                                  \
    ASSERT_TRUE(format(NAME, mnojestva, all_file));                 \

#define INCORRECT(name1, name2, name3, name4, name5)                \
    vector<myset> mnojestva;                                        \
    string all_file;                                                \
    CORRECT_FALSE(name1)                                            \
    CORRECT_FALSE(name2)                                            \
    CORRECT_FALSE(name3)                                            \
    CORRECT_FALSE(name4)                                            \
    CORRECT_FALSE(name5)                                            \

#define SIMPLE_SETS(NAME, name)                                                                                         \
    TEST(SIMPLE_SETS_TEST, name){                                                                                       \
        vector<myset> mnojestva;                                                                                        \
        string all_file;                                                                                                \
        format(NAME, mnojestva, all_file);                                                                              \
        ASSERT_TRUE(regex_match(all_file.c_str(), regex ("(\\w+=((\\{\\w*(,\\w+)*\\})|(\\<\\w*(,\\w+)*\\>))\n)+")));    \
    }                                                                                                                   \

#define CORRECT_RESULT(NAME)                                                                            \
    mnojestva.clear();                                                                                  \
    all_file = "";                                                                                      \
    do_all(NAME);                                                                                       \
    mnojestva.clear();                                                                                  \
    all_file = "";                                                                                      \
    name2 = NAME;                                                                                       \
    name2.pop_back(); name2.pop_back(); name2.pop_back(); name2.pop_back();                             \
    ASSERT_TRUE(format("../sets/RESULT(" + name2.substr(8) + ").txt", mnojestva, all_file));            \

#define CORRECT_UNION(NAME_SETS, NAME_RESULT, name)                                                                     \
    TEST(UNION_TEST, name){                                                                                             \
        vector<myset> mnojestva;                                                                                        \
        string all_sets, all_result;                                                                                    \
        /* приводим файлы к удобному, "простому" формату */                                                             \
        format(NAME_SETS, mnojestva, all_sets);                                                                         \
        format(NAME_RESULT, mnojestva, all_result);                                                                     \
        /* находим все эелементы исходных множеств */                                                                   \
        const regex regular1("(\\w+)(?=,|\\}|\\>)");                                                                    \
        const vector<smatch> matches{                                                                                   \
            sregex_iterator{C_ALL(all_sets), regular1},                                                                 \
            sregex_iterator{}                                                                                           \
        };                                                                                                              \
        /* проверяем что для любого элемента из данных множеств, */                                                     \
        /* сущетсвует единнственный соответсвующий эелемент в результирующем множестве */                               \
        for (int i{0}; i < matches.size(); i++){                                                                        \
            const regex regular2(matches[i].str());                                                                     \
            const ptrdiff_t match_count(distance(sregex_iterator{C_ALL(all_result), regular2}, sregex_iterator{}));     \
            ASSERT_EQ(1, match_count);                                                                                  \
        }                                                                                                               \
    }                                                                                                                   \

// недопустимыe пробелы
TEST(FORMAT_TEST, incorrect_1){
    INCORRECT("../sets/bad_1.txt","../sets/bad_2.txt","../sets/bad_3.txt","../sets/bad_4.txt","../sets/bad_5.txt");
}
// недопустимые отступы
TEST(FORMAT_TEST, incorrect_2){
    INCORRECT("../sets/bad_6.txt","../sets/bad_7.txt","../sets/bad_8.txt","../sets/bad_9.txt","../sets/bad_10.txt");
}
// недопустимыe символы
TEST(FORMAT_TEST, incorrect_3){
    INCORRECT("../sets/bad_11.txt","../sets/bad_12.txt","../sets/bad_13.txt","../sets/bad_14.txt","../sets/bad_15.txt");
}
// неправильное применение {} и <>
TEST(FORMAT_TEST, incorrect_4){
    INCORRECT("../sets/bad_16.txt","../sets/bad_17.txt","../sets/bad_18.txt","../sets/bad_19.txt","../sets/bad_20.txt");
}
// неправильное применение = и ,
TEST(FORMAT_TEST, incorrect_5){
    INCORRECT("../sets/bad_21.txt","../sets/bad_22.txt","../sets/bad_23.txt","../sets/bad_24.txt","../sets/bad_25.txt");
}

// правильный формат
TEST(FORMAT_TEST, correct_1){
    vector<myset> mnojestva;
    string all_file, name2;
    CORRECT_TRUE("../sets/good_1.txt");
    CORRECT_TRUE("../sets/good_2.txt");
    CORRECT_TRUE("../sets/good_3.txt");
    CORRECT_TRUE("../sets/good_4.txt");
    CORRECT_TRUE("../sets/good_5.txt");
}
/*
    проверка на правильное упрощение множеств 
    (если множетсво, содержит внтури себя другое множетсво,
    то внутреннее множество получает имя и заменяется на это имя )
*/
SIMPLE_SETS("../sets/good_1.txt", sets_1);
SIMPLE_SETS("../sets/good_2.txt", sets_2);
SIMPLE_SETS("../sets/good_3.txt", sets_3);
SIMPLE_SETS("../sets/good_4.txt", sets_4);
SIMPLE_SETS("../sets/good_5.txt", sets_5);

// правильный формат результирующего файла
TEST(FORMAT_TEST, correct_result){
    vector<myset> mnojestva;
    string all_file;
    string name2;
    CORRECT_RESULT("../sets/good_1.txt");
    CORRECT_RESULT("../sets/good_2.txt");
    CORRECT_RESULT("../sets/good_3.txt");
    CORRECT_RESULT("../sets/good_4.txt");
    CORRECT_RESULT("../sets/good_5.txt");
}

CORRECT_UNION("../sets/good_1.txt", "../sets/RESULT(good_1).txt", correct_1);
CORRECT_UNION("../sets/good_1.txt", "../sets/RESULT(good_1).txt", correct_2);
CORRECT_UNION("../sets/good_1.txt", "../sets/RESULT(good_1).txt", correct_3);
CORRECT_UNION("../sets/good_1.txt", "../sets/RESULT(good_1).txt", correct_4);
CORRECT_UNION("../sets/good_1.txt", "../sets/RESULT(good_1).txt", correct_5);

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
