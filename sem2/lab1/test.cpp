#include "masivv.h"
#include <gtest/gtest.h>

//тест сортировки(№1 на правильность самой сортиртировки)
TEST(Array2Test, SortTest_1){
    Time x;
    Masiv2 arr(7,16);
    arr.mkmas(-25,25);
    
    arr.Sort(true,0,true);
    for (int i{0}; i < 6; i++)
        ASSERT_GE(arr.ElementG(i,0), arr.ElementG(i+1,0));
    arr.Sort(true,7,true);
    for (int i{0}; i < 6; i++)
        ASSERT_GE(arr.ElementG(i,7), arr.ElementG(i+1,7));
    arr.Sort(true,15,true);
    for (int i{0}; i < 6; i++)
        ASSERT_GE(arr.ElementG(i,15), arr.ElementG(i+1,15));

    arr.Sort(true,0,false);
    for (int i{0}; i < 6; i++)
        ASSERT_LE(arr.ElementG(i,0), arr.ElementG(i+1,0));
    arr.Sort(true,7,false);
    for (int i{0}; i < 6; i++)
        ASSERT_LE(arr.ElementG(i,7), arr.ElementG(i+1,7));
    arr.Sort(true,15,false);
    for (int i{0}; i < 6; i++)
        ASSERT_LE(arr.ElementG(i,15), arr.ElementG(i+1,15));

    arr.Sort(false,0,true);
    for (int i{0}; i < 15; i++)
        ASSERT_GE(arr.ElementG(0,i), arr.ElementG(0,i+1));
    arr.Sort(false,4,true);
    for (int i{0}; i < 15; i++)
        ASSERT_GE(arr.ElementG(4,i), arr.ElementG(4,i+1));
    arr.Sort(false,6,true);
    for (int i{0}; i < 15; i++)
        ASSERT_GE(arr.ElementG(6,i), arr.ElementG(6,i+1));

    arr.Sort(false,0,false);
    for (int i{0}; i < 15; i++)
        ASSERT_LE(arr.ElementG(0,i), arr.ElementG(0,i+1));
    arr.Sort(false,4,false);
    for (int i{0}; i < 15; i++)
        ASSERT_LE(arr.ElementG(4,i), arr.ElementG(4,i+1));
    arr.Sort(false,6,false);
    for (int i{0}; i < 15; i++)
        ASSERT_LE(arr.ElementG(6,i), arr.ElementG(6,i+1));
}

//тест на вставку элемента в отсортированный масив(№1 сохранение сортировки)
TEST(Array2Test, PushInSort_1){
    Masiv2 arr_2(7,16);
    arr_2.mkmas(-25,25);
    Masiv arr1(7),arr2(18);

    arr_2.Sort(false,3,true);
    arr1.mkmas(-25,25);
    arr_2.PushInSort(arr1);
    for (int i{0}; i < 16; i++)
        ASSERT_GE(arr_2.ElementG(3,i), arr_2.ElementG(3,i+1));
    
    arr_2.Sort(false,3,false);
    arr1.mkmas(-25,25);
    arr_2.PushInSort(arr1);
    for (int i{0}; i < 17; i++)
        ASSERT_LE(arr_2.ElementG(3,i), arr_2.ElementG(3,i+1));

    arr_2.Sort(true,3,true);
    arr2.mkmas(-25,25);
    arr_2.PushInSort(arr2);
    for (int i{0}; i < 7; i++)
        ASSERT_GE(arr_2.ElementG(i,3), arr_2.ElementG(i+1,3));

    arr_2.Sort(true,3,false);
    arr2.mkmas(-25,25);
    arr_2.PushInSort(arr2);
    for (int i{0}; i < 8; i++)
        ASSERT_LE(arr_2.ElementG(i,3), arr_2.ElementG(i+1,3));
}

//тест на поиск элемента в масиве
TEST(Array2Test, SearchInSort){
    Masiv2 arr(14,25);
    int k;

    arr.mkmas(-25,25);
    arr.Sort(true,5,true);
    k = arr.SearchInSort(7);
    if (k != -1)
        ASSERT_EQ(7, arr.ElementG(k,5));
    else
        for (int i{0}; i < 14; i++)
            ASSERT_NE(7, arr.ElementG(i,5));

    arr.mkmas(-25,25);
    arr.Sort(true,5,false);
    k = arr.SearchInSort(7);
    if (k != -1)
        ASSERT_EQ(7, arr.ElementG(k,5));
    else
        for (int i{0}; i < 14; i++)
            ASSERT_NE(7, arr.ElementG(i,5));
    
    arr.mkmas(-25,25);
    arr.Sort(false,5,true);
    k = arr.SearchInSort(7);
    if (k != -1)
        ASSERT_EQ(7, arr.ElementG(5,k));
    else
        for (int i{0}; i < 14; i++)
            ASSERT_NE(7, arr.ElementG(5,i));

    arr.mkmas(-25,25);
    arr.Sort(false,5,false);
    k = arr.SearchInSort(7);
    if (k != -1)
        ASSERT_EQ(7, arr.ElementG(5,k));
    else
        for (int i{0}; i < 14; i++)
            ASSERT_NE(7, arr.ElementG(5,i));
}

//тест сортировки(№2 сохранение "целостности" элементов)
TEST(Array2Test, SortTest_2){
    Masiv2 arr1(7,16);
    arr1.mkmas(-25,25);
    Masiv2 arr2(arr1);
    int k;

    
    arr1.Sort(true,5,true);
    for (int i{0}; i < 7; i++){
        k = arr1.SearchInSort(arr2.ElementG(i,5));
        if ((k == 0 || arr1.ElementG(k,5) != arr1.ElementG(k-1,5)) && (k == 6 || arr1.ElementG(k,5) != arr1.ElementG(k+1,5)))
            for (int j{0}; j < 16; j++)
                ASSERT_EQ(arr1.ElementG(k,j), arr2.ElementG(i,j));
    }

    arr1.Sort(true,5,false);
    for (int i{0}; i < 7; i++){
        k = arr1.SearchInSort(arr2.ElementG(i,5));
        if ((k == 0 || arr1.ElementG(k,5) != arr1.ElementG(k-1,5)) && (k == 6 || arr1.ElementG(k,5) != arr1.ElementG(k+1,5)))
            for (int j{0}; j < 16; j++)
                ASSERT_EQ(arr1.ElementG(k,j), arr2.ElementG(i,j));
    }

    arr1.mkmas(-25,25);
    Masiv2 arr3(arr1);

    arr1.Sort(false,5,true);
    for (int i{0}; i < 16; i++){
        k = arr1.SearchInSort(arr3.ElementG(5,i));
        if ((k == 0 || arr1.ElementG(5,k) != arr1.ElementG(5,k-1)) && (k == 16 || arr1.ElementG(5,k) != arr1.ElementG(5,k+1)))
            for (int j{0}; j < 7; j++)
                ASSERT_EQ(arr1.ElementG(j,k), arr3.ElementG(j,i));
    }

    arr1.Sort(false,5,false);
    for (int i{0}; i < 16; i++){
        k = arr1.SearchInSort(arr3.ElementG(5,i));
        if ((k == 0 || arr1.ElementG(5,k) != arr1.ElementG(5,k-1)) && (k == 16 || arr1.ElementG(5,k) != arr1.ElementG(5,k+1)))
            for (int j{0}; j < 7; j++)
                ASSERT_EQ(arr1.ElementG(j,k), arr3.ElementG(j,i));
    }

}

//тест на вставку элемента в отсортированный масив(№2 сохранение "целостности" элемента)
TEST(Array2Test, PushInSort_2){
    Masiv2 arr_2(7,16);
    arr_2.mkmas(-25,25);
    Masiv arr1(7),arr2(18);
    int k;

    arr_2.Sort(false,3,true);
    arr1.mkmas(-25,25);
    arr_2.PushInSort(arr1);
    k = arr_2.SearchInSort(arr1.ElementG(3));
    for (int i{0}; i < 7; i++)
        ASSERT_EQ(arr1.ElementG(i), arr_2.ElementG(i,k));

    arr_2.Sort(false,3,false);
    arr1.mkmas(-25,25);
    arr_2.PushInSort(arr1);
    k = arr_2.SearchInSort(arr1.ElementG(3));
    for (int i{0}; i < 7; i++)
        ASSERT_EQ(arr1.ElementG(i), arr_2.ElementG(i,k));

    arr_2.Sort(true,3,true);
    arr2.mkmas(-25,25);
    arr_2.PushInSort(arr2);
    k = arr_2.SearchInSort(arr2.ElementG(3));
    for (int i{0}; i < 18; i++)
        ASSERT_EQ(arr2.ElementG(i), arr_2.ElementG(k,i));

    arr_2.Sort(true,3,false);
    arr2.mkmas(-25,25);
    arr_2.PushInSort(arr2);
    k = arr_2.SearchInSort(arr2.ElementG(3));
    for (int i{0}; i < 18; i++)
        ASSERT_EQ(arr2.ElementG(i), arr_2.ElementG(k,i));
}

//тест на объединение двух масивов(сохранение сортировки)
TEST(Array2Test, UnionSort){
    Masiv2 arr1(7,13),arr2(8,13),arr_res(2,2);

    arr1.mkmas(-25,25);
    arr2.mkmas(-25,25);

    arr1.Sort(true,6,true);
    arr2.Sort(true,6,true);
    arr_res.UnionSort(arr1,arr2);
    for (int i {0}; i < 14; i++)
        ASSERT_GE(arr_res.ElementG(i,6), arr_res.ElementG(i+1,6));
    
    arr1.Sort(true,6,false);
    arr2.Sort(true,6,true);
    arr_res.UnionSort(arr1,arr2);
    for (int i {0}; i < 14; i++)
        ASSERT_LE(arr_res.ElementG(i,6), arr_res.ElementG(i+1,6));

    arr1.Sort(true,6,true);
    arr2.Sort(true,6,false);
    arr_res.UnionSort(arr1,arr2);
    for (int i {0}; i < 14; i++)
        ASSERT_GE(arr_res.ElementG(i,6), arr_res.ElementG(i+1,6));

    arr1.Sort(true,6,false);
    arr2.Sort(true,6,false);
    arr_res.UnionSort(arr1,arr2);
    for (int i {0}; i < 14; i++)
        ASSERT_LE(arr_res.ElementG(i,6), arr_res.ElementG(i+1,6));

    Masiv2 arr3(7,4),arr4(7,12);

    arr3.mkmas(-25,25);
    arr4.mkmas(-25,25);

    arr3.Sort(false,6,true);
    arr4.Sort(false,6,true);
    arr_res.UnionSort(arr3,arr4);
    for (int i {0}; i < 15; i++)
        ASSERT_GE(arr_res.ElementG(6,i), arr_res.ElementG(6,i+1));

    arr3.Sort(false,6,false);
    arr4.Sort(false,6,true);
    arr_res.UnionSort(arr3,arr4);
    for (int i {0}; i < 15; i++)
        ASSERT_LE(arr_res.ElementG(6,i), arr_res.ElementG(6,i+1));

    arr3.Sort(false,6,true);
    arr4.Sort(false,6,false);
    arr_res.UnionSort(arr3,arr4);
    for (int i {0}; i < 15; i++)
        ASSERT_GE(arr_res.ElementG(6,i), arr_res.ElementG(6,i+1));

    arr3.Sort(false,6,false);
    arr4.Sort(false,6,false);
    arr_res.UnionSort(arr3,arr4);
    for (int i {0}; i < 15; i++)
        ASSERT_LE(arr_res.ElementG(6,i), arr_res.ElementG(6,i+1));
}

//тест на пересечение двух масивов(сохранение сортировки)
TEST(Array2Test, IntersectionSort){
    Masiv2 arr1(7,13),arr2(8,13),arr_res(2,2);
    int k;

    arr1.mkmas(-25,25);
    arr2.mkmas(-25,25);

    arr1.Sort(true,6,true);
    arr2.Sort(true,6,true);
    arr_res.IntersectionSort(arr1,arr2);
    k = arr_res.SizeNG() - 1;
    for (int i {0}; i < k; i++)
        ASSERT_GE(arr_res.ElementG(i,6), arr_res.ElementG(i+1,6));
    
    arr1.Sort(true,6,false);
    arr2.Sort(true,6,true);
    arr_res.IntersectionSort(arr1,arr2);
    k = arr_res.SizeNG() - 1;
    for (int i {0}; i < k; i++)
        ASSERT_LE(arr_res.ElementG(i,6), arr_res.ElementG(i+1,6));

    arr1.Sort(true,6,true);
    arr2.Sort(true,6,false);
    arr_res.IntersectionSort(arr1,arr2);
    k = arr_res.SizeNG() - 1;
    for (int i {0}; i < k; i++)
        ASSERT_GE(arr_res.ElementG(i,6), arr_res.ElementG(i+1,6));
    
    arr1.Sort(true,6,false);
    arr2.Sort(true,6,false);
    arr_res.IntersectionSort(arr1,arr2);
    k = arr_res.SizeNG() - 1;
    for (int i {0}; i < k; i++)
        ASSERT_LE(arr_res.ElementG(i,6), arr_res.ElementG(i+1,6));

    Masiv2 arr3(7,5),arr4(7,12);

    arr3.mkmas(-25,25);
    arr4.mkmas(-25,25);

    arr3.Sort(false,6,true);
    arr4.Sort(false,6,true);
    arr_res.IntersectionSort(arr3,arr4);
    k = arr_res.SizeMG() - 1;
    for (int i {0}; i < k; i++)
        ASSERT_GE(arr_res.ElementG(6,i), arr_res.ElementG(6,i+1));

    arr3.Sort(false,6,false);
    arr4.Sort(false,6,true);
    arr_res.IntersectionSort(arr3,arr4);
    k = arr_res.SizeMG() - 1;
    for (int i {0}; i < k; i++)
        ASSERT_LE(arr_res.ElementG(6,i), arr_res.ElementG(6,i+1));

    arr3.Sort(false,6,true);
    arr4.Sort(false,6,false);
    arr_res.IntersectionSort(arr3,arr4);
    k = arr_res.SizeMG() - 1;
    for (int i {0}; i < k; i++)
        ASSERT_GE(arr_res.ElementG(6,i), arr_res.ElementG(6,i+1));

    arr3.Sort(false,6,false);
    arr4.Sort(false,6,false);
    arr_res.IntersectionSort(arr3,arr4);
    k = arr_res.SizeMG() - 1;
    for (int i {0}; i < k; i++)
        ASSERT_LE(arr_res.ElementG(6,i), arr_res.ElementG(6,i+1));
}

//"ломаем" метод сорт
TEST(Array2BreakTest, SortTest){
    Masiv2 arr(7,16);
    arr.mkmas(-25,25);

    arr.Sort(true,1000,true);
    arr.Sort(true,-1000,true);
    arr.Sort(true,1000,false);
    arr.Sort(true,-1000,false);
    arr.Sort(false,1000,true);
    arr.Sort(false,-1000,true);
    arr.Sort(false,1000,false);
    arr.Sort(false,-1000,false);

    ASSERT_FALSE(arr.SortG());
}

//"ломаем" метод пушинсорт
TEST(Array2BreakTest, PushInSort){
    Masiv2 arr_2(7,16);
    arr_2.mkmas(-25,25);
    Masiv arr1(7),arr2(17);

    arr1.mkmas(-25,25);
    arr_2.PushInSort(arr1);
    ASSERT_EQ(17,arr_2.SizeMG());
    
    arr_2.Sort(true,4,true);
    arr1.mkmas(-25,25);
    arr_2.PushInSort(arr1);
    ASSERT_EQ(7,arr_2.SizeNG());
    ASSERT_EQ(17,arr_2.SizeMG());

    arr_2.Sort(true,4,false);
    arr1.mkmas(-25,25);
    arr_2.PushInSort(arr1);
    ASSERT_EQ(7,arr_2.SizeNG());
    ASSERT_EQ(17,arr_2.SizeMG());

    arr2.mkmas(-25,25);
    arr_2.PushInSort(arr2);
    ASSERT_EQ(8,arr_2.SizeNG());

    arr_2.Sort(false,4,true);
    arr2.mkmas(-25,25);
    arr_2.PushInSort(arr2);
    ASSERT_EQ(8,arr_2.SizeNG());
    ASSERT_EQ(17,arr_2.SizeMG());

    arr_2.Sort(false,4,false);
    arr2.mkmas(-25,25);
    arr_2.PushInSort(arr2);
    ASSERT_EQ(8,arr_2.SizeNG());
    ASSERT_EQ(17,arr_2.SizeMG());
}

//"ломаем" метод серчинсорт
TEST(Array2BreakTest, SearchInSort){
    Masiv2 arr(14,25);

    ASSERT_EQ(-1, arr.SearchInSort(7));

    arr.mkmas(-25,25);
    ASSERT_EQ(-1, arr.SearchInSort(7));
}

//"ломаем" метод унионсорт
TEST(Array2BreakTest, UnionSort){
    Masiv2 arr1(7,13),arr2(8,13),arr_res(2,2);

    arr1.mkmas(-25,25);
    arr_res.UnionSort(arr1,arr2);
    ASSERT_FALSE(arr_res.SortG());

    arr2.mkmas(-25,25);
    arr_res.UnionSort(arr1,arr2);
    ASSERT_FALSE(arr_res.SortG());

    arr1.Sort(true,3,true);
    arr_res.UnionSort(arr1,arr2);
    ASSERT_FALSE(arr_res.SortG());

    arr2.Sort(false,3,true);
    arr_res.UnionSort(arr1,arr2);
    ASSERT_FALSE(arr_res.SortG());

    arr2.Sort(true,5,true);
    arr_res.UnionSort(arr1,arr2);
    ASSERT_FALSE(arr_res.SortG());
}

//"ломаем" метод интерсекшнсорт
TEST(Array2BreakTest, IntersectionSort){
    Masiv2 arr1(7,13),arr2(8,13),arr_res(2,2);

    arr1.mkmas(-25,25);
    arr_res.IntersectionSort(arr1,arr2);
    ASSERT_FALSE(arr_res.SortG());

    arr2.mkmas(-25,25);
    arr_res.IntersectionSort(arr1,arr2);
    ASSERT_FALSE(arr_res.SortG());

    arr1.Sort(true,3,true);
    arr_res.IntersectionSort(arr1,arr2);
    ASSERT_FALSE(arr_res.SortG());

    arr2.Sort(false,3,true);
    arr_res.IntersectionSort(arr1,arr2);
    ASSERT_FALSE(arr_res.SortG());

    arr2.Sort(false,5,true);
    arr_res.IntersectionSort(arr1,arr2);
    ASSERT_FALSE(arr_res.SortG());
}

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}