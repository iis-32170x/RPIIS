#include "pch.h"
#include "gtest/gtest.h" 
#include "BTREE.hpp" 

TEST(BTreeTest, SearchTest) {
    BTree tree(3); 

    tree.insert(1);
    tree.insert(3);

    ASSERT_TRUE(tree.search(7) == nullptr); 
    tree.insert(7);
    ASSERT_TRUE(tree.search(7) != nullptr); 
    tree.insert(10);

    tree.insert(11);
  
    ASSERT_TRUE(tree.search(7) != nullptr); 
    ASSERT_TRUE(tree.search(2) == nullptr); 
}

TEST(BTreeTest, InsertTest) {
    BTree tree(3); 

    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(10);

    ASSERT_TRUE(tree.search(1) != nullptr);
    ASSERT_TRUE(tree.search(3) != nullptr);
    ASSERT_TRUE(tree.search(7) != nullptr);
    ASSERT_TRUE(tree.search(10) != nullptr);
}

TEST(BTreeTest, RemoveTest) {
    BTree tree(3); 

    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(10);

    ASSERT_TRUE(tree.search(3) != nullptr);
    tree.remove(3);
    ASSERT_TRUE(tree.search(3) == nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
