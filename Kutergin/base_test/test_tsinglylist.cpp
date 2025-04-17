#include "tsinglylist.h"
#include <gtest.h>


TEST(SinglyList, can_create_empty_list) {
	SinglyList<int> list;
	EXPECT_EQ(list.length(), 0);
	EXPECT_TRUE(list.empty());
}


TEST(SinglyList, can_add_element_to_end) {
	SinglyList<int> list;
	list.addToEnd(42);
	EXPECT_EQ(list.length(), 1);
	EXPECT_EQ(list.getItem(0), 42);
}

TEST(SinglyList, can_add_element_to_start) {
	SinglyList<int> list;
	list.addToStart(42);
	EXPECT_EQ(list.length(), 1);
	EXPECT_EQ(list.getItem(0), 42);
}

TEST(SinglyList, can_add_multiple_elements) {
	SinglyList<int> list;
	list.addToEnd(1);
	list.addToEnd(2);
	list.addToStart(0);
	EXPECT_EQ(list.length(), 3);
	EXPECT_EQ(list.getItem(0), 0);
	EXPECT_EQ(list.getItem(1), 1);
	EXPECT_EQ(list.getItem(2), 2);
}


TEST(SinglyList, can_erase_element_by_index) {
	SinglyList<int> list;
	list.addToEnd(10);
	list.addToEnd(20);
	list.addToEnd(30);

	list.eraseAt(1);
	EXPECT_EQ(list.length(), 2);
	EXPECT_EQ(list.getItem(0), 10);
	EXPECT_EQ(list.getItem(1), 30);
}

TEST(SinglyList, erase_throws_for_invalid_index) {
	SinglyList<int> list;
	list.addToEnd(10);
	EXPECT_THROW(list.eraseAt(5), std::out_of_range);
}


TEST(SinglyList, can_get_item_by_index) {
	SinglyList<int> list;
	list.addToEnd(100);
	list.addToEnd(200);
	EXPECT_EQ(list.getItem(1), 200);
}

TEST(SinglyList, get_item_throws_for_invalid_index) {
	SinglyList<int> list;
	EXPECT_THROW(list.getItem(0), std::out_of_range);
}


TEST(SinglyList, can_reset_list) {
	SinglyList<int> list;
	list.addToEnd(10);
	list.addToEnd(20);
	list.reset();
	EXPECT_EQ(list.length(), 0);
	EXPECT_TRUE(list.empty());
}


TEST(SinglyList, can_copy_list) {
	SinglyList<int> list1;
	list1.addToEnd(10);
	list1.addToEnd(20);

	SinglyList<int> list2(list1);
	EXPECT_EQ(list2.length(), 2);
	EXPECT_EQ(list2.getItem(0), 10);
	EXPECT_EQ(list2.getItem(1), 20);
	EXPECT_EQ(list1, list2);
}


TEST(SinglyList, can_move_list) {
	SinglyList<int> list1;
	list1.addToEnd(10);
	list1.addToEnd(20);

	SinglyList<int> list2 = std::move(list1);
	EXPECT_EQ(list2.length(), 2);
	EXPECT_EQ(list2.getItem(0), 10);
	EXPECT_EQ(list2.getItem(1), 20);
	EXPECT_TRUE(list1.empty());
}


TEST(SinglyList, can_compare_equal_lists) {
	SinglyList<int> list1;
	list1.addToEnd(1);
	list1.addToEnd(2);

	SinglyList<int> list2;
	list2.addToEnd(1);
	list2.addToEnd(2);

	EXPECT_TRUE(list1 == list2);
	EXPECT_FALSE(list1 != list2);
}

TEST(SinglyList, can_compare_non_equal_lists) {
	SinglyList<int> list1;
	list1.addToEnd(1);
	list1.addToEnd(2);

	SinglyList<int> list2;
	list2.addToEnd(3);
	list2.addToEnd(4);

	EXPECT_FALSE(list1 == list2);
	EXPECT_TRUE(list1 != list2);
}


TEST(SinglyList, can_iterate_over_list) {
	SinglyList<int> list;
	list.addToEnd(1);
	list.addToEnd(2);
	list.addToEnd(3);

	int sum = 0;
	for (auto value : list) {
		sum += value;
	}
	EXPECT_EQ(sum, 6);
}


TEST(SinglyList, can_store_custom_types) {
	struct CustomType {
		int x;
		double y;
	};
	SinglyList<CustomType> list;
	list.addToEnd({ 1, 1.5 });
	list.addToEnd({ 2, 2.5 });

	EXPECT_EQ(list.getItem(0).x, 1);
	EXPECT_EQ(list.getItem(1).y, 2.5);
}
