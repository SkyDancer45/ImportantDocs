#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void merge(std::vector<int> arr, int low, int mid, int high) {
  int n1 = mid - low + 1;
  int n2 = high - mid;
  std::vector<int> left(n1), right(n2);
  for (int i = 0; i < left.size(); i++) {
    left[i] = arr[i + low];
  }
  for (int j = 0; j < right.size(); j++) {
    right[j] = arr[j + mid];
  }
  int i = 0, j = 0, k = low;
  while (i < left.size() && j < right.size()) {

    if (left[i] <= right[j]) {

      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < left.size()) {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < right.size()) {
    arr[k] = right[i];
    j++;
    k++;
  }
}
void mergeSort(std::vector<int> &arr, int low, int high) {
  if (high - low > 1) {

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid, high);
    merge(arr, low, mid, high);
  }
}
int main(int argc, char *argv[]) {
  std::vector<int> arr = {4, 2, 1, 6, 5};

  mergeSort(arr, 0, arr.size() - 1);
  for (int i : arr) {
    std::cout << "\n" << i;
  }
  return 0;
}
