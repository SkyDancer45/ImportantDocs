#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using colorValuesMap = std::unordered_map<int, int>;
using colorValuesMapIterator = colorValuesMap::const_iterator;
void swap(int i, int j, vector<int> &arr) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
void sortColors(vector<int> &arr) {
  int low = 0, mid = 0, high = arr.size() - 1;
  while (mid <= high) {
    int i = arr[mid];
    if (i == 2) {
      swap(mid, high, arr);
      high--;
    } else if (i == 1) {
      mid++;
    } else {
      swap(low, mid, arr);
      low++;
      mid++;
    }
  }
}
// void sortColors(vector<int> &arr) {
//
//   colorValuesMap mpp;
//   mpp[0] = 0;
//   mpp[1] = 0;
//   mpp[2] = 0;
//   for (int i : arr) {
//     if (i == 0) {
//       mpp[0] = mpp[0] + 1;
//     }
//     if (i == 1) {
//       mpp[1] = mpp[1] + 1;
//     }
//     if (i == 2) {
//       mpp[2] = mpp[2] + 1;
//     }
//   }
//   int oneCount = mpp[1];
//   int zeroCount = mpp[0];
//   int twoCount = mpp[2];
//   int i = 0;
//   for (; i < mpp[0]; i++) {
//
//     arr[i] = 0;
//   }
//   for (; i < mpp[0] + mpp[1]; i++) {
//     arr[i] = 1;
//   }
//   for (; i < mpp[0] + mpp[1] + mpp[2]; i++) {
//     arr[i] = 2;
//   }
// }
int main(int argc, char *argv[]) {
  vector<int> arr = {2, 1, 1, 0, 2, 0};
  sortColors(arr);
  for (int i : arr) {
    std::cout << i;
  }
  return 0;
}
