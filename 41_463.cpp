#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == 1) {
                    perimeter += 4;

                    // Up
                    if (i > 0 && grid[i - 1][j] == 1)
                        perimeter--;

                    // Down
                    if (i < rows - 1 && grid[i + 1][j] == 1)
                        perimeter--;

                    // Left
                    if (j > 0 && grid[i][j - 1] == 1)
                        perimeter--;

                    // Right
                    if (j < cols - 1 && grid[i][j + 1] == 1)
                        perimeter--;
                }
            }
        }

        return perimeter;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    cout << "Perimeter: " << obj.islandPerimeter(grid);

    return 0;
}
    