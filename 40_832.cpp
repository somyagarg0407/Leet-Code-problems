#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        vector<vector<int>> final(image[0].size(),
                                  vector<int>(image.size()));

        // Flip horizontally
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image.size(); j++) {
                final[i][j] = image[i][image.size() - j - 1];
            }
        }

        // Invert image
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image.size(); j++) {
                if (final[i][j] == 0) {
                    final[i][j] = 1;
                } else {
                    final[i][j] = 0;
                }
            }
        }

        return final;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> image = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}
    };

    vector<vector<int>> result = obj.flipAndInvertImage(image);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
