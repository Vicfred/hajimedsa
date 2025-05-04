// vicfred
// https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
// two pointers, sliding window
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int64_t findSubstring(const string &str) {
  int64_t n = str.size();
  // to store all different characters of the string
  vector<char> visited(26, false);
  int64_t distinct = 0;
  for(int64_t i = 0; i < n; ++i) {
    if(visited[str[i] - 'a'] == false) {
      visited[str[i] - 'a'] = true;
      distinct += 1;
    }
  }
  // to store visited characters
  // in the current window
  vector<int64_t> cur(26, 0);
  int64_t count = 0;
  int64_t ans = n;
  int64_t start = 0;
  for(int i = 0; i < n; ++i) {
    cout << "start: " << start << " end: " << i << " ";
    for(int x = start; x <= i; ++x) {
      cout << str[x];
    } cout << endl;
    // count characters in the current window
    cur[str[i] - 'a'] += 1;
    if(cur[str[i] - 'a'] == 1) {
      count += 1;
    }
    // if the count becomes same as overall
    while(count == distinct) {
      ans = min(ans, i - start + 1);
      // remove characters from the left
      cur[str[start] - 'a'] -= 1;
      if(cur[str[start] - 'a'] == 0) {
        count -= 1;
      }
      start += 1;
    }
  }
  return ans;
}

int main() {
  string str = "aabcbcdbca";
  cout << findSubstring(str) << endl;
  return 0;
}
