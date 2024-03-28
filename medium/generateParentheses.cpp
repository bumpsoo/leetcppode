#include <string>
#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.com/problems/generate-parentheses
class Solution {
public:
  void generateParenthesisHelp(
      vector<string> &v, int open, int close, int n, string str
  ) {
    if (str.size() == 2 * n) {
      v.push_back(str);
      return;
    }
    if (open < n) {
      generateParenthesisHelp(v, open + 1, close, n, str+"(");
    }
    if (open > close) {
      generateParenthesisHelp(v, open, close + 1, n, str+")");
    }
  }
  vector<string> generateParenthesis(int n) {
    auto ret = vector<string>();
    generateParenthesisHelp(ret, 0, 0, n, "");
    return ret;
  }
};

int main() {
  auto s = Solution();
  auto v = s.generateParenthesis(3);
  auto exp = vector<string>{"((()))","(()())","(())()","()(())","()()()"};
  for (auto i = 0; i < exp.size(); i++) {
    if (v[i].compare(exp[i])) {
      cout << v[i] << endl;
      return 1;
    }
  }
}
