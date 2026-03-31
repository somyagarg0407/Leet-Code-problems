#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> us(s.begin(), s.end());
        return us.size();
    }
};