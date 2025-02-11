// binarySearch A: list of int, n: size of list: x: no_search
int binarySearch(int A[], int n, int x) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (x == A[mid])
      return mid;
    else if (x < A[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
}

int binary_recursive_search(int A[], int high, int x, int low = 0) {
  int mid = low + (high - low) / 2;
  if (x == A[mid])
    return mid;
  else if (x < A[mid])
    return binary_recursive_search(A, mid - 1, x, low);
  else {
    return binary_recursive_search(A, high, x, mid + 1);
  }
  return -1;
}

int binary_search_first(int A[], int n, int x) {
  int low = 0, high = n - 1, result = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (x == A[mid])
      result = mid, high = mid - 1;
    else if (x < A[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  return result;
}

int binary_search_last(int A[], int n, int x) {
  int low = 0, high = n - 1, result = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (x == A[mid])
      result = mid, low = mid + 1;
    else if (x < A[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  return result;
}

int find_count(int A[], int n, int x) {
  int firstIndex = binary_search_first(A, n, x);
  int lastIndex = binary_search_last(A, n, x);
  return (lastIndex - firstIndex + 1);
}

int find_rotation_count(int A[], int n) {
  int low = 0, high = n - 1;
  while (low <= high) {
    // case 1
    if (A[low] <= A[high])
      return low;

    int mid = (low + high) / 2;
    int next = (mid + 1) % n,
        prev = (mid + n - 1) % n; // modulo n incase if we reached last element

    // case 2
    if (A[mid] <= A[next] && A[mid] <= A[prev])
      return mid;
    else if (A[mid] <= A[high]) // case 3
      high = mid - 1;
    else if (A[mid] >= A[low]) // case 4
      low = mid + 1;
  }
  return -1;
}

int circular_array_search(int A[], int n, int x) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (A[mid] == x) // case 1
      return mid;

    if (A[mid] <= A[high]) { // case 2
      if (x > A[mid] && x <= A[high])
        low = mid + 1;
      else
        high = mid - 1;
    }

    if (A[low] <= A[mid]) { // case 3
      if (x >= A[low] && x < A[mid])
        high = mid - 1;
      else
        low = mid + 1;
    }
  }
  return -1;
}
