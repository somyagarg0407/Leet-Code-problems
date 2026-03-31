#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                if (words[i][j] == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter words: ";
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    char x;
    cout << "Enter character: ";
    cin >> x;

    vector<int> result = obj.findWordsContaining(words, x);

    cout << "Indices: ";
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}