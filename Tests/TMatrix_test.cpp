#include <gtest/gtest.h>
#include "../TMatrix/TMatrix.h"


TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(13));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	m[0][1] = 6;
	TMatrix<int> p(m);
	EXPECT_TRUE(m == p);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);

	EXPECT_TRUE(4 == v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(4);
	v[0][1] = 5;
	EXPECT_EQ(5, v[0][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> v(4);

	ASSERT_ANY_THROW(v[-5][5] = 5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> v(4);

	ASSERT_ANY_THROW(v[6][0]=1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> v(4);
	ASSERT_NO_THROW(v = v);
}


TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> v(4);
	v[0][0] = 5;
	TMatrix<int> p(4);
	ASSERT_NO_THROW(v = p);
}


TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> v(4);
	v[0][0] = 5;
	TMatrix<int> p(4);
	v = p;
	EXPECT_TRUE(v== p);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> v(4);
	v[1][3] = 5;
	EXPECT_TRUE(v == v);
}
TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> v(4);
	TMatrix<int> p(5);
	EXPECT_FALSE(v == p);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> v(4);
	v[0][0] = 5;
	TMatrix<int> p(4);
	p = p + v;
	EXPECT_EQ(p[0][0], 5);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> v(4);
	TMatrix<int> p(5);
	ASSERT_ANY_THROW(v = v + p);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> v(4);
	v[0][0] = 5;
	TMatrix<int> p(4);
	p = p - v;
	EXPECT_EQ(p[0][0], -5);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> v(4);
	TMatrix<int> p(5);
	ASSERT_ANY_THROW(v = v - p);
}