#include "gtest/gtest.h"
#include "../TVector/TVector.h"

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(5);
	v = v + 5;
	TVector<int> p(v);

	EXPECT_EQ(v, p);
}


TEST(TVector, can_get_size)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}


TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v.GetValue(5));
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(4);
	TVector<int> p(4);
	ASSERT_NO_THROW(v = p);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(4);
	v[1] = 5;
	TVector<int> p(v);
	EXPECT_TRUE(v == p);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(4);
	v[1] = 5;
	EXPECT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(4);
	TVector<int> p(5);
	EXPECT_FALSE(v == p);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(4);
	v = v + 5;
	EXPECT_EQ(v[0], 5);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(4);
	v[0] = 5;
	v = v - 5;
	EXPECT_EQ(v[0], 0);
}

TEST(TVector, can_multiply_vector_by_scalar)
{
	TVector<int> v(4);
	v[0] = 1;
	v = v * 5;
	EXPECT_EQ(v[0], 5);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(4);
	v[0] = 5;
	TVector<int> p(4);
	ASSERT_NO_THROW(v = v + p);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	TVector<int> p(5);
	ASSERT_ANY_THROW(v = v + p);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(4);
	v[0] = 5;
	TVector<int> p(4);
	ASSERT_NO_THROW(v = v - p);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	TVector<int> p(5);
	ASSERT_ANY_THROW(v = v + p);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(4);
	v[0] = 5;
	TVector<int> p(4);
	ASSERT_NO_THROW(v = v * p);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	TVector<int> p(5);
	ASSERT_ANY_THROW(v = v * p);
}