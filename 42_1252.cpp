#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < indices.size(); i++) {
            row[indices[i][0]]++;
            col[indices[i][1]]++;
        }

        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((row[i] + col[j]) % 2 != 0){
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {

    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    int k;
    cout << "Enter number of index pairs: ";
    cin >> k;

    vector<vector<int>> indices(k, vector<int>(2));

    cout << "Enter the index pairs:\n";
    for(int i=0;i<k;i++){
        cin >> indices[i][0] >> indices[i][1];
    }

    Solution obj;
    cout << "Number of odd cells: " << obj.oddCells(m, n, indices);

    return 0;
}
