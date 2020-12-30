#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 0322. Coin Change

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= strs.size(); i++) {
            // 统计当前字符串中0，1个数
            vector<int> cnt(2);
            for (char c : strs[i - 1]) {
                if (c == '0') {
                    ++cnt[0];
                }
                else {
                    ++cnt[1];
                }
            }

            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    // 如果当前物品不能装进背包，继承上一轮的结果
                    if (cnt[0] > j || cnt[1] > k) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                    // 如果当前物品能装进背包，对比：
                    // 1）装进包，则数量为：减去当前物品重量的那一轮dp里的物品数量 + 1
                    // 2）能装而不装，继承上一轮结果的物品数量
                    // 比较二者大小
                    else {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - cnt[0]][k - cnt[1]] + 1);
                    }

                }
            }
        }
        return dp[strs.size()][m][n];
    }
};


struct TreeNode
{
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