#include "include/binary_search.hpp"
#include <gtest/gtest.h>

int sortedArray[] = {2, 3, 6, 7, 8, 23, 44, 50, 52, 64};

TEST(BinarySearch, SimpleBinarySearch) {
  int index = binarySearch(sortedArray, 10, 44);
  EXPECT_EQ(index, 6);
}

TEST(BinarySearch, BinaryRescursiveSearch) {
  int index = binary_recursive_search(sortedArray, 10, 52);
  EXPECT_EQ(index, 8);
}

TEST(BinarySearch, CircularArraySearch) {
  int rotated_array[] = {22, 34, 54, 75, 2, 3, 4, 6, 7, 9};
  int index = circular_array_search(rotated_array, 10, 54);

  // Expect two strings not to be equal.
  /*EXPECT_STRNE("hello", "world");*/

  // Expect equality.
  EXPECT_EQ(index, 2);
}
