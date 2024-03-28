#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// https://leetcode.com/problems/sort-colors
class Solution {
public:
  void sortColors(vector<int>& nums) {
    auto v = unordered_map<int, int>();
    for (int i = 0; i < nums.size(); i++) {
      v[nums[i]]++;
    }
    int last = 0;
    for (int num : vector<int>{0,1,2}) {
      for (int i = 0; i < v[num]; i++) {
        nums[last+i] = num;
      }
      last += v[num];
    }
  }
};

int main() {
  auto s = Solution();
  auto v = vector<int>{2,0,2,1,1,0};
  s.sortColors(v);
  if (v != vector<int>{0,0,1,1,2,2}) {
    for (auto val : v)
    cout << val << endl;
    return 1;
  }
  v = {2,0,1};
  s.sortColors(v);
  if (v != vector<int>{0,1,2}) {
    for (auto val : v)
    cout << val << endl;
    return 1;
  }
}
