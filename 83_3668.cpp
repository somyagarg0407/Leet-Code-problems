#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;

        for (int i = 0; i < order.size(); i++) {
            for (int j = 0; j < friends.size(); j++) {
                if (order[i] == friends[j]) {
                    ans.push_back(friends[j]);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n, m;
    cout << "Enter size of order: ";
    cin >> n;

    vector<int> order(n);
    cout << "Enter elements of order: ";
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }

    cout << "Enter size of friends: ";
    cin >> m;

    vector<int> friends(m);
    cout << "Enter elements of friends: ";
    for (int i = 0; i < m; i++) {
        cin >> friends[i];
    }

    vector<int> result = obj.recoverOrder(order, friends);

    cout << "Recovered Order: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}