#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

// https://leetcode.com/problems/groups-of-special-equivalent-strings/

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:

  int numSpecialEquivGroups2(vector<string> &A) {
    unordered_set<string> S;
    for (const auto &item : A) {
      string sig(52, '\0');
      // evens
      for (int i = 0; i < item.length(); i += 2) ++sig[item[i] - 'a'];
      for (int i = 1; i < item.length(); i += 2) ++sig[item[i] - 'a' + 26];
      cout << sig << endl;
      S.insert(move(sig));
    }
    return S.size();
  }

  int numSpecialEquivGroups(vector<string> &A) {
    set<vector<char>> S;
    for (const auto &item : A) {
      vector<char> sig(52);
      // evens
      for (int i = 0; i < item.length(); ++i) ++sig[item[i] - 'a' + 26 * (i % 2)];
      S.insert(move(sig));
    }
    return S.size();
  }
};

void test1() {
  vector<string> v1{"a", "b", "c", "a", "c", "c"};

  cout << "3 ? " << Solution().numSpecialEquivGroups(v1) << endl;
}

void test2() {

}

void test3() {

}