#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<int> freq(26, 0);
        
        for(char c : words[0])
            freq[c - 'a']++;
        
        for(int i = 1; i < words.size(); i++) {
            vector<int> temp(26, 0);
            
            for(char c : words[i])   //-------------------IMPORTANT---------------
                temp[c - 'a']++;
            
            for(int j = 0; j < 26; j++)
                freq[j] = min(freq[j], temp[j]); //----------------IMPORTANT---------------
        }
        
        vector<string> result;
        
        for(int i = 0; i < 26; i++) {
            while(freq[i] > 0) {
                result.push_back(string(1, i + 'a')); //---------IMPORTANT-------
                freq[i]--;
            }
        }
        
        return result;
    }
};

int main() {
    Solution obj;
    
    vector<string> words = {"bella", "label", "roller"};
    
    vector<string> ans = obj.commonChars(words);
    
    for(string s : ans)
        cout << s << " ";
    
    return 0;
}