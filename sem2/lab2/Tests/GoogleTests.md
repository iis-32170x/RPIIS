``` c++
#include "pch.h"
#include "D:\БГУИР\Пиво\sem2\Разность множеств\разность множеств\Header.h"


TEST(SetTest, AddAndContains) {
    Set<int> set;
    set.add(1);
    EXPECT_TRUE(set.contains(1));
    EXPECT_FALSE(set.contains(2));
}

TEST(SetTest, GetElements) {
    Set<int> set;
    set.add(1);
    set.add(2);
    std::vector<int> expected = { 1, 2 };
    EXPECT_EQ(set.getElements(), expected);
}

TEST(SetTest, Difference) {
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    Set<int> set2;
    set2.add(2);
    set2.add(3);
    std::vector<int> expected = { 1 };
    EXPECT_EQ(set1.difference(set2), expected);
}
```
