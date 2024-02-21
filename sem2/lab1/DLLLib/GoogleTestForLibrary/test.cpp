#include "pch.h"
#include "..\DualLinkedListLibrary\DLLLibrary.h"

using namespace DLLLibrary;

	TEST(LinkedListTest, PushFrontTest) {
		LinkedList list;
		list.pushFront(2);
		list.pushFront(1);

		EXPECT_EQ(list.GetSize(), 2);
		EXPECT_EQ(list.getFront(), 1);
		EXPECT_EQ(list.getBack(), 2);
	}

	TEST(LinkedListTest, PushBackTest) {
		LinkedList list;
		list.pushBack(1);
		list.pushBack(2);

		EXPECT_EQ(list.GetSize(), 2);
		EXPECT_EQ(list.getFront(), 1);
		EXPECT_EQ(list.getBack(), 2);
	}

	TEST(LinkedListTest, PopFrontTest) {
		LinkedList list;
		list.pushBack(1);
		list.pushBack(2);
		list.popFront();

		EXPECT_EQ(list.GetSize(), 1);
		EXPECT_EQ(list.getFront(), 2);
		EXPECT_EQ(list.getBack(), 2);
	}

	TEST(LinkedListTest, PopBackTest) {
		LinkedList list;
		list.pushBack(1);
		list.pushBack(2);
		list.popBack();

		EXPECT_EQ(list.GetSize(), 1);
		EXPECT_EQ(list.getFront(), 1);
		EXPECT_EQ(list.getBack(), 1);
	}

	TEST(LinkedListTest, eraseTest) {
		LinkedList list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		list.erase(list.getNode(1));

		EXPECT_EQ(list.GetSize(), 2);
		EXPECT_EQ(list.getFront(), 1);
		EXPECT_EQ(list.getBack(), 3);
	}

	TEST(LinkedListTest, insertAfterTest) {
		LinkedList list;
		list.pushFront(1);
		list.insertAfter(list.getNode(0), 2);
		list.insertAfter(list.getNode(0), 3);

		EXPECT_EQ(list.GetSize(), 3);
		EXPECT_EQ(list.getFront(), 1);
		EXPECT_EQ(list.getBack(), 2);
	}

	TEST(LinkedListTest, insertBeforeTest) {
		LinkedList list;
		list.pushFront(1);
		list.insertBefore(list.getNode(0), 2);
		list.insertBefore(list.getNode(0), 3);

		EXPECT_EQ(list.GetSize(), 3);
		EXPECT_EQ(list.getFront(), 3);
		EXPECT_EQ(list.getBack(), 1);
	}

	TEST(LinkedListTest, SortTest) {
		LinkedList list;
		list.pushFront(3);
		list.pushFront(100);
		list.pushFront(1);

		list.Sort();

		EXPECT_EQ(list.GetSize(), 3);
		EXPECT_EQ(list.getFront(), 1);
		EXPECT_EQ(list.getBack(), 100);
	}

	TEST(LinkedListTest, MergeTest) {
		LinkedList list1;
		list1.pushFront(1);
		list1.pushFront(2);
		list1.pushFront(3);

		LinkedList list2;
		list2.pushFront(1);
		list2.pushFront(2);
		list2.pushFront(3);

		LinkedList mergedList = list1.merge(list2);

		EXPECT_EQ(mergedList.GetSize(), 6);
		EXPECT_EQ(mergedList.getFront(), 3);
		EXPECT_EQ(mergedList.getBack(), 1);
	}

	TEST(LinkedListTest, IntersectionTest) {
		LinkedList list1;
		list1.pushFront(1);
		list1.pushFront(2);
		list1.pushFront(3);
		list1.pushFront(4);

		LinkedList list2;
		list2.pushFront(5);
		list2.pushFront(2);
		list2.pushFront(3);

		LinkedList interssectedList = list1.intersection(list2);

		EXPECT_EQ(interssectedList.GetSize(), 2);
		EXPECT_EQ(interssectedList.getFront(), 3);
		EXPECT_EQ(interssectedList.getBack(), 2);
	}
	int main(int argc, char** argv) {
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
}