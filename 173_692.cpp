
#include <bits/stdc++.h>
using namespace std;

struct compare {
    bool operator()(pair<int, string>& a, pair<int, string>& b) {

        if (a.first == b.first) {
            return a.second < b.second; // Same frequency → keep smaller word, remove larger word
        }

        return a.first > b.first;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {

    unordered_map<string, int> freq;
    vector<string> ans;

    // Frequency count
    for (string word : words) {
        freq[word]++;
    }

    // Min heap
    priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        compare
    > pq;

    // Push all words
    for (auto it : freq) {
        pq.push({it.second, it.first});

        if (pq.size() > k) {
            pq.pop();
        }
    }

    // Get k elements
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    // Highest priority first
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    vector<string> words = {
        "i", "love", "leetcode", "i", "love", "coding"
    };

    int k = 2;

    vector<string> ans = topKFrequent(words, k);

    cout << "Top " << k << " frequent words: ";

    for (string word : ans) {
        cout << word << " ";
    }

    cout << endl;

    return 0;
}

