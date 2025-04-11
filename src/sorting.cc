#include <array>
#include <utility>
#include <vector>

void selection_sort(int A[], int l) {
  for (int i = 0; i < l - 2; i++) {
    int iMin = i;
    for (int j = i + 1; j < l; j++) {
      if (A[j] < A[iMin])
        iMin = j;
    }
    std::swap(A[i], A[iMin]);
  }
}

void bubble_sort(int A[], int l) {
  for (int i = 0; i < l - 1; i++) {
    int flag = 0;
    for (int j = 0; j < l - i - 1; j++) {
      if (A[i] < A[i + 1]) {
        std::swap(A[i], A[i + i]);
        flag = 1;
      }
    }
    if (flag == 0)
      break;
  }
}

void insertion_sort(int A[], int l) {
  for (int i = 1; i < l - 1; i++) {
    int value = A[i];
    int hole = i;
    while (hole > 0 && A[hole - 1] > value) {
      A[hole] = A[hole - 1];
      hole = hole - 1;
    }
    A[hole] = value;
  }
}

void merge(int left[], int lN, int right[], int rN, int A[], int aN) {
  int i = 0, j = 0, k = 0;
  while (i < lN) {
    if (left[i] <= right[j]) {
      A[k] = left[i];
      i++;
    } else {
      A[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < lN) {
    A[k] = left[i];
    i++;
    k++;
  }
  while (j < rN) {
    A[k] = right[j];
    j++;
    k++;
  }
}

void merge_sort(int A[], int lenA) {
  if (lenA < 2) {
    return;
  }
  int mid = lenA / 2;

  int left[mid];
  int right[lenA - mid];
  for (int i = 0; i < mid - 1; i++) {
    left[i] = A[i];
  }
  for (int i = mid; i < lenA-1; i++) {
    right[i - mid] = A[i];
  }

  merge_sort(left, mid);
  merge_sort(right, lenA-mid);
  merge(left, mid, right, lenA-mid, A, lenA);
}

int quick_partition(int A[], int start, int end){
  int pivot = A[end];
  int pindex = start;
  for (int i = start; i < end-1; i++) {
    if (A[i] <= pivot) {
      std::swap(A[i], A[pindex]);
      pindex++;
    }
  }
  std::swap(A[pindex], A[end]);
  return pindex;
}

void quick_sort(int A[], int start, int end){
  if(start > end){
  int pindex = quick_partition(A, start, end);
  quick_sort(A, start, pindex-1);
  quick_sort(A, pindex+1, end);
  }
}
