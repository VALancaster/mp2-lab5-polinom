#include "tsinglylist.h"
#include <gtest.h>

TEST(TSinglyList, can_create_default_singly_list)
{
	TSinglyList<int> list;

	EXPECT_TRUE(list.IsEmpty());
	EXPECT_EQ(list.size(), 0);
}

TEST(TSinglyList, can_create_singly_list_from_vector)
{
	std::vector<int> v = { 1, 2, 3 };
	TSinglyList<int> list(v);

	EXPECT_EQ(list.size(), 3);
	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list[1], 2);
	EXPECT_EQ(list[2], 3);
}

TEST(TSinglyList, can_create_copied_singly_list)
{
	std::vector<int> v = { 1, 2, 3 };
	TSinglyList<int> original(v);
	TSinglyList<int> copy(original);

	EXPECT_EQ(copy.size(), 3);
	EXPECT_EQ(copy[0], 1);
	EXPECT_EQ(copy[1], 2);
	EXPECT_EQ(copy[2], 3);
}

TEST(TSinglyList, copy_assignment_operator_works) 
{
	std::vector<int> v = { 1, 2, 3 };
	TSinglyList<int> original(v);
	TSinglyList<int> copy;

	copy = original;
	
	EXPECT_EQ(copy.size(), 3);
	EXPECT_EQ(copy[0], 1);
	EXPECT_EQ(copy[1], 2);
	EXPECT_EQ(copy[2], 3);
}

TEST(TSinglyList, can_push_front) 
{
    TSinglyList<int> list;

    list.PushFront(1);
    list.PushFront(2);
    list.PushFront(3);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.Front(), 3);
}

TEST(TSinglyList, can_pop_front) 
{
    TSinglyList<int> list;

    list.PushFront(1);
    list.PushFront(2);
    list.PopFront();

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.Front(), 1);
}

TEST(TSinglyList, can_push_after) 
{
    TSinglyList<int> list;

    list.PushFront(1);
    list.PushFront(2);
    list.PushAfter(0, 3); 

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list[1], 3);
}

TEST(TSinglyList, can_erase_after) 
{
    TSinglyList<int> list;

    list.PushFront(1);
    list.PushFront(2);
    list.PushFront(3);
    list.EraseAfter(0); 

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[1], 1);
}

TEST(TSinglyList, can_return_pointer_to_element_by_its_position) 
{
    TSinglyList<int> list;

    list.PushFront(1);
    list.PushFront(2);
    list.PushFront(3);

    EXPECT_EQ(list.ToPos(1)->value, 2);
}

TEST(TSinglyList, can_clear) 
{
    TSinglyList<int> list;

    list.PushFront(1);
    list.PushFront(2);
    list.Clear();

    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(list.size(), 0);
}

TEST(TSinglyList, can_return_value_by_index) 
{
    TSinglyList<int> list;

    list.PushFront(1);
    list.PushFront(2);

    EXPECT_EQ(list[0], 2);
    EXPECT_EQ(list[1], 1);
}
