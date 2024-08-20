#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target) {

  int left = 0, right = size(arr) - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) {

      return {left, right};
    } else if (sum < target) {

      left++;
    } else {

      right--;
    }
  }
  return {-1, -1};
}

int main() {
  int n = 5;
  vector<int> ans1 = {2, 6, 5, 8, 11};

  int target = 7;
  vector<int> ans = twoSum(ans1, target);
  std::cout << "This is the answer for variant 2: [" << ans[0] << ", " << ans[1]
            << "]" << std::endl;
  return 0;
}
