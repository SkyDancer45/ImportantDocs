#include <iostream>
#include <unordered_map>
#include <vector>
int nby2(std::vector<int> &arr) {
  int count = 0, element;
  for (int i : arr) {
    if (i == element) {
      count++;
    } else {
      if (count == 0) {
        element = i;
        count = 1;
      } else {
        count--;
      }
    }
  }
  int cnt1 = 0;
  for (int i : arr) {
    if (i == element) {
      cnt1++;
    }
  }
  if (cnt1 > (arr.size()) / 2) {

    return element;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  int ans = nby2(arr);
  std::cout << ans;
  return 0;
}
