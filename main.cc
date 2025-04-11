#include "binary_search.hpp"
#include "sorting.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <vector>

int sortedArray[] = {2, 3, 6, 7, 8, 23, 44, 50, 52, 64};
int unSortedArray[] = {8, 50, 6, 64, 2, 23, 44, 3, 52, 7};

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
  EXPECT_EQ(index, 2);
}

TEST(Sortingalgo, SelectionSort) {
  selection_sort(unSortedArray, 10);
  testing::internal::ArrayEq(unSortedArray, sortedArray);
}

TEST(Sortingalgo, BubbleSort) {
  bubble_sort(unSortedArray, 10);
  testing::internal::ArrayEq(unSortedArray, sortedArray);
}

TEST(Sortingalgo, InsertionSort) {
  insertion_sort(unSortedArray, 10);
  testing::internal::ArrayEq(unSortedArray, sortedArray);
}

TEST(Sortingalgo, MergeSort) {
  merge_sort(unSortedArray, 10);
  testing::internal::ArrayEq(unSortedArray, sortedArray);
}

TEST(Sortingalgo, QuickSort) {
  quick_sort(unSortedArray, 0, 9);
  testing::internal::ArrayEq(unSortedArray, sortedArray);
}
