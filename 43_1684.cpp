#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {

        vector<char> letter;
        vector<char> word2;
        int count = 0;
        int final = 0;

        for (int i = 0; i < allowed.length(); i++)
        {
            letter.push_back(allowed[i]);
        }

        for (int i = 0; i < words.size(); i++)
        {

            for (int j = 0; j < words[i].length(); j++)
            {
                word2.push_back(words[i][j]);
            }

            for (int k = 0; k < letter.size(); k++)
            {
                for (int m = 0; m < word2.size(); m++)
                {
                    if (word2[m] == letter[k])
                    {
                        count++;
                    }
                }
            }

            if (count == word2.size())
            {
                final++;
            }

            count = 0;
            word2.clear();
        }

        return final;
    }
};

int main()
{
    Solution obj;
    string allowed = "ab";
    vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
    cout << obj.countConsistentStrings(allowed, words);
    return 0;
}