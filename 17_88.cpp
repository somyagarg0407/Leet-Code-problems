#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = m; i < n + m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nums1[i] = nums2[j];
                i++;
            }
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);

    // print result
    for (int x : nums1)
    {
        cout << x << " ";
    }

    return 0;
}
