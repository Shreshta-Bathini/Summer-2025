#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
      vector<int> p (26,0);
      vector<int> q(26,0);
      if (s.length()!=t.length())
      return false;
      for (int i=0; i<s.length(); i++) {
        p[s[i]-'a']++;
        q[t[i]-'a']++;
      } 
      for (int i=0; i<26; i++) {
        if (p[i]!=q[i])
        return false;
      } 
      return true;
    }
};
