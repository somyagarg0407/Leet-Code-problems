#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        vector<char> vowels;
        vector<char> cons;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowels.push_back(s[i]);
            } else {
                cons.push_back(s[i]);
            }
        }

        unordered_map<char, int> freq1;

        for (int i = 0; i < vowels.size(); i++) {
            freq1[vowels[i]]++;
        }

        int maxFreq1 = 0;

        for (auto it : freq1) {
            if (it.second > maxFreq1) {
                maxFreq1 = it.second;
            }
        }

        unordered_map<char, int> freq2;

        for (int i = 0; i < cons.size(); i++) {
            freq2[cons[i]]++;
        }

        int maxFreq2 = 0;

        for (auto it : freq2) {
            if (it.second > maxFreq2) {
                maxFreq2 = it.second;
            }
        }

        return maxFreq1 + maxFreq2;
    }
};