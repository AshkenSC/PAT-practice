#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 213. House Robber II

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);
        dp1[0] = nums[0];
        dp1[1] = nums[1];
        dp1[2] = nums[2] + nums[0];
        dp2[1] = nums[1];
        dp2[2] = nums[2];
        dp2[3] = nums[3] + nums[1];

        for (int i = 3; i < nums.size(); i++) {
            if (i == 3) {
                dp1[i] = max(dp1[i - 2], dp1[i - 3]) + nums[i];
            }
            else if (i == nums.size() - 1) {
                dp2[i] = max(dp2[i - 2], dp2[i - 3]) + nums[i];
            }
            dp1[i] = max(dp1[i - 2], dp1[i - 3]) + nums[i];
            dp2[i] = max(dp2[i - 2], dp2[i - 3]) + nums[i];
        }

        int result;
        int n = nums.size();
        result = max(dp1[n - 2], dp1[n - 3]);
        result = max(result, dp2[n - 2]);
        result = max(result, dp2[n - 1]);

        return result;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main() {
    Solution sol;
    vector<int> input = {2, 3, 1, 1, 4};
    bool res = sol.canJump(input);
    cout << res;

    return 0;
}