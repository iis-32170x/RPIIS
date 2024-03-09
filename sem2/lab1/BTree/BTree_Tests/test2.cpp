#include "pch.h"
#include "gtest/gtest.h" 
#include "BTREE.hpp" 

TEST(BTreeTest, SearchTest) {
    BTree tree(4);

    tree.insert(4);
    tree.insert(8);

    ASSERT_TRUE(tree.search(7) == nullptr); 
    tree.insert(7);
    ASSERT_TRUE(tree.search(7) != nullptr); 

    tree.insert(10);
    tree.insert(15);
    tree.insert(22);
    tree.insert(18);

    ASSERT_TRUE(tree.search(15) != nullptr);
    ASSERT_TRUE(tree.search(20) == nullptr); 
    ASSERT_TRUE(tree.search(4) != nullptr); 
    ASSERT_TRUE(tree.search(30) == nullptr);
}

TEST(BTreeTest, InsertTest) {
    BTree tree(4);

    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(10);
    tree.insert(15);
    tree.insert(22);
    tree.insert(18);
    tree.insert(16);
    tree.insert(2);
    tree.insert(38);

    ASSERT_TRUE(tree.search(1) != nullptr);
    ASSERT_TRUE(tree.search(4) != nullptr);
    ASSERT_TRUE(tree.search(10) != nullptr);
    ASSERT_TRUE(tree.search(15) != nullptr);
    ASSERT_TRUE(tree.search(22) != nullptr);
    ASSERT_TRUE(tree.search(18) != nullptr);
    ASSERT_TRUE(tree.search(16) != nullptr);
    ASSERT_TRUE(tree.search(2) != nullptr);
    ASSERT_TRUE(tree.search(38) != nullptr);
}

TEST(BTreeTest, RemoveTest) {
    BTree tree(4);

    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(10);
    tree.insert(15);
    tree.insert(22);
    tree.insert(18);
    tree.insert(25);
    tree.insert(30);
    tree.insert(8);

    ASSERT_TRUE(tree.search(15) != nullptr);
    tree.remove(15);
    ASSERT_TRUE(tree.search(15) == nullptr);

    ASSERT_TRUE(tree.search(18) != nullptr);
    tree.remove(18);
    ASSERT_TRUE(tree.search(18) == nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
