//
// Created by xinardelis on 29/10/24.
//

#include <gtest/gtest.h>
#include "dictionary.h"

TEST(DictionaryCopyConstructor, CopiesEmptyTree) {
  Dictionary original;
  Dictionary copy(original);
  EXPECT_EQ(copy.size(), 0);
}

TEST(DictionaryCopyConstructor, CopiesSingleElementTree) {
  Dictionary original;
  original += "key1";
  original["key1"] = "value1";
  Dictionary copy(original);
  EXPECT_EQ(copy.size(), 1);
  EXPECT_EQ(copy["key1"], original["key1"]);
}

TEST(DictionaryCopyConstructor, CopiesMultipleElementsTree) {
  Dictionary original;
  original += "key1";
  original += "key2";
  original += "key3";
  original["key1"] = "value1";
  original["key2"] = "value2";
  original["key3"] = "value3";
  Dictionary copy(original);
  EXPECT_EQ(copy.size(), 3);
  EXPECT_EQ(copy["key1"], original["key1"]);
  EXPECT_EQ(copy["key2"], original["key2"]);
  EXPECT_EQ(copy["key3"], original["key3"]);
}

TEST(DictionaryCopyConstructor, ModifyingOriginalDoesNotAffectCopy) {
  Dictionary original;
  original += "key1";
  original["key1"] = "value1";
  Dictionary copy(original);
  original += "key2";
  EXPECT_EQ(copy.size(), 1);
  EXPECT_EQ(copy["key1"], "value1");
  EXPECT_THROW(copy["key2"], std::out_of_range);
}

TEST(DictionaryCopyConstructor, ModifyingCopyDoesNotAffectOriginal) {
  Dictionary original;
  original += "key1";
  Dictionary copy(original);
  copy += "key2";
  copy["key2"] = "value2";
  EXPECT_EQ(original.size(), 1);
  EXPECT_EQ(copy["key1"], "");
  EXPECT_EQ(copy["key2"], "value2");
}

TEST(DictionaryRemoveOperator, RemovesLeafNode) {
  Dictionary dict;
  dict += "key1";
  dict -= "key1";
  EXPECT_EQ(dict.size(), 0);
  EXPECT_THROW(dict["key1"], std::out_of_range);
}

TEST(DictionaryRemoveOperator, RemovesNodeWithOnlyLeftChild) {
  Dictionary dict;
  dict += "key1";
  dict += "key0";
  dict -= "key1";
  EXPECT_EQ(dict.size(), 1);
  EXPECT_THROW(dict["key1"], std::out_of_range);
  EXPECT_NO_THROW(dict["key0"]);
}

TEST(DictionaryRemoveOperator, RemovesNodeWithOnlyRightChild) {
  Dictionary dict;
  dict += "key1";
  dict += "key2";
  dict -= "key1";
  EXPECT_EQ(dict.size(), 1);
  EXPECT_THROW(dict["key1"], std::out_of_range);
  EXPECT_NO_THROW(dict["key2"]);
}

TEST(DictionaryRemoveOperator, RemovesNodeWithTwoChildren) {
  Dictionary dict;
  dict += "key1";
  dict += "key0";
  dict += "key2";
  dict -= "key1";
  EXPECT_EQ(dict.size(), 2);
  EXPECT_THROW(dict["key1"], std::out_of_range);
  EXPECT_NO_THROW(dict["key0"]);
  EXPECT_NO_THROW(dict["key2"]);
}

TEST(DictionaryRemoveOperator, RemovesRootNode) {
  Dictionary dict;
  dict += "key1";
  dict -= "key1";
  EXPECT_EQ(dict.size(), 0);
  EXPECT_THROW(dict["key1"], std::out_of_range);
}

TEST(DictionaryRemoveOperator, RemovesNodeWithSuccessorHavingRightChild) {
  Dictionary dict;
  dict += "key1";
  dict += "key3";
  dict += "key2";
  dict -= "key1";
  EXPECT_EQ(dict.size(), 2);
  EXPECT_THROW(dict["key1"], std::out_of_range);
  EXPECT_NO_THROW(dict["key2"]);
  EXPECT_NO_THROW(dict["key3"]);
}

TEST(Dictionary, GetSize) {
  Dictionary dict;
  dict += "key1";
  dict += "key2";
  dict += "key3";
  EXPECT_EQ(dict.size(), 3);
}

TEST(Dictionary, SaveAndLoad) {
  Dictionary dict;
  dict += "key1";
  dict += "key2";
  dict += "key3";
  dict["key1"] = "зн1";
  dict["key2"] = "зн2";
  dict["key3"] = "знач";
  dict.save("test.txt");
  Dictionary loaded;
  loaded.load("test.txt");
  EXPECT_EQ(loaded["key1"], dict["key1"]);
  EXPECT_EQ(loaded["key2"], dict["key2"]);
  EXPECT_EQ(loaded["key3"], dict["key3"]);
  EXPECT_EQ(loaded.size(), 3);
}

TEST(Dictionary, LoadNonExistentFile) {
  Dictionary dict;
  EXPECT_THROW(dict.load("non_existent_file.txt"), std::runtime_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}